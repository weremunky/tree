#include <iostream>
#include <cstring>
#include <cctype>
#include "Tree.h"

IntBinaryTree::IntBinaryTree() //Constructor
{
  root = nullptr;
}

void IntBinaryTree::removeNode(TreeNode *&nodePtr)
{
  TreeNode *tempNodePtr = nullptr;
  
  if(nodePtr->right == nullptr) //Removes nodes from the right
  {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->left;
    delete tempNodePtr;
  }
  
  else if(nodePtr->left == nullptr) //Removes nodes from the left
  {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->right;
    delete tempNodePtr;
  }
  
  else //Deletes the nodes
  {
    tempNodePtr = nodePtr->right;
     
    while(tempNodePtr->left)
    {
        tempNodePtr = tempNodePtr->left;
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
  }
  
}

void IntBinaryTree::inputNode(TreeNode *&nodePtr, TreeNode *&newNode)
{
  
  if (nodePtr == nullptr) //If there are currently no nodes in the stack
  {
    nodePtr = newNode;
  }
  
  else if (newNode->treeValue < nodePtr->treeValue) //The node inserts into left sub tree if it's less than the root
  {
    inputNode(nodePtr->left, newNode);  
  }
  
  else //If the node is bigger, it inserts into the right subtree
  {
    inputNode(nodePtr->right, newNode);  
  }
}

void IntBinaryTree::insertNode(int value)
{
  TreeNode *newNode = nullptr;
  newNode = new TreeNode; //Creates a new node in stack
  
  newNode->treeValue = value; //Stores the value into the stack node
  newNode->left = newNode->right = nullptr;

  inputNode(root, newNode); //Passes the node into the function
}

void IntBinaryTree::deleteNode(int value, TreeNode *&nodePtr)
{
  if(nodePtr->treeValue > value)
  {
    deleteNode(value, nodePtr->left);
  }
    
  else if(nodePtr->treeValue < value)
  {
    deleteNode(value, nodePtr->right);
  }
    
  else
  {
    removeNode(nodePtr);
  }
}

void IntBinaryTree::showOrder(TreeNode *nodePtr) const
{
  if (nodePtr) //If node exists in the stack
  {
    showOrder(nodePtr->left);                                   
    cout << nodePtr->treeValue << " "; //Outputs nodes with spaces in the set order
    showOrder(nodePtr->right);

  }
}

int IntBinaryTree::nodeCount(TreeNode *&nodePtr)
{
  if(nodePtr == nullptr) //If there are no nodes in the stack, it returns 0
  {
    return 0;
  }
  
  else //Adds the nodes from both right and left together
  {
    return 1 + nodeCount(nodePtr->right) + nodeCount(nodePtr->left);
  }
  
}

int IntBinaryTree::leafCount(TreeNode *&nodePtr)
{
  if(nodePtr == nullptr) //If there are no nodes in the stack, it returns 0
  {
    return 0;
  }
  
  if(nodePtr->right == nullptr && nodePtr->left == nullptr) 
  {
    return 1;
  }
  
  return leafCount(nodePtr->right) + leafCount(nodePtr->left); //Adds the nodes from both right and left together
}

int IntBinaryTree::treeHeight(TreeNode *&nodePtr)
{
  if(nodePtr == nullptr) //If there are no nodes in the stack, the height is impossible to output
  {
    return 0;
  }
  
  else
  {
    int left = treeHeight(nodePtr->left); //Sets the left integer to the tree height of the left
    int right = treeHeight(nodePtr->right); //Sets the right integer to the tree height of the right
    
    return max(left, right) +1; //Returns max value from right/left and adds 1 for the root
  }
  
}

int IntBinaryTree::treeWidth(TreeNode *&nodePtr, int lvl)
{
    if (lvl == 1) //If the width level equals to 1
    {
        return 1;
    }
    
    else if (lvl > 1) //If the width level is greater than 1, counts nodes at each level
    {
        int right = treeWidth(nodePtr->right, lvl - 1);
        int left = treeWidth(nodePtr->left, lvl - 1);
        
        return right + left; //Returns added left and right levels
    }
    
    return 0;
}

int IntBinaryTree::treeWidth()
{
  if (root == nullptr) //If the root is empty, the width will be 0
  {
    return 0;
  }
    
  int maxWidth = 0;
  int height = treeHeight(root);
    
  for (int lvl = 1; lvl <= height; ++lvl) 
  {
    int levelWidth = treeWidth(root, lvl);
    maxWidth = max(maxWidth, levelWidth);
  }
    
    return maxWidth; //Returns the maximum width, the greater of the two tested widths
}

bool IntBinaryTree::findNode(int value)
{
  TreeNode *nodePtr = root;
 
  while(nodePtr) //While node exists in the stack
  {
    if(nodePtr->treeValue == value)
    {
      return true;
    }
      
    else if(nodePtr->treeValue > value) //If the pointer is greater than the value, it goes to the right
    {
      nodePtr = nodePtr->right;
    }
      
    else //Else, it goes to the left
    {
      nodePtr = nodePtr->left;
    }
      
  }
 
 return false;
 
}