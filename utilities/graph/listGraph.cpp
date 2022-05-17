#ifndef LIST_GRAPH
#define LIST_GRAPH

#include "edge.cpp"
#include "../list/list.cpp"

using namespace std;

class ListGraph
{

private: 
    List<Edge> * edgeList;
    int E;
    int N;

    bool isCharged;
    bool isDirected;

public:    
    ListGraph(int N, bool isDirected, bool isCharged)
    {
        this->E = 0;
        this->N = N;
        
        this->isDirected = isDirected;
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
        int chargeE = this-> isCharged ? charge : 1;
        Edge e1 (origin, destiny, chargeE);

        //assert(!this->edgeList->exists(e1));
        
        List<Edge> * originList = &(this->edgeList[origin]);
        originList -> insertFirst(e1);

        if (!isDirected)
        {
            Edge e2 (destiny, origin, chargeE);
            List<Edge> * destinyList = &(this->edgeList[destiny]);
            destinyList -> insertFirst(e2);
        }

        this->E ++;
    }

    List<Edge> adjacencies(int origin)
    {
        return this->edgeList[origin];
        //return this->edgeList[origin].clone();
    }

};

#endif
