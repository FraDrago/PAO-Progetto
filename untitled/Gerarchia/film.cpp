#include "film.h"

film::film(string t , unsigned int v, bool a, unsigned int min): completo (t,v,a), duratamin(min) {}

unsigned int film::getmin() const{
    return duratamin;
}


void film::setdurata(unsigned int min){
    duratamin=min;
}
