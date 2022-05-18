#ifndef MATRIX_GRAPH
#define MATRIX_GRAPH

class MatrixGraph
{

private:
  bool **matrix;
  int N;

public:
  MatrixGraph(int N)
  {
    this->N = N;

    matrix = new bool *[N + 1];
    for (int v = 1; v <= N; v++)
    {
      matrix[v] = new bool[N + 1];
      for (int w = 1; w <= N; w++)
      {
        matrix[v][w] = false;
      }
    }
  }

  void addEdge(int origin, int destiny)
  {
    matrix[origin][destiny] = true;
  }

  bool **getMatrix()
  {
    return this->matrix;
  }

  int amountNodes()
  {
    return this->N;
  }
};

#endif