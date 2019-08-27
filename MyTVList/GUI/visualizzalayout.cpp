#include "visualizzalayout.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>



Visualizzalayout::Visualizzalayout(string t, QString condu, bool anim, QString titolo, QString gentext, int valu, int minvisti, int ept, int epv, int minep, QWidget* parent):
    QWidget (parent), conduttore(new QLabel("Conduttore:  " + condu)), animated(new QLabel(this)),
    nome(new QLabel(this)), eptot(new QLabel(QString::number(ept),this)), genere(new QLabel(this)),
    tempoep(new QLabel(this)), val(new QLineEdit(this)), epvisti(new QLineEdit(this)),
    plus(new QPushButton(this)), tempotot(new QLabel(this)), modifica(new QPushButton("Modifica"))
{
    //creo i layout
    QVBoxLayout* mainlayout= new QVBoxLayout();
    QHBoxLayout* nomevalep=new QHBoxLayout();
    QHBoxLayout* valore=new QHBoxLayout();
    QHBoxLayout* episodi=new QHBoxLayout();
    QHBoxLayout* gencondani=new QHBoxLayout();
    QHBoxLayout* cond=new QHBoxLayout();
    QHBoxLayout* temp=new QHBoxLayout();

    nomevalep->setAlignment(Qt::AlignLeft);
    gencondani->setAlignment(Qt::AlignLeft);


    //conduttore e animato
    //conduttore->setText("Conduttore:  " + condu);
    cond->addWidget(conduttore);
    conduttore->setStyleSheet("font-weight: bold;");
    animated->setStyleSheet("font-weight: bold;");
    if (anim)
        animated->setText("La serie è animata");
    else
        animated->setText("La serie non è animata");



    //GENERE TEMPO TOT E TEMPO EP
    genere->setText("Genere:  " + gentext);
    genere->setStyleSheet("font-weight: bold;");
    genere->setMargin(10);

    tempotot->setText("minuti:  " + QString::number(minvisti));
    tempotot->setStyleSheet("font-weight: bold;");
    tempotot->setMargin(10);


    tempoep->setText("Minuti episodio:  " + QString::number(minep));
    tempoep->setStyleSheet("font-weight: bold;");
    tempoep->setMargin(10);

    temp->addWidget(tempotot);
    temp->addWidget(tempoep);
    temp->setAlignment(Qt::AlignLeft);



    gencondani->addWidget(genere);
    gencondani->addLayout(cond);
    gencondani->addWidget(animated);

    //EPISODI

    plus->setText("+");
    plus->setStyleSheet("font-weight: bold;");
    plus->setFixedWidth(25);

    //eptot->setText(QString::number(ept));
    eptot->setStyleSheet("font-weight: bold;");
    //eptot->resize(10,10);




    QLabel* e=new QLabel("Episodi:  ");
    e->setStyleSheet("font-weight: bold;");
    e->setHidden(t!="serietv");
    epvisti->setText(QString::number(epv));
    epvisti->setFixedWidth(28);
    //eptot->setFixedWidth(28);
    epvisti->setMaxLength(3);
    epvisti->setValidator(new QIntValidator(0,999,this));

    episodi->setMargin(10);
    episodi->addWidget(e);
    episodi->addWidget(epvisti);
    episodi->addWidget(eptot);
    episodi->addWidget(plus);
    episodi->setAlignment(Qt::AlignLeft);



    //VALORE
    QLabel* dival=new QLabel(this);
    dival->setText("/10");
    dival->setStyleSheet("font-weight: bold;");


    QLabel* v=new QLabel("Valutazione:  ");
    v->setStyleSheet("font-weight: bold;");
    val->setText(QString::number(valu));
    val->setMaxLength(2);
    val->setFixedWidth(20);
    val->setValidator(new QIntValidator(0,10,this));

    valore->setMargin(3);
    valore->signalsBlocked();
    valore->addWidget(v);
    valore->addWidget(val);
    valore->addWidget(dival);

    nome->setText("Titolo:  " + titolo);
    nome->setStyleSheet("font-weight: bold;");
    nome->setMargin(10);



    //Assemblo il nomevalep
    nomevalep->addWidget(nome);
    nomevalep->addLayout(valore);
    nomevalep->addLayout(episodi);

    //Assemblo il mainlayout
    mainlayout->addLayout(nomevalep);
    mainlayout->addLayout(gencondani);
    mainlayout->addLayout(temp);
    mainlayout->addWidget(modifica);

    setLayout(mainlayout);
    connect(plus, SIGNAL(clicked()), this, SLOT(buttonplus()));
    //setMinimumSize(200,200);
}

void Visualizzalayout::buttonplus(){
    int a=epvisti->text().toInt();
    int b=eptot->text().toInt();
    if(a<b)
        a=a+1;
    epvisti->setText(QString::number(a));
}

void Visualizzalayout::updatevisual(string t, QString condu, bool anim, QString titolo, QString gentext, int valu, int minvisti, int ept, int epv, int minep){

    nome->setText("Titolo:  " + titolo);
    eptot->setText(QString::number(ept));
    genere->setText("Genere:  " + gentext);
    tempoep->setText("Minuti episodio:  " + QString::number(minep));
    val->setText(QString::number(valu));
    epvisti->setText(QString::number(epv));
    tempotot->setText("minuti:  " + QString::number(minvisti));
    if (anim)
        animated->setText("E' animata");
    else
        animated->setText("Non è animata");


    if (t=="serietv"){
        conduttore->hide();
        epvisti->show();
        eptot->show();
        plus->show();
        tempoep->show();
        animated->show();

    }
    if (t=="film"){
        animated->show();
        conduttore->hide();
        epvisti->hide();
        eptot->hide();
        plus->hide();
        tempoep->hide();

    }
    if (t=="documentario"){
        conduttore->show();
        conduttore->setText("Conduttore:  " + condu);
        animated->hide();
        epvisti->hide();
        eptot->hide();
        plus->hide();
        tempoep->hide();

    }



}




QLineEdit* Visualizzalayout::getval() const{
    return val;
}
QLineEdit* Visualizzalayout::getepvisti() const{
    return epvisti;
}
QPushButton* Visualizzalayout::getplus() const{
    return plus;
}


QPushButton* Visualizzalayout::getmodifica() const{
    return modifica;
}


