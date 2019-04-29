#ifndef LIST_H
#define LIST_H

#include "base_container.h"
#include "list_iterator.h"
#include "const_list_iterator.h"
#include "node.h"

template <typename T>
class List : public container::base_container
{
public:
    List(): head(nullptr), tail(nullptr){}
    List(Node<T> *list);
    List(T* array, int n);
    List(const List<T> &list);
    List(List<T> && list);
    //List(std::initializer_list<std::initializer_list<T>> lst);

    // операторы
    List<T>& operator =(const List<T> &list);
    List<T>& operator =(List<T> &&list);


    List<T>& operator +(const List<T> &list) const;
    List<T>& operator +=(const List<T> &list);
    List<T>& operator +=(const T &value);

    List<T>& operator [](const int i);
    List<T>& operator [](const int i) const;

    List<T>& operator ==(const List<T> &list) const;
    List<T>& operator !=(const List<T> &list) const;

    List<T>& operator <<(const List<T> &list);
    List<T>& operator <<(const T &value);


    //итераторы
    list_iterator<T> begin();
    list_iterator<T> end();
    const_list_iterator<T> begin() const;
    const_list_iterator<T> end() const;

    //push_back;
    //pop_back;
    //clear
    //insert
    //swap
    //size
    //front
    //back
    //at
    //data
    //is_empty
    //*num
    // num
    // +num





    ~List();
private:
    Node<T> *head;
    Node<T> *tail;
};

#endif // LIST_H
