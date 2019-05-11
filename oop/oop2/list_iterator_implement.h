#ifndef LIST_ITERATOR_IMPLEMENT_H
#define LIST_ITERATOR_IMPLEMENT_H

#include "list_iterator.h"
using namespace iterator;
template<typename T>
list_iterator<T>::list_iterator(const list_iterator<T>& iter):
    base_iterator<T>(iter.ptr)
{}

template<typename T>
list_iterator<T>::list_iterator(std::shared_ptr<Node<T>> ptr):
    base_iterator<T>(ptr)
{}

template<typename T>
T& list_iterator<T>::operator *()
{
    return this->ptr.lock()->get_obj();
}
template<typename T>
Node<T>* list_iterator<T>::operator ->()
{
    return this->ptr.lock();
}
template<typename T>
const T& list_iterator<T>::operator *() const
{
    return this->ptr.lock()->get_obj();
}
template<typename T>
const std::shared_ptr<Node<T>> list_iterator<T>::operator ->() const
{
    return this->ptr.lock();
}


#endif // LIST_ITERATOR_IMPLEMENT_H
