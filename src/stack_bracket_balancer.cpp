#include <iostream>
#include "stack.cpp"
using namespace::std;

bool checkBalance(char* brackets) {
  Stack stack;

  int brackets_length = strlen(brackets);
  
  for (int i = 0; i < brackets_length; i++) {
    char currentBracket = brackets[i];
    if(currentBracket == '{') {
      stack.Push(currentBracket);
    } else {      
      if(stack.Pop() != '{') {
        return false;
      }
    }
  }  
  return stack.IsEmpty();
}

int main(int argc, char** argv) {
  if(argc != 2){
    cout<<"Please enter only 1 argument, i.e {}{{}}"<<endl;
    return -1;
  }

  if(checkBalance(argv[1])) {
    cout<<"The brackets "<<argv[1]<<" is balanced."<<endl;
  } else {
    cout<<"The brackets "<<argv[1]<<" is not balanced."<<endl;
  }
}

