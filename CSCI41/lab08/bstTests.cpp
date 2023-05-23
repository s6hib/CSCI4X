#include <iostream>
#include <vector>
#include "bst.h"
#include "testing.h"
using namespace std;

void testCatch();
void testSearch();
void testRelease();

int main() {
  testCatch();
  testSearch();
  testRelease();

  return 0;
}

vector<Pokemon> listOfPokemon() {
  vector<Pokemon> v = {
                       {6,"Charizard","Fire/Flying"},
                       {25,"Pikachu","Electric"},
                       {5,"Charmeleon","Fire"},
                       {2,"Ivysaur","Grass/Poison"},
                       {9,"Blastoise","Water"},
                       {8,"Wartortle","Water"},
                       {3,"Venusaur","Grass/Poison"},
                       {1,"Bulbasaur","Grass/Poison"},
                       {4,"Charmander","Fire"},
                       {7,"Squirtle","Water"}
                      };
  return v;
}

void testCatch() {
  BST b;

  assertEquals(b.orderedListOfCaughtPokemon(), "", "empty bst");

  vector<Pokemon> v = listOfPokemon();

  for (const auto& pokemon : v) {
    b.catchPokemon(pokemon);
  }

  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "2: Ivysaur (Grass/Poison)\n"
               "3: Venusaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "5: Charmeleon (Fire)\n"
               "6: Charizard (Fire/Flying)\n"
               "7: Squirtle (Water)\n"
               "8: Wartortle (Water)\n"
               "9: Blastoise (Water)\n"
               "25: Pikachu (Electric)\n",
               "catch 'em all");
}

void testSearch() {
  BST b;

  vector<Pokemon> v = listOfPokemon();

  for (const auto& pokemon : v) {
    b.catchPokemon(pokemon);
  }

  for (const auto& pokemon : v) {
    const Pokemon* p = b.searchForPokemon(pokemon.number);
    assertTrue(p != nullptr && p->number == pokemon.number, "search for " + to_string(pokemon));
  }

  const Pokemon* p = b.searchForPokemon(151);
  assertTrue(p == nullptr, "search for something not there");
}

void testRelease() {
  BST b;

  vector<Pokemon> v = listOfPokemon();

  for (const auto& pokemon : v) {
    b.catchPokemon(pokemon);
  }

  b.releasePokemon(6);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "2: Ivysaur (Grass/Poison)\n"
               "3: Venusaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "5: Charmeleon (Fire)\n"
               "7: Squirtle (Water)\n"
               "8: Wartortle (Water)\n"
               "9: Blastoise (Water)\n"
               "25: Pikachu (Electric)\n",
               "remove 6");
  b.releasePokemon(25);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "2: Ivysaur (Grass/Poison)\n"
               "3: Venusaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "5: Charmeleon (Fire)\n"
               "7: Squirtle (Water)\n"
               "8: Wartortle (Water)\n"
               "9: Blastoise (Water)\n",
               "remove 25");
  b.releasePokemon(5);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "2: Ivysaur (Grass/Poison)\n"
               "3: Venusaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "7: Squirtle (Water)\n"
               "8: Wartortle (Water)\n"
               "9: Blastoise (Water)\n",
               "remove 5");
  b.releasePokemon(2);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "3: Venusaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "7: Squirtle (Water)\n"
               "8: Wartortle (Water)\n"
               "9: Blastoise (Water)\n",
               "remove 2");
  b.releasePokemon(9);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "3: Venusaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "7: Squirtle (Water)\n"
               "8: Wartortle (Water)\n",
               "remove 9");
  b.releasePokemon(8);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "3: Venusaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "7: Squirtle (Water)\n",
               "remove 8");
  b.releasePokemon(3);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "1: Bulbasaur (Grass/Poison)\n"
               "4: Charmander (Fire)\n"
               "7: Squirtle (Water)\n",
               "remove 3");
  b.releasePokemon(1);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "4: Charmander (Fire)\n"
               "7: Squirtle (Water)\n",
               "remove 1");
  b.releasePokemon(4);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "7: Squirtle (Water)\n",
               "remove 4");
  b.releasePokemon(7);
  assertEquals(b.orderedListOfCaughtPokemon(),
               "",
               "remove 7");
}