#include "expressions.h"
#include <queue> // where will you use this?
using namespace std;

// You must use recursion for every function except for breadthFirst

// FΙХME: implement the evaluation function to perform the operations
//        represented by the expression tree
int evaluate(ExpressionNode *root) {
  return 42;
}

// FΙХME: implement preorder traversal for expression trees, outputting a string.
//        For each node, your string should contain the data (leaf nodes) or the
//        op (interior nodes). You should put spaces between each node value.
std::string preOrder(ExpressionNode* root) {
  return "";
}

// FΙХME: implement postorder traversal for expression trees, with the same output style as preOrder
std::string postOrder(ExpressionNode* root) {
  return "";
}

// FΙХME: implement inorder traversal for expression trees, with the same output style as preOrder
std::string inOrder(ExpressionNode* root) {
  return "";
}

// THIS IS THE ONLY NON-RECURSIVE FUNCTION
// FΙХME: implement breadth-first order traversal for expression trees, with the same output style as preOrder
std::string breadthFirst(ExpressionNode* root) {
  return "";
}

// FΙХME: calculate the height of a tree by finding the maximum-length
//        path from the root
int height(ExpressionNode* root) {
  return 42;
}

// FΙХME: mirror all the nodes in the tree (i.e., make it so that
//        every left child becomes the right child, and vice-versa)
void reverse(ExpressionNode* root) {
  return;
}