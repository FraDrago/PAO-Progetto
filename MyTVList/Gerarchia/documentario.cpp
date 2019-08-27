#include "documentario.h"

documentario::documentario(string t , unsigned int v, bool a, unsigned int m, string c, tipologia z): completo (t,v,a), duratamin(m), conduttore(c), tipo(z) {}

documentario::documentario(documentario * f): completo (f->getTitolo(),f->getValutazione(),f->getanimato()), duratamin(f->duratamin), conduttore(f->conduttore), tipo(f->tipo) {}

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

string documentario::getGenere() const {

    return converstring(tipo);
}



string documentario::getTipoTV() const{return "documentario";}


documentario::tipologia documentario::converttipologia(string t)
{
    if(t=="Generale"){
        return documentario::tipologia::Generale;
    }else if(t=="Storia"){
        return documentario::tipologia::Storia;
    }else if(t=="Cultura"){
        return documentario::tipologia::Cultura;
    }else if(t=="Natura"){
        return documentario::tipologia::Natura;
    }else if(t=="Tecnologia"){
        return documentario::tipologia::Tecnologia;
    }

    throw std::exception();
}

string documentario::converstring(tipologia n){

    if(n==Generale){
        return "Generale";
    }else if(n==Storia){
        return "Storia";
    }else if(n==Cultura){
        return "Cultura";
    }else if(n==Natura){
        return "Natura";
    }else if(n==Tecnologia){
        return "Tecnologia";
    }

  throw std::exception();
}
