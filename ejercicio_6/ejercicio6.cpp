#ifndef EJERCICIO_6
#define EJERCICIO_6

#include <string>
#include <iostream>

using namespace std;

const char SEPARATOR = ' ';

class MatrixGraph
{

private:
    bool ** matrix;
    int N;

public:
    MatrixGraph(int N)
    {
        this->N = N;

        matrix = new bool * [N+1];
        for (int v = 1; v <= N; v++){
            matrix[v] = new bool [N+1];
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

    bool ** getMatrix()
    {
        return this->matrix;
    }

    int amountNodes()
    {
        return this->N;
    }
};

bool ** warshall(MatrixGraph * graph)
{
    bool ** matrix = graph -> getMatrix(); 
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

    MatrixGraph * graph = new MatrixGraph(N);

    for (int e = 0; e < E ; e++)
    {
        getline(cin, input);
        int separatorIndex = input.find(SEPARATOR);

        int origin = stoi(input.substr(0, separatorIndex));
        int destiny = stoi(input.substr(separatorIndex + 1));

        graph -> addEdge(origin, destiny);
    }

    bool ** transitiveClosureMatrix = warshall(graph);

    for (int v = 1; v <= N; v ++)
    {
        int w;
        for (w = 1; w <= N && transitiveClosureMatrix[v][w]; w++);
        if (w == N+1)
        {
            cout << v << endl;
        }
    }

    return 1;
}
#endif
