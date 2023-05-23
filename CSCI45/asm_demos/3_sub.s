/*
int main() {
	int x = 100;
	x = x - 58;
	return x;
}

Note: after you run this, type "echo $?" to see the return value from a program
*/

.global main
main:
	MOV R0, #100 //R0 is always the return value from a function
	SUB R0, R0, #58 //x = x - 58
	RSB R0, R0, #10 //x = 10 - x - reverse subtract is for when you need a constant in the first operand
	BX LR  //Return from function, R0 is return value
