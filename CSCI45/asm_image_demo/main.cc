#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <cstdlib>
#include <arm_neon.h>
#include <ctime>
using namespace cimg_library;
using namespace std;

//This will dump the contents of an image file to the screen
void print_image (unsigned char *in, int width, int height) {
	for (int i = 0; i < width*height*3; i++)
		cout << (unsigned int)in[i] << endl;
}

//When compiled with -Dstudent_code, this flag will be set and it will include this code. If not set, it will include the code in the #else section
#ifdef student_code
extern "C" {
	void sdarken(unsigned char *in,unsigned char *out, int width, int height);
	void greyscale(unsigned char *in,unsigned char *out, int width, int height);
}
#else 
extern "C" {
#ifdef HAVE_NEON
//This function will reduce the brightness of all colors in the image by half, and write the results to out
void darken(unsigned char *in,unsigned char *out, int width, int height) {
	uint8x16_t foo;
	for (int i = 0; i < width*height*3; i+=128) {
		foo = vld1q_u8 (in+i); 
		foo = vshrq_n_u8(foo,1); //Divide by 2
		vst1q_u8 (out+i, foo);
		//out[i] = in[i] / 2;
	}
	return;
}
#else
/* Naive C++ implementation */
void darken(unsigned char *in,unsigned char *out, int width, int height) {
	cout << "" << width << " " << height << endl;
	for (int i = 0; i < width*height*3; i++)
		out[i] = in[i] / 2;
}
#endif
}
#endif

void usage() {
	cout << "Error: this program needs to be called with a command line parameter indicating what file to open.\n";
	cout << "For example, a.out kyoto.jpg\n";
	exit(1);
}

const int NANO = 1000000000;

//Returns time in nanoseconds since launch
long high_time() {
    timespec t; //High Resolution Timer Struct
    if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&t)) {
        cout << "Error reading clock.\n";
        exit(1);
    }
    return t.tv_nsec; //Time in nanoseconds
}

int main(int argc, char **argv) {
	cout.precision(4); //Show four digits of precision
	if (argc != 2) usage(); //Check command line parameters

	//PHASE 1 - Load the image
	long start_time = high_time();
	CImg<unsigned char> in_image(argv[1]); //Load the image file
	//Create an array to write the processed data into
	CImg<unsigned char> out_image1(in_image.width(),in_image.height(),1,3,0);
	//And another array for the results of the second filter
	CImg<unsigned char> out_image2(in_image.width(),in_image.height(),1,3,0);
	long end_time = high_time();
	cerr << "Image load time: " << double(end_time - start_time)/NANO << " secs\n";

	//PHASE 2 - Do the image processing operation
	start_time = high_time();
#ifdef student_code
	sdarken(in_image,out_image1,in_image.width(),in_image.height());
	end_time = high_time();
	cerr << "Neon Darken time: " << double(end_time - start_time)/NANO << " secs\n";
	start_time = high_time();
	greyscale(out_image1,out_image2,in_image.width(),in_image.height());
	end_time = high_time();
	cerr << "Greyscale time: " << double(end_time - start_time)/NANO << " secs\n";
#else
	darken(in_image,out_image1,in_image.width(),in_image.height());
	end_time = high_time();
	cerr << "C++ Darken time: " << double(end_time - start_time)/NANO << " secs\n";
#endif

	//PHASE 3 - Write the image(s)
	start_time = high_time();
	out_image1.save_jpeg("output.jpg",50); //This saves your image with filter1 applied
#ifdef student_code
	out_image2.save_jpeg("output2.jpg",50); //This saves your image with filter1 and 2 applied
#endif
	//darkimage.save_png("output.png");
	end_time = high_time();
	cerr << "Image write time: " << double(end_time - start_time)/NANO << " secs\n";
}
