#ifndef LIST_ITERATOR_IMPLEMENT_H
#define LIST_ITERATOR_IMPLEMENT_H

#include "base_iterator.h"
#include "list_iterator.h"
using namespace iterator;
template<typename T>
list_iterator<T>::list_iterator(const list_iterator<T>& iter):
    base_iterator<T>(iter.ptr)
{}

template<typename T>
list_iterator<T>::list_iterator(Node<T> *ptr):
    base_iterator<T>(ptr)
{}

template<typename T>
Node<T>& list_iterator<T>::operator *()
{
    return this->ptr->get_obj();
}
template<typename T>
Node<T>* list_iterator<T>::operator ->()
{
    return this->ptr;
}
template<typename T>
const Node<T>& list_iterator<T>::operator *() const
{
    return this->ptr->get_obj();
}
template<typename T>
const Node<T>* list_iterator<T>::operator ->() const
{
    return this->ptr;
}


#endif // LIST_ITERATOR_IMPLEMENT_H
