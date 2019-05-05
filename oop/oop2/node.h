#ifndef NODE_H
#define NODE_H


template<typename Key>
class Node
{
private:
    Key key;
    Node<Key> *next;
    Node<Key> *prev;

public:
    Node():
        next(nullptr),
        prev(nullptr)
    {}
    Node(Key &key):
        key(key),
        next(nullptr),
        prev(nullptr)
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

    void set_next(Node<Key> *next)
    {
        this->next = next;
    }
    void set_prev(Node<Key> *prev)
    {
        this->prev = prev;
    }

    Node<Key> *get_next() const
    {
        return next;
    }
    Node<Key> *get_prev() const
    {
        return prev;
    }
};

#endif // NODE_H
