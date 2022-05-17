#ifndef EDGE
#define EDGE

class Edge
{
public:
  int origin;
  int destiny;
  int charge;

  Edge(int origin, int destiny, int charge) : origin(origin) , destiny(destiny), charge(charge) {}
  Edge() {}

  bool operator==(const Edge &other) const
  {
    return origin == other.origin && destiny == other.destiny 
      && charge == other.charge;
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

};

#endif