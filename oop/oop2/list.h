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
    List<T>& operator +(const T &value);
    List<T>& operator +=(const List<T> &list);
    List<T>& operator +=(const T &value);

    List<T>& operator [](const int i);
    List<T>& operator [](const int i) const;

    bool operator ==(const List<T> &list) const;
    bool operator !=(const List<T> &list) const;

    List<T>& operator <<(const List<T> &list);
    List<T>& operator <<(const T &value);

    T* to_array(size_t &size);


    //итераторы
    list_iterator<T> begin();
    list_iterator<T> end();
    const_list_iterator<T> begin() const;
    const_list_iterator<T> end() const;

    void append(const List<T>& list);
    void append(const T& elem);
    void remove(const T& elem);

    void clear();
    int compare(const List<T>& list);

    void InsertAfter(const T& el, list_iterator<T>& insert_after);
    void remove(list_iterator<T>& iter);

    bool is_empty();
    size_t size() const;
    size_t lenght() const;
    size_t count(const T& value);

    T& first();
    const T& first() const;
    T& last();
    const T& last() const;
    T& pop_back();
    T& pop_front();
    void push_back(const T& value);
    void push_front(const T& value);

    void sort();
    void reverse();


    //T value(int i) const;
    //const T& at(int i) const;


    ~List();
private:
    Node<T> *head;
    Node<T> *tail;
};

#endif // LIST_H
