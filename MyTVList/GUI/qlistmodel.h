#ifndef QLISTMODEL_H
#define QLISTMODEL_H
#include <QAbstractListModel>
#include <QCheckBox>
#include <Gerarchia/completo.h>


class Modello;

class qlistmodel : public QAbstractListModel
{

private:
    Modello * model;
    bool seriecheck;
    bool filmcheck;
    bool documcheck;
    std::map<string,int> generi;
public:

   // qlistmodel(QObject* = nullptr);
    qlistmodel(QObject* = nullptr, bool =true, bool =true, bool =true);
    //qlistmodel(Modello*);
    ~qlistmodel() override;

    void eraseall() const;
    void caricadati() const;
    void salvadati() const;
    unsigned int minvisti() const;
    void newaddress(string);
    void removeserie(int row);
    void removefilm(int row);
    void removedocum(int row);


     completo* getcompleto(int i) const;
    bool insertRos(completo* =nullptr, int=0, int = 1, const QModelIndex& = QModelIndex());
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex&, int role = Qt::DisplayRole) const override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    void setcheck (bool= true, bool= true, bool= true) ;

};

#endif // QLISTMODEL_H

