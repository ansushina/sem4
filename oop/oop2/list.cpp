#include "list.h"
#include "base_container.h"
#include "list_iterator.h"
#include "const_list_iterator.h"
#include "node.h"
#include <stdio.h>

template <typename T>
List<T>::List(Node<T> *list)
{
    if (!list)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        Node<T> *node, *tmp;
        Node<T> *head = new Node<T>;
        if (!head)
            //memeror
        head->set_obj(list->get_obj());
        this->head = head;
        tmp = head;

        for (node = list->get_next(); node; node = node->get_next())
        {
            Node<T> *new_node = new Node<T>;
            if (!new_node)
                //memeeror
            tmp->set_next(new_node);
            new_node->set_obj(node->get_obj());
            this->tail = new_node;
            tmp = tmp->get_next();
        }
    }

}
template <typename T>
List<T>::List(T* array, int n)
{
    if (!array)
    {
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }
    Node<T> *node, *tmp;
    Node<T> *head = new Node<T>;
    if (!head)
        //
    head->set_obj(array[0]);
    tmp =  head;
    for (size_t i = 1; i < n; i++)
    {
        Node<T> *new_node = new Node<T>;
        if (!new_node)
            //memeeror
        tmp->set_next(new_node);
        new_node->set_obj(array[i]);
        this->tail = new_node;
        tmp = tmp->get_next();
    }
}
template <typename T>
List<T>::List(const List<T> &list)
{
    if (!list.head)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        Node<T> *node, *tmp;
        Node<T> *head = new Node<T>;
        if (!head)
            //memeror
        this->head = head;
        head->set_obj(list.head->get_obj());
        tmp =  head;

        for (node = list.head->get_next(); node; node = node->get_next())
        {
            Node<T> *new_node = new Node<T>;
            if (!new_node)
                //memeeror
            tmp->set_next(new_node);
            new_node->set_obj(node->get_obj());
            this->tail = new_node;
            tmp = tmp->get_next();
        }
    }
}

template <typename T>
List<T>::List(List<T> && list)
{
    this->head = list.head;
    this->tail = list.tail;
}
//List(std::initializer_list<std::initializer_list<T>> lst);

// операторы
template <typename T>
List<T>& List<T>::operator =(const List<T> &list)
{
    if (this->lenght() <= list.lenght())
    {
        Node<T> *cl = list.head, *ct = this->head;
        while (ct)
        {
            ct->set_obj();
        }
    }
    else
    {}

}

template <typename T>
List<T>& List<T>::operator =(List<T> &&list)
{
    this->head = list.head;
    this->tail = list.tail;
    return *this;
}

template <typename T>
List<T>& List<T>::operator +(const List<T> &list) const
{

}
template <typename T>
List<T>& operator +(const T &value)
{

}
template <typename T>
List<T>& List<T>::operator +=(const List<T> &list)
{
    this->append(list);
    return *this;
}
template <typename T>
List<T>& List<T>::operator +=(const T &value)
{
    this->append(value);
    return *this;
}

template <typename T>
List<T>& List<T>::operator [](const int i)
{
    if (!this->head)
        ;
    Node<T> *node = this->head;
    for (int j = 0; j < i; j++)
    {
        node = node->get_next();
    }
}
template <typename T>
List<T>& List<T>::operator [](const int i) const{}
template <typename T>
bool List<T>::operator ==(const List<T> &list) const
{
    Node<T> *nodet = this->head, *nodel = list.head;
    while (nodet && nodel && nodet->get_obj() == nodel->get_obj())
    {
        nodet = nodet->get_next();
        nodel = nodel->get_next();
    }
    if (nodet == nullptr && nodel == nullptr)
        return true;
    return false;

}
template <typename T>
bool List<T>::operator !=(const List<T> &list) const
{
    return !(*this==list);
}
template <typename T>
List<T>& List<T>::operator <<(const List<T> &list){}
template <typename T>
List<T>& List<T>::operator <<(const T &value){}
template <typename T>
T* List<T>::to_array(size_t &size)
{
    T* arr = new T[this->lenght()];
    if (!arr)
        //memerr
    Node<T> *node = this->head;
    for( size_t i  = 0; i < this->lenght(); i++)
    {
         arr[i] = node->get_obj();
         node = node->get_next();
    }
    size = this->lenght();

    return arr;
}


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
void List<T>::append(const List<T>& list)
{
    if (!this->head)
    {
        *this = list;
        return *this;
    }
    Node<T> * tmp = list.head;
    while(tmp)
    {
        Node<T> *node = new Node<T>;
        if (!node)
            //memerr
        node->set_obj(tmp->get_obj());
        this->tail->set_next(node);
        this->tail = node;
    }

}
template <typename T>
void List<T>::append(const T& elem)
{
    Node<T> *node = new Node<T>;
    if (!node)
        //memerr
    node->set_obj(elem);
    if (!this->head)
    {
        this->head = node;
        this->tail = node;
        return;
    }
    this->tail->set_next(node);
    this->tail = node;
}
template <typename T>
void List<T>::remove(const T& elem)
{
    if (!this->head)
        //throw
    Node<T> *node = this->head;
    while (node->get_next()->get_obj() != elem)
    {
        node = node->get_next();
    }
    Node<T> *next = node->get_next()->get_next();
    delete node->get_next();
    node->next = next;
}
template <typename T>
void List<T>::clear()
{
    Node<T> *node;
    while (this->head)
    {
        node = this->head->get_next();
        delete this->head;
        this->head = node;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

//not all
template <typename T>
int List<T>::compare(const List<T>& list)
{
    if (*this == list)
        return 0;
    return 1;
}
template <typename T>
void List<T>::InsertAfter(const T& el, list_iterator<T>& insert_after)
{
    Node<T> *node = new Node<T>;
    node->set_obj(el);
    node->next = insert_after->get_next();
    insert_after->set_next(node);
}
template <typename T>
void List<T>::remove(list_iterator<T>& iter)
{
    if (!this->head)
        //throw
    Node<T> *node = this->head;
    while (node->get_next() != *iter)
    {
        node = node->get_next();
    }
    Node<T> *next = node->get_next()->get_next();
    delete node->get_next();
    node->next = next;
}


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
    return (this->len * sizeof(Node<T>));
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
T& List<T>::pop_back()
{
    if (!this->tail)
        //throw
    T data = this->tail->get_obj();
    Node<T> *tmp = this->head;
    while (tmp->get_next() != this->tail)
    {
        tmp = tmp->get_next();
    }
    delete this->tail;
    this->tail = tmp;
    return data;

}
template <typename T>
T& List<T>::pop_front()
{
    if (!this->head)
        //throw
    T data = this->head->get_obj();
    Node<T> *tmp = this->head->next;
    delete this->head;
    this->head = tmp;
    return data;
}
template <typename T>
void List<T>::push_back(const T& value)
{
    Node<T> *node = new Node<T>;
    if (!node)
        //memerr
    node->set_obj(value);
    if (!this->head)
    {
        this->head = node;
        this->tail = node;
        return;
    }
    this->tail->set_next(node);
    this->tail = node;
}
template <typename T>
void List<T>::push_front(const T& value)
{
    Node<T> *node = new Node<T>;
    if (!node)
        //memerr
    node->set_obj(value);
    if (!this->head)
    {
        this->head = node;
        this->tail = node;
        return;
    }
    node->set_next(this->head);
    this->head = node;
}
template <typename T>
void List<T>::sort(){}
template <typename T>
void List<T>::reverse(){}


template <typename T>
 List<T>::~List()
{

    Node<T> *node;
    while (this->head)
    {
        node = this->head->get_next();
        delete this->head;
        this->head = node;
    }

}

