#ifndef LIST_NODE
#define LIST_NODE

#include <iostream>
#include <assert.h>

template <typename T>
class ListNode
{
public:
  T value;
  ListNode<T> *next;
  ListNode<T> *previous;

  ListNode(const T &e, ListNode<T> *n, ListNode<T> *p) : value(e), next(n), previous(p) {}
  virtual ~ListNode() {}
};

#endif