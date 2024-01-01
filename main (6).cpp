/*
*
* 
*
* 
*
*
*
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Tree.h"
using namespace std;

void menu(); //Function that outputs the header and lists the options to the user

void insertInt(IntBinaryTree &); //Fucntion to input an integer

void showTree(IntBinaryTree &); //Function that displays the tree

void showLeaf(IntBinaryTree &); //Function that displays the leaf

void showHeight(IntBinaryTree &); //Function that displays the tree's height

void showWidth(IntBinaryTree &); //Function that displays the tree's width

void exitProgram(); //Function to exit the program


int main()
{
    IntBinaryTree tree;
    int option;
    
    while (option != 6)
    {
      menu();
      cin >> option; //User option input
      
      switch(option) //Switch statement to create a menu loop
      {
        
        case 1:
            insertInt(tree);
            break;
        case 2:
            showTree(tree);
            break;
        case 3:
            showLeaf(tree);
            break;
        case 4:
            showHeight(tree);
            break;
        case 5:
            showWidth(tree);
            break;
        case 6:
            exitProgram();
            break;

      }
      
    }
}


void menu()
{
  cout << "\n** Binary Tree **\n\n" << "1. Insert One Integer Into The Tree\n" << "2. Display The Tree\n" << "3. Display Leaf Count\n" << "4. Display Tree Height\n"<< "5. Display Tree Width\n" << "6. Exit\n";

  cout << "\nChoose an option: ";
}

void insertInt(IntBinaryTree &tree)
{
  cout << "\nEnter an integer to the tree: ";
  
  int integer; 
  cin >> integer; //User input
  
  tree.insertNode(integer); //Inserts the integer into the tree
  cout << endl << "The integer " << integer << " has been added successfully!\n\n";
}

void showTree(IntBinaryTree &tree)
{
  if(tree.nodeCount() > 0) //If tree is not empty
  {
    cout << "\n\nCurrent Tree: \n\n";
    tree.showOrder(); //Displays the current tree
    cout << endl;
  }
  
  else //If tree is empty
  {
    cout << "\n\nThe tree is currently empty.\n\n";
    tree.showOrder(); //Displays the current tree
    cout << endl;
  }
}

void showLeaf(IntBinaryTree &tree)
{
  cout << "\nCurrent Leaf Count: " << tree.leafCount() << endl;
}

void showHeight(IntBinaryTree &tree)
{
  cout << "\nCurrent Tree Height: " << tree.treeHeight() << endl;
}

void showWidth(IntBinaryTree &tree)
{
  cout << "\nCurrent Tree Width: " << tree.treeWidth() << endl;
}

void exitProgram() //Function to exit the program
{
  cout << "\nThank you for using Binary Tree tool!\n";

  exit (0);
}
