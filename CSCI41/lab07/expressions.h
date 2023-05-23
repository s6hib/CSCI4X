#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include <cstdlib>
#include <iostream>
#include <string>

// This is the type of Nodes in our tree.
// Every leaf node has a data value set,
// and every non-leaf node has an op value set
struct ExpressionNode {
  int data;
  char op;
  ExpressionNode* left;
  ExpressionNode* right;
};

// see the .cpp file for descriptions of these functions
int evaluate(ExpressionNode* root);
std::string preOrder(ExpressionNode* root);
std::string postOrder(ExpressionNode* root);
std::string inOrder(ExpressionNode* root);
std::string breadthFirst(ExpressionNode* root);
int height(ExpressionNode* root);
void reverse(ExpressionNode* root);

#endif /* EXPRESSIONNODE_H */