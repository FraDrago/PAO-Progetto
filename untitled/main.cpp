#include "Gerarchia/completo.h"
#include "Gerarchia/serietv.h"
#include "Gerarchia/film.h"
#include "Gerarchia/documentario.h"
#include "Gerarchia/qontainer.h"
#include "Gerarchia/completo.cpp"
//#include <QApplication>
#include <iostream>
using namespace std;

int main(/*int argc, char *argv[]*/)
{
    //QApplication a(argc, argv);

    //string t , unsigned int v, bool a, unsigned int epv, unsigned int ept, unsigned int min

    serietv f("ciao", 7,false, 5, 10, 24); //120
    serietv z("ciao", 7,false, 1, 10, 20); //20
    serietv s("ciaa",10,false,10,10, 12); //120
    serietv t("catto",9,false,1,10, 40); //40
    //film t("miao", 10);
    cout<<f.getminep();
    unsigned int minuti;
    //completo r;
    qontainer<serietv> q;
    q.insert(f);
    q.insert(s);
    q.insert(t);
    q.insert(z);
    //q.tempotot();
    minuti=q.minutivisti();
    cout<<endl<<"ecco il tempo: "<<minuti;
   // cout<<q.first->info.getTitolo();
    qontainer<serietv> prova=q.ricerca("ciao");
    cout<<endl<<"il titolo bello e':" <<(*(prova.begin())).getTitolo();

    cout<<endl<<q.getsize()<<endl<<endl;
    //cout<<endl<<q.first->info.getTitolo()<<endl<<endl;

   //new qontainer(nodo* =nullptr, nodo* =nullptr, unsigned int =0);


    //MainWindow w;
    //w.show();

   // return a.exec();
}
