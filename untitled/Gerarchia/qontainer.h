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

};



#endif // QONTAINER_H
