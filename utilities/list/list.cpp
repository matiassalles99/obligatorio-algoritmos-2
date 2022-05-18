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
    this->head = this->tail = NULL;
    this->size = 0;
  }

  void insertFirst(T value)
  {
    ListNode<T> *newNode = new ListNode<T>(value, NULL, NULL);
    ListNode<T> *aux = this->head;

    if (aux != NULL)
    {
      newNode->next = aux;
      aux->previous = newNode;
    }
    else
    {
      this->tail = newNode;
    }

    this->head = newNode;
    this->size++;
  }

  void insertLast(T value)
  {
    ListNode<T> *newNode = new ListNode<T>(value, NULL, NULL);

    if (this->head == NULL)
    {
      this->head = newNode;
      this->size++;
      return;
    }

    ListNode<T> *aux = this->head;
    while (aux->next != NULL)
      aux = aux->next;

    newNode->previous = aux;
    this->tail = aux->next = newNode;
    this->size++;
  }

  void remove(T value)
  {
    // assert(this->exists(value));
    ListNode<T> *aux = this->head;

    while (aux->value != value && aux->next != NULL)
      aux = aux->next;

    if (this->tail == aux)
    {
      this->tail = aux->previous;
    }

    if (aux->next == NULL && aux->previous != NULL)
    {
      ListNode<T> *previous = aux->previous;
      previous->next = NULL;
      delete aux;
    }
    else if (aux->next != NULL && aux->previous == NULL)
    {
      this->head = aux->next;
      this->head->previous = NULL;
      delete aux;
    }
    else if (aux->next == NULL && aux->previous == NULL)
    {
      this->head = NULL;
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

  T pullTailValue()
  {
    // assert(this->size > 0);
    ListNode<T> *tail = this->tail;
    T tailValue = tail->value;

    this->tail = this->tail->previous;
    if (this->tail == NULL)
    {
      this->head = NULL;
    }
    else
    {
      this->tail->next = NULL;
    }

    delete tail;
    this->size--;

    return tailValue;
  }

  bool exists(T value)
  {
    ListNode<T> *aux = this->head;
    bool exists = false;

    if (this->head == NULL)
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

  T retrieveValue(T value)
  {
    // assert(this->exists(value));
    ListNode<T> *aux = this->head;

    while (aux->value != value && aux->next != NULL)
      aux = aux->next;

    return aux->value;
  }

  void update(T value)
  {
    // assert(this->exists(value));
    ListNode<T> *aux = this->head;

    while (aux->value != value && aux->next != NULL)
      aux = aux->next;

    aux->value = value;
  }

  List<T> clone()
  {
    List<T> clone;

    ListNode<T> *aux = this->head;
    while (aux != NULL)
    {
      T value = aux->value;
      clone.insertLast(value);
      aux = aux->next;
    }

    return clone;
  }

  void print()
  {
    ListNode<T> *aux = this->head;
    std::cout << "Size: " << this->size << std::endl;

    while (aux != NULL)
    {
      std::cout << " " << aux->value << " ->";
      aux = aux->next;
    }
  }

  ListNode<T> *head;
  ListNode<T> *tail;
  int size;
};

#endif
