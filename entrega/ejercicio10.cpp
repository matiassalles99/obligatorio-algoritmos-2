#ifndef EJERCICIO_10
#define EJERCICIO_10

#include <iostream>
using namespace std;

int numberOfElements, M, cases, Mi;
int **matrix;
int *set;

void loadMatrix()
{
  matrix = new int *[numberOfElements + 1];
  for (int i = 0; i <= numberOfElements; i++)
  {
    matrix[i] = new int[M + 1];
    for (int j = 0; j <= M; j++)
    {
      matrix[i][j] = -1;
    }
  }

  for (int x = 0; x <= numberOfElements; x++)
  {
    matrix[x][0] = 1;
  }

  for (int y = 1; y <= M; y++)
  {
    matrix[0][y] = 0;
  }

  for (int n = 1; n <= numberOfElements; n++)
  {
    for (int m = 1; m <= M; m++)
    {
      if (n == 0 && m > 0)
      {
        matrix[n][m] = 0;
      }
      else if (n >= 0 && m == 0)
      {
        matrix[n][m] = 1;
      }
      else if (n > 0 && m > 0 && set[n] <= m)
      {
        matrix[n][m] = matrix[n - 1][m] || matrix[n - 1][m - set[n]];
      }
      else
      {
        matrix[n][m] = matrix[n - 1][m];
      }
    }
  }
}

int main()
{
  cin >> numberOfElements;

  set = new int[numberOfElements + 1];
  for (int i = 1; i <= numberOfElements; i++)
  {
    cin >> set[i];
  }
  cin >> M;
  loadMatrix();

  cin >> cases;

  while (cases > 0)
  {
    cin >> Mi;
    if (cases == 1)
      cout << matrix[numberOfElements][Mi];
    else
      cout << matrix[numberOfElements][Mi] << endl;

    cases--;
  }
}

#endif