#include "ui/ParametersDialog.hpp"
#include "./ui_parametersdialog.h"


ParametersDialog::ParametersDialog(std::vector<double> *params, std::vector<bool> *flags, QWidget* parent)
    : QDialog(parent), ui(new Ui::ParametersDialog), _params(params), _flags(flags)
{
    ui->setupUi(this);
    ui->param1->setValue(_params->at(0));
    ui->param2->setValue(_params->at(1));
    ui->min_radius->setValue(_params->at(2));
    ui->max_radius->setValue(_params->at(3));
    ui->area_deviation->setValue(_params->at(4));

    ui->check_circle->setChecked(_flags->at(0));
    ui->check_rectangle->setChecked(_flags->at(1));
}

void ParametersDialog::refresh_params()
{
    _params->at(0) = ui->param1->value();
    _params->at(1) = ui->param2->value();
    _params->at(2) = ui->min_radius->value();
    _params->at(3) = ui->max_radius->value();
    _params->at(4) = ui->area_deviation->value();

    _flags->at(0) = ui->check_circle->isChecked();
    _flags->at(1) = ui->check_rectangle->isChecked();
}