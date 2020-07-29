#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* left;
  Node* right;
  int degree;
  int level;
  int height;
  int balFactor;

  Node();
  Node(int data);
  Node(const Node& node);
  void print();
  int compareWith(Node* &ptr);
};

Node::Node():data(0), left(NULL), right(NULL), degree(0), level(0), balFactor(0)
{

}

Node::Node(int data):data(data), left(NULL), right(NULL), degree(0), level(0), balFactor(0)
{

}

void Node::print()
{
  cout<<data;
}

Node::Node(const Node& node):data(node.data), left(node.left), right(node.right), degree(node.degree), level(node.level), balFactor(node.balFactor)
{

}

int Node::compareWith(Node* &ptr)
{
  if(data < ptr->data) return -1;
  else if(data > ptr->data) return 1;
  else return 0;
}
