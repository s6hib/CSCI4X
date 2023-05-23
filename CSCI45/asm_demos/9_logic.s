/* Logical AND
	int x = 42, y = 21;
	if (x && y) coolio(); //Short Circuit Evaluation: If x is false, it will not look at y
	else notcoolio();
*/

/* Short circuit evaluation - do not evaluate the second half if it doesn't matter
	int *arr = malloc(400);
	if (arr && *arr = 42) { //If arr is null it does NOT check arr[0] to be 42
	}
	if (x || y) //if x is true, y is not evaluated
	if (x.health <= 0 || x.conditions()) //If you are dead, it will not call conditions

// Short circuit evaluation is part of the core C/C++ languages
int *ptr = new int[100];
//....
if (ptr && ptr[0] == 42) {
...
}
if (ptr && foo(ptr)) {
...
}
//SSE also works for or statements
//If a is true, there is no reason to look at b
//So if a is true, it will not evaluate b at all
if (a || b) coolio();
*/

/*
Bitwise options:
AND R0, R1 //x = x & y
ORR R0, R1 //x = x | y
EOR R0, R1 //x = x ^ y
MOVN R0, R0 //x ~= x

Be careful using these because a lot of students think they are the logical versions, not the bitwise versions. ORR is basically no different than logical OR though.
*/

.global main
main:
	MOV R0, #42 //x = 42
	MOV R1, #21 //y = 21
	//This is doing BITWISE AND, not logical, so is bad
	/* Uncomment this to see that the answer is 0
	//x is    101010
	//y is    010101
	//x & y = 000000

	AND R0,R0,R1 //x = x & y, which will be 0...
	MOV R7, #1
	SWI 0
	*/

	//This is the straightforward way of doing logical AND
	/*
	MOV R2, #0
	CMP R0, #0
	MOVNE R2, #1
	CMP R1, #0
	ADDNE R2, #1
	CMP R2, #2
	BEQ happy
	BL notcoolio
	BAL continue

happy:
	BL coolio

continue:
	//More code here
	*/
	
	//In C++ short circuit evaluation works like this:
	//if (ptr && ptr->x == 42) will never seg fault on a null pointer
	//if (bob() || cindy()) if bob returns true, it will not even call cindy()

	//Short circuit evaluation
	CMP R0, #0
	BEQ notcoolio
	CMP R1, #0
	BEQ notcoolio
	//BAL coolio

coolio:
	//syscall exit(1)
	MOV R0, #1 //Parameters are passed to syscalls using R0-R3
	MOV R7, #1 //The OS checks R7 to see what syscall to do
	SWI 0 //Give control to the operating system

notcoolio:
	//syscall exit(0)
	MOV R0, #0
	MOV R7, #1 
	SWI 0










	
