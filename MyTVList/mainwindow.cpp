#include "mainwindow.h"

#include <QMainWindow>




MainWindow::MainWindow( QWidget *p) :
    QMainWindow(p), genere(new TipoTV(this)),
    min(new QLabel()), visual(new Visualizzalayout()),

    addel(new aggiungielemento()),

    proxy(new proxymodel(this)),
    qmodel(new qlistmodel(this)),qparent(new QWidget()),
    list(new QListView()), cerca(new QLineEdit()), buttonModifica(new QPushButton("Anteprima/Modifica")),
    buttonRimuovi(new QPushButton("Rimuovi"))

{
    resize(400,600);
    // Creo il menu
    QMenuBar *menuBar = new QMenuBar();
    QMenu *menu = new QMenu("File", menuBar);
    QAction *salva = new QAction("Salva", menu);
    QAction *carica = new QAction("Carica", menu);
    QAction *exit = new QAction("Exit", menu);
    // Assemblo il menu
    menuBar->addMenu(menu);
    menu->addAction(salva);
    menu->addAction(carica);
    menu->addAction(exit);
    setMenuBar(menuBar);
    QString m=QString::number(qmodel->minvisti());
    min->setText("minuti visti: " + m);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *selezioneLayout = new QHBoxLayout();
    QVBoxLayout *listaelim = new QVBoxLayout();
    QVBoxLayout *listaLayout = new QVBoxLayout();
    QHBoxLayout *pulsantiLayout = new QHBoxLayout();
    QVBoxLayout *insLayout = new QVBoxLayout();
    QHBoxLayout *pulsantielimina = new QHBoxLayout();




    // Creo i pulsanti
    QPushButton *buttonAggiungi = new QPushButton("Aggiungi");
    QPushButton *elimserie = new QPushButton("Elimina tutte le serie");
    QPushButton *elimfilm = new QPushButton("Elimina tutti i film");
    QPushButton *elimdocum = new QPushButton("Elimina tutti i documentari");


    // Creo pulsantielimina
    pulsantielimina->addWidget(elimserie);
    pulsantielimina->addWidget(elimfilm);
    pulsantielimina->addWidget(elimdocum);
    pulsantielimina->setMargin(20);


    //modifico pulsanti elimina
    elimserie->setFixedWidth(150);
    elimfilm->setFixedWidth(150);
    elimdocum->setFixedWidth(150);

    //creo la barra di ricerca
    cerca->setPlaceholderText("Cerca su MyTVList");


    //listaelim
    listaelim->addLayout(listaLayout);
    listaelim->addLayout(pulsantielimina);

    // Assemblo il mainLayout
    mainLayout->addLayout(selezioneLayout);
    mainLayout->addLayout(listaelim);
    mainLayout->addLayout(pulsantiLayout);
    mainLayout->addWidget(min);


    // Assemblo il selezioneLayout
    selezioneLayout->addWidget(cerca);
    selezioneLayout->addWidget(genere);



    // Assemblo il listaLayout
    listaLayout->addWidget(list);


    // Assemblo il layout dell'inserimento
    insLayout->setSpacing(0);
    insLayout->addWidget(buttonRimuovi);
    insLayout->addWidget(buttonModifica);

    // Assemblo il layout dei pulsanti
    pulsantiLayout->addLayout(insLayout);
    pulsantiLayout->addWidget(buttonAggiungi);

    if (qmodel->rowCount()==0)
        buttonModifica->setEnabled(false);

    proxy->setSourceModel(qmodel);
    list->setModel(proxy);


    qparent->setLayout(mainLayout);




    // Set QWidget as the central layout of the main window
    setCentralWidget(qparent);

    connect(elimserie, SIGNAL(clicked()), this, SLOT(eliminaserie()));
    connect(elimfilm, SIGNAL(clicked()), this, SLOT(eliminafilm()));
    connect(elimdocum, SIGNAL(clicked()), this, SLOT(eliminadocum()));

    connect(visual->getmodifica(), SIGNAL(clicked()), this, SLOT(modificabutton()));
    connect(visual->getplus(), SIGNAL(clicked()), this, SLOT(plusone()));
    connect(genere, SIGNAL(activated(int)), this, SLOT(cecca(int)));
    connect(buttonModifica, SIGNAL(clicked()), this, SLOT(modifica()));
    connect(buttonAggiungi, SIGNAL(clicked()), this, SLOT(aggiungilayout()));
    connect(buttonRimuovi, SIGNAL(clicked()), this, SLOT(elimina()));
    connect(cerca, SIGNAL(textChanged(QString)), this, SLOT(textFilterChanged()));
    connect(salva, SIGNAL(triggered()), this, SLOT(saveData()));
    connect(carica, SIGNAL(triggered()), this, SLOT(loadData()));
    connect(addel->getAddButton(), SIGNAL(clicked()), this, SLOT(addlist()));
}


void MainWindow::eliminaserie(){
    int lung= list->selectionModel()->currentIndex().row();
    qmodel->removeserie(lung);
    proxy->setSourceModel(qmodel);
    list->setModel(proxy);
}

void MainWindow::eliminafilm(){
    int lung= list->selectionModel()->currentIndex().row();
    qmodel->removefilm(lung);
    proxy->setSourceModel(qmodel);
    list->setModel(proxy);
}

void MainWindow::eliminadocum(){
    int lung= list->selectionModel()->currentIndex().row();
    qmodel->removedocum(lung);
    proxy->setSourceModel(qmodel);
    list->setModel(proxy);
}


void MainWindow::modificabutton(){

    int diffval=visual->getval()->text().toInt();
    int diffep=visual->getepvisti()->text().toInt();
    qmodel->getcompleto(current)->setValutazione(diffval);



    if (diffep!=0)
        dynamic_cast<serietv*>(qmodel->getcompleto(current))->setEpvisti(diffep);
    QString m=QString::number(qmodel->minvisti());
    visual->hide();
    min->setText("minuti visti: " + m);
}



void MainWindow::plusone(){

    if (dynamic_cast<serietv*>(qmodel->getcompleto(current)))
        dynamic_cast<serietv*>(qmodel->getcompleto(current))->aumentaep();
    QString m=QString::number(qmodel->minvisti());
    min->setText("minuti visti: " + m);

}



void MainWindow::cecca(int n){
    switch (n) {
    case 0: //operacinematografica
        buttonRimuovi->setEnabled(true);
        buttonModifica->setEnabled(true);
        qmodel->setcheck(true,true,true);
        break;
    case 1: //serie TV
        buttonRimuovi->setEnabled(false);
        buttonModifica->setEnabled(false);
        qmodel->setcheck(true,false,false);
        break;
    case 2: //Film
        buttonRimuovi->setEnabled(false);
        buttonModifica->setEnabled(false);
        qmodel->setcheck(false,true,false);
        break;
    case 3: //Documentario
        buttonRimuovi->setEnabled(false);
        buttonModifica->setEnabled(false);
        qmodel->setcheck(false,false,true);
        break;


    }

    proxy->setSourceModel(qmodel);
    list->setModel(proxy);

}


void MainWindow::elimina()const{

    list->model()->removeRows(list->selectionModel()->currentIndex().row(),1);
    QString m=QString::number(qmodel->minvisti());
    min->setText("minuti visti: " + m);
}


void MainWindow::modifica() {
    QModelIndex changemodel= list->selectionModel()->currentIndex();
    current=proxy->toggleType(changemodel);


    //prendo i vari elementi
    QString titolo =QString::fromStdString( qmodel->getcompleto(current)->getTitolo());
    QString gen =QString::fromStdString( qmodel->getcompleto(current)->getGenere());
    int va=static_cast<int>(qmodel->getcompleto(current)->getValutazione());
    int tt=static_cast<int>(qmodel->getcompleto(current)->getmin());
    int ept=0;
    int epv=0;
    int minep=0;
    string tipo=qmodel->getcompleto(current)->getTipoTV();
    QString condu;
    if (dynamic_cast<serietv*>(qmodel->getcompleto(current)))
        ept=static_cast<int>(dynamic_cast<serietv*>(qmodel->getcompleto(current))->getepisoditot());
    if (dynamic_cast<serietv*>(qmodel->getcompleto(current)))
        epv=static_cast<int>(dynamic_cast<serietv*>(qmodel->getcompleto(current))->getepisodivisti());
    if (dynamic_cast<serietv*>(qmodel->getcompleto(current)))
        minep=static_cast<int>(dynamic_cast<serietv*>(qmodel->getcompleto(current))->getminep());
    bool ani=qmodel->getcompleto(current)->getanimato();
    if (dynamic_cast<documentario*>(qmodel->getcompleto(current)))
        condu =QString::fromStdString(dynamic_cast<documentario*>(qmodel->getcompleto(current))->getconduttore());

    //inserisco tutto nel metodo updatevisual
    visual->updatevisual(tipo,condu,ani, titolo,gen,va,tt, ept, epv, minep);
    visual->show();

}



void MainWindow::textFilterChanged() {
    QRegExp regex(cerca->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxy->setFilterRegExp(regex);
}

void MainWindow::saveData() const{
    qmodel->salvadati();
}

void MainWindow::loadData() const{
    QString file= QFileDialog::getOpenFileName(list, tr("Choose file"),"../fine", "File XML(*.xml)");
    if (file!="")
    {
        qmodel->eraseall();
        qmodel->newaddress(file.toStdString());
        qmodel->caricadati();
        proxy->setSourceModel(qmodel);
        list->setModel(proxy);
        buttonModifica->setEnabled(true);
        QString m=QString::number(qmodel->minvisti());
        min->setText("minuti visti: " + m);
    }


}

void MainWindow::aggiungilayout(){
    addel->show();
}





void MainWindow::addlist() {

    int indiceTipo=addel->getTipo()->currentIndex();

    string nome=addel->getNome()->text().toStdString();
    unsigned int val=addel->getValutazione()->text().toUInt();  //static_cast<int>
    bool animato= addel->getanimated()->isChecked();

    unsigned int epv=0;
    unsigned int ept=0;
    unsigned int durata=0;
    string conduttore="";

    completo* addare = nullptr;

    switch (indiceTipo) {
    case 1:
        epv=addel->getepv()->text().toUInt();
        ept=addel->getept()->text().toUInt();
        durata=addel->getdurep()->text().toUInt();
        addare= new serietv(nome, val, animato,epv,ept,durata,serietv::convertgenere(addel->getGenere()->currentText().toStdString()));
        break;
    case 2:
        durata=addel->getduratt()->text().toUInt();
        addare= new film(nome, val, animato,durata,film::convertgenere(addel->getGenere()->currentText().toStdString()));
        break;
    case 3:
        durata=addel->getduratt()->text().toUInt();
        conduttore=addel->getconduttore()->text().toStdString();
        addare= new documentario(nome, val, animato,durata,conduttore,documentario::converttipologia(addel->getGendoc()->currentText().toStdString()));
        break;

    }

    if(addare!= nullptr && !(addare->getTitolo()=="")){
        if (epv<=ept){
        qmodel->insertRos(addare, proxy->rowCount(), 1);
        proxy->setSourceModel(qmodel);
        list->setModel(proxy);
        QMessageBox::information(this,"Conferma", "Contenuto aggiunto");
        addel->hide();
        } else {
            QMessageBox::information(addel,"Conferma", "Numero di episodi visti maggiore dei totali");
        }
    }else {
        QMessageBox::information(addel,"Conferma", "Compila i campi");

    }


    // seleziona ultimo elemento

    list->selectionModel()->clearCurrentIndex();
    list->selectionModel()->select(proxy->index(qmodel->rowCount() - 1, 0), QItemSelectionModel::Select);
}




MainWindow::~MainWindow() {}
