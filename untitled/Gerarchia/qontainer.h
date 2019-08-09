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
        nodo(nodo* =nullptr, nodo* =nullptr, T =T());
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

};

// NODO
template <typename T>
qontainer<T>::nodo::nodo(nodo* p, nodo* n, T i): prev(p), next(n), info(i) {}

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
        first=last=new nodo(i, nullptr, aux);
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
