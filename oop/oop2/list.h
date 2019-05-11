#ifndef LIST_H
#define LIST_H

#include "base_container.h"
#include "list_iterator_implement.h"
#include "const_list_iterator_implement.h"
#include "node.h"
#include "exceptions.h"
#include <time.h>
#include <typeinfo>
#include <memory>

template <typename T>
class List : public container::base_container
{
public:
    List(): head(nullptr), tail(nullptr){}
    List(T* array, int n);
    List(const List<T> &list);
    List(List<T> && list);
    List(std::initializer_list<T> lst);

    virtual ~List();
    List<T>& operator =(const List<T> &list);
    List<T>& operator =(List<T> &&list);
    List<T>& operator =(std::initializer_list<T> lst);

    List<T> unite(const List<T> &list) const;
    List<T> operator +(const List<T> &list) const;

    List<T> unite(const T &value) const;
    List<T> operator +(const T &value) const;

    List<T>& append(const List<T>& list);
    List<T>& operator +=(const List<T> &list);

    List<T>& append(const T& elem);
    List<T>& operator +=(const T &value);

    List<T>& push_back(const T& value);
    List<T>& push_front(const T& value);

    List<T>& InsertAfter(const T& el, list_iterator<T>& insert_after);
    List<T>& InsertAfter(const List<T> &list, list_iterator<T>& insert_after);

    bool compare(const List<T>& list) const;
    bool operator ==(const List<T> &list) const;
    bool operator !=(const List<T> &list) const;

    //итераторы
    list_iterator<T> begin();
    list_iterator<T> end();
    const_list_iterator<T> begin() const;
    const_list_iterator<T> end() const;

    void clear();

    List<T>& remove(list_iterator<T>& iter);
    T& pop_front();

    bool is_empty();
    size_t lenght() const;

    T& first();
    const T& first() const;
    T& last();
    const T& last() const;

    //T** to_array(size_t &size);
protected:
    List<T>& append_list(const List<T>& list);
    List<T>& append_el(const T& elem);
    List<T>& append(std::shared_ptr<Node<T>> el);
    List<T>& InsertAfter(std::shared_ptr<Node<T>> el, list_iterator<T>& insert_after);
    void free();

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

#endif // LIST_H
