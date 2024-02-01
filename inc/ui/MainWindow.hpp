#pragma once
#include <QMainWindow>
#include <QString>
#include <QStringListModel>
#include <QModelIndex>
#include "base/Label.hpp"
#include "base/Detector.hpp"
#include "ui/ParametersDialog.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void init();

private slots:
    void open_file();
    void open_folder();
    void last();
    void next();
    void select(const QModelIndex& index);

    void detect();
    void show_image();
    void edit_params();

private:
    Ui::MainWindow *ui;
    Label *_label;
    Detector _detector;

    std::vector<double> _params;
    std::vector<bool> _flags;
    QString _path;
    QStringList _file_list;
    QStringListModel *_file_model;
    QModelIndex _index;
};