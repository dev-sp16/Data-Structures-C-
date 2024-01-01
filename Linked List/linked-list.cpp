#include <iostream>

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

class LinkedList {
private:
  Node* head;
  Node* tail;
  int length;

public:
  LinkedList( int data ) {
    Node* node = new Node( data );
    head = node;
    tail = node;
    length = 1;
  }

  ~LinkedList() {
    Node* temp = head;
    while( head ) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void Append( int value );
  void RemoveLast();
  void Prepend( int value );
  void RemoveFirst();
  void Insert( int index, int value );
  void Delete( int index );
  void Reverse();
  void Print();
};

void LinkedList::Append( int value ) {
  Node* node = new Node( value );
  if( head == nullptr ) {
    head = node;
    tail = node;
  }
  else {
    tail->next = node;
    tail = node;
  }

  length++;
}

void LinkedList::RemoveLast()
{
  Node* temp = head;

  if( head == nullptr ) {
    return;
  }
  else if( length == 1 ) {
    delete head;
    head = nullptr;
    tail = nullptr;
  }
  else {
    while( temp->next->next ) {
     temp = temp->next;    
    }

    delete temp->next;
    temp->next = nullptr;
    tail = temp;
  }

  length--;
}

void LinkedList::Prepend( int value ) {
  Node* node = new Node( value );

  if( head == nullptr ) {
    head = node;
    tail = node;
  }
  else {
    node->next = head;
    head = node;
  }

  length++;
}

void LinkedList::RemoveFirst() {
  if( head == nullptr ) return;

  Node* temp = head;
  
  if( length == 1 ) {
    head = nullptr;
    tail = nullptr;
  }
  else {
    head = temp->next;
  }

  delete temp;
  length--;
}

void LinkedList::Insert( int index, int value ) {
  if( index < 0 || index > length ) {
    cout << "ERROR: Invalid index value '" + to_string( index ) + "'"  << endl;
    return;
  }

  if( index == 0 ) {
    Prepend( value );
  }
  else if( index == length ) {
    Append( value );
  }
  else {
    Node* temp = head;
    
    for( int i = 0; i < index - 1; i++ ) {
      temp = temp->next;
    }

    Node* node = new Node( value );
    node->next = temp->next;
    temp->next = node;
    length++;
  }

}

void LinkedList::Delete( int index ) {
  if( index < 0 || index >= length ) {
    cout << "Invalid index value '" + to_string( index ) + "'" << endl;
    return;
  }

  if( index == 0 ) {
    RemoveFirst();
  }
  else if( index == length - 1 ) {
    RemoveLast();
  }
  else {
    Node* prev = head;
    for( int i = 0; i < index - 1; i++ ) {
      prev = prev->next;
    }

    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    length--;
  }
}

void LinkedList::Reverse() {
  Node* temp = head;
  head = tail;
  tail = temp;

  Node* after = temp;
  Node* before = nullptr;
  while( temp ) {
    after = temp->next;
    temp->next = before;
    before = temp;
    temp = after;
  }
}

void LinkedList::Print() {
  Node* temp = head;
  while( temp ) {
    cout << "Data: " << temp->data << "\t";
    temp = temp->next;
  }

  cout << "Length: " << length << endl;
}

int main() {
  LinkedList* linkedList = new LinkedList( 1 );

  linkedList->Append( 2 );
  linkedList->Append( 3 );

  linkedList->Print();

  linkedList->RemoveLast();
  linkedList->Print();

  linkedList->Prepend( 4 );
  linkedList->Print();

  linkedList->RemoveFirst();
  linkedList->Print();

  linkedList->Insert( 0, 5 );
  linkedList->Insert( 3, 6 );
  linkedList->Insert( 4, 5 );
  linkedList->Print();

  linkedList->Reverse();
  linkedList->Print();

  linkedList->Delete( 0 );
  linkedList->Delete( 3 );
  linkedList->Delete( 1 );
  linkedList->Print();

  linkedList->Reverse();
  linkedList->Print();

  return 0;
}