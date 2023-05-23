#include <stdio.h>
#include <math.h>
#include <stdlib.h>

extern double fun1(double x);
extern double fun2(double x, double y);
extern double fun3(double x, double y, float z);

double professor_fun1(double x) {
	unsigned int i = (unsigned int)x % 2;
	if (i) return x*-1.1;
	else return x*1.1;
}

double professor_fun2(double x, double y) {
	if (x >= y) x *= y;
	else x /= y;
	return x;
}

double professor_fun3(double x, double y, float z) {
	for (int i = 0; i < 5; i++) {
		x = sqrt(abs(x)) - z;
		y = 4*y - z;
		z += 1.1;
	}
	return x+y;
}


int main(int argc, char **argv) {
	//Call the VFP function on each of them
	double x = 0;
	double y = 0;
	float  z = 0;
	printf("Please enter x, y, and z:\n");
	//With scanf, lf is a double, f is a float
	scanf("%lf %lf %f",&x, &y, &z);

	//With printf lf and f are the same
	//TEST CASE 1
	fprintf(stderr,"fun1(%f) = %lf\n",x,fun1(x));
	fprintf(stderr,"professor_fun1(%lf) = %lf\n",x,professor_fun1(x));
	if (abs(fun1(x) - professor_fun1(x)) > 0.1)
		printf("TEST 1 FAILED\n\n");
	else
		printf("TEST 1 PASSED\n\n");

	//TEST CASE 2
	fprintf(stderr,"fun2(%f) = %lf\n",x,fun2(x,y));
	fprintf(stderr,"professor_fun2(%lf) = %lf\n",x,professor_fun2(x,y));
	if (abs(fun2(x,y) - professor_fun2(x,y)) > 0.1)
		printf("TEST 2 FAILED\n\n");
	else
		printf("TEST 2 PASSED\n\n");

	//TEST CASE 3
	fprintf(stderr,"fun3(%f) = %lf\n",x,fun3(x,y,z));
	fprintf(stderr,"professor_fun3(%lf) = %lf\n",x,professor_fun3(x,y,z));
	if (abs(fun3(x,y,z) - professor_fun3(x,y,z)) > 0.1)
		printf("TEST 3 FAILED\n\n");
	else
		printf("TEST 3 PASSED\n\n");

}
