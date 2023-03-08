#include "ui/ParametersDialog.hpp"
#include "./ui_parametersdialog.h"


ParametersDialog::ParametersDialog(std::vector<double> *params, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ParametersDialog)
    , _params(params)
{
    ui->setupUi(this);
    ui->param1->setValue(_params->at(0));
    ui->param2->setValue(_params->at(1));
    ui->minRadius->setValue(_params->at(2));
    ui->maxRadius->setValue(_params->at(3));
}

void ParametersDialog::refresh_params()
{
    _params->at(0) = ui->param1->value();
    _params->at(1) = ui->param2->value();
    _params->at(2) = ui->minRadius->value();
    _params->at(3) = ui->maxRadius->value();
}