#include "serietv.h"

serietv::serietv(string t , unsigned int v, bool a, unsigned int epv, unsigned int ept, unsigned int min): completo (t,v,a), episodivisti(epv), episoditot(ept), durataep(min) {}

unsigned int serietv::getminep() const{
    return durataep;
}

unsigned int serietv::getmintot() const{
    return durataep*episoditot;
}

unsigned int serietv::getminvisti() const{
    return durataep*episodivisti;
}

void serietv::setEpvisti(const unsigned int v){
    episodivisti=v;
}

void serietv::setEptot(const unsigned int t){
    episoditot=t;
}

void serietv::setdurataep(const unsigned int m){
    durataep=m;
}

void serietv::aumentaep(){
    if (episodivisti<episoditot)
        episodivisti++;
}
