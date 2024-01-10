#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node( int data ) {
      this->data = data;
      prev = nullptr;
      next = nullptr;
    }
};

class DoublyLinkedList {
  private:
    Node* head;
    Node* tail;

  public:
    DoublyLinkedList( int data ) {
      Node* newNode = new Node( data );
      head = newNode;
      tail = newNode;
    }

    ~DoublyLinkedList() {
      Node* temp = head;

      while( head ) {
        head = head->next;
        delete temp;
        temp = head;
      }
    }

    void Print() {
      Node* temp = head;
      if( temp == nullptr ) cout << "Empty DLL" << endl;

      while( temp ) {
        cout << temp->data << "\t";
        temp = temp->next;
      }

      cout << endl;
    }

    int GetLength() {
      Node* temp = head;
      int count = 0;
      while( temp != nullptr ) {
        count++;
        temp = temp->next;
      }

      return count;
    }

    void Append( int data );
    void DeleteLast();
    void Prepend( int data );
    void DeleteFirst();
    bool Insert( int index, int data );
    bool Delete( int index );
};

void DoublyLinkedList::Append( int data ) {
  Node* newNode = new Node( data );
  if( head == nullptr ) {
    head = newNode;
    tail = newNode;
  }
  else{
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

void DoublyLinkedList::DeleteLast() {
  Node* temp = tail;

  if( head == nullptr ) return;
 
  if( head == tail ) {
    delete head;
    head = nullptr;
    tail = nullptr;
  }
  else {
    tail = temp->prev;
    tail->next = nullptr;
    delete temp;
  }
}

void DoublyLinkedList::Prepend( int data ) {
  Node* newNode = new Node( data );
  if( head == nullptr ) {
    head = newNode;
    tail = newNode;
  }
  else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void DoublyLinkedList::DeleteFirst() {
  Node* temp = head;
  if( head == nullptr ) return;

  if( head == tail ) {
    head = nullptr;
    tail = nullptr;
  }
  else {
    head = temp->next;
    head->prev = nullptr;
  }

  delete temp;
}

bool DoublyLinkedList::Insert( int index, int data ) {
  int length = GetLength();
  if( index < 0 || index > length ) {
    return false;
  }

  if( index == 0 ) {
    Prepend( data );
  }
  else if( index == length ) {
    Append( data );
  }
  else {
    Node* temp = head;
    Node* newNode = new Node( data );
    for( int i = 0; i < index - 1; i++ ) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    newNode->next->prev = newNode;
    temp->next = newNode;
  }
  
  return true;
}

bool DoublyLinkedList::Delete( int index ) {
  int length = GetLength();
  if( index < 0 || index >= length ) return false;

  if( index == 0 ) DeleteFirst();
  else if( index == length - 1 ) DeleteLast();
  else {
    Node* temp = head;
    for( int i = 0; i < index - 1; i++ ) {
      temp = temp->next;
    }

    Node* after = temp->next;
    temp->next = after->next;
    after->next->prev = temp;
    delete after;
  }

  return true;
}

int main() {

  DoublyLinkedList* dll = new DoublyLinkedList( 1 );
  dll->Print();

  dll->Insert( 0, 2 );
  dll->Insert( 2, 3 );
  dll->Insert( 1, 4 );

  dll->Print();

  dll->Delete( 3 );
  dll->Print();
  dll->Delete( 2 );
  dll->Print();
  dll->Delete( 1 );
  dll->Print();
  dll->Delete( 0 );
  dll->Print();

  return 0;
}