#ifndef EJERCICIO_2
#define EJERCICIO_2

#include <iostream>
#include <string>
#include "./utilities/hash_table/open_hash_table.cpp"

using namespace std;

const char SEPARATOR = ' ';

int hashFunction(string name)
{
  int hashValue = 0;
  for (int i = 0; i < name.length(); i++)
    hashValue += name.at(i);

  return hashValue;
}

int main()
{
  int amountOfTurns;
  string input;

  cin >> amountOfTurns;
  cin.ignore();

  OpenHashTable<string, int> *hash_table = new OpenHashTable<string, int>(amountOfTurns, &hashFunction);

  int maxScore = INT32_MIN;
  string winnerName = "";

  for (int i = 0; i < amountOfTurns; i++)
  {
    getline(cin, input);
    int separatorIndex = input.find(SEPARATOR);
    string playerName = input.substr(0, separatorIndex);
    int playerPoints = stoi(input.substr(separatorIndex + 1));

    int newPlayerPoints = playerPoints;
    if (hash_table->exists(playerName))
    {
      newPlayerPoints += hash_table->retrieveValue(playerName);
      hash_table->update(playerName, newPlayerPoints);
    }
    else
    {
      hash_table->insert(playerName, newPlayerPoints);
    }

    if (newPlayerPoints > maxScore)
    {
      maxScore = newPlayerPoints;
      winnerName = playerName;
    }
  }

  cout << winnerName << endl;
  return 1;
};

#endif
