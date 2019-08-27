#ifndef COMPLETO_H
#define COMPLETO_H
#include <string>
using std::string;


class completo {

public:
    enum genere {
        Generale,
        Azione,
        Romantico,
        Horror,
        Avventura
    };
    completo(string , unsigned int = 0, bool= false);
    virtual ~completo() = default;

    virtual unsigned int getmin() const=0;


    virtual string getGenere() const=0;
    virtual string getTipoTV() const=0;
    string getTitolo() const;
    bool getanimato() const;
    unsigned int getValutazione() const;

    void setTitolo(const string);
    void setValutazione(const unsigned int);
    void setAnimato(const bool);

    virtual bool operator==(const completo&) const;
    virtual bool operator!=(const completo&) const;

private:
    string titolo;
    unsigned int valutazione;
    bool animato;

};
std::ostream& operator<<(std::ostream& , const completo& );
#endif // COMPLETO_H
