#ifndef EJERCICIO_7
#define EJERCICIO_7

#include <string>
#include <iostream>

#include "./utilities/graph/undirected_list_graph.cpp"
#include "./utilities/mfset/mfset.cpp"
#include "./utilities/heap/min_heap.cpp"

using namespace std;

const char SEPARATOR = ' ';

int minimumTreeCoverCharge(int N, MinHeap<Edge> *heap)
{
    int charge = 0;
    MFSet *mfset = new MFSet(N);

    while (!heap->isEmpty())
    {
        Edge minEdge = heap->pullMin();
        int originRepresentative = mfset->find(minEdge.origin);
        int destinyRepresentative = mfset->find(minEdge.destiny);
        if (originRepresentative != destinyRepresentative)
        {
            charge += minEdge.charge;
            mfset->merge(minEdge.origin, minEdge.destiny);
        }
    }

    if (mfset->amountConnectedComponents() > 1)
    {
        return -1;
    }

    return charge;
}

int main()
{

    string input;
    int N;
    int E;

    cin >> N;
    cin >> E;
    cin.ignore();

    UndirectedListGraph *graph = new UndirectedListGraph(N, true);

    for (int e = 0; e < E; e++)
    {
        getline(cin, input);
        int fstSeparatorIndex = input.find(SEPARATOR);

        string originInput = input.substr(0, fstSeparatorIndex);
        int origin = stoi(originInput);

        string afterOriginInput = input.substr(fstSeparatorIndex + 1);
        int sndSeparatorIndex = afterOriginInput.find(SEPARATOR);

        string destinyInput = afterOriginInput.substr(0, sndSeparatorIndex);
        int destiny = stoi(destinyInput);

        string afterDestinyInput = afterOriginInput.substr(sndSeparatorIndex + 1);
        int afterDestinySeparatorIndex = afterDestinyInput.find(SEPARATOR);

        string chargeInput = afterDestinyInput.substr(0, afterDestinySeparatorIndex);
        int charge = stoi(chargeInput);

        graph->addEdge(origin, destiny, charge);
    }

    int maxAmountOfElements = N * N;
    MinHeap<Edge> *heap = new MinHeap<Edge>(maxAmountOfElements);

    for (int n = 1; n <= N; n++)
    {
        List<Edge> adjacencies = graph->adjacencies(n);
        int adjacenciesAmount = adjacencies.size;
        for (int e = 0; e < adjacenciesAmount; e++)
        {
            Edge edge = (adjacencies.pullTailValue());
            heap->insert(Edge(edge));
        }
    }

    int totalCharge = minimumTreeCoverCharge(N, heap);
    cout << totalCharge;

    return 1;
}

#endif