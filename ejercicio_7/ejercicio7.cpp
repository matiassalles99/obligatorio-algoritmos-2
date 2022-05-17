#ifndef EJERCICIO_7
#define EJERCICIO_7

#include <string>
#include <iostream>

#include "../utilities/graph/undirectedListGraph.cpp"
#include "../utilities/graph/mfset.cpp"
#include "../utilities/heap/min_heap.cpp"

using namespace std;

const char SEPARATOR = ' ';

int minimumTreeCoverCharge(int N, MinHeap<Edge> * heap)
{
    int charge = 0;
    MFSet * mfset = new MFSet(N);

    while (!heap->isEmpty())
    {
        Edge min_e = heap->pullMin();
        int origin_representative = mfset->find(min_e.origin);
        int destiny_representative = mfset->find(min_e.destiny);
        if (origin_representative != destiny_representative)
        {
            charge += min_e.charge;
            mfset->merge(min_e.origin, min_e.destiny);
        }
    }

    if (mfset->amountConnectedComponents(N) > 1)
    {
        return -1;
    }
    
    return charge;
}

int main(){

    string input;
    int N;
    int E;

    cin >> N;
    cin >> E;
    cin.ignore();

    UndirectedListGraph * graph = new UndirectedListGraph(N, true);

    for (int e = 0; e < E ; e++)
    {
        getline(cin, input);
        int fstSeparatorIndex = input.find(SEPARATOR);

        string s_origin = input.substr(0, fstSeparatorIndex);
        int origin = stoi(s_origin);
        
        string after_origin_input = input.substr(fstSeparatorIndex + 1);
        int sndSeparatorIndex = after_origin_input.find(SEPARATOR);

        string s_destiny = input.substr(fstSeparatorIndex + 1, sndSeparatorIndex);
        int destiny = stoi(s_destiny);

        string s_charge = input.substr(sndSeparatorIndex + 1);
        int charge = stoi(s_charge);

        graph -> addEdge(origin, destiny, charge);
    }

    int max_amountOfElements = N * N;
    MinHeap<Edge> *heap = new MinHeap<Edge>(max_amountOfElements);

    for (int n = 0; n < E; n ++)
    {
        List<Edge> adjacencies_n = graph->adjacencies(n);
        for (int e = 0; e < adjacencies_n.size; e++)
        {
            heap->insert(adjacencies_n.pullTailValue());
        }
    }

    int totalCharge = minimumTreeCoverCharge(N, heap);
    cout << totalCharge;

    return 1;
}

#endif