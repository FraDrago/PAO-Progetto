#ifndef SERIETV_H
#define SERIETV_H
#include "completo.h"

class serietv : public completo {
private:
    unsigned int episodi;

public:
    serietv(string = "nd", unsigned int = 0, unsigned int =0);
    virtual ~serietv() = default;

    unsigned int getepisodi() const;


};


#endif // SERIETV_H
