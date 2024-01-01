#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class IntBinaryTree //Binary Tree class declaration
{
    private:
        struct TreeNode //Declares a tree node
        {
            TreeNode *left; //Points to the left child node
            TreeNode *right; //Points to the right child node
            int treeValue; //Holds a value in the node
        };
        
        TreeNode *root; //Points to the root node 
        
        void removeNode(TreeNode *&);
        void inputNode(TreeNode *&, TreeNode *&);
        void deleteNode(int, TreeNode *&);
        void showOrder(TreeNode *) const;
        int nodeCount(TreeNode *&);
        int leafCount(TreeNode *&);
        int treeHeight(TreeNode *&);
        int treeWidth(TreeNode *&, int level);
        
    
    public: 
        IntBinaryTree(); //Constructor
        
        //Linked list operations
        void insertNode(int);
        void showOrder() const {showOrder(root);}
        int nodeCount(){return nodeCount(root);}
        int leafCount(){return leafCount(root);}
        int treeHeight(){return treeHeight(root);}
        int treeWidth();
        bool findNode(int);
    
    
};

#endif