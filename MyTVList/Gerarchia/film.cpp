#include "film.h"

film::film(string t , unsigned int v, bool a, unsigned int min, genere g): completo (t,v,a), duratamin(min), tipo(g) {}

film::film(film * f): completo (f->getTitolo(),f->getValutazione(),f->getanimato()), duratamin(f->duratamin), tipo(f->tipo) {}

unsigned int film::getmin() const{
    return duratamin;
}



void film::setdurata(unsigned int min){
    duratamin=min;
}

string film::getTipoTV() const{return "film";}


string film::getGenere() const {
    return converstring(tipo);
}

string film::converstring(genere n){
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

film::genere film::convertgenere(string n){
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

