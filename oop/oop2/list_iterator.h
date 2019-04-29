#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
#include "base_iterator.h"
using namespace iterator;
template<typename T>
class list_iterator : public base_iterator<T>
{
public:
    list_iterator(constlist_iterator<T>&);
    list_iterator(T*);
    T &operator *();
    T *operator ->();
    const T &operator *() const;
    const T *operator ->() const;
};

#endif // LIST_ITERATOR_H
