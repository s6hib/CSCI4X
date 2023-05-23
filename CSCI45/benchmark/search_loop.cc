#include <iostream>
#include <chrono>
using namespace std;

bool check_prime(long long int n);

int main() {

auto start = std::chrono::steady_clock::now();

for(long long int i = 100'000'000; i < 100'000'082; i++){

 if (check_prime(i))
    cout << i << " is a prime number." << endl;
//  else
//    cout << i << " is not a prime number." << endl;
}

auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

  return 0;
}
