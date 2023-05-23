#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

extern "C" {
    int function_one(unsigned char *in, unsigned char *out, size_t width, size_t height);
    int function_two(int *arr, size_t n, unsigned int stride);
}

int main(int argc, char **argv) {
    int retval;
    cout << "We have " << argc << " command line parameter(s)\n";
    cout << "Parameters are:\n";
    for (int i = 0; i < argc; i++) {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }

    // Create and initialize an array
    vector<int> arr1 = {3, 7, 11, 17, 23, 31};
    size_t arr1_size = arr1.size();

    vector<unsigned char> in(256);
    vector<unsigned char> out(256);
    size_t width = 16, height = 16;
    for (size_t i = 0; i < in.size(); i++) {
        in[i] = static_cast<unsigned char>(i);
    }

    // Call the assembly functions with the created arrays
    clock_t start_time = clock();
    retval = function_one(in.data(), out.data(), width, height);
    clock_t end_time = clock();
    cout << "Running time for function_one: " << end_time - start_time << " ticks\n";
    cout << "function_one returned: " << retval << endl;

    start_time = clock();
    retval = function_two(arr1.data(), arr1_size, 2);
    end_time = clock();
    cout << "Running time for function_two: " << end_time - start_time << " ticks\n";
    cout << "function_two returned: " << retval << endl;
}

