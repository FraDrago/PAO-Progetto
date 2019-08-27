#ifndef FILM_H
#define FILM_H
#include "completo.h"

class film : public completo {
private:
    unsigned int duratamin;
    genere tipo;

public:
    film(string , unsigned int = 0, bool= false, unsigned int = 0, genere=Generale);
    film(film* = nullptr);
    virtual ~film() = default;
    virtual string getGenere() const;
    unsigned int getmin() const;
    void setdurata(unsigned int);
    string getTipoTV() const final;
    static string converstring(genere);
    static genere convertgenere(string);



};


#endif // FILM_H
