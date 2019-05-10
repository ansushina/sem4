#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
#include "base_iterator_implement.h"
using namespace iterator;
template<typename T>
class list_iterator : public base_iterator<T>
{
public:
    list_iterator(const list_iterator<T>&);
    list_iterator(std::shared_ptr<Node<T>> ptr);
    T& operator *();
    std::shared_ptr<Node<T>> operator ->();
    const T &operator *() const;
    const std::shared_ptr<Node<T>>  operator ->() const;
};

#endif // LIST_ITERATOR_H
