#ifndef LIST
#define LIST

#include <iostream>
#include "list_node.cpp"
using namespace std;

template <typename T>
class List
{
public:
  List()
  {
    cout << "Constructor lista" << endl;
    this->list = NULL;
    this->size = 0;
  }

  void insert(T value)
  {
    ListNode<T> *newNode = new ListNode<T>(value, NULL, NULL);

    if (list == NULL)
    {
      this->list = newNode;
      this->size++;
      return;
    }

    ListNode<T> *aux = this->list;
    while (aux->next != NULL)
      aux = aux->next;

    newNode->previous = aux;
    aux->next = newNode;
  }

  void remove(T value)
  {
    cout << "remove!" << endl;
    assert(this->exists(value));
    ListNode<T> *aux = this->list;

    if (this->list->value == value)
    {
      this->list = NULL;
      delete aux;
      this->size--;
      return;
    }

    while (aux->value != value && aux->next != NULL)
      aux = aux->next;

    if (aux->next == NULL)
    {
      ListNode<T> *previous = aux->previous;
      previous->next = NULL;
      delete aux;
    }
    else
    {
      ListNode<T> *next = aux->next;
      ListNode<T> *previous = aux->previous;
      previous->next = next;
      next->previous = previous;
      delete aux;
    }
    this->size--;
  }

  bool exists(T value)
  {
    ListNode<T> *aux = this->list;
    bool exists = false;

    if (this->list == NULL)
      return false;

    while (aux->next != NULL && !exists)
    {
      if (aux->value == value)
        exists = true;
      aux = aux->next;
    }

    return exists;
  }

  void print()
  {
    ListNode<T> *aux = this->list;
    while (aux != NULL)
    {
      std::cout << " " << aux->value << " ->";
      aux = aux->next;
    }
  }

  ListNode<T> *list;
  int size;
};

#endif
