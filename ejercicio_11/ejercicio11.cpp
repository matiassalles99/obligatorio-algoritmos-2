#ifndef EJERCICIO_11
#define EJERCICIO_11

#include <iostream>
using namespace std;

int M, N, K, P;
int **matrix;
int movY[] = {0, -1, 0, 1};
int movX[] = {-1, 0, 1, 0};

void initializeMatrix()
{
  matrix = new int *[M + 1];

  for (int i = 1; i <= M; i++)
  {
    matrix[i] = new int[N + 1];
  }

  for (int j = 1; j <= N; j++)
  {
    for (int i = 1; i <= M; i++)
    {
      cin >> matrix[i][j];
    }
  }
}

void initializedVisited(bool **visited)
{
  for (int i = 1; i <= M; i++)
  {
    visited[i] = new bool[N + 1];
  }
  for (int j = 1; j <= N; j++)
  {
    for (int i = 1; i <= M; i++)
    {
      visited[i][j] = false;
    }
  }
}

bool isPositionValid(int x, int y)
{
  return (x <= M && x > 0 && y <= N && y > 0 && matrix[x][y] != 0);
}

void mazeBacktracking(int Xi, int Yi, int Xf, int Yf, int &optimalSum, int currentSum,
                      bool **visited)
{
  if (Xi == Xf && Yi == Yf)
  {
    if (currentSum < optimalSum)
    {
      optimalSum = currentSum;
    }
  }
  else
  {
    for (int i = 0; i < 4; i++)
    {
      int x = Xi + movX[i];
      int y = Yi + movY[i];
      if (isPositionValid(x, y) && !visited[x][y] && currentSum + matrix[x][y] < K)
      {
        visited[x][y] = true;
        int sumaLocal = currentSum + matrix[x][y];
        mazeBacktracking(x, y, Xf, Yf, optimalSum, sumaLocal, visited);
        visited[x][y] = false;
      }
    }
  }
}

void maze(int Xi, int Yi, int Xf, int Yf)
{
  int currentSum = matrix[Xi][Yi];
  int optimalSum = INT_MAX;
  bool **visited = new bool *[M];
  initializedVisited(visited);
  visited[Xi][Yi] = true;

  mazeBacktracking(Xi, Yi, Xf, Yf, optimalSum, currentSum, visited);
  cout << optimalSum << endl;
}

int main()
{
  cin >> M >> N >> K;
  initializeMatrix();

  cin >> P;

  while (P > 0)
  {
    int Xi, Yi, Xf, Yf;
    cin >> Xi >> Yi >> Xf >> Yf;

    maze(Xi, Yi, Xf, Yf);
    P--;
  }
}

#endif