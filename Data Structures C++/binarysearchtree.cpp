#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node( int data ) {
      this->data = data;
      left = nullptr;
      right = nullptr;
    }
};

class BinarySearchTree{
  private:
    Node* root;

  public:
    BinarySearchTree() {
      root = nullptr;
    }

    void Destory( Node* node ) {
      if( node == nullptr ) return;
      if( node->left ) Destory( node->left );
      if( node->right ) Destory( node->right );
      delete node;
    }

    ~BinarySearchTree() {
      Destory( root );
    }

    bool Insert( int data );
    bool Contains( int data );
};

bool BinarySearchTree::Insert( int data ) {
  Node* newNode = new Node( data );

  if( root == nullptr ) {
    root = newNode;
    return true;
  }

  Node* temp = root;
  while( true ) {
    if( newNode->data == temp->data ) return false;
    if( newNode->data < temp->data ){
      if( temp->left == nullptr ) {
        temp->left = newNode;
        return true;
      }
      temp = temp->left;
    }
    else {
      if( temp->right == nullptr ) {
        temp->right = newNode;
        return true;
      }
      temp = temp->right;
    }
  }
}

bool BinarySearchTree::Contains( int data ) {
  if( root == nullptr ) return false;

  Node* temp = root;
  while( true ) {
    if( temp == nullptr ) return false;
    if( data < temp->data ) {
      temp = temp->left;
    }
    else if( data > temp->data ) {
      temp = temp->right;
    }
    else {
      return true;
    }
  }

  return false;
}

int main() {
  BinarySearchTree* bst = new BinarySearchTree();
  bst->Insert( 6 );
  bst->Insert( 4 );
  bst->Insert( 8 );
  bst->Insert( 1 );
  cout << bst->Contains( 5 );
  cout << bst->Contains( 6 );
  return 0;
}