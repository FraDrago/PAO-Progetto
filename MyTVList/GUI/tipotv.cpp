#include "tipotv.h"

TipoTV::TipoTV(QWidget* parent):
    QComboBox (parent)
{
    addItem("Opera cinematografica");
    addItem("Serie TV");
    addItem("Film");
    addItem("Documentario");
}

