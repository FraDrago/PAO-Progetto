#include "aggiungielemento.h"

aggiungielemento::aggiungielemento(QWidget* parent):
    QWidget (parent),
    conduttore(new QLineEdit(this)),
    duratt(new QLineEdit(this)),
    durep(new QLineEdit(this)),
    epv(new QLineEdit(this)),
    ept(new QLineEdit(this)),
    tipo(new TipoTV(this)),
    genere(new genereTV(this)),
    generedocumentario(new genereDocum(this)),
    nome(new QLineEdit(this)),
    Valutazione(new QLineEdit(this)),
    animated(new QCheckBox("Animato?",this)),
    AddButton(new QPushButton("Aggiungi",this)),
    ResetButton(new QPushButton("Reset",this))
{
    // Creo tutti i layout che mi servono
    QVBoxLayout* maininserisci= new QVBoxLayout();
    QHBoxLayout* durata= new QHBoxLayout();
    QHBoxLayout* nometipoval= new QHBoxLayout();
    QHBoxLayout* genanim= new QHBoxLayout();
    QHBoxLayout* gen= new QHBoxLayout();
    QHBoxLayout* pulsanti= new QHBoxLayout();



    // Assemblo il Layoutprincipale
    maininserisci->addLayout(nometipoval);
    maininserisci->addLayout(genanim);
    maininserisci->addLayout(durata);
    maininserisci->addLayout(pulsanti);

    // costruisco il conduttore
    conduttore->setPlaceholderText("Nome del conduttore");

    //costruisco durata
    durata->setAlignment(Qt::AlignLeft);
    durata->addWidget(duratt);
    durata->addWidget(durep);

    //costruisco duratt e durep
    duratt->setPlaceholderText("Durata");
    durep->setPlaceholderText("Durata episodio");
    duratt->setFixedWidth(100);
    durep->setFixedWidth(100);
    duratt->setMaxLength(3);
    durep->setMaxLength(3);
    duratt->setValidator(new QIntValidator(0,999,this));
    durep->setValidator(new QIntValidator(0,999,this));


    //costruisco gli episodi
    QLabel* epi= new QLabel("  episodi: ",this);
    QLabel* slash= new QLabel("/",this);
    epv->setFixedWidth(28);
    ept->setFixedWidth(28);
    epv->setMaxLength(3);
    ept->setMaxLength(3);
    epv->setValidator(new QIntValidator(0,999,this));
    ept->setValidator(new QIntValidator(0,999,this));

    //Costruisco il nome tipo e valutazione e Valutazione
    nome->setPlaceholderText("Inserisci il nome");
    Valutazione->setMaxLength(2);
    Valutazione->setValidator(new QIntValidator(0,10,this));
    Valutazione->setPlaceholderText("Valutazione");
    Valutazione->setFixedWidth(100);



    //Assemblo il Layout nome tipo e valutazione
    nometipoval->addWidget(nome);
    nometipoval->addWidget(tipo);
    nometipoval->addWidget(Valutazione);
    nometipoval->addWidget(epi);
    nometipoval->addWidget(epv);
    nometipoval->addWidget(slash);
    nometipoval->addWidget(ept);

    //Assemblo il Layout del genere
    gen->addWidget(genere);
    gen->addWidget(generedocumentario);

    //Assemblo il Layout genere/Valutazione
    genanim->addLayout(gen);
    genanim->addWidget(animated);
    genanim->setSpacing(10);
    genanim->addWidget(conduttore);

    //Assemblo il Layout dei pulsanti
    pulsanti->addWidget(ResetButton);
    pulsanti->addWidget(AddButton);

    pulsanti->setSpacing(5);

    setLayout(maininserisci);

    Bloccato(0);

    //le varie connessioni
    connect(tipo,SIGNAL(activated(int)),this,SLOT(Bloccato(int)));
    connect(ResetButton,SIGNAL(clicked()),this,SLOT(resetta()));

}




TipoTV *aggiungielemento::getTipo() const
{
    return tipo;
}

genereTV *aggiungielemento::getGenere() const
{
    return genere;
}

genereDocum *aggiungielemento::getGendoc() const
{
    return generedocumentario;
}

QLineEdit *aggiungielemento::getNome() const
{
    return nome;
}

QLineEdit *aggiungielemento::getValutazione() const
{
    return Valutazione;
}

QCheckBox *aggiungielemento::getanimated() const
{
    return animated;
}

QPushButton *aggiungielemento::getAddButton() const
{
    return AddButton;
}

QLineEdit *aggiungielemento::getconduttore() const{
    return conduttore;
}
QLineEdit *aggiungielemento::getduratt() const{
    return duratt;
}
QLineEdit *aggiungielemento::getdurep() const{
    return durep;
}
QLineEdit *aggiungielemento::getepv() const{
    return epv;
}
QLineEdit *aggiungielemento::getept() const{
    return ept;
}



void aggiungielemento::resetta()const{


    nome->setText("");
    Valutazione->setText("0");
    tipo->setCurrentIndex(0);
    genere->setCurrentIndex(0);
    generedocumentario->setCurrentIndex(0);
    animated->setChecked(false);

    epv->setText("0");
    ept->setText("0");
    duratt->setText("0");
    durep->setText("0");
    conduttore->setText("");
    Bloccato(0);


}

void aggiungielemento::Bloccato(int n)const
{
    switch (n) {
    case 0: //operacinematografica
        animated->setEnabled(false);
        genere->setEnabled(false);
        generedocumentario->setEnabled(false);
        epv->setEnabled(false);
        ept->setEnabled(false);
        duratt->setEnabled(false);
        durep->setEnabled(false);
        conduttore->setEnabled(false);
        break;
    case 1: //serie TV
        animated->setEnabled(true);
        genere->setEnabled(true);
        generedocumentario->setEnabled(false);
        epv->setEnabled(true);
        ept->setEnabled(true);
        duratt->setEnabled(false);
        durep->setEnabled(true);
        conduttore->setEnabled(false);
        break;
    case 2: //Film
        animated->setEnabled(true);
        genere->setEnabled(true);
        generedocumentario->setEnabled(false);
        epv->setEnabled(false);
        ept->setEnabled(false);
        duratt->setEnabled(true);
        durep->setEnabled(false);
        conduttore->setEnabled(false);
        break;
    case 3: //Documentario
        animated->setEnabled(false);
        genere->setEnabled(false);
        generedocumentario->setEnabled(true);
        epv->setEnabled(false);
        ept->setEnabled(false);
        duratt->setEnabled(true);
        durep->setEnabled(false);
        conduttore->setEnabled(true);
        break;


    }
}


