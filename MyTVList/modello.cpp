#include "modello.h"
#include <QSaveFile>

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>

Modello::Modello() {

}

Modello::~Modello() {}

Modello::Modello(qontainer<completo*> c) : list(c){}

//Modello::Modello(string p): list(), path(p) {}

void Modello::add(completo* t) {
    list.insert(t);
}

void Modello::eraseall(){
    list.eraseall();
}



const completo* Modello::getcompleto(int index)  {
    return list.at(static_cast<unsigned int>(index));
}

int Modello::getsize() const{

   return static_cast<int>(list.getsize());
}

void Modello::cancella( completo* t) {
    list.remove(t);
}

void Modello::cancella( int t) {
    list.remove(t);
}

unsigned int Modello::size() const{
    return list.getsize();
}

void Modello::editcompleto(int index, const string& text) {
    list[index]->setTitolo(text);
}



unsigned int Modello::minutivisti() const{

    unsigned int min=0;
    for (auto it=list.begin();it!=list.end();it++) {
        min=min+(*it)->getmin();
    }
    return min;
}







// //////////////////////////////////////////////////


qontainer<film*> Modello::allfilm() const{
    qontainer<film*> filmtot;
    for(auto it=list.begin(); it!=list.end(); it++)
    {
        if (dynamic_cast<film*>(*it))
            filmtot.insert(new film(static_cast<film*>(*it)));
    }
    return filmtot;
}

qontainer<serietv*> Modello::allserie() const{
    qontainer<serietv*> serietot;
    for(auto it=list.begin(); it!=list.end(); it++)
    {
        if (dynamic_cast<serietv*>(*it))
            serietot.insert(new serietv(static_cast<serietv*>(*it)));
    }
    return serietot;
}


qontainer<documentario*> Modello::alldocum() const{
    qontainer<documentario*> documtot;
    for(auto it=list.begin(); it!=list.end(); it++)
    {
        if (dynamic_cast<documentario*>(*it))
            documtot.insert(new documentario(static_cast<documentario*>(*it)));
    }
    return documtot;
}


void Modello::load(){
    // apre un file
    QFile file(QString::fromStdString(path));

    //se non riesce a leggerlo
    if(!file.open(QIODevice::ReadOnly)) {
            qWarning() << "Non è stato possibile aprire il file" << file.errorString();
        }

        // Lettura del File XML
        QXmlStreamReader reader(&file);
        if(reader.readNextStartElement()){
            if(reader.name()=="root"){
                while(reader.readNextStartElement()){
                    const QXmlStreamAttributes attributes = reader.attributes();
                    string titolo= attributes.hasAttribute("titolo")? attributes.value("titolo").toString().toStdString(): "";
                    unsigned int valutazione=attributes.hasAttribute("valutazione")? attributes.value("valutazione").toUInt():1;
                    bool animato=attributes.hasAttribute("animato")? attributes.value("animato").toString()=="true"? true: false : false;
                    const QString textValue = reader.readElementText();
                    if(reader.name()== "serietv")
                    {

                        serietv::genere tipo=serietv::convertgenere(attributes.hasAttribute("genere")? attributes.value("genere").toString().toStdString(): ""); //sistemare il ""
                        unsigned int episodivisti=attributes.hasAttribute("epv")? attributes.value("epv").toUInt():0;
                        unsigned int episoditot=attributes.hasAttribute("eptot")? attributes.value("eptot").toUInt():0;
                        unsigned int durataep=attributes.hasAttribute("durata")? attributes.value("durata").toUInt():0;

                        list.insert(new serietv(titolo, valutazione, animato, episodivisti, episoditot,durataep,tipo));

                    }
                    else if(reader.name()== "film")
                    {

                        serietv::genere tipo=serietv::convertgenere(attributes.hasAttribute("genere")? attributes.value("genere").toString().toStdString(): ""); //sistemare il ""
                        unsigned int duratamin=attributes.hasAttribute("durata")? attributes.value("durata").toUInt():0;

                        list.insert(new film(titolo, valutazione, animato,duratamin,tipo));

                    }
                    else if(reader.name()== "documentario")
                    {

                        documentario::tipologia tipo=documentario::converttipologia( attributes.hasAttribute("genere")? attributes.value("genere").toString().toStdString(): "");
                        unsigned int duratamin=attributes.hasAttribute("durata")? attributes.value("durata").toUInt():0;
                        string conduttore= attributes.hasAttribute("conduttore")? attributes.value("conduttore").toString().toStdString(): "";

                        list.insert(new documentario(titolo, valutazione, animato,duratamin,conduttore,tipo));

                    }
                    else{
                        reader.skipCurrentElement();  // qDebug() << "Letto Todo " + type + ": " + textValue;
                    }
                }
            }
        }


        file.close();

}

void Modello::save() const{

    QSaveFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << "NON VA";
    }

    QXmlStreamWriter writer(&file);

    writer.setAutoFormatting(true); // Per leggibilità del file XML
    writer.writeStartDocument();    // Scrive le intestazioni XML
    writer.writeComment("File di salvataggio. Non deve essere modificato");

    writer.writeStartElement("root");                                // <root>

    auto it=list.begin();
    while(it!=list.end()) {
        const completo* salvataggio = *it;
        const QString tipo=QString::fromStdString(salvataggio->getTipoTV());
        writer.writeEmptyElement(tipo);


        writer.writeAttribute("titolo",QString::fromStdString(salvataggio->getTitolo()));
        writer.writeAttribute("valutazione",QString("%1").arg(salvataggio->getValutazione()));
        writer.writeAttribute("animato",salvataggio->getanimato()? "true": "false");
        writer.writeAttribute("genere",QString::fromStdString(salvataggio->getGenere()));

        if(tipo=="serietv"){
            const serietv* serie= static_cast<const serietv*>(salvataggio);
            writer.writeAttribute("epv",QString("%1").arg(serie->getepisodivisti()));
            writer.writeAttribute("eptot",QString("%1").arg(serie->getepisoditot()));
            writer.writeAttribute("durata",QString("%1").arg(serie->getminep()));


        }else if(tipo=="film"){
            const film* filmo= static_cast<const film*>(salvataggio);
            writer.writeAttribute("durata",QString("%1").arg(filmo->getmin()));;

        }else if(tipo=="documentario"){
            const documentario* doc= static_cast<const documentario*>(salvataggio);
            writer.writeAttribute("durata",QString("%1").arg(doc->getmin()));
            writer.writeAttribute("conduttore",QString::fromStdString(doc->getconduttore()));

        }
        if (writer.hasError()){
            throw std::exception();
        }

        it++;
    }

    writer.writeEndElement();
    writer.writeEndDocument();
    file.commit();
}

void Modello::setNewPath(std::string str){
    path= str;
}









