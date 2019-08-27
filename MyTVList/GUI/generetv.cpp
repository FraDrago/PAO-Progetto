#include "generetv.h"

genereTV::genereTV(QWidget* parent):
    QComboBox (parent)
{
    addItem("Generale");
    addItem("Azione");
    addItem("Romantico");
    addItem("Horror");
    addItem("Avventura");
}
