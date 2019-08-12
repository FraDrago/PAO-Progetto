    #ifndef DOCUMENTARIO_H
#define DOCUMENTARIO_H
#include "completo.h"
#include <string>
using std::string;


class documentario : public completo {

public:
    enum tipologia {
        Generale,
        Storia,
        Cultura,
        Natura,
        Tecnologia
    };

    documentario(string = "nd", unsigned int = 0, bool= false, unsigned int = 0, string= "nd", tipologia = Generale);
    virtual ~documentario() = default;
    unsigned int getmin() const;
    string getconduttore() const;
    tipologia getTipo() const;
    void setdurata(unsigned int);
    void setconduttore(string);
    void setTipo(tipologia);

private:
    unsigned int duratamin;
    string conduttore;
    tipologia tipo;

    //SE USO ENUM DOVRO' FARE LE VARIE CONVERSIONI DA ENUM A STRINGA E VICEVERSA, FARE IN CASO DI NECESSITA'
};

#endif // DOCUMENTARIO_H
