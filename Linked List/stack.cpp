#include <iostream>
#include <climits>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node( int data ) {
      this->data = data;
      next = nullptr;
    }
};

class Stack {
  private:
    Node* top;

  public:
    Stack( int data ) {
      Node* newNode = new Node( data );
      top = newNode;
    }

    ~Stack() {
      Node* temp = top;
      while( top ) {
        delete temp;
        top = top->next;
        temp = top;
      }
    }

    void Print() {
      Node* temp = top;
      while( temp ) {
        cout << temp->data << endl;
        temp = temp->next;
      }
    }

    void Push( int data );
    int Pop();
};

void Stack::Push( int data ) {
  Node* newNode = new Node( data );
  newNode->next = top;
  top = newNode;
}

int Stack::Pop() {
  if( top == nullptr ) return INT_MIN;

  Node* temp = top;
  top = top->next;
  int poppedValue = temp->data;
  delete temp;
  return poppedValue;
}

int main() {
  Stack* stack = new Stack( 1 );
  stack->Push( 2 );
  stack->Push( 3 );
  stack->Push( 4 );
  stack->Push( 5 );

  stack->Print();

  cout << "Popping elements..." << endl;
  cout << stack->Pop() << endl;
  cout << stack->Pop() << endl;
  cout << stack->Pop() << endl;

  cout << "Final stack: " << endl;
  stack->Print();
  return 0;
}