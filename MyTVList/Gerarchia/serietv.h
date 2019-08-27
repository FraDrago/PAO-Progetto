#ifndef SERIETV_H
#define SERIETV_H
#include "completo.h"

class serietv : public completo {
private:
    unsigned int episodivisti;
    unsigned int episoditot;
    unsigned int durataep;
    genere tipo;

public:
    serietv(string, unsigned int = 0, bool= false , unsigned int = 0, unsigned int =0, unsigned int= 0, genere=Generale);
    serietv(serietv* = nullptr);
    virtual ~serietv() = default;

    virtual string getGenere() const;
    unsigned int getepisodivisti() const;
    unsigned int getepisoditot() const;
    unsigned int getminep() const;
    unsigned int getmintot() const;
    unsigned int getmin() const;
    string getTipoTV() const final;
    bool operator==(const serietv&) const;

    void setEpvisti(const unsigned int);
    void setEptot(const unsigned int);
    void setdurataep(const unsigned int);
    void aumentaep();
    static string converstring(genere);
    static genere convertgenere(string);


};


#endif // SERIETV_H
