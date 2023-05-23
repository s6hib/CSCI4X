#ifndef TESTING_H
#define TESTING_H

#include <string>
#include <iostream>

void assertTrue(bool b, std::string description);

template <class T, class U>
void assertEquals(const T& x, const U& y, std::string description) {
  if (x == y) {
    std::cout << "PASSED: " << description << std::endl;
  } else {
    std::cout << "FAILED: " << description << std::endl;
    std::cout << "  " << x << std::endl;
    std::cout << "  !=" << std::endl;
    std::cout << "  " << y << std::endl;

  }
}

#endif