#include <iostream>
#include "../src/linked_list.cpp"

using namespace::std;

class LinkedListInsertion : public LinkedList{

  public:

    void InsertAtPosition(int position, Node *newNode) {
      if(IsEmpty())
        return Insert(newNode);

      Node *pin = head;
      int iteratorCount = 0;

      // find the Node at requested position
      while(pin != NULL && iteratorCount < position) {
        pin = pin->next;
        iteratorCount++;
      }

      // insert at pin Node
      newNode->next = pin->next;
      pin->next = newNode;
    }
};
