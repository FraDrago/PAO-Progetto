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

    documentario(string , unsigned int = 0, bool= false, unsigned int = 0, string= "", tipologia = Generale);
    documentario(documentario* = nullptr);
    virtual ~documentario() = default;
    virtual string getGenere() const;
    unsigned int getmin() const;
    string getconduttore() const;
    tipologia getTipo() const;
    void setdurata(unsigned int);
    void setconduttore(string);
    void setTipo(tipologia);

    static tipologia converttipologia(string);
    static string converstring(tipologia);

    string getTipoTV() const final;



private:
    unsigned int duratamin;
    string conduttore;
    tipologia tipo;

};

#endif // DOCUMENTARIO_H
