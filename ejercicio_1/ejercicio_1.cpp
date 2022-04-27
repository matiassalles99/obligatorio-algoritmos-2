#ifndef EJERCICIO_1
#define EJERCICIO_1

#include <iostream>
#include <string>
#include "../utilities/hash_table/open_hash_table.cpp"
using namespace std;

int hashFunction(char door)
{
    return int(door) - 65;
}

int main()
{
    int minimumKeys = 0;
    int numberOfRooms;
    string detailsInput;

    cin >> numberOfRooms;
    cin >> detailsInput;

    OpenHashTable<char, char> *hash_table = new OpenHashTable<char, char>(26, &hashFunction);
    int length = 2 * (numberOfRooms - 1);

    for (int i = 0; i < length; i += 2)
    {
        char retrievedKey = detailsInput[i];
        char door = detailsInput[i + 1];

        hash_table->insert(toupper(retrievedKey), retrievedKey);

        if (hash_table->exists(door))
            hash_table->remove(door);
        else
            minimumKeys++;
    }

    cout << minimumKeys << endl;
    return 1;
};

#endif
