#ifndef EJERCICIO_8
#define EJERCICIO_8

#include <string>
#include <iostream>

#include "./utilities/heap/min_heap.cpp"

using namespace std;

class Flight
{
public:
    int departure;
    int arrival;

    Flight(int departure, int arrival) : departure(departure), arrival(arrival) {}
    Flight() {}

    bool operator==(const Flight &other) const
    {
        return departure == other.departure && arrival == other.arrival;
    }

    bool operator!=(const Flight &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Flight &other) const
    {
        return arrival < other.arrival;
    }

    bool operator>(const Flight &other) const
    {
        return arrival > other.arrival;
    }

    friend ostream &operator<<(ostream &os, Flight const &e)
    {
        cout << "arrival: " << e.arrival << " departure: " << e.departure << endl;
        return os;
    }
};

const char SEPARATOR = ' ';

int main()
{
    string input;
    int numberOfFlights;

    cin >> numberOfFlights;
    cin.ignore();

    MinHeap<Flight> *heap = new MinHeap<Flight>(numberOfFlights);

    for (int i = 0; i < numberOfFlights; i++)
    {
        getline(cin, input);
        int separatorIndex = input.find(SEPARATOR);

        string arrivalInput = input.substr(0, separatorIndex);
        int arrival = stoi(arrivalInput);

        string departureInput = input.substr(separatorIndex + 1, separatorIndex);
        int departure = stoi(departureInput);

        heap->insert(*(new Flight(departure, arrival)));
    }

    int totalPlatforms = 1;
    MinHeap<int> *departuresHeap = new MinHeap<int>(numberOfFlights);
    departuresHeap->insert(heap->pullMin().departure);

    while (!heap->isEmpty())
    {
        Flight currentFlight = heap->pullMin();
        if (departuresHeap->min() > currentFlight.arrival)
        {
            totalPlatforms++;
        }
        else
        {
            departuresHeap->pullMin();
        }
        departuresHeap->insert(currentFlight.departure);
    }

    cout << totalPlatforms;
}

#endif
