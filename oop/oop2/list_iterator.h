#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
#include "base_iterator.h"
using namespace iterator;
template<typename T>
class list_iterator : public base_iterator<T>
{
public:
    list_iterator(const list_iterator<T>&);
    list_iterator(Node<T>*);
    Node<T> &operator *();
    Node<T> *operator ->();
    const Node<T> &operator *() const;
    const Node<T> *operator ->() const;
};

#endif // LIST_ITERATOR_H
