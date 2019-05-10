#ifndef LIST_IMPLEMENT_H
#define LIST_IMPLEMENT_H

#include "list.h"

template <typename T>
List<T>::List(T* array, int n)
{
    time_t t_time;
    t_time = time(NULL);
    if (!array)
    {
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }
    try
    {
        for (int i = 0; i < n; i++)
        {
            std::shared_ptr<Node<T>> new_node = std::shared_ptr<Node<T>>(new Node<T>);
            new_node->set_obj(array[i]);
            this->append(new_node);
        }
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
    }
}
template <typename T>
List<T>::List(const List<T> &list)
{
    time_t t_time;
    t_time = time(NULL);
    if (!list.head)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        try
        {
            std::shared_ptr<Node<T>> node;

            for (node = list.head; node; node = node->get_next())
            {
                std::shared_ptr<Node<T>> new_node = std::shared_ptr<Node<T>>(new Node<T>);
                new_node->set_obj(node->get_obj());
                this->append(new_node);
            }
        }
        catch (std::bad_alloc)
        {
            throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
        }
    }
}

template <typename T>
List<T>::List(List<T> &&list)
{
    this->head = list.head;
    this->tail = list.tail;
}

template <typename T>
List<T>::List(std::initializer_list<T> lst)
{
    time_t t_time;
    t_time = time(NULL);
    if (!lst)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        try
        {
            for (int i = 0; i < lst.size(); i++)
            {
                std::shared_ptr<Node<T>> new_node = std::shared_ptr<Node<T>>(new Node<T>);
                new_node->set_obj(lst[i]);
                this->append(new_node);
            }
        }
        catch (std::bad_alloc)
        {
            throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
        }
    }
}

// операторы
template <typename T>
List<T>& List<T>::operator =(const List<T> &list)
{
    time_t t_time;
    t_time = time(NULL);
    if (*this == list)
    {
        return *this;
    }

    this->clear();
    if (!list.head)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        try
        {
            std::shared_ptr<Node<T>> node;
            for (node = list.head; node; node = node->get_next())
            {
                std::shared_ptr<Node<T>> new_node = std::shared_ptr<Node<T>>(new Node<T>);
                new_node->set_obj(node->get_obj());
                this->append(new_node);
            }
        }
        catch (std::bad_alloc)
        {
            throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
        }
    }
    return *this;
}

template <typename T>
List<T>& List<T>::operator =(List<T> &&list)
{
    this->clear();
    this->head = list.head;
    this->tail = list.tail;
    return *this;
}


template <typename T>
List<T> List<T>::unite(const List<T> &list) const
{
    List<T> *tmp = new List<T>;
    *tmp = *this;
    tmp->append_list(list);
    return *tmp;
}
template <typename T>
List<T> List<T>::unite(const T &value) const
{
    List<T> *tmp = new List<T>;
    *tmp = *this;
    tmp->append_el(value);
    return *tmp;
}
template <typename T>
List<T> List<T>::operator +(const List<T> &list) const
{
    List<T> *tmp = new List<T>;
    *tmp = *this;
    tmp->append_list(list);
    return *tmp;
}
template <typename T>
List<T> List<T>::operator +(const T &value) const
{
    List<T> *tmp = new List<T>;
    *tmp = *this;
    tmp->append_el(value);
    return *tmp;
}
template <typename T>
List<T> &List<T>::append(const List<T>& list)
{
    this->append_list(list);
    return this;
}

template <typename T>
List<T>& List<T>::append(const T& elem)
{
    this->append_el(elem);
    return *this;
}
template <typename T>
List<T>& List<T>::operator +=(const List<T> &list)
{
    this->append_list(list);
    return *this;
}
template <typename T>
List<T>& List<T>::operator +=(const T &value)
{
    this->append_el(value);
    return *this;
}

template <typename T>
bool List<T>::compare(const List<T>& list) const
{
    if (*this == list)
        return true;
    return false;
}

template <typename T>
bool List<T>::operator ==(const List<T> &list) const
{
    std::shared_ptr<Node<T>> nodet = this->head, nodel = list.head;
    while (nodet && nodel && nodet->get_obj() == nodel->get_obj())
    {
        nodet = nodet->get_next();
        nodel = nodel->get_next();
    }
    if (!nodet && !nodel)
        return true;
    return false;

}
template <typename T>
bool List<T>::operator !=(const List<T> &list) const
{
    return !(*this==list);
}
/*template <typename T>
List<T>& List<T>::operator <<(const List<T> &list){}
template <typename T>
List<T>& List<T>::operator <<(const T &value){}*/
/*template <typename T>
T** List<T>::to_array(size_t &size)
{
    time_t t_time;
    t_time = time(NULL);
    T* arr = new T[this->lenght()];
    if (!arr)
        throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
    Node<T> *node = this->head;
    for( size_t i  = 0; i < this->len; i++)
    {
         arr[i] = node->get_obj();
         node = node->get_next();
    }
    size = this->lenght();

    return &arr;
}*/


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
void List<T>::clear()
{
    this->free();
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;
}

template <typename T>
List<T>& List<T>::InsertAfter(const T& el, list_iterator<T>& insert_after)
{
    std::shared_ptr<Node<T>> node = std::shared_ptr<Node<T>>(new Node<T>);
    node->set_obj(el);
    this->InsertAfter(node,insert_after);
    return *this;
}

template <typename T>
List<T>& List<T>::InsertAfter(const List<T> &list, list_iterator<T>& insert_after)
{
    time_t t_time;
    t_time = time(NULL);
    try
    {
        std::shared_ptr<Node<T>> node;
        for (node = list.head; node; node = node->get_next())
        {
            std::shared_ptr<Node<T>> new_node = std::shared_ptr<Node<T>>(new Node<T>);
            new_node->set_obj(node->get_obj());
            this->InsertAfter(new_node,insert_after);
        }
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
    }
    return *this;
}

template <typename T>
List<T>& List<T>::remove(list_iterator<T>& iter)
{
    time_t t_time;
    t_time = time(NULL);
    if (!this->head)
        throw list_index_out_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "List index out of range");
    std::shared_ptr<Node<T>> node = this->head;
    while (node->get_next() != *iter)
    {
        node = node->get_next();
    }
    std::shared_ptr<Node<T>> next = node->get_next()->get_next();
    node->get_next().reset();
    node->next = next;
    this->len--;
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

size_t List<T>::count(const T& value)
{
    if(!this->head)
        return 0;
    std::shared_ptr<Node<T>> tmp = this->head;
    size_t count = 0;
    while (tmp)
    {
        if (tmp->get_obj() == value)
            count++;
        tmp = tmp->get_next();
    }
    return count;
}

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
T& List<T>::pop_front()
{
    time_t t_time;
    t_time = time(NULL);
    if (!this->head)
        throw list_index_out_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "List index out of range");
    T *data = new T;
    *data = this->head->get_obj();
    std::shared_ptr<Node<T>> tmp = this->head->get_next();
    this->head.reset();
    this->head = tmp;
    this->len--;
    return *data;

}
template <typename T>
List<T>& List<T>::push_back(const T& value)
{
    this->append_el(value);
    return *this;
}
template <typename T>
List<T>& List<T>::push_front(const T& value)
{
    time_t t_time;
    t_time = time(NULL);
    try
    {
        std::shared_ptr<Node<T>> node = std::shared_ptr<Node<T>>(new Node<T>);
        node->set_obj(value);
        if (!this->head)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            node->set_next(this->head);
            this->head = node;
        }
        this->len++;
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
    }
    return *this;
}

template <typename T>
List<T>::~List()
{
    this->free();
}

template <typename T>
List<T>& List<T>::append(std::shared_ptr<Node<T>> node)
{
    if (!this->head)
    {
        this->head = node;
        this->tail = node;
        this->len++;
        return *this;
    }
    this->tail->set_next(node);
    this->tail = node;
    this->len++;
    return *this;
}
template <typename T>
List<T> &List<T>::append_list(const List<T>& list)
{
    time_t t_time;
    t_time = time(NULL);
    std::shared_ptr<Node<T>> tmp = list.head;
    while(tmp)
    {
        try
        {
            std::shared_ptr<Node<T>> node = std::shared_ptr<Node<T>>(new Node<T>);
            node->set_obj(tmp->get_obj());
            this->append(node);
        }
        catch (std::bad_alloc)
        {
            throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
        }
        tmp = tmp->get_next();
    }
    return *this;
}

template <typename T>
List<T>& List<T>::append_el(const T& elem)
{
    time_t t_time;
    t_time = time(NULL);
    try
    {
        std::shared_ptr<Node<T>>node = std::shared_ptr<Node<T>>(new Node<T>);
        node->set_obj(elem);
        this->append(node);
    }
    catch (std::bad_alloc)
    {
        throw memory_allocate_exception(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Allocation error");
    }

    return *this;
}

template <typename T>
void List<T>::free()
{
    std::shared_ptr<Node<T>> node;
    while (this->head != nullptr)
    {
        node = this->head->get_next();
        this->head.reset();
        this->head = node;
    }
}

template <typename T>
List<T>& List<T>::InsertAfter(std::shared_ptr<Node<T>> node, list_iterator<T>& insert_after)
{
    node->next = insert_after->get_next();
    insert_after->set_next(node);
    this->len++;
    return *this;
}
#endif // LIST_IMPLEMENT_H
