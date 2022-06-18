#ifndef EJERCICIO_3
#define EJERCICIO_3

#include <iostream>
#include <string>
#include "./utilities/heap/max_heap.cpp"

using namespace std;

int main()
{
  int maxElementsToFind;
  int amountOfElements;

  cin >> maxElementsToFind;
  cin >> amountOfElements;

  MaxHeap<int> *heap = new MaxHeap<int>(amountOfElements);

  for (int i = 0; i < amountOfElements; i++)
  {
    int value;
    cin >> value;

    heap->insert(value);
  };

  for (int i = 0; i < maxElementsToFind; i++)
  {
    cout << heap->pullMax() << endl;
  }
  
  return 1;
};

#endif
