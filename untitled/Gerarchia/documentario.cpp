#include "documentario.h"

documentario::documentario(string t , unsigned int v, bool a, unsigned int m, string c, tipologia z): completo (t,v,a), duratamin(m), conduttore(c), tipo(z) {}

unsigned int documentario::getmin() const{
    return duratamin;
}
string documentario::getconduttore() const{
    return conduttore;
}
documentario::tipologia documentario::getTipo() const{
    return tipo;
}
void documentario::setdurata(unsigned int m){
    duratamin=m;
}

void documentario::setconduttore(string c){
    conduttore=c;
}
void documentario::setTipo(tipologia t){
    tipo=t;
}
