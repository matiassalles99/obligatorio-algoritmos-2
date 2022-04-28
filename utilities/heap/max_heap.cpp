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
        this->top = 0;
        this->capacity = capacity;
        this->array = new int[this->capacity + 1];
    }

    void insert(T value)
    {
        this->top++;
        this->array[this->top] = value;
        this->swim(this->array, this->top);
    }

    T pullMax()
    {
        int max = this->array[1];
        this->top--;
        this->array[1] = this->array[this->top];
        sink(this->array, 1);
        return max;
    }

private:
    void swim(int *array, int position)
    {
        if (position > 1 && array[position / 2] < array[position])
        {
            int swap = array[position / 2];
            array[position / 2] = array[position];
            array[position] = swap;
            swim(array, position / 2);
        }
    }

    void sink(int *array, int position)
    {
        int swap = array[position];
        while (2 * position <= this->top)
        {
            int son = 2 * position;
            if (son + 1 <= this->top && array[son] < array[son + 1])
                son++;

            if (swap < array[son])
            {
                array[position] = array[son];
                position = son;
            }
            else
                break;
        }
        array[position] = swap;
    }
};