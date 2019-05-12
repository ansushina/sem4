#ifndef CONST_LIST_ITERATOR_H
#define CONST_LIST_ITERATOR_H
#include "base_iterator.h"
using namespace iterator;
template <typename T>
class const_list_iterator : public base_iterator<T>
{
public:
    const_list_iterator(const const_list_iterator<T>&);
    const_list_iterator(std::shared_ptr<Node<T>>);

    const T& operator *() const;
    const std::shared_ptr<Node<T>> operator ->() const;
};

#include"const_list_iterator_implement.h"
#endif // CONST_LIST_ITERATOR_H
