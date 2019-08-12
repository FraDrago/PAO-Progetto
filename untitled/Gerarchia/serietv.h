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

    void setEpvisti(const unsigned int);
    void setEptot(const unsigned int);
    void setdurataep(const unsigned int);
    void aumentaep();


};


#endif // SERIETV_H
