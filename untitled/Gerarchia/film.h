#ifndef FILM_H
#define FILM_H
#include "completo.h"

class film : public completo {

public:
    film(string = "nd", unsigned int = 0);
    virtual ~film() = default;

};


#endif // FILM_H
