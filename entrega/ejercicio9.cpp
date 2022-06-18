#ifndef EJERCICIO_9
#define EJERCICIO_9

#include <iostream>
using namespace std;

int main()
{
  int max, cases, N, K;
  unsigned long *arr;

  cin >> max;
  cin >> cases;

  arr = new unsigned long[max + 1];

  for (int i = 1; i <= max; i++)
  {
    arr[i] = 0;
  }

  arr[0] = 1;
  int row = 1;

  for (int i = 0; i < cases; i++)
  {
    cin >> N;
    cin >> K;

    while (row <= N)
    {
      for (int i = row; i > 0; i--)
      {
        arr[i] = arr[i] + arr[i - 1];
      }
      row++;
    }

    cout << arr[K] << endl;
  }
}

#endif