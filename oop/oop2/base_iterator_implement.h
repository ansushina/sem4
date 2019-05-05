#ifndef BASE_ITERATOR_IMPLEMENT_H
#define BASE_ITERATOR_IMPLEMENT_H

#include "base_iterator.h"
using namespace iterator;

template<typename T>
base_iterator<T>::base_iterator()
{
    this->ptr = nullptr;
}

template<typename T>
base_iterator<T>::base_iterator(const base_iterator<T> &iter)
{
    this->ptr = iter.ptr;
}

template<typename T>
base_iterator<T>::base_iterator(T*ptr)
{
    this->ptr = ptr;
}

template<typename T>
base_iterator<T>::~base_iterator()
{
    this->ptr = nullptr;
}

template<typename T>
base_iterator<T>& base_iterator<T>::operator =(const base_iterator<T>& iter)
{
    if (this != &iter)
        this->ptr = iter.ptr;
    return *this;
}

template<typename T>
base_iterator<T>& base_iterator<T>::operator ++()
{
    if (this->ptr != nullptr)
        this->ptr = this->ptr->get_next();
    return *this;
}

template<typename T>
base_iterator<T> base_iterator<T>::operator ++(int)
{
    base_iterator tmp = *this;
    this->operator++;
    return tmp;
}
template<typename T>
base_iterator<T>& base_iterator<T>::operator --()
{
    if (this->ptr != nullptr)
        this->ptr = this->ptr->get_prev();
    return *this;
}

template<typename T>
base_iterator<T> base_iterator<T>::operator --(int)
{
    base_iterator tmp = *this;
    this->operator--;
    return tmp;
}
template<typename T>
base_iterator<T>::operator bool() const
{
    if (this->ptr)
        return true;
    return false;
}
template<typename T>
bool base_iterator<T>::operator ==(const base_iterator<T>& iter) const
{
    return (this->ptr->get_obj() == iter.ptr->get_obj());
}
template<typename T>
bool base_iterator<T>::operator !=(const base_iterator<T>&iter) const
{
    return (this->ptr->get_obj() != iter.ptr->get_obj());
}
#endif // BASE_ITERATOR_IMPLEMENT_H
