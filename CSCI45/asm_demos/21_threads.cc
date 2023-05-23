//compile with g++ -std=c++2a -O3 21_threads.cc -pthread
#include "/public/read.h"
#include <thread>
#include <vector>
#include <chrono>
#include <numeric>
using namespace std;

//Thread tutorial:
	//This spawns off a thread to run the function chamillionaire on a different CPU
	//thread t1(chamillionaire)
	//If you want to wait for t1 to finish:
	// t1.join();
	//If you don't want to join, then do this instead:
	// t1.detach();

int THREADS = 1; //How many threads we want
vector<int> vec; //Holds the data to sum up
vector<int64_t> retval; //Give each thread its own place to return a sum

//ID is our thread id
void charmillionaire(int id) {
	//We could also get our id like this:
	//std::thread::id this_id = std::this_thread::get_id();
	int64_t sum = 0;

	//We hoist the size out of the loop since it will not change
	//The optimizer will try to hoist, but it is not always successful
	// since it sometimes can't prove size will not change in the loop
	size_t hoist = vec.size(); 
	//TODO: Have each thread only compute its fraction of the vector
	// Right now each thread is adding up the entire vector
	for (size_t i = 0; i < hoist; i++) {
		sum += vec[i];
	}
	retval.at(id) = sum;
}
int main() {
	const int SIZE = read("How many values do you want?\n");
	vec.resize(SIZE);
	//Fill with random data of data between 1 and 10
	generate(vec.begin(),vec.end(),[](){ return rand()%10+1; });
	cout << "Sum: " << accumulate(vec.begin(),vec.end(),int64_t(0)) << endl;
	
	//To avoid a race condition, each thread has its own return value
	// in the retval vector. Thread 0 will return into retval.at(0), etc.
	THREADS = read("How many threads do you want?\n");
	retval.resize(THREADS); 

	const auto start = std::chrono::steady_clock::now();
	vector<thread> threads;
	for (int i = 0; i < THREADS; i++) {
		//thread t1(charmillionaire,i); //This is how you spawn a thread
		threads.push_back(thread(charmillionaire,i)); 
	}
	cout << "They see me rollin'" << endl;
	cout << "They hatin'" << endl;

	//...

	//In the meantime... the threads will be doing computations on different CPUs

	//...

	//Wait for all the threads to finish
	for (int i = 0; i < THREADS; i++) {
		threads.at(i).join(); //Wait for thread 0 to finish, then thread 1, then thread 2...
	}
	//We add up all the retvals to get the final sum
	cout << "Threads returned a sum of: " << accumulate(retval.begin(),retval.end(),int64_t(0)) << endl;

	//And finally we print how long all this took
	const auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "Total running time: " << diff.count() << endl;
}
