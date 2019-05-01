#include "list.h"
#include "base_container.h"
#include "list_iterator.h"
#include "const_list_iterator.h"
#include "node.h"
#include <stdio.h>

template <typename T>
List<T>::List(Node<T> *list){}
template <typename T>
List<T>::List(T* array, int n){}
template <typename T>
List<T>::List(const List<T> &list){}
template <typename T>
List<T>::List(List<T> && list){}
//List(std::initializer_list<std::initializer_list<T>> lst);

// операторы
template <typename T>
List<T>& List<T>::operator =(const List<T> &list){}
template <typename T>
List<T>& List<T>::operator =(List<T> &&list){}

template <typename T>
List<T>& List<T>::operator +(const List<T> &list) const{}
template <typename T>
List<T>& List<T>::operator +=(const List<T> &list){}
template <typename T>
List<T>& List<T>::operator +=(const T &value){}

template <typename T>
List<T>& List<T>::operator [](const int i){}
template <typename T>
List<T>& List<T>::operator [](const int i) const{}
template <typename T>
List<T>& List<T>::operator ==(const List<T> &list) const{}
template <typename T>
List<T>& List<T>::operator !=(const List<T> &list) const{}
template <typename T>
List<T>& List<T>::operator <<(const List<T> &list){}
template <typename T>
List<T>& List<T>::operator <<(const T &value){}
template <typename T>
T* List<T>::to_array(size_t &size);


//итераторы
template <typename T>
list_iterator<T> List<T>::begin()
{
    return list_iterator<T>(this->head);
}
template <typename T>
list_iterator<T> List<T>::end()
{
    return list_iterator<T>(this->tail);
}
template <typename T>
const_list_iterator<T> List<T>::begin() const
{
    return const_list_iterator<T>(this->head);
}
template <typename T>
const_list_iterator<T> List<T>::end() const
{
    return const_list_iterator<T>(this->tail);
}

template <typename T>
void List<T>::append(const List<T>& list){}
template <typename T>
void List<T>::append(const T& elem){}
template <typename T>
void List<T>::remove(const T& elem){}
template <typename T>
void List<T>::clear(){}
template <typename T>
bool List<T>::compare(const List<T>& list){}
template <typename T>
void List<T>::InsertAfter(const T& el, list_iterator<T>& insert_after){}
template <typename T>
void List<T>::remove(list_iterator<T>& iter){}
template <typename T>
bool List<T>::is_empty()
{
    return this->head == nullptr;
}
template <typename T>
size_t List<T>::size() const
{
    return this->len;
}
template <typename T>
size_t List<T>::lenght() const
{
    return this->len;
}
template <typename T>
size_t List<T>::count(const T& value){}
template <typename T>
T& List<T>::first()
{
    return this->head->get_obj();
}
template <typename T>
const T& List<T>::first() const
{
    return this->head->get_obj();
}
template <typename T>
T& List<T>::last()
{
    return this->tail->get_obj();
}
template <typename T>
const T& List<T>::last() const
{
    return this->tail->get_obj();
}
template <typename T>
T& List<T>::pop_back(){}
template <typename T>
T& List<T>::pop_front(){}
template <typename T>
void List<T>::push_back(const T& value){}
template <typename T>
void List<T>::push_front(const T& value){}
template <typename T>
void List<T>::sort(){}
template <typename T>
void List<T>::reverse(){}
