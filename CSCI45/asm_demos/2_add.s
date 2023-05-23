/*
int main() {
	int x = 10;
	int y = 89;
	x = x + y;
	x += 42;
	return x;
}

Note: after you run this, type "echo $?" to see the return value from a program
*/

.global main
main:
	MOV R0, #10 //R0 is always the return value from a function
	MOV R1, #89
	ADD R0, R0, R1 //x = x + y
	//Almost every three parameter command (like ADD, SUB, etc.) have a flexible third parameter
	//The third parameter can either be a register or a constant int
	ADD R0, R0, #42 //x = x + 42
	BX LR  //Return from function, R0 is return value
