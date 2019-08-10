#ifndef FILM_H
#define FILM_H
#include "completo.h"

class film : public completo {
private:
    unsigned int duratamin;

public:
    film(string = "nd", unsigned int = 0, bool= false, unsigned int = 0);
    virtual ~film() = default;
    unsigned int getmin() const;
    void setdurata(unsigned int);

};


#endif // FILM_H
