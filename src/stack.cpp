#include <iostream>
using namespace::std;

#define MAX_SIZE 10

class Stack {
  public:
    int _stack[MAX_SIZE];
    int top;

    Stack() {
      top = -1;
    }

    bool IsEmpty() {
      return top == -1;
    }

    void Push(int value) {
      if(top >= MAX_SIZE - 1) {
        return; // stack is full
      }

      _stack[++top] = value;
    }

    int Pop() {
      if(IsEmpty()) {
        return 0; // stack is empty
      }

      return _stack[top--];
    }

    string Stringify() {
      string content = "[";
      for(int i=top; i>=0; i--) {
        content += " " + to_string(_stack[i]);
        if(i == 0) {
          content += " ";
        }
      }      
      content += "]";
      return content;
    }
};