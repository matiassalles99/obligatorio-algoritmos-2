#ifndef UNDIRECTED_LIST_GRAPH
#define UNDIRECTED_LIST_GRAPH

#include "edge.cpp"
#include "../list/list.cpp"

using namespace std;

class UndirectedListGraph
{

private:
    List<Edge> *edgeList;
    int E;
    int N;
    bool isCharged;

public:
    UndirectedListGraph(int N, bool isCharged)
    {
        this->E = 0;
        this->N = N;

        this->isCharged = isCharged;

        this->edgeList = new List<Edge>[N + 1];
    }

    int amountEdges()
    {
        return this->E;
    }

    int amountNodes()
    {
        return this->N;
    }

    void addEdge(int origin, int destiny, int charge)
    {
        int edgeCharge = this->isCharged ? charge : 1;
        Edge e1(origin, destiny, edgeCharge);

        List<Edge> *originList = &(this->edgeList[origin]);
        originList->insertFirst(e1);

        if (origin != destiny)
        {
            Edge e2(destiny, origin, edgeCharge);
            List<Edge> *destinyList = &(this->edgeList[destiny]);
            destinyList->insertFirst(e2);
        }

        this->E++;
    }

    List<Edge> adjacencies(int origin)
    {
        return this->edgeList[origin];
    }
};

#endif
