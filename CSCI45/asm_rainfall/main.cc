#include <iostream>
using namespace std;

//Type aliasing
using u32 = uint32_t; //I sometimes do this, sometimes not
using u64 = uint64_t; //This is how you type alias if you're into that kind of stuff

void die() {
	cout << "BAD INPUT!\n";
	exit(EXIT_FAILURE);
}

//You will write this in rainfall.s
extern "C" void asm_rainfall(int *arr, struct Retval *retval);

//Helper functions to do division
extern "C" u32 division(u32 x, u32 y) {
	return x / y;
}
extern "C" u32 division64(u64 x, u32 y) {
	return x / y;
}

//Helper function that will help you debug your code
//Won't get autograded as it uses cerr
extern "C" void print_int(int x) {
	cerr << x << endl;
}
extern "C" void print_uint(u32 x) {
	cerr << x << endl;
}
extern "C" void print_uint64(u64 x) {
	cerr << x << endl;
}

struct Retval {
	u32 sunny_days; //You will write here how many days had 0 rain
	u32 rainy_days; //How many days had >= 1 inch of rain
	u32 total_days; //sunny_days + rainy_days basically
	u32 avg_rainfall; //Average rainfall across all days
	u32 avg_rain_on_rainy_days; //Average rainfall just on rainy days
	u32 max_rainfall; //How much rain the rainiest day had
};

int main() {
	cout << "Please enter a random seed (0 for current time, -1 to enter data manually):\n";
	int seed = 0; 
	cin >> seed;
	if (!cin) die();
	if (seed) srand(seed);
	else srand(time(0));
	cout << "How many days of rainfall data do you want to generate? (Max one year)\n";
	int size = 0;
	cin >> size;
	if (!cin or size <= 0 or size > 366) die();
	int *arr = new int[size+1];
	if (!arr) die();
	if (seed == -1) {
		for (int i = 0; i < size; i++) {
			cout << "Please enter the rainfall data for day " << i << ": " << endl;
			int temp = 0;
			cin >> temp;
			if (!cin) die();
			arr[i] = temp;
		}
		arr[size] = -1; //Terminate array with a -1
	}
	else {
		cout << "How much rain on average do you want to get on rainy days?\n";
		int intensity = 0;
		cin >> intensity;
		if (!cin or intensity < 0) die();

		cout << "What percentage (0 to 100) of days are sunny?\n";
		int sun_percentage = 0;
		cin >> sun_percentage;
		if (!cin or sun_percentage < 0 or sun_percentage > 100) die();

		//Generate the rainfall 
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % (intensity * 2) + 1;
			//Throw some errors in 1% of the time
			if (rand() % 100 == 0) arr[i] = -1 * arr[i] - 1;
			//Make a certain percentage of days sunny
			else if (rand() % 100 < sun_percentage) arr[i] = 0;
			//static_assert(0,"Delete this to get your code to compile. You can delete the next line too, if it is causing you to disconnect.");
			//print_int(arr[i]); //You can delete this if it's too spammy
		}
		//Terminate with a -1
		arr[size] = -1;
	}
	Retval retval;
	cout << "Calling asm_rainfall...\n";
	asm_rainfall(arr,&retval);
	cout << "...returned from asm_rainfall.\n";
	cout << "Sunny days: " << retval.sunny_days << endl;
	cout << "Rainy days: " << retval.rainy_days << endl;
	cout << "Total days: " << retval.total_days << endl;
	cout << "Average rainfall: " << retval.avg_rainfall << endl;
	cout << "Average rain on rainy days: " << retval.avg_rain_on_rainy_days << endl;
	cout << "Max Rainfall: " << retval.max_rainfall << endl;
	delete[] arr; //Don't leak memory
}
