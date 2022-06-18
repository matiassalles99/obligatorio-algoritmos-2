#ifndef EDGE
#define EDGE

#include <iostream>
using namespace std;

class Edge
{
public:
  int origin;
  int destiny;
  int charge;

  Edge(int origin, int destiny, int charge) : origin(origin), destiny(destiny), charge(charge) {}
  Edge() {}
  Edge(const Edge &edge)
  {
    this->origin = edge.origin;
    this->destiny = edge.destiny;
    this->charge = edge.charge;
  }

  bool operator==(const Edge &other) const
  {
    return origin == other.origin && destiny == other.destiny && charge == other.charge;
  }

  bool operator!=(const Edge &other) const
  {
    return !(*this == other);
  }

  bool operator<(const Edge &other) const
  {
    return charge < other.charge;
  }

  bool operator>(const Edge &other) const
  {
    return charge > other.charge;
  }

  friend ostream &operator<<(ostream &os, Edge const &e)
  {
    cout << "Origen: " << e.origin << " Destino: " << e.destiny << " Carga: " << e.charge << endl;
    return os;
  }
};

#endif