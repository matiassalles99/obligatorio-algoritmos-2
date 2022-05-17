#ifndef EDGE
#define EDGE

#include <assert.h>

class Edge
{
public:
  int origin;
  int destiny;
  int charge;

  Edge(int origin, int destiny, int charge) : origin(origin) , destiny(destiny), charge(charge) {}

  bool operator==(const Edge &other) const
  {
    return origin == other.origin && destiny == other.destiny 
      && charge == other.charge;
  }

  bool operator!=(const Edge &other) const
  {
    return !(*this == other);
  }

};

#endif