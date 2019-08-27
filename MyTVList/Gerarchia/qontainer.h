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
        T info;
        nodo* next;
        nodo( T =T(), nodo* =nullptr);
        ~nodo();
    };

    //      OGGETTI DEL QONTAINER
    nodo* first;
    nodo* last;
    unsigned int size;
public:
    //qontainer();
    qontainer(nodo* =nullptr, nodo* =nullptr, unsigned int =0);
    qontainer( qontainer* );
    ~qontainer();
    const T& operator[](int);


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
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void insert(const T&);
    void remove(T); //si rimuove un T costante? CONTROLLARE IN SEGUITO
    void remove(int);
    void push_back(const T&);  // SE NON USATO TOGLIERE


    T& at(unsigned int) ;
    unsigned int getsize() const;
    bool esiste();
    void eraseall() ;


};



template<typename T>
void qontainer<T>::eraseall() { //testare
    if (size){
        size=size-1;
        delete first;
    }
    first=last=nullptr;


}

template <typename T>
T& qontainer<T>::at(unsigned int a) {

    auto it=begin();
    while (it!=end() && size>=a && a!=0)
    {
        it++;
        a--;
    }
    return *it;
}

template <typename T>
bool qontainer<T>::esiste(){
    if (first)
        return  true;
    else {
        return false;
    }
}

template <typename T>
const T& qontainer<T>::operator[](int n){
    auto it=begin();
    while (it!=end() && n!=0)
    {
        it++;
        n--;
    }
    return *it;
}

// NODO
template <typename T>
qontainer<T>::nodo::nodo(T i, nodo* n): info(i), next(n)  {}

template<typename T>
qontainer<T>::nodo::~nodo() {if (info) delete info;}

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


//6)operatore ->
template <typename T>
typename qontainer<T>::nodo* qontainer<T>::iterator::operator->() {
    return punt;
}

//7) operatore *
template <typename T>
T& qontainer<T>::iterator::operator*() {
    return  punt->info;
}

//8) begin()
template <typename T>
typename qontainer<T>::iterator qontainer<T>::begin()  {
    iterator aux(first);
    return aux;
}

//9) end()
template <typename T>
typename qontainer<T>::iterator qontainer<T>::end()  {
    iterator aux(nullptr);
    return aux;
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
    const_iterator aux(first);
    return aux;
}

//9) end()
template <typename T>
typename qontainer<T>::const_iterator qontainer<T>::end() const {
    const_iterator aux(nullptr);
    return aux;
}






//QONTAINER


template <typename T>
qontainer<T>::qontainer(nodo* f, nodo* l, unsigned int s): first(f), last(l), size(s) {}

template <typename T>
qontainer<T>::qontainer( qontainer* q) {
    auto it=q->begin();
    while(it!=q->end())
    {
        this->insert(*q);
    }
}

template<typename T> //COME CAVOLO SI FA IL DISTRUTTORE DI UNA LISTA?!?
qontainer<T>::~qontainer<T>(){
    nodo * a = first, *b;
    while (a) {
        b = a;
        a = a->next;
        delete b;
    }
    last = nullptr;
}



template<typename T>
void qontainer<T>::push_back(const T& t){  // SE NON USATO TOGLIERE
    last->next=new nodo(t,0,0);
    last=last->next;
}




template <typename T>
unsigned int qontainer<T>::getsize() const{
    return size;
}




template <typename T>
void qontainer<T>::insert(const T& i){  //credo si possa fare meglio, RIGUARDARE
    if (!first){
        size=1;
        first=last=new nodo(i, nullptr);
    }
    else {

        first=new nodo(i, first);
        size=size+1;
    }
}

template <typename T>
void qontainer<T>::remove( T i){
    nodo* prec=nullptr;
    nodo* aux=first;
    int s=size;


    while (aux && !((*(aux->info))==(*i)) && s>1) //finchè esiste aux e le info sono diverse va avanti
    {
        prec=aux;
        aux=aux->next;
        s=s-1;
    }
    //devo dividere in diversi casi: 1. se next non c'è quindi è alla fine 2: se prev non c'è quindi è all'inizio 3: se è in mezzo quindi prev e next ci sono
    if (aux)
    {
        if (!(aux->next)){
            last=prec;
            last->next=nullptr;
        }
        else if (!prec)
            first=first->next;
        else if (aux->next && prec)
        {
            prec->next=aux->next;

        }
        delete aux;
        size=size-1;
    }
}

template <typename T>
void qontainer<T>::remove(int i){
    nodo* prec=nullptr;
    nodo* aux=first;

    while (aux && i>=0)
    {
        prec=aux;
        aux=aux->next;
        i=i-1;
    }
    //devo dividere in diversi casi: 1. se next non c'è quindi è alla fine 2: se prev non c'è quindi è all'inizio 3: se è in mezzo quindi prev e next ci sono
    if (aux)
    {
        if (!(aux->next)){
            last=prec;
            last->next=nullptr;
        }
        else if (!prec)
            first=first->next;
        else if (aux->next && prec)
        {
            prec->next=aux->next;

        }
        delete aux;
        size=size-1;
    }
}



#endif // QONTAINER_H
