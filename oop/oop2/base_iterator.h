#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H
#include <memory>
#include "exceptions.h"
#include <time.h>
#include "node.h"

namespace iterator
{
    template<typename T>
    class base_iterator
    {
    public:
        base_iterator(const base_iterator<T>&);
        base_iterator(std::shared_ptr<Node<T>> ptr);
        base_iterator(std::weak_ptr<Node<T>> ptr);
        virtual ~base_iterator();

        base_iterator<T>&operator =(const base_iterator<T>&);

        base_iterator<T>& operator ++();
        base_iterator<T> operator ++(int);

        operator bool() const;
        bool operator ==(const base_iterator<T>&) const;
        bool operator !=(const base_iterator<T>&) const;
    protected:
        std::weak_ptr<Node<T>> ptr;
    };
}


#include "base_iterator_implement.h"
#endif // BASE_ITERATOR_H
