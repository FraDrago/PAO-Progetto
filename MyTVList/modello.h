#ifndef MODELLO_H
#define MODELLO_H
#include "Gerarchia/qontainer.h"
#include "Gerarchia/completo.h"
#include "Gerarchia/documentario.h"
#include "Gerarchia/serietv.h"
#include "Gerarchia/film.h"

class Modello
{
private:
    qontainer<completo*> list;
    string path;

public:
    Modello();
    Modello(qontainer<completo*>);
    ~Modello();


    //void printALL() const;

    unsigned int minutivisti() const;
    qontainer<completo*> ricercavalutazione(unsigned int) ;
    //qontainer<completo*> ricercagenere(string) ;
    qontainer<serietv*> allserie() const;
    qontainer<film*> allfilm() const;
    qontainer<documentario*> alldocum() const;


    void add(completo*);
    void cancella( completo*);
    void cancella( int);
    void eraseall();

    const completo* getcompleto(int) ;
    int getsize() const;

    unsigned int size() const;
    void load();
    void save() const;

    void editcompleto(int, const string&);


    void setNewPath(string);

};

#endif // MODELLO_H
