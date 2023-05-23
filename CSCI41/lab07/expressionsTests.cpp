#include <iostream>
#include <string>
#include "expressions.h"
#include "testing.h"
using namespace std;

// utility functions
ExpressionNode* makeEmptyTree();
ExpressionNode* makeSimpleTree();
ExpressionNode* makeComplicatedTree();
void deleteTree(ExpressionNode *root);

// testing functions
void test_evaluate();
void test_preOrder();
void test_postOrder();
void test_inOrder();
void test_breadthFirst();
void test_height();
void test_reverse();

int main() {
  test_evaluate();
  test_preOrder();
  test_postOrder();
  test_inOrder();
  test_breadthFirst();
  test_height();
  test_reverse();

  return 0;
}

void test_evaluate() {
  ExpressionNode* simpleTree = makeSimpleTree();
  ExpressionNode* complicatedTree = makeComplicatedTree();

  assertEquals(evaluate(simpleTree), 17, "simple evaluate");
  assertEquals(evaluate(complicatedTree), -53, "complicated evaluate");

  deleteTree(simpleTree);
  deleteTree(complicatedTree);
}

void test_preOrder() {
  ExpressionNode* simpleTree = makeSimpleTree();
  ExpressionNode* complicatedTree = makeComplicatedTree();

  assertEquals(preOrder(simpleTree), "+ 2 * 3 5", "simple preOrder");
  assertEquals(preOrder(complicatedTree), "+ / + * 6 7 - 3 + 5 4 2 - 1 * 8 9", "complicated preOrder");

  deleteTree(simpleTree);
  deleteTree(complicatedTree);
}

void test_postOrder() {
  ExpressionNode* simpleTree = makeSimpleTree();
  ExpressionNode* complicatedTree = makeComplicatedTree();

  assertEquals(postOrder(simpleTree), "2 3 5 * +", "simple postOrder");
  assertEquals(postOrder(complicatedTree), "6 7 * 3 5 4 + - + 2 / 1 8 9 * - +", "complicated postOrder");

  deleteTree(simpleTree);
  deleteTree(complicatedTree);
}

void test_inOrder() {
  ExpressionNode* simpleTree = makeSimpleTree();
  ExpressionNode* complicatedTree = makeComplicatedTree();

  assertEquals(inOrder(simpleTree), "2 + 3 * 5", "simple inOrder");
  assertEquals(inOrder(complicatedTree), "6 * 7 + 3 - 5 + 4 / 2 + 1 - 8 * 9", "complicated inOrder");

  deleteTree(simpleTree);
  deleteTree(complicatedTree);
}

void test_breadthFirst() {
  ExpressionNode* simpleTree = makeSimpleTree();
  ExpressionNode* complicatedTree = makeComplicatedTree();

  assertEquals(breadthFirst(simpleTree), "+ 2 * 3 5", "simple breadthFirst");
  assertEquals(breadthFirst(complicatedTree), "+ / - + 2 1 * * - 8 9 6 7 3 + 5 4", "complicated breadthFirst");

  deleteTree(simpleTree);
  deleteTree(complicatedTree);
}

void test_height() {
  ExpressionNode* emptyTree = makeEmptyTree();
  ExpressionNode* simpleTree = makeSimpleTree();
  ExpressionNode* complicatedTree = makeComplicatedTree();

  assertEquals(height(emptyTree), -1, "empty height");
  assertEquals(height(simpleTree), 2, "simple height");
  assertEquals(height(complicatedTree), 5, "complicated height");

  deleteTree(simpleTree);
  deleteTree(complicatedTree);
}

void test_reverse() {
  ExpressionNode* emptyTree = makeEmptyTree();
  ExpressionNode* simpleTree = makeSimpleTree();
  ExpressionNode* complicatedTree = makeComplicatedTree();

  reverse(emptyTree);
  assertTrue(emptyTree == nullptr, "empty reverse");
  reverse(simpleTree);
  assertEquals(preOrder(simpleTree), "+ * 5 3 2", "simple reverse");
  reverse(complicatedTree);
  assertEquals(preOrder(complicatedTree), "+ - * 9 8 1 / 2 + - + 4 5 3 * 7 6", "complicated reverse");

  deleteTree(simpleTree);
  deleteTree(complicatedTree);
}

// recursively delete an entire tree
void deleteTree(ExpressionNode *root) {
  // base case: empty tree; nothing to delete
  if (root == nullptr) return;

  // recursive case
  // delete the left subtree
  deleteTree(root->left);
  // delete the right subtree
  deleteTree(root->right);
  // delete the current node
  delete root;
}

ExpressionNode* makeEmptyTree() { return nullptr; }

ExpressionNode* makeSimpleTree() {
  // make a tree for 2 + 3*5:
  //
  //      +
  //     / \
  //    2   *
  //       / \
  //      3   5
  //
  ExpressionNode* plus = new ExpressionNode;
  ExpressionNode* times = new ExpressionNode;

  ExpressionNode* two = new ExpressionNode;
  ExpressionNode* three = new ExpressionNode;
  ExpressionNode* five = new ExpressionNode;

  plus->op = '+';
  times->op = '*';

  two->data = 2;
  three->data = 3;
  five->data = 5;

  plus->left = two;
  plus->right = times;
  times->left = three;
  times->right = five;

  two->left = two->right = nullptr;
  three->left = three->right = nullptr;
  five->left = five->right = nullptr;

  return plus; // + is the root
}
ExpressionNode* makeComplicatedTree() {
  // make a tree for (((6*7) + (3-(5+4))) / 2) + (1 - 8*9):
  //
  //                       +
  //                      / \
  //                    /     \
  //                  /         \
  //                /            \
  //              "/"             -
  //              /  \           / \
  //             /     \        1   *
  //            |       \          / \
  //            +        2        8   9
  //           /  \
  //          /     \
  //         *        -
  //        / \      / \
  //       6   7    3   +
  //                   / \
  //                  5  4
  //
  ExpressionNode* number1 = new ExpressionNode;
  ExpressionNode* number2 = new ExpressionNode;
  ExpressionNode* number3 = new ExpressionNode;
  ExpressionNode* number4 = new ExpressionNode;
  ExpressionNode* number5 = new ExpressionNode;
  ExpressionNode* number6 = new ExpressionNode;
  ExpressionNode* number7 = new ExpressionNode;
  ExpressionNode* number8 = new ExpressionNode;
  ExpressionNode* number9 = new ExpressionNode;
  number1->left = number1->right = nullptr;
  number1->data = 1;
  number2->left = number2->right = nullptr;
  number2->data = 2;
  number3->left = number3->right = nullptr;
  number3->data = 3;
  number4->left = number4->right = nullptr;
  number4->data = 4;
  number5->left = number5->right = nullptr;
  number5->data = 5;
  number6->left = number6->right = nullptr;
  number6->data = 6;
  number7->left = number7->right = nullptr;
  number7->data = 7;
  number8->left = number8->right = nullptr;
  number8->data = 8;
  number9->left = number9->right = nullptr;
  number9->data = 9;

  ExpressionNode* times67 = new ExpressionNode;
  times67->op = '*';
  times67->left = number6;
  times67->right = number7;

  ExpressionNode* plus54 = new ExpressionNode;
  plus54->op = '+';
  plus54->left = number5;
  plus54->right = number4;

  ExpressionNode* minus3plus = new ExpressionNode;
  minus3plus->op = '-';
  minus3plus->left = number3;
  minus3plus->right = plus54;

  ExpressionNode* plustimesminus = new ExpressionNode;
  plustimesminus->op = '+';
  plustimesminus->left = times67;
  plustimesminus->right = minus3plus;

  ExpressionNode* divplus2 = new ExpressionNode;
  divplus2->op = '/';
  divplus2->left = plustimesminus;
  divplus2->right = number2;

  ExpressionNode* times89 = new ExpressionNode;
  times89->op = '*';
  times89->left = number8;
  times89->right = number9;

  ExpressionNode* minus1times = new ExpressionNode;
  minus1times->op = '-';
  minus1times->left = number1;
  minus1times->right = times89;

  ExpressionNode* plusdivideminus = new ExpressionNode;
  plusdivideminus->op = '+';
  plusdivideminus->left = divplus2;
  plusdivideminus->right = minus1times;

  return plusdivideminus;
}