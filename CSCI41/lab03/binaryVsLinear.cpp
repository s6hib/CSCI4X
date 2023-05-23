#include "timer.h"
#include <vector>
using namespace std;

// uses linear to search for the key in the vector v
// returns the index of the key, if you find it
// returns -1 if not found
int linearSearch(const vector<int>& v, int key) {
  // FΙХME: implement this function
  return -1;
}

// uses binary search to search for the key in the vector v
// returns the index of the key, if you find it
// returns -1 if not found
int binarySearch(const vector<int>& v, int key) {
  // FΙХME: implement this function
  return -1;
}

int main() {
  vector<int> v;

  // fill v with a lot of sorted data
  for (int i = 0; i < 35000; i++) {
    v.push_back(i);
  }

  // linear search for every key
  // (also search for one key that's not there)
  Timer linTimer("linear search");
  linTimer.start();
  for (int i = 0; i < 35001; i++) {
    linearSearch(v, i);
  }
  linTimer.stop();
  linTimer.printData();

  //  binary search for every key
  // (also search for one key that's not there)
  Timer binTimer("binary search");
  binTimer.start();
  for (int i = 0; i < 35001; i++) {
    binarySearch(v, i);
  }
  binTimer.stop();
  binTimer.printData();

  return 0;
}