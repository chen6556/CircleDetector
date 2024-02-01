#pragma once
#include <QDialog>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class ParametersDialog;}
QT_END_NAMESPACE

class ParametersDialog: public QDialog
{
    Q_OBJECT

private:
    Ui::ParametersDialog *ui;
    std::vector<double> *_params;
    std::vector<bool> *_flags;

private slots:
    void refresh_params();

public:
    ParametersDialog(std::vector<double> *params, std::vector<bool> *flags, QWidget* parent = nullptr);
};