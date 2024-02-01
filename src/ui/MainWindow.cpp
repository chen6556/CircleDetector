#include "ui/MainWindow.hpp"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _file_model(new QStringListModel)
    , _label(new Label)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _file_model;
    delete _label;
    QJsonArray params;
    for (const double param : _params)
    {
        params.append(param);
    }
    QJsonArray flags;
    for (const bool flag : _flags)
    {
        flags.append(flag);
    }
    QJsonObject obj;
    obj.insert("path", _path.isEmpty() ? "C:/" : _path);
    obj.insert("params", params);
    obj.insert("flags", flags);
    QJsonDocument doc(obj);
    QFile file("./config.json");
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.close();
}

void MainWindow::init()
{
    ui->listView->setModel(_file_model);
    ui->verticalLayout->insertWidget(0, _label);
    QFile file("./config.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value = file.readAll();
    file.close();
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if (parseJsonErr.error == QJsonParseError::NoError)
    {
        QJsonObject obj = document.object();
        _path = obj.value("path").toString();
        for (const QJsonValueRef param : obj.value("params").toArray())
        {
            _params.push_back(param.toDouble());
        }
        for (const QJsonValueRef flag : obj.value("flags").toArray())
        {
            _flags.push_back(flag.toBool());
        }
        _detector.set_detect_circle(_flags.at(0));
        _detector.set_detect_rectangle(_flags.at(1));
    }
    else
    {
        _path = "C:/";
        _params.push_back(80);
        _params.push_back(20);
        _params.push_back(10);
        _params.push_back(200);
        _params.push_back(0.1);

        _flags.push_back(true);
        _flags.push_back(false);
    }
}

void MainWindow::open_file()
{
    QFileDialog* dialog = new QFileDialog();
    dialog->setModal(true);
    dialog->setDirectory(_path);
    dialog->setFileMode(QFileDialog::ExistingFiles);
    dialog->setNameFilters({"Pictures (*.png *.jpg)", "All Files (*.)"});
    QStringList files =  dialog->getOpenFileNames();
    if (!files.isEmpty())
    {
        QFileInfo info(files.first());
        _path = info.canonicalPath();
        _file_list.clear();
        std::for_each(files.begin(), files.end(), [this](const QString& file){_file_list.append(QFileInfo(file).fileName());});
        _file_model->setStringList(_file_list);
        _index = _file_model->index(0);
        ui->listView->setCurrentIndex(_index);
        show_image();
    }
    delete dialog;
}

void MainWindow::open_folder()
{
    QFileDialog* dialog = new QFileDialog();
    dialog->setModal(true);
    dialog->setDirectory(_path);
    dialog->setFileMode(QFileDialog::Directory);
    QString path = dialog->getExistingDirectory();
    if (!path.isEmpty())
    {
        QDir dir(path);
        _path = path;
        _file_list = dir.entryList({"*.png", "*.jpg"}, QDir::Files | QDir::Readable, QDir::Name);
        _file_model->setStringList(_file_list);
        _index = _file_model->index(0);
        ui->listView->setCurrentIndex(_index);
        show_image();
    }
    delete dialog;
}

void MainWindow::last()
{
    if (_file_model->rowCount() == 0)
    {
        return;
    }
    if (_index.row() <=  0)
    {
        _index = _file_model->index(_file_model->rowCount() - 1);
    }
    else
    {
        _index = _file_model->index(_index.row() - 1);
    }
    ui->listView->setCurrentIndex(_index);
    show_image();
}

void MainWindow::next()
{
    if (_file_model->rowCount() == 0)
    {
        return;
    }
    if (_index.row() >=  _file_model->rowCount() - 1)
    {
        _index = _file_model->index(0);
    }
    else
    {
        _index = _file_model->index(_index.row() + 1);
    }
    ui->listView->setCurrentIndex(_index);
    show_image();
}

void MainWindow::select(const QModelIndex& index)
{
    if (!index.isValid())
    {
        return;
    }
    _index = index;
    ui->listView->setCurrentIndex(_index);
    show_image();
}

void MainWindow::detect()
{
    _detector.load_img(_label->pixmap());
    _detector.detect(_params.at(0), _params.at(1), _params.at(2), _params.at(3));
    _label->setPixmap(_detector.result_to_QPixmap());
}

void MainWindow::show_image()
{
    if (_index.isValid())
    {
        _label->setPixmap(_path + '/' + _index.data().toString());
    }
}

void MainWindow::edit_params()
{
    ParametersDialog dialog(&_params, &_flags, this);
    dialog.exec();

    _detector.set_detect_circle(_flags.at(0));
    _detector.set_detect_rectangle(_flags.at(1));
}