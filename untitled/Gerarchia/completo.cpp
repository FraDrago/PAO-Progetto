#include "completo.h"

completo::completo(string t , unsigned int v) : titolo(t) , valutazione(v) {}

bool completo::operator==(const completo& comp) const{
    return (titolo == comp.titolo);
}

string completo::getTitolo() const {
    return titolo;
}
unsigned int completo::getValutazione() const {
    return valutazione;
}
