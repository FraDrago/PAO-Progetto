#ifndef SERIETV_H
#define SERIETV_H
#include "completo.h"

class serietv : public completo {
private:
    unsigned int episodivisti;
    unsigned int episoditot;
    unsigned int durataep;

public:
    serietv(string = "nd", unsigned int = 0, bool= false , unsigned int = 0, unsigned int =0, unsigned int= 0);
    virtual ~serietv() = default;

    unsigned int getepisodivisti() const;
    unsigned int getepisoditot() const;
    unsigned int getminep() const;
    unsigned int getmintot() const;
    unsigned int getmin() const;
<<<<<<< d5c55625f8df057bf058a41a04744bc39667aa3b:untitled/Gerarchia/serietv.h
=======
    string getTipoTV() const final;
   // virtual string getTitolo() const;
    bool operator==(const serietv&) const;
>>>>>>> FINALE:MyTVList/Gerarchia/serietv.h

    void setEpvisti(const unsigned int);
    void setEptot(const unsigned int);
    void setdurataep(const unsigned int);
    void aumentaep();


};


#endif // SERIETV_H
