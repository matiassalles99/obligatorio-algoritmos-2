#ifndef EJERCICIO_4
#define EJERCICIO_4

#include "../utilities/graph/listGraph.cpp"
#include "../utilities/graph/mfset.cpp"
#include "../utilities/heap/max_heap.cpp"
using namespace std;

const char SEPARATOR = ' ';

MFSet * kruskal(ListGraph * graph)
{
    int N = graph->amountNodes();
    int E = graph->amountEdges();

    MFSet * mfset = new MFSet(N); 
	
	for (int n = 1; n <= N ; n++)
    {
        List<Edge> adjacencies_n = graph->adjacencies(n);
        List<Edge> unvisited_edges_n = adjacencies_n.clone();
        int edges_origin_n = adjacencies_n.size-1;
		
        for (int e = 0; e < edges_origin_n; e++)
        {
            Edge limit_e = unvisited_edges_n.pullTailValue();

            int origin_representative = mfset->find(limit_e.origin);
            int destiny_representative = mfset->find(limit_e.destiny);
            if (origin_representative != destiny_representative)
            {
                mfset->merge(origin_representative, destiny_representative);
		    }
        }
    }

    return mfset;
}

int main()
{
    string input;
    int N;
    int E;

    cin >> N;
    cin >> E;
    cin.ignore();

    ListGraph * graph = new ListGraph(N, false, false);

    for (int e = 0; e < E ; e++)
    {
        getline(cin, input);
        int separatorIndex = input.find(SEPARATOR);

        int origin = stoi(input.substr(0, separatorIndex));
        int destiny = stoi(input.substr(separatorIndex + 1));

        graph->addEdge(origin, destiny, 1);
    }

    MFSet * mfset = kruskal(graph);
    cout << mfset -> amountConnectedComponents(N) << endl;

    return 1;
}

#endif