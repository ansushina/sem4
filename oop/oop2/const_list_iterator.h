#ifndef CONST_LIST_ITERATOR_H
#define CONST_LIST_ITERATOR_H
#include "base_iterator.h"
using namespace iterator;
template <typename T>
class const_list_iterator : public base_iterator<T>
{
public:
    const_list_iterator(const const_list_iterator<T>&);
    const_list_iterator(Node<T>*);

    const Node<T>& operator *() const;
    const Node<T>* operator ->() const;
};

#endif // CONST_LIST_ITERATOR_H
