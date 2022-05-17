#ifndef EJERCICIO_4
#define EJERCICIO_4

#include "../utilities/graph/listGraph.cpp"

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

void DFS(ListGraph * graph, int origin, bool * &visited)
{
    visited[origin] = true;
    List<Edge> adjacencies = graph->adjacencies(origin);
    
    while (adjacencies.head != NULL)
    {
        int n_adj = adjacencies.head->value.destiny;
        if(!visited[n_adj])
        {
            DFS(graph, n_adj, visited);
        }
        adjacencies.head = adjacencies.head->next;
    }
}

int amountConnectedComponents(ListGraph * graph)
{
    int N = graph->amountNodes();
	bool * visited = initVisited(N);
	int amount = 0;

	for (int n = 1; n <= N; n++)
    {
        if (!visited[n])
        {   
            DFS(graph, n, visited);
		    amount ++;
        }
    }

	return amount;
}
	
int main()
{
    string input;
    int N;
    int E;

    cin >> N;
    cin >> E;
    cin.ignore();

    ListGraph * graph = new ListGraph (N, false, false);

    for (int e = 1; e <= E ; e++)
    {
        getline(cin, input);
        int separatorIndex = input.find(SEPARATOR);

        int origin = stoi(input.substr(0, separatorIndex));
        int destiny = stoi(input.substr(separatorIndex + 1));

        graph->addEdge(origin, destiny, 1);
    }

    cout << amountConnectedComponents(graph) << endl; 

    return 1;
}

#endif