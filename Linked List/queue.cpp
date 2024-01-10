#include <climits>
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class Queue {
private:
  Node *first;
  Node *last;

public:
  Queue(int data) {
    Node *newNode = new Node(data);
    first = newNode;
    last = newNode;
  }

  ~Queue() {
    Node *temp = first;
    while (first) {
      delete temp;
      first = first->next;
      temp = first;
    }
  }

  void Print() {
    Node *temp = first;
    while (temp) {
      cout << temp->data << "\t" ;
      temp = temp->next;
    }
    cout << endl;
  }

   void Enqueue(int data);
  int Dequeue();
};

void Queue::Enqueue(int data) {
  Node *newNode = new Node(data);

  if (first == nullptr) {
    first = newNode;
    last = newNode;
  } else {
    last->next = newNode;
    last = newNode;
  }
}

int Queue::Dequeue() {
  int dqueuedVal = INT_MIN;
  if (first == nullptr)
    return dqueuedVal;
  else if (first == last) {
    dqueuedVal = first->data;
    delete first;
    first = nullptr;
    last = nullptr;
  } else {
    Node *temp = first;
    first = first->next;
    dqueuedVal = temp->data;
    delete temp;
  }

  return dqueuedVal;
}

int main() {
  Queue *q = new Queue( 7 );
  q->Enqueue(1);
  q->Enqueue(2);
  q->Enqueue(3);
  q->Enqueue(4);
  q->Enqueue(5);
  q->Print();
  q->Dequeue();
  q->Print();
  q->Dequeue();
  q->Dequeue();
  q->Print();
  q->Dequeue();
  q->Dequeue();
  q->Print();
  q->Dequeue();
  q->Print();
  return 0;
}