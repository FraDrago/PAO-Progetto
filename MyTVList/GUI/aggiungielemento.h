#ifndef AGGIUNGIELEMENTO_H
#define AGGIUNGIELEMENTO_H
#include <QMainWindow>

#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>


#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>

#include "tipotv.h"
#include "generetv.h"
#include "generedocum.h"

class aggiungielemento: public QWidget {
    Q_OBJECT
  private:
    QLineEdit *conduttore;
    QLineEdit *duratt;
    QLineEdit *durep;
    QLineEdit *epv;
    QLineEdit *ept;
    TipoTV *tipo;
    genereTV *genere;
    genereDocum *generedocumentario;
    QLineEdit *nome;
    QLineEdit *Valutazione;
    QCheckBox *animated;
    QPushButton *AddButton;
    QPushButton *ResetButton;

  public:


    aggiungielemento(QWidget * =nullptr);


    QLineEdit *getconduttore() const;
    QLineEdit *getduratt() const;
    QLineEdit *getdurep() const;
    QLineEdit *getepv() const;
    QLineEdit *getept() const;

    TipoTV *getTipo()const;
    genereTV *getGenere()const;
    genereDocum *getGendoc()const;
    QLineEdit *getNome() const;
    QLineEdit *getValutazione() const;
    QCheckBox *getanimated() const;

    QPushButton *getAddButton() const;


public slots:
      void resetta() const;
      void Bloccato(int)const;


};

#endif // AGGIUNGIELEMENTO_H
