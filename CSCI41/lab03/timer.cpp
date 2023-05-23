#include "timer.h"

#include <iostream>
using namespace std;

Timer::Timer(std::string description): description(description) {}

void Timer::start() {
  // FΙХME: set begin appropriately
}

void Timer::stop() {
  // FΙХME: set end appropriately
}

double Timer::getSecondsElapsed() const {
  // FΙХME: calculate the number of seconds between start() and stop()
  return 0;
}

void Timer::printData() const {
  cout << description << ": " << getSecondsElapsed() << " seconds" << endl;
}