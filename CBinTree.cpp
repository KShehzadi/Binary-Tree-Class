#include <iostream>
#include "Node.cpp"
using namespace std;

int tempInt;

class CBinTree
{
public:
  Node* root;
  int count;

  CBinTree();
  CBinTree(Node* &ptr);
  void insert(Node* &ptr);
  Node* find(Node* &ptr);
  void printInOrder();
  void printRevOrder();
  void printPreOrder();
  void printPostOrder();
  void setDegree();
  void setLevelOfNodes();
  void setBalanceFactor();
};

CBinTree::CBinTree():root(NULL), count(0)
{

}

CBinTree::CBinTree(Node* &ptr):root(ptr), count(1)
{
  root->left = root->right = NULL;
  ptr = NULL;
}

void CBinTree::insert(Node* &ptr)
{
  Node* rp = root;
  Node* bp;

  if(!count)
  {
    root = ptr;
    count++;
    ptr = ptr->left = ptr->right = NULL;
    return;
  }

  while(rp)
  {
    bp = rp;
    if(rp->data < ptr->data) rp = rp->right;
    else if(rp->data > ptr->data) rp = rp->left;
    else return;
  }

  if(bp->data > ptr->data) bp->left = ptr;
  else bp->right = ptr;

  count++;
  ptr = ptr->left = ptr->right = NULL;
}

Node* CBinTree::find(Node* &ptr)
{
  Node* rp = root;
  Node* bp;

  while(rp)
  {
    bp = rp;
    if(ptr->compareWith(rp) == 0) return rp;
    else if(ptr->compareWith(rp) == -1) rp = rp->left;
    else rp = rp->right;
  }

  return NULL;
}

//*************************
void prtInOrder(Node* root)
{
  if(root)
  {
    prtInOrder(root->left);
    root->print();
    prtInOrder(root->right);
  }
}

void prtRevOrder(Node* root)
{
  if(root)
  {
    prtRevOrder(root->right);
    root->print();
    prtRevOrder(root->left);
  }
}

void prtPreOrder(Node* root)
{
  if(root)
  {
    root->print();
    prtPreOrder(root->right);
    prtPreOrder(root->left);
  }
}

void prtPostOrder(Node* root)
{
  if(root)
  {
    prtPostOrder(root->left);
    prtPostOrder(root->right);
    root->print();
  }
}

//Local Funtions***********

void CBinTree::printInOrder()
{
  prtInOrder(root);
}

void CBinTree::printRevOrder()
{
  prtRevOrder(root);
}

void CBinTree::printPreOrder()
{
  prtPreOrder(root);
}

void CBinTree::printPostOrder()
{
  prtPostOrder(root);
}

void setDegreeLocal(Node* root)
{
  if(root)
  {
    if(root->left)
    {
      root->degree++;
      setDegreeLocal(root->left);
    }
    if(root->right)
    {
      root->degree++;
      setDegreeLocal(root->right);
    }
  }
}

int setHeightOfNodes(Node* root)
{
  if(root)
  {
    int leftHeight = setHeightOfNodes(root->left);
    int rightHeight = setHeightOfNodes(root->right);

    if(leftHeight > rightHeight)
    {
      root->height = leftHeight;
      return 1 + leftHeight;
    }
    else
    {
      root->height = rightHeight;
      return 1 + rightHeight;
    }
  }
  else
  {
    return 1;
  }
}

void correctLvlOfNodes(Node* root)
{
  if(root)
  {
    correctLvlOfNodes(root->left);
    root->level = tempInt - root->height + 1;
    correctLvlOfNodes(root->right);
  }
}

void setBalFactor(Node* root)
{
  if(root)
  {
    int leftHeight = 0;
    int rightHeight = 0;

    if(root->left) leftHeight = root->left->height;
    if(root->right) rightHeight = root->right->height;

    root->balFactor = leftHeight - rightHeight;

    setBalFactor(root->left);
    setBalFactor(root->right);
  }
}

//*************************

void CBinTree::setDegree()
{
  setDegreeLocal(root);
}

void CBinTree::setLevelOfNodes()
{
  setHeightOfNodes(root);
  tempInt = root->height;
  correctLvlOfNodes(root);
}

void CBinTree::setBalanceFactor()
{
  this->setLevelOfNodes();
  setBalFactor(root);
}

int main()
{
  Node* ptr1 = new Node(1);
  Node* ptr2 = new Node(2);
  Node* ptr3 = new Node(3);
  Node* ptr4 = new Node(4);


  CBinTree* C1 = new CBinTree();

  C1->insert(ptr2);
  C1->insert(ptr1);
  C1->insert(ptr3);
  C1->insert(ptr4);

  C1->setDegree();
  C1->setLevelOfNodes();
  C1->setBalanceFactor();

  cout<<C1->root->balFactor<<endl;



  return 0;
}
