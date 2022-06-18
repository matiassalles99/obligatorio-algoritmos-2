#ifndef MATRIX_GRAPH
#define MATRIX_GRAPH

class UndirectedUnweightedMatrixGraph
{

private:
  bool **matrix;
  int N;
  int E;

public:
  UndirectedUnweightedMatrixGraph(int N)
  {
    this->N = N;
    this->E = 0;

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
    this->E ++;
  }

  bool **getMatrix()
  {
    return this->matrix;
  }

  int amountNodes()
  {
    return this->N;
  }

  int amountEdges()
  {
    return this->E;
  }
};

#endif