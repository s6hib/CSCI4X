#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <ctime>

class Timer {
public:
  Timer(std::string description);
  void start();
  void stop();
  double getSecondsElapsed() const;
  void printData() const;
private:
  std::string description;
  clock_t begin;
  clock_t end;
};

#endif /* TIMER_H */