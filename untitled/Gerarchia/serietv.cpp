#include "serietv.h"

serietv::serietv(string t , unsigned int v, bool a, unsigned int epv, unsigned int ept, unsigned int min): completo (t,v,a), episodivisti(epv), episoditot(ept), durataep(min) {}

unsigned int serietv::getminep() const{
    return durataep;
}

unsigned int serietv::getmintot() const{
    return durataep*episoditot;
}

unsigned int serietv::getmin() const{
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
<<<<<<< d5c55625f8df057bf058a41a04744bc39667aa3b:untitled/Gerarchia/serietv.cpp
=======

string serietv::getTipoTV() const{return "serietv";}


string serietv::getGenere() const {
    return converstring(tipo);
}


string serietv::converstring(genere n){
    if(n==Generale){
        return "Generale";
    }else if(n==Azione){
        return "Azione";
    }else if(n==Romantico){
        return "Romantico";
    }else if(n==Horror){
        return "Horror";
    }else if(n==Avventura){
        return "Avventura";
    }

    throw std::exception();
}

serietv::genere serietv::convertgenere(string n){
    if(n=="Generale"){
        return Generale;
    }else if(n=="Azione"){
        return Azione;
    }else if(n=="Romantico"){
        return Romantico;
    }else if(n=="Horror"){
        return Horror;
    }else if(n=="Avventura"){
        return Avventura;
    }

    throw std::exception();
}

bool serietv::operator==(const serietv & c) const{
    return completo::operator==(c);
}
>>>>>>> FINALE:MyTVList/Gerarchia/serietv.cpp
