#ifndef EJERCICIO_5
#define EJERCICIO_5

#include <string>
#include <iostream>

#include "../utilities/graph/undirectedListGraph.cpp"

using namespace std;

const char SEPARATOR = ' ';

bool * initVisited(int N)
{
    bool * visited = new bool [N+1];
    for (int n = 1; n <= N; n++) 
    {
        visited[n] = false;
    }
    return visited;
}

void limit_DFS(UndirectedListGraph * graph, int origin, int n_limit, bool * &visited)
{
    if (origin == n_limit) 
        return;
    
    visited[origin] = true;
    List<Edge> adjacencies = graph->adjacencies(origin);
    
    while (adjacencies.head != NULL)
    {
        int n_adj = adjacencies.head->value.destiny;
        if(!visited[n_adj])
        {
            limit_DFS(graph, n_adj, n_limit, visited);
        }
        adjacencies.head = adjacencies.head->next;
    }
}

bool existsFalse(bool *visited, int limit_n, int N)
{
    for (int n = 1; n <= N; n++)
    {
        if (!visited[n] && n != limit_n)
        {
            return true;
        }
    }
    return false;
}

bool isJointPoint(UndirectedListGraph * graph, int n_limit, int N)
{
    bool * visited = initVisited(N);
    List<Edge> adjacencies = graph->adjacencies(n_limit);
    int n_adj = adjacencies.head->value.destiny;
    limit_DFS (graph, n_adj, n_limit, visited);
    return existsFalse (visited, n_limit, N);
}

int main()
{
    string input;
    int N;
    int E;

    cin >> N;
    cin >> E;
    cin.ignore();

    UndirectedListGraph * graph = new UndirectedListGraph(N, false);

    for (int e = 0; e < E ; e++)
    {
        getline(cin, input);
        int separatorIndex = input.find(SEPARATOR);

        int origin = stoi(input.substr(0, separatorIndex));
        int destiny = stoi(input.substr(separatorIndex + 1));

        graph -> addEdge(origin, destiny, 1);
    }

    for (int n = 1; n <= N ; n++)
    {
        if (isJointPoint(graph, n, N))
        {
            cout << n << endl;
        }
    }

    return 1;
}

#endif