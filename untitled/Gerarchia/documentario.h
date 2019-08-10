#ifndef DOCUMENTARIO_H
#define DOCUMENTARIO_H
#include "completo.h"
#include <string>
using std::string;


class documentario : public completo {

public:
    enum tipologia {
        Storia,
        Cultura,
        Natura,
        Tecnologia
    };

    documentario(string = "nd", unsigned int = 0, bool= false, unsigned int = 0);
    virtual ~documentario() = default;
    unsigned int getmin() const;
    void setdurata(unsigned int);

private:
    unsigned int duratamin;
    string conduttore;
    tipologia tipo;

};

#endif // DOCUMENTARIO_H
