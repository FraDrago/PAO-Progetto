#include "qlistmodel.h"
#include "modello.h"
//#include "visualizzalayout.h"
#include <Gerarchia/serietv.h>
#include <Gerarchia/film.h>
#include <Gerarchia/documentario.h>

#include <QFont>

//qlistmodel::qlistmodel(QObject* parent) : QAbstractListModel(parent), model(new Modello()) {}

qlistmodel::qlistmodel(QObject* parent, bool s, bool f, bool d) :
    QAbstractListModel(parent),
    model(new Modello()), seriecheck(s), filmcheck(f), documcheck(d) {
    generi={{"serietv",0},{"film",1},{"documentario",2}};

}

qlistmodel::~qlistmodel() {
    delete model;
}


void qlistmodel::newaddress(string a){
    model->setNewPath(a);
}


/*
 * Ritorna la dimensione (numero di righe) del modello
 */
int qlistmodel::rowCount(const QModelIndex&) const {
    int righe= 0;
    if (seriecheck && filmcheck && documcheck)
    {
        righe= static_cast<int>(model->size());
    }
    else if(seriecheck && !filmcheck && !documcheck)
    {
        righe= static_cast<int>(model->allserie().getsize());
    }
    else if(!seriecheck && filmcheck && !documcheck)
    {
        righe= static_cast<int>(model->allfilm().getsize());
    }
    else if(!seriecheck && !filmcheck && documcheck)
    {
        righe= static_cast<int>(model->alldocum().getsize());
    }


    return righe;
}


void qlistmodel::eraseall() const{
    model->eraseall();
}

void qlistmodel::removeserie(int a){

    int righe= static_cast<int>(model->allserie().getsize());
    int i=0;
    while (a && i<righe && a) {
        if (model->allserie().esiste())
        model->allserie().remove(0);
        i++;
    }

}

void qlistmodel::removefilm(int a){

    int righe= static_cast<int>(model->allfilm().getsize());
    int i=0;
    while (a && i<righe && a) {
        if (model->allfilm().esiste())
        model->allfilm().remove(0);
        i++;
    }

}

void qlistmodel::removedocum(int a){
    int righe= static_cast<int>(model->alldocum().getsize());
    int i=0;
    while (a && i<righe && a) {
        if (model->alldocum().esiste())
        model->alldocum().remove(0);
        i++;
    }

}


bool qlistmodel::removeRows(int numero, int quanti, const QModelIndex &parent){

    if(quanti){
        beginRemoveRows(parent,numero,numero+quanti-1);
        model->cancella(numero);
        endRemoveRows();
    }
    return true;
}


QVariant qlistmodel::data(const QModelIndex& index, int role) const {
    QVariant variant;
    if (!index.isValid() || index.row() >= static_cast<int>(model->size()))
        return QVariant();


    switch (role){
    case Qt::DisplayRole:
        if (seriecheck && filmcheck && documcheck)
        {
            variant=QString::fromStdString(model->getcompleto(index.row())->getTitolo());
        }
        else if(seriecheck && !filmcheck && !documcheck)
        {
            variant=QString::fromStdString(model->allserie().at(static_cast<unsigned int>(index.row()))->getTitolo());
        }
        else if(!seriecheck && filmcheck && !documcheck)
        {
            variant=QString::fromStdString(model->allfilm().at(static_cast<unsigned int>(index.row()))->getTitolo());
        }
        else if(!seriecheck && !filmcheck && documcheck)
        {
            variant=QString::fromStdString(model->alldocum().at(static_cast<unsigned int>(index.row()))->getTitolo());
        }
        break;


        case Qt::DecorationRole:
        variant=QIcon("../MyTVList/icon/film.svg");
        if (seriecheck && filmcheck && documcheck)
        {
            switch(generi.at(model->getcompleto(index.row())->getTipoTV())){
            case 0:
                variant=QIcon("../MyTVList/icon/serietv.svg");
            break;
            case 1:
                variant=QIcon("../MyTVList/icon/film.svg");
            break;
            case 2:
                variant=QIcon("../MyTVList/icon/documentario.svg");
            break;
            }
        }
        else if(seriecheck && !filmcheck && !documcheck)
        {
            variant=QIcon("../MyTVList/icon/serietv.svg");
        }
        else if(!seriecheck && filmcheck && !documcheck)
        {
            variant=QIcon("../MyTVList/icon/film.svg");
        }
        else if(!seriecheck && !filmcheck && documcheck)
        {
            variant=QIcon("../MyTVList/icon/documentario.svg");
        }
        break;


        case Qt::FontRole:
            QFont font("Arial", 14/*, QFont::Bold*/);
        return font;

        }

        return variant;

      //return QVariant();
}

void qlistmodel::setcheck(bool a, bool b, bool c) {
    seriecheck=a;
    filmcheck=b;
    documcheck=c;
}

void qlistmodel::caricadati() const{  model->load(); }

void qlistmodel::salvadati() const{  model->save(); }

bool qlistmodel::insertRos(completo* c, int begin, int count, const QModelIndex& parent) {
    beginInsertRows(parent, begin, begin + count - 1);
    model->add(c); // effettuare l'aggiunta sul modello dei dati

    endInsertRows();

    return true;
}


unsigned int qlistmodel::minvisti() const{
    return model->minutivisti();
}






 completo* qlistmodel::getcompleto(int i) const{
    return const_cast<completo* >(model->getcompleto(i));
}





