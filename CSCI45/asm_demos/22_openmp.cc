//OpenMP is a simple way to parallelize code
//#include <omp.h> brings in OpenMP
//Then compile with g++ -std=c++2a 22_openmp.cc -fopenmp
//Key Ideas:
//OpenMP - Parallelize the next for loop:
//   #pragma omp parallel for
//OpenMP - Spawn 10 threads that each run the next block of code:
//   #pragma omp parallel num_threads(10)
//Get my thread number:
//   int id = omp_get_thread_num();

#include "/public/read.h"
#include <omp.h>
#include <vector>
#include <chrono>
#include <numeric>
using namespace std;

vector<int> vec;

//Sum up the entire vector
int64_t chamillionaire(int id) {
	int64_t sum = 0;
	// If we weren't doing this in threads we could do this:
	//#pragma omp parallel for
	//And then it would automatically parallelize
	//TODO: Figure out which fraction of the vector is ours and add it up
	//Right now each thread will return the entire sum, which is wrong
	for (size_t i = 0; i < vec.size(); i++) 
		sum += vec[i];
	return sum;
}

int main(){
	const int SIZE = read("How many values do you want?\n");
	vec.resize(SIZE);
	//Fill with random data of data between 1 and 10
	generate(vec.begin(),vec.end(),[](){ return rand()%10+1; });
	cout << "Sum: " << accumulate(vec.begin(),vec.end(),int64_t(0)) << endl;
	
	//To avoid a race condition, each thread has its own return value
	// in the retval vector. Thread 0 will return into retval.at(0), etc.
	const int THREADS = read("How many threads do you want?\n");

	const auto start = std::chrono::steady_clock::now();
	int64_t sum = 0;
  #pragma omp parallel num_threads(THREADS)
	{
		int id = omp_get_thread_num();
		sum += chamillionaire(id);
	}
	cout << "OpenMP returned a value of: " << sum << endl;

	//And finally we print how long all this took
	const auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "Total running time: " << diff.count() << endl;
}
