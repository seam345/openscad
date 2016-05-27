#include "parametertext.h"

ParameterText::ParameterText(ParameterObject *parameterobject)
{
    object=parameterobject;
    set();
    connect(lineEdit,SIGNAL(editingFinished()),this,SLOT(on_Changed()));
}

void ParameterText::on_Changed()
{
    if (object->dvt == Value::NUMBER) {
        try {
            object->value = ValuePtr(boost::lexical_cast<double>(lineEdit->text().toStdString()));
        } catch (const boost::bad_lexical_cast& e) {
            lineEdit->setText(QString::fromStdString(object->defaultValue->toString()));
        }
    } else {
        object->value = ValuePtr(lineEdit->text().toStdString());
    }
    emit changed();
}

void ParameterText::setValue()
{
    this->stackedWidget->setCurrentWidget(this->pageText);
    this->lineEdit->setText(QString::fromStdString(object->defaultValue->toString()));
}
