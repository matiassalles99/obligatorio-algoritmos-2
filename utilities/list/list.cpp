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
    this->list = NULL;
    this->size = 0;
  }

  void insert(T value)
  {
    ListNode<T> *newNode = new ListNode<T>(value, NULL, NULL);

    if (this->list == NULL)
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
    this->size++;
  }

  void remove(T value)
  {
    assert(this->exists(value));
    ListNode<T> *aux = this->list;

    while (aux->value != value && aux->next != NULL)
      aux = aux->next;

    if (aux->next == NULL && aux->previous != NULL)
    {
      ListNode<T> *previous = aux->previous;
      previous->next = NULL;
      delete aux;
    }
    else if (aux->next != NULL && aux->previous == NULL)
    {
      this->list = aux->next;
      this->list->previous = NULL;
      delete aux;
    }
    else if (aux->next == NULL && aux->previous == NULL)
    {
      this->list = NULL;
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
    if (aux->value == value)
      return true;

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
