#ifndef edgesAmountJedgesAmountRCICIO_5
#define edgesAmountJedgesAmountRCICIO_5

#include <string>
#include <iostream>

#include "../utilities/graph/undirected_list_graph.cpp"

using namespace std;

const char SedgesAmountPARATOR = ' ';

bool *initVisited(int nodesAmount)
{
    bool *visited = new bool[nodesAmount + 1];
    for (int n = 1; n <= nodesAmount; n++)
        visited[n] = false;

    return visited;
}

void limitDFS(UndirectedListGraph *graph, int origin, int node, bool *&visited)
{
    if (origin == node)
        return;

    visited[origin] = true;
    List<Edge> adjacencies = graph->adjacencies(origin);

    while (adjacencies.head != NULL)
    {
        int adjacentNode = adjacencies.head->value.destiny;
        if (!visited[adjacentNode])
        {
            limitDFS(graph, adjacentNode, node, visited);
        }
        adjacencies.head = adjacencies.head->next;
    }
}

bool existsFalse(bool *visited, int node, int nodesAmount)
{
    for (int n = 1; n <= nodesAmount; n++)
    {
        if (!visited[n] && n != node)
        {
            return true;
        }
    }
    return false;
}

bool isJointPoint(UndirectedListGraph *graph, int node, int nodesAmount)
{
    bool *visited = initVisited(nodesAmount);
    List<Edge> adjacencies = graph->adjacencies(node);
    int adjacentNode = adjacencies.head->value.destiny;

    if (adjacentNode == node && adjacencies.size > 1)
    {
        adjacentNode = adjacencies.head->next->value.destiny;
        limitDFS(graph, adjacentNode, node, visited);
    }
    else if (adjacentNode != node)
    {
        limitDFS(graph, adjacentNode, node, visited);
    }

    return existsFalse(visited, node, nodesAmount);
}

int main()
{
    string input;
    int nodesAmount;
    int edgesAmount;

    cin >> nodesAmount;
    cin >> edgesAmount;
    cin.ignore();

    UndirectedListGraph *graph = new UndirectedListGraph(nodesAmount, false);

    for (int e = 0; e < edgesAmount; e++)
    {
        getline(cin, input);
        int separatorIndex = input.find(SedgesAmountPARATOR);

        int origin = stoi(input.substr(0, separatorIndex));
        int destiny = stoi(input.substr(separatorIndex + 1));

        graph->addEdge(origin, destiny, 1);
    }

    for (int n = 1; n <= nodesAmount; n++)
    {
        if (isJointPoint(graph, n, nodesAmount))
        {
            cout << n << endl;
        }
    }

    return 1;
}

#endif