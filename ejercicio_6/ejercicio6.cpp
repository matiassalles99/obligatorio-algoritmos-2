#ifndef EJERCICIO_6
#define EJERCICIO_6

#include <string>
#include <iostream>
#include "../utilities/graph/matrix_graph.cpp"

using namespace std;

const char SEPARATOR = ' ';

bool **warshall(MatrixGraph *graph)
{
    bool **matrix = graph->getMatrix();
    int N = graph->amountNodes();

    for (int k = 1; k <= N; k++)
    {
        for (int v = 1; v <= N; v++)
        {
            for (int w = 1; w <= N; w++)
            {
                matrix[v][w] = matrix[v][w] || matrix[v][k] && matrix[k][w];
            }
        }
    }

    for (int n = 1; n <= N; n++)
    {
        matrix[n][n] = true;
    }

    return matrix;
}

int main()
{
    string input;
    int N;
    int E;

    cin >> N;
    cin >> E;
    cin.ignore();

    MatrixGraph *graph = new MatrixGraph(N);

    for (int e = 0; e < E; e++)
    {
        getline(cin, input);
        int separatorIndex = input.find(SEPARATOR);

        int origin = stoi(input.substr(0, separatorIndex));
        int destiny = stoi(input.substr(separatorIndex + 1));

        graph->addEdge(origin, destiny);
    }

    bool **transitiveClosureMatrix = warshall(graph);

    for (int v = 1; v <= N; v++)
    {
        int w;
        for (w = 1; w <= N && transitiveClosureMatrix[v][w]; w++)
            ;
        if (w == N + 1)
        {
            cout << v << endl;
        }
    }

    return 1;
}
#endif
