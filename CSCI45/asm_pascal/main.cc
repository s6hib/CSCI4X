#include <iostream>
#include <cstdlib> //Malloc; Free
#include "/public/colors.h"
#include "/public/read.h"
using namespace std;

extern "C" {
	//Utility functions, these you can't rewrite into ASM for credit
	int mod_10(int x) {
		return x % 10;
	}
	bool divisible(int x, int y) {
		return x % y == 0;
	}
	int get_cols() {
		auto [rows,cols] = get_terminal_size();
		return cols;
	}
	int get_rows() {
		auto [rows,cols] = get_terminal_size();
		return rows;
	}
	struct Color {
		unsigned char R,G,B;
	};
	//Prints the color for value val at location (x,y) using the color palette selected by colors
	void print_color(int val, int x, int y, int colors) {
		resetcolor();
		movecursor(x,y);
		//Palette holds all the color schemes we have loaded, just "1" by default
		vector<vector<Color>> palette;
		//This is how you make a new color palette
		vector<Color> default_palette = { //10 colors since we are doing Mod 10 by default
			{20,20,20},
			{0,63,92},
			{88,80,141},
			{138,80,143},
			{188,80,144},
			{222,90,121},
			{255,99,97},
			{255,133,49},
			{255,166,0},
			{80,40,2}
		};

		vector<Color> second_palette = { //xtra credit palette
            {200, 194, 16},
			{23, 123, 200},
			{200, 23, 182}
        };

		vector<Color> third_palette = { //xtra credit palette
            {142, 21, 242},
            {56, 242, 21},
            {255, 54, 0}
        };

		//Extra Credit: Make your own sets of palettes add them to the palette list like this:
		palette.push_back(default_palette); //This is just so there is a colors 0, ignore this
		palette.push_back(default_palette); //Colors == 1 picks the default palette
		palette.push_back(second_palette);  //xtra credit palette
		 palette.push_back(third_palette);  //xtra credit palette

		if (colors >= (int)palette.size()) {
			cout << "Palette not found!\n";
			exit(1);
		}

		//Extra Credit: Experiment with different modulus values (or primes) for your new palettes
		//I use the size of the palette by default
		val = abs(val) % palette.at(colors).size();

		unsigned char R = palette.at(colors).at(val).R;
		unsigned char G = palette.at(colors).at(val).G;
		unsigned char B = palette.at(colors).at(val).B;
		setbgcolor(R,G,B);

		//Compile with -DDEBUG to enable printing the values on top of the colors!
#ifdef DEBUG
		cout << val;
#else
		cout << ' ';
#endif
	}

	//Section A - Getters and Setters, C Style
	int get(int *arr, int COLS, int y, int x) {
		//NOTE: We are not bounds checking on the bottom of the array!
		//This is because we're not passing in ROWS
		if (y < 0 or x < 0 or x >= COLS) return 0;
		return arr[y*COLS+x];
	}
	//NOTE: Load the fifth parameter via: LDR r4, [sp]
	void set(int *arr, int COLS, int y, int x, int val) {
		arr[y*COLS+x] = val;
	}

	int get2(int *arr, int COLS, int y, int x);
	void set2(int *arr, int COLS, int y, int x, int val);

	//Section B - New and Delete, C Style
	int* alloc_array(const int ROWS, const int COLS) {
		return (int*) malloc(sizeof(int)*ROWS*COLS); //4 bytes x ROWS x COLS alloced
	}
	void free_array(int *arr) {
		free(arr);
	}

int* alloc_array2(const int ROWS, const int COLS);
void free_array2(int *arr);

	//Section C - Constructor, C Style
	void init_array(int *arr, const int ROWS, const int COLS) {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				set2(arr,COLS,i,j,0);
			}
		}
		//Start off with a 1 in the middle of the top row
		set2(arr,COLS,0,COLS/2,1);
	}

	//Section D - Pascal's Triangle
	//This function computes the value of (n choose k) from combinatorics
	//Also makes a cool looking triangle
	void pascal(int *arr, const int ROWS, const int COLS, int row) {
		if (row < 1 || row >= ROWS) return; //Bound check
		for (int i = 0; i < COLS; i++) {
			int x = get2(arr,COLS,row-1,i-1); //Get element northwest of us
			int y = get2(arr,COLS,row-1,i+1); //Get element northeast of us
			int sum = x + y; //PASCAL'S VERY COMPLEX ALGORITHM
			set2(arr,COLS,row,i,sum);
		}
	}
	//Section E - Operator<<, C Style
	void print(int *arr, const int ROWS, const int COLS, int colors) {
		if (!colors) { //Print the triangle out using text
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					int val = get2(arr,COLS,i,j);
					if (val == 0) cout << ' ';
					else cout << mod_10(val); //Just print last digit so it lines up ok
				}
				cout << endl;
			}
		}
		else { //Print colors
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					int val = get2(arr,COLS,i,j);
					print_color(val, i+1, j, colors);
				}
			}
			cout << RESET << endl;
		}
	}
}

int main() {
	int ROWS = get_rows(); //y
	int COLS = get_cols(); //x
	clearscreen();
	cerr << "Welcome to ASM Pascal! Screen size: " << ROWS << " rows and " << COLS << " cols" << endl;
	ROWS = read("How many rows do you want?\n"); //Note: Anything over 34 will overflow!
	COLS = read("How many cols do you want?\n");
	int colors = read("Do you want 0) Text Output 1) Color Output?\n");
	int *arr = alloc_array2(ROWS,COLS); //Alloc an array of ints of size ROWSxCOLS
	init_array(arr, ROWS, COLS); //Initialize the array to all 0s except one 1 in the middle of the top row
	for (int i = 0; i < ROWS; i++) //Run the Pascal's Triangle algorithm
		pascal(arr,ROWS,COLS,i);
	print(arr,ROWS,COLS,colors); //Print it to the screen either in text or with colors
	resetcolor(); //Stop it from screwing up our colors

	free_array2(arr); //Free the array
}
