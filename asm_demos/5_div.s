/*
int main() {
	int x = 32;
	int y = 8;
	int z = x / y;
	return z;
}

Note: after you run this, type "echo $?" to see the return value from a program
*/

//THERE IS NO DIVIDE COMMAND, BUT...
//We can right shift to do division by powers of 2

//1011 = 8*1 + 4*0 + 2*1 + 1*1 = 8 + 2 + 1 = 11
//If we right shift 1011 once, it becomes 101. All the digits move right one spot, and 0s fill in
//101 = 4*1 + 2*0 + 1*1 = 4 + 1 = 5
//So 11 / 2 = 5
//If we right shift 1011 twice, it becomes 10. So 11 / 4 = 2

.global main
main:
	MOV R0, #32 //x = 32;
	MOV R0, R0, LSR #3 //x = x >> 3; (Divide by 2^3.)
	BX LR  //Return from function, R0 is return value
