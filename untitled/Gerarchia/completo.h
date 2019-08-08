#ifndef COMPLETO_H
#define COMPLETO_H
#include <string>
using std::string;

class completo {
private:
    string titolo;
    unsigned int valutazione;

public:
    completo(string = "nd", unsigned int = 0);
    virtual ~completo() = default;
    virtual bool operator==(const completo&) const;

    string getTitolo() const;
    unsigned int getValutazione() const;


};

#endif // COMPLETO_H
