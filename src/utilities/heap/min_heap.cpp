#ifndef MIN_HEAP
#define MIN_HEAP

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MinHeap
{
private:
    int top;
    int capacity;
    T *array;

public:
    MinHeap(int capacity)
    {
        this->top = 1;
        this->capacity = capacity;
        this->array = new T[this->capacity + 1];
    }

    bool isEmpty()
    {
        return this->top == 1;
    }

    void insert(T value)
    {
        this->array[this->top] = value;
        this->swim(this->top);
        this->top++;
    }

    T pullMin()
    {
        T min = this->array[1];
        this->array[1] = this->array[this->top - 1];
        this->top--;
        sink(1);
        return min;
    }

    T min()
    {
        return this->array[1];
    }

private:
    void swim(int position)
    {
        if (position > 1 && this->array[position / 2] > this->array[position])
        {
            T swap = this->array[position / 2];
            this->array[position / 2] = this->array[position];
            this->array[position] = swap;
            swim(position / 2);
        }
    }

    void sink(int position)
    {
        T swap = this->array[position];
        while (2 * position < this->top)
        {
            int son = 2 * position;
            if (son + 1 < this->top && this->array[son] > this->array[son + 1])
                son++;

            if (swap > this->array[son])
            {
                this->array[position] = this->array[son];
                position = son;
            }
            else
                break;
        }
        this->array[position] = swap;
    }
};

#endif