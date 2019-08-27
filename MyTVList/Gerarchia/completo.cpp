#include "completo.h"


completo::completo(string t , unsigned int v, bool a) : titolo(t) , valutazione(v), animato(a) {}

bool completo::operator==(const completo& comp) const{
    return (titolo == comp.titolo);
}

bool completo::operator!=(const completo& comp) const{
    return (titolo != comp.titolo);
}



string completo::getTitolo() const {
    return titolo;
}
unsigned int completo::getValutazione() const {
    return valutazione;
}

bool completo::getanimato() const {
    return animato;
}


void completo::setTitolo(const string t) { //mi conviene passarlo per riferimento? GUARDARE DOPO
    titolo=t;
}

void completo::setValutazione(const unsigned int b) {
    valutazione=b;
}
void completo::setAnimato(const bool a){
    animato=a;
}



