#ifndef QONTAINER_H
#define QONTAINER_H
#include <string>
using std::string;
//#include "completo.h"

template <class T>
class qontainer{
    friend class const_iterator;
    friend class iterator;
private:

    //                         INIZIO CLASSE NODO
    class nodo{
    public:
        nodo* prev;
        nodo* next;
        T info;
        nodo( T =T(), nodo* =nullptr, nodo* =nullptr);
        ~nodo()=default;
    };

    //      OGGETTI DEL QONTAINER
    nodo* first;
    nodo* last;
    unsigned int size;
public:
    qontainer(nodo* =nullptr, nodo* =nullptr, unsigned int =0);
    qontainer(const qontainer&);
    ~qontainer();

    //                         INIZIO CLASSE ITERATOR
    class iterator{
        friend class qontainer;
    private:
        nodo* punt;
    public:
        iterator(nodo* =nullptr);
        bool operator==(const iterator&);
        bool operator!=(const iterator&);
        iterator& operator++();
        iterator operator++(int);
        //iterator& operator--();
        //iterator operator--(int);
        T& operator*();
        nodo* operator->();
    };

    //                         INIZIO CLASSE CONST_ITERATOR
    class const_iterator{
        friend class qontainer<T>;
        private:
            const nodo* punt;
        public:
            const_iterator(const nodo* =nullptr);

            bool operator==(const_iterator it) const;
            bool operator!= (const_iterator it) const;
            const_iterator& operator++() ;
            const_iterator operator++(int) ;
            //const_iterator& operator--();
            //const_iterator operator--(int);
            //nodo* operator*() const;
            const T& operator*() const;
            nodo* operator->() const;

        };

    iterator begin();
    iterator& end();
    const_iterator begin() const;
    const_iterator& end() const;

    void insert(const T&);
    void remove(const T&); //si rimuove un T costante? CONTROLLARE IN SEGUITO
    void push_back(const T&);  // SE NON USATO TOGLIERE

    unsigned int getsize() const;
    unsigned int minutivisti() const;
    qontainer ricerca(string) ;

};

// NODO
template <typename T>
qontainer<T>::nodo::nodo(T i, nodo* p, nodo* n): info(i), prev(p), next(n)  {}

//                                                ITERATOR

//1) definizione
template<class T>
qontainer<T>::iterator::iterator(nodo* n): punt(n)  {}

//2) operatore uguale
template<class T>
bool qontainer<T>::iterator::operator==(const iterator& it){
    return punt==it.punt;
}

//3) operatore diverso
template <class T>
bool qontainer<T>::iterator::operator!=(const iterator& it){
    return punt != it.punt;
}

//4) operatore ++ prefisso
template <class T>
typename qontainer<T>::iterator& qontainer<T>::iterator::operator++(){
    if (punt)
        punt=punt->next;
    return *this;
}

//5) operatore ++ postfisso
template<class T>
typename qontainer<T>::iterator qontainer<T>::iterator::operator++(int){
    iterator it(*this);
    if (punt) punt=punt->next;
    return it;
}


//6)operatore *
template <typename T>
typename qontainer<T>::nodo* qontainer<T>::iterator::operator->() {
    return punt;
}

//7) operatore ->
template <typename T>
T& qontainer<T>::iterator::operator*() {
    return  punt->info;
}

//8) begin()
template <typename T>
typename qontainer<T>::iterator qontainer<T>::begin()  {
    return *(new iterator(first));
}

//9) end()
template <typename T>
typename qontainer<T>::iterator& qontainer<T>::end()  {
    return *(new iterator(nullptr));
}









//                                     CONST_ITERATOR

//1) definizione
template <typename T>
qontainer<T>::const_iterator::const_iterator(const nodo* n): punt(n)  {}

//2) operatore uguale
template <typename T>
bool qontainer<T>::const_iterator::operator==(const_iterator it) const {
    return punt == it.punt;
}

//3) operatore diverso
template <typename T>
bool qontainer<T>::const_iterator::operator!=(const_iterator it) const {
    return punt != it.punt;
}

//4) operatore ++ prefisso
template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::const_iterator::operator++() {
    if (punt)
        punt=punt->next;
    return *this;
}

//5) operatore ++ postfisso
template <typename T>
typename qontainer<T>::const_iterator qontainer<T>::const_iterator::operator++(int ) { //WAITTA UN SECONDO
    const_iterator it(*this);
    if (punt) punt=punt->next;
    return it;
}


//6)operatore ->
template <typename T>
typename qontainer<T>::nodo* qontainer<T>::const_iterator::operator->() const {
    return punt;
}

//7) operatore *
template <typename T>
const T& qontainer<T>::const_iterator::operator*() const {
    return  punt->info;
}


//8) begin()
template <typename T>
typename qontainer<T>::const_iterator qontainer<T>::begin() const {
    return *(new const_iterator(first));
}

//9) end()
template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::end() const {
    return *(new const_iterator());
}






//QONTAINER

template <typename T>
qontainer<T> qontainer<T>::ricerca(string nome) {
    qontainer<T> aux;
    for (auto it=begin();it!=end();it++) {
        if (nome==(*it).getTitolo())
            aux.insert(*it);
        /*else {
            throw qualcosa
        }*/
    }
    return aux;
}


template<typename T>
void qontainer<T>::push_back(const T& t){  // SE NON USATO TOGLIERE
    last->next=new nodo(t,0,0);
    last=last->next;
}

template <typename T>
unsigned int qontainer<T>::minutivisti() const{

    unsigned int min=0;
    for (auto it=begin();it!=end();it++) {
        min=min+(*it).getmin();
    }
    return min;
}

/*template <typename T>
unsigned int qontainer<T>::tempotot() const{
    unsigned int tempo=0;
    for (auto it=begin();it!=end(); it++) {
        tempo=(*it)->getmin()+tempo;
    }
    return tempo;
}*/

template <typename T>
unsigned int qontainer<T>::getsize() const{
    return size;
}

template<typename T> //COME CAVOLO SI FA IL DISTRUTTORE DI UNA LISTA?!?
qontainer<T>::~qontainer<T>(){
    if (first)
        delete first;
}

template <typename T>
qontainer<T>::qontainer(nodo* f, nodo* l, unsigned int s): first(f), last(l), size(s) {}

template <typename T>
qontainer<T>::qontainer(const qontainer& q): first(q.first), last(q.last), size(q.size) {}

template <typename T>
void qontainer<T>::insert(const T& i){  //credo si possa fare meglio, RIGUARDARE
    if (!first){
        size=1;
        first=last=new nodo(i, nullptr, nullptr);
    }
    else {
        nodo* aux=first;
        first=new nodo(i, nullptr, aux);
        size=size+1;
    }
}

template <typename T>
void qontainer<T>::remove(const T& i){
    nodo* aux=first;
    while (aux && !(aux->info==i)) //finchè esiste aux e le info sono diverse va avanti
        aux=aux->next;
    //devo dividere in diversi casi: 1. se next non c'è quindi è alla fine 2: se prev non c'è quindi è all'inizio 3: se è in mezzo quindi prev e next ci sono
    if (aux)
    {
        if (!(aux->next))
            last=last->prev;

        if (!(aux->prev))
            first=first->next;

        if (aux->next && aux->prev)
        {
            aux->prev->next=aux->next;

        }
        delete aux;
        size=size-1;
    }
}

/*template <typename T>
void qontainer<T>::totale() const{
    while (first)
}*/ // al momento non so come farlo bene, tecnicamente dovrei usare uno static per far si che un valore sia sempre aggiornato, oppure non serve e inserisco su insert e remove


#endif // QONTAINER_H
