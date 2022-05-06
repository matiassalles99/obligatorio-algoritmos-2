#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MaxHeap
{
private:
    int top;
    int capacity;
    int *array;

public:
    MaxHeap(int capacity)
    {
        this->top = 1;
        this->capacity = capacity;
        this->array = new int[this->capacity + 1];
    }

    void insert(T value)
    {
        this->top++;
        this->array[this->top] = value;
        this->swim(this->top);
    }

    T pullMax()
    {
        int max = this->array[1];
        this->top--;
        this->array[1] = this->array[this->top];
        sink(1);
        return max;
    }

private:
    void swim(int position)
    {
        if (position > 1 && this->array[position / 2] < this->array[position])
        {
            int swap = this->array[position / 2];
            this->array[position / 2] = this->array[position];
            this->array[position] = swap;
            swim(position / 2);
        }
    }

    void sink(int position)
    {
        int swap = this->array[position];
        while (2 * position < this->top)
        {
            int son = 2 * position;
            if (son + 1 < this->top && this->array[son] < this->array[son + 1])
                son++;

            if (swap < this->array[son])
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