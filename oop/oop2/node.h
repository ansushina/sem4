#ifndef NODE_H
#define NODE_H
#include <memory>

template<typename Key>
class Node
{
private:
    Key key;
    std::shared_ptr<Node<Key>> next;


public:
    Node():
        next(nullptr)
    {}
    Node(Key &key):
        key(key),
        next(nullptr)
    {}
    ~Node(){}
    const Key& get_obj() const
    {
        return this->key;
    }
    Key& get_obj()
    {
        return this->key;
    }
    void set_obj(const Key &key)
    {
        this->key = key;
    }

    void set_next(std::shared_ptr<Node<Key>>next)
    {
        this->next = next;
    }

    std::shared_ptr<Node<Key>> get_next() const
    {
        return next;
    }

};

#endif // NODE_H
