#ifndef CONST_LIST_ITERATOR_IMPLRMRNT_H
#define CONST_LIST_ITERATOR_IMPLRMRNT_H
#include "base_iterator.h"
#include "const_list_iterator.h"
using namespace iterator;

template <typename T>
const_list_iterator<T>::const_list_iterator(const const_list_iterator<T>& iter):
    base_iterator<T>(iter.ptr)
{}
template <typename T>
const_list_iterator<T>::const_list_iterator(Node<T>* ptr):
    base_iterator<T>(ptr)
{}

template <typename T>
const Node<T>& const_list_iterator<T>::operator *() const
{
    return this->ptr->get_obj();
}
template <typename T>
const Node<T>* const_list_iterator<T>::operator ->() const
{
    return this->ptr;
}



#endif // CONST_LIST_ITERATOR_IMPLRMRNT_H