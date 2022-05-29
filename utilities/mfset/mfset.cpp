#ifndef MF_SET
#define MF_SET

#include <iostream>
using namespace std;

class MFSet
{
private:
    int *sets;
    int size;

public:
    MFSet(int numberOfElements)
    {
        this->sets = new int[numberOfElements + 1];
        this->size = numberOfElements + 1;
        for (int i = 0; i < this->size; i++)
        {
            this->sets[i] = i;
        }
    }

    int find(int n)
    {
        int father = this->sets[n];
        if (father != n)
        {
            return find(father);
        }   
        return father;
    }

    void merge(int firstElement, int secondElement)
    {
        int firstElementSet = find(firstElement);
        int secondElementSet = find(secondElement);

        if (firstElementSet != secondElementSet)
        {
            this->sets[secondElementSet] = firstElementSet;
        }
    }

    int amountConnectedComponents()
    {
        int amount = 0;
        for (int i = 1; i < this->size; i++)
        {
            if (this->sets[i] == i)
            {
                amount++;
            }
        }
        return amount;
    }

    void print()
    {
        for (int n = 1; n < this->size; n++)
        {
            cout << this->sets[n] << " ";
        }
        cout << endl;
    }
};

#endif