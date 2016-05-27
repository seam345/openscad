#include "parameterslider.h"

ParameterSlider::ParameterSlider(ParameterObject *parameterobject)
{
    object=parameterobject;
    set();
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(on_Changed(int)));
}
void ParameterSlider::on_Changed(int)
{
    double v = slider->value();
    object->value = ValuePtr(v);
    //to be corrected
    this->labelSliderValue->setText(QString::number(v, 'f', 0));
    emit changed();
}

void ParameterSlider::setValue()
{
    this->stackedWidget->setCurrentWidget(this->pageSlider);
    this->slider->setMaximum(object->values->toRange().end_value());
    this->slider->setValue(object->value->toDouble());
    this->slider->setMinimum(object->values->toRange().begin_value());
    this->labelSliderValue->setText(QString::number(object->value->toDouble(), 'f', 0));
}
