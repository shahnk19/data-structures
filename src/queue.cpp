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

class Queue {
  public:
    Node *head, *tail;

    Queue() {
      head = NULL;
      tail = NULL;
    }

    bool IsEmpty() {
      if(head == NULL)
        return true;
      return false;
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
