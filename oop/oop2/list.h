#ifndef LIST_H
#define LIST_H

#include "base_container.h"

template<typename T>
struct Node
{
    Node(): next(nullptr){}
    Node(T &key): key(key), next(nullptr){}
    ~Node() {}

    T key;
    Node *next;
};

template <typename T>
class List : public container::base_container
{
public:
    List();
    List(Node<T> *list);
    List(T* array);
    List(const List<T> &list);
    List(List<T> && list);
    //List(std::initializer_list<std::initializer_list<T>> lst);

    List<T>& operator =(const List<T> &list);
    List<T>& operator =(List<T> &list);
    //List<T>& operator =(std::initializer_list<std::initializer_list<T>> lst);

    List<T>& operator +(const List<T> &list);
    List<T>& operator [](const int i);

    //push_back;
    //pop_back;
    //operator ==
    //operator !=
    //operator <=
    // operator >=
    //operator >
    //operator <
    //clear
    // insert
    //swap
    //size
    //front
    //back
    //at
    //data
    //is_empty
    //*num
    // //num
    // +num
    // -num
    //




    ~List();
};

#endif // LIST_H
