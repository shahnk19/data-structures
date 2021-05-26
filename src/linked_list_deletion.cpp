#include <iostream>
#include "../src/linked_list.cpp"

using namespace::std;

class LinkedListDeletion : public LinkedList{

  public:

    void RemoveAtPosition(int position) {
      if(position < 0)
        return;
      if(IsEmpty())
        return;
      if(position == 0)
        return Remove();

      Node *pin = head;
      int iteratorCount = 1;

      // find the Node at requested position
      while(pin != NULL && iteratorCount < position) {
        pin = pin->next;
        iteratorCount++;
      }

      // we hit the end of the list
      if(pin == NULL || pin->next == NULL)
        return;

      // delete the node after the pin Node
      Node *toDelete = pin->next;
      pin->next = toDelete->next;
      delete toDelete;
    }

    void RemoveAtNode(int referenceValue) {
      Node *pin = head;
      Node *prev = head;

      // find the Node at requested position
      while(pin != NULL) {
        if(pin->value == referenceValue)
          break;
        prev = pin;
        pin = pin->next;
      }

      if(pin == NULL)
        return;

      if(pin == head)
        return Remove();

      // delete the node at the reference Node
      prev->next = pin->next;
      delete pin;
    }

    void RemoveAtTail() {
      if(IsEmpty())
        return;

      Node *pin = head;
      Node *prev = head;

      // find the last Node
      while(pin->next != NULL) {
        prev = pin;
        pin = pin->next;
      }

      if(pin == head)
        return Remove();

      // delete the last node
      prev->next = NULL;
      delete pin;
    }
};
