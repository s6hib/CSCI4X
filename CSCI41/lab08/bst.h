#ifndef BST_H
#define BST_H

#include <string>

// We will be storing Pokemon in the nodes of our BST
struct Pokemon {
  int number;
  std::string name;
  std::string type;
};

std::string to_string(const Pokemon& p);

class BST {
public:
  BST();
  // insert
  void catchPokemon(const Pokemon& p);
  // delete
  void releasePokemon(int key);
  // search
  const Pokemon* searchForPokemon(int key) const;
  // in-order traversal and pretty printing
  std::string orderedListOfCaughtPokemon() const;

  // Lawton implemented this for you for debugging purposes
  std::string toGraphviz() const;

private:
  struct BSTNode {
    int key;
    Pokemon data;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
  };

  // in-order traversal recursive helper
  std::string inOrder(BSTNode* root) const;
  // search helper function
  BSTNode* search(int key) const;
  // remove helper function
  void remove(BSTNode* key);
  // predecessor function, used in the remove function
  BSTNode* predecessor(BSTNode* n) const;

  // pointer to the root node
  BSTNode* root;
};

#endif /* BST_H */