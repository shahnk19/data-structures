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
};
