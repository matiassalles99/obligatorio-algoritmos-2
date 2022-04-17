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
        cout << "Constructor" << endl;
        this->array = new List<NodeStructure>[size];
        this->size = size;
        this->hashFunction = hashFunction;
    }

    void insert(Key key, Value value)
    {
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> list = this->array[position];
        list.insert(*(new NodeStructure(key, value)));

        cout << "ACA INSERT SIZE" << list.size << "position " << position << endl;
        cout << "Memory " << &list << endl;
        list.print();
        cout << endl;
    }

    void remove(Key key)
    {
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> list = this->array[position];
        list.remove(*(new NodeStructure(key, NULL)));
    }

    bool exists(Key key)
    {
        int position = this->hashFunction(key) % this->size;
        List<NodeStructure> list = this->array[position];

        cout << "ACA EXISTS"
             << "position " << position << endl;
        cout << "Size " << list.size << endl;
        cout << "Memory " << &list << endl;
        list.print();
        return list.exists(*(new NodeStructure(key, NULL)));
    }

    void imprimir()
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
