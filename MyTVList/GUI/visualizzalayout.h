#ifndef VISUALIZZALAYOUT_H
#define VISUALIZZALAYOUT_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

#include <QLabel>
#include "GUI/qlistmodel.h" //in caso cancellare



class Visualizzalayout: public QWidget
{
    Q_OBJECT
private:
    QLabel* conduttore;
    QLabel* animated;
    QLabel* nome;
    QLabel* eptot;
    QLabel* genere;
    QLabel* tempoep;
    QLineEdit* val;
    QLineEdit* epvisti;
    QPushButton* plus;
    QLabel* tempotot;
    QPushButton* modifica;
    //QLineEdit *nome;
public slots:
    void buttonplus();
public:
    void updatevisual(string , QString, bool, QString ,QString, int, int,int, int,int);
    Visualizzalayout(string="", QString ="",bool =false, QString ="",QString ="", int =0, int=0,int =0, int=0,int =0, QWidget * =nullptr);
    QLineEdit *getval() const;
    QLineEdit *getepvisti() const;
    QPushButton *getplus() const;
    QPushButton *getmodifica() const;

};

#endif // VISUALIZZALAYOUT_H
