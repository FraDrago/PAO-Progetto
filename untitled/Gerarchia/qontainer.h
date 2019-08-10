#ifndef QONTAINER_H
#define QONTAINER_H

template <class T>
class qontainer{
    friend class const_iterator;
private:
    class nodo{
    public:
        nodo* prev;
        nodo* next;
        T info;
        nodo( T =T(), nodo* =nullptr, nodo* =nullptr);
        ~nodo()=default;
    };
    nodo* first;
    nodo* last;
    unsigned int size;
    // unsigned int minuti;
public:
    qontainer(nodo* =nullptr, nodo* =nullptr, unsigned int =0);
    qontainer(const qontainer&);
    ~qontainer();

    void insert(const T);
    void remove(const T); //si rimuove un T costante? CONTROLLARE IN SEGUITO

    unsigned int getsize() const;
    //void totale() const;

    class const_iterator{
        friend class qontainer<T>;
        private:
            const qontainer::nodo* punt;
        public:
            const_iterator(qontainer::nodo* =nullptr); //punt(n)  {}

            const_iterator& operator++() ;
            const_iterator& operator++(int) ;
            const_iterator& operator--();
            const_iterator& operator--(int);
            const T& operator*() const;

        };

        const_iterator& begin() const;
        const_iterator& end() const;


};

// NODO
template <typename T>
qontainer<T>::nodo::nodo(T i, nodo* p, nodo* n): info(i), prev(p), next(n)  {}

//CONST_ITERATOR

template <typename T>
qontainer<T>::const_iterator::const_iterator(qontainer::nodo* n): punt(n)  {}

template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::begin() const {
    return new const_iterator(first);
}

template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::end() const {
    return new const_iterator(nullptr);
}

template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::const_iterator::operator++() {

    return *this;
}

template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::const_iterator::operator++(int ) {
    const_iterator it(*this);
    if (punt) punt=punt->next;
    return it;
}

template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::const_iterator::operator--() {
    if(punt)   punt=punt->pre;
    return *this;
}

template <typename T>
typename qontainer<T>::const_iterator& qontainer<T>::const_iterator::operator--(int ) {
    const_iterator it(*this);
    if(punt)    punt=punt->prev;
    return it;
}




//QONTAINER
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
void qontainer<T>::insert(const T i){  //credo si possa fare meglio, RIGUARDARE
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
void qontainer<T>::remove(const T i){
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
