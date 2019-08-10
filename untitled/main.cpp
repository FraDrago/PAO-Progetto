#include "Gerarchia/completo.h"
#include "Gerarchia/qontainer.h"
#include "Gerarchia/completo.cpp"
//#include <QApplication>
#include <iostream>
using namespace std;

int main(/*int argc, char *argv[]*/)
{
    //QApplication a(argc, argv);

    completo f("ciao", 7);
    completo t("miao", 10);

    qontainer<completo> q;
    q.insert(f);
    q.insert(t);


    cout<<endl<<q.getsize()<<endl<<endl;
    //cout<<endl<<q.first->info.getTitolo()<<endl<<endl;

   //new qontainer(nodo* =nullptr, nodo* =nullptr, unsigned int =0);


    //MainWindow w;
    //w.show();

   // return a.exec();
}
