#include "generedocum.h"

genereDocum::genereDocum(QWidget* parent):
    QComboBox (parent)
{
    addItem("Generale");
    addItem("Storia");
    addItem("Cultura");
    addItem("Natura");
    addItem("Tecnologia");
}

