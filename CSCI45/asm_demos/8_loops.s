/*

LAB TIME - write a loop to add up all the numbers from 0 to 9 or whatever

//Program to compute powers of 2
int main() {
	int x = 1;
	int y = 5; //2 ^ 5 power this means
	for (int i = 0; i < y; i++) { //We will actually do this by counting down
		x *= 2;
	}
	return x;
}

Note: after you run this, type "echo $?" to see the return value from a program
*/

//Note that we could do if and else using the code from 6, so this is just
//showing a different way of doing conditionals using suffixes

//R15 = PC = the memory address of the next line of code to run
//When you do a branch statement, it sets this for you!
//R14 = LR = the memory address we came from to this function. It's the return address
//So you usually end a function with BX LR, or POP {PC}

//Remember:
//B jumps to a label and nothing else
//BL jumps to a label and sets LR/R14 to the current spot in code

.global main
main:
	MOV R4, #1 //x = 1
	MOV R5, #5 //y = 5
	MOV R6, #2 //We'll be multiplying by 2, and MUL doesn't allow immediates

top:  //Top of the for loop
	//Option 1
	SUB R5, R5, #1 //y-- - We usually count down our for loops with y--, rather than i++
	CMP R5, #0

	//Better Option 2
	//The S suffix means "Do a free CMP between the destination register and 0 after the command runs"
	//S suffix is the same thing as CMP R5, #0 after the SUB runs
	SUBS R5, #1 //Same as the TWO lines above
	//The above is the same as:
	//SUB R5, #1
	//CMP R5, #0

	BLT done //If y < 0 then finish
	
	//This is the body of the loop
	MUL R4, R4, R6 //x *= 2

	//The bottom of a loop is to just jump back up to the top
	BAL top //Go back to the top of the loop

done:
	MOV R0, R4 //return x;
	BX LR  //Return from function, R0 is return value - see the result with echo $?
