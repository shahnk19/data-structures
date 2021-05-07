#include <iostream>
using namespace::std;

struct Node {
  Node *next;
  int value;

  public:

    Node(int val) {
      value = val;
      next = NULL;
    }
};

class LinkedList {
  Node *head;

  public:

    LinkedList() {
      head = NULL;
    }

    bool IsEmpty() {
      if(head == NULL)
        return true;
      return false;
    }

    void Insert(Node *newNode) {
      newNode->next = head;
      head = newNode;
    }

    void Remove() {
      if(!head)
        return;

      Node *tmp = head;
      head = tmp->next;
      tmp->next = NULL;

      delete tmp;
    }

    void Display() {
      cout<<Stringify();
    }

    string Stringify() {
      string content = "[";
      Node *pin = head;
      while(pin) {
        content += " " + to_string(pin->value) + " ";
        pin = pin->next;
        if(pin) {
          content += "->";
        }
      }
      content += "]";
      return content;
    }
};
