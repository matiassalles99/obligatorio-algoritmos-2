#ifndef OPEN_HASH_TABLE
#define OPEN_HASH_TABLE

#include <iostream>
#include "../list/list.cpp"
using namespace std;

template <typename Key, typename Value>
class OpenHashTable
{
public:
    OpenHashTable(int size, int (*hashFunction)(Key))
    {
        this->array = new List<NodeStructure>[size]();
        this->size = size;
        this->hashFunction = hashFunction;
    }

    void insert(Key key, Value value)
    {
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> *list = &(this->array[position]);
        list->insertLast(*(new NodeStructure(key, value)));
    }

    void remove(Key key)
    {
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> *list = &(this->array[position]);
        list->remove(*(new NodeStructure(key, Value())));
    }

    bool exists(Key key)
    {
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> *list = &(this->array[position]);
        return list->exists(*(new NodeStructure(key, Value())));
    }

    Value retrieveValue(Key key)
    {
        assert(this->exists(key));
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> *list = &(this->array[position]);
        NodeStructure retrievedNode = list->retrieveValue(*(new NodeStructure(key, Value())));
        return retrievedNode.value;
    }

    void update(Key key, Value value)
    {
        assert(this->exists(key));
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> *list = &(this->array[position]);
        list->update(*(new NodeStructure(key, value)));
    }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << "[ ] ->";
            List<NodeStructure> list = this->array[i];
            list.print();
            cout << " nl" << endl;
        }
    }

private:
    class NodeStructure
    {
    public:
        Key key;
        Value value;

        NodeStructure(Key key, Value value) : key(key), value(value) {}

        bool operator==(const NodeStructure &other) const
        {
            return key == other.key;
        }

        bool operator!=(const NodeStructure &other) const
        {
            return !(*this == other);
        }

        friend ostream &operator<<(ostream &os, NodeStructure const &v)
        {
            cout << "Key: " << v.key << " Value: " << v.value;
            return os;
        }
    };

    List<NodeStructure> *array;
    int size;
    int (*hashFunction)(Key);
};

#endif
