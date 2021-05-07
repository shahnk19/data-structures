#include <iostream>
#include "../src/linked_list.cpp"

using namespace::std;

class LinkedListInsertion : public LinkedList{

  public:

    void InsertAtPosition(int position, Node *newNode) {
      if(position < 0)
        return;
      if(IsEmpty())
        return Insert(newNode);

      Node *pin = head;
      int iteratorCount = 0;

      // find the Node at requested position
      while(pin != NULL && iteratorCount < position) {
        pin = pin->next;
        iteratorCount++;
      }

      // we hit the end of the list
      if(pin == NULL)
        return;

      // insert at pin Node
      newNode->next = pin->next;
      pin->next = newNode;
    }

    void InsertAfter(Node *referenceNode, Node *newNode) {
      if(referenceNode == NULL)
        return;

      newNode->next = referenceNode->next;
      referenceNode->next = newNode;
    }
};
