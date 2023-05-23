#include "/public/read.h"
#include <chrono>
#include <numeric>
#include <queue>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;
using namespace std::chrono; //Chrono code from cppreference
using hrc = chrono::high_resolution_clock; //Chrono code from cppreference

int main() {
	cout << "Welcome to Data Structure Speed Test.\nWe will generate random data and average them together using different data structures.\n";
	int choice = read("0. 1D heap array\n1. 2D stack array\n2. 1D vector\n3. 2D vector of vectors\n4. Linked List\n5. Forward List\n6. Deque\n");
	if (choice < 0 or choice > 6) return 0;
	int size = read("How many elements total?\n");
	if (size <= 0) return 0;

	//Generate random data then accumulate it depending on our data structure of choice
	hrc::time_point t1 = hrc::now();
	int64_t sum = 0;
	if (choice == 0) {
		int *arr = new int[size];
		for (int i = 0; i < size; i++) arr[i] = rand() % 100;
		//Yes we must do this in a separate loop
		for (int i = 0; i < size; i++) sum += arr[i];
		delete[] arr;
	}
	else if (choice == 1) {
		size = sqrt(size);
		int arr[size][size]; //Will crash if you exceed stack size
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				arr[i][j] = rand() % 100;
				//arr[j][i] = rand() % 100;
		//Option 1 - Row Major Order
		//Option 2 - Column Major Order
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				//sum += arr[j][i];
				sum += arr[i][j];
	}
	else if (choice == 2) {
		vector<int> vec(size);
		//Option 1 - Use .at() for safety
		//Option 2 - Use [] for speed
		for (int i = 0; i < size; i++) vec.at(i) = rand() % 100;
		//Yes we must do this in a separate loop
		for (int i = 0; i < size; i++) sum += vec.at(i);
	}
	else if (choice == 3) {
		size = sqrt(size);
		cout << size << endl;
		vector<vector<int>> vec(size,vector<int>(size));
		//Option 1 - Use .at() for safety
		//Option 2 - Use [] for speed
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				vec.at(i).at(j) = rand() % 100;
				//vec[i][j] = rand() % 100;
		//Option 1 - Do the loop ourself
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				sum += vec.at(i).at(j);
				//sum += vec[i][j];
		//Option 2 - Try std::accumulate()
	}
	else if (choice == 4) {
		list<int> li;
		//Option 1 - Use .push_back
		//Option 2 - Use .push_front
		for (int i = 0; i < size; i++) li.push_back(rand() % 100);
		//Yes we must do this in a separate loop
		for (auto it = li.begin(); it != li.end(); it++) sum += *it;
	}
	else if (choice == 5) {
		//Option 1 - No optimize
		//Option 2 - -O1
		//Option 3 - -O3
		forward_list<int> li;
		for (int i = 0; i < size; i++) li.push_front(rand() % 100);
		//Yes we must do this in a separate loop
		for (auto it = li.begin(); it != li.end(); it++) sum += *it;
	}
	else if (choice == 6) {
		deque<int> dec(size);
		//Option 1 - Use .at() for safety
		//Option 2 - Use [] for speed
		for (int i = 0; i < size; i++) dec[i] = rand() % 100;
		//Yes we must do this in a separate loop
		for (int i = 0; i < size; i++) sum += dec[i];
	}
	cout << "Sum: " << sum << endl;
	hrc::time_point t2 = hrc::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	cerr << "Time: " << time_span.count() << endl;
}
