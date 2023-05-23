/*
int main() {
	int x = 32;
	int y = 20;
	if (x > y) {
		x++; //This is just placeholder code
		x++;
		x++;
		x++;
		x++;
		x++;
		x++;
		x++;
		x++;
		x++;
		x++;
	}
	else {
		x--; //Pretend we're doing something useful here
		x--;
		x--;
		x--;
		x--;
		x--;
		x--;
		x--;
		x--;
		x--;
	}
	return x;
}

Note: after you run this, type "echo $?" to see the return value from a program
*/

//Note that if we return -10 from main, UNIX will underflow the result and show 246

.global main
main:
	MOV R1, #32 //x = 32
	MOV R2, #20 //y = 20
	CMP R1,R2 	//x <=> y
	//BAL - Branch Always
	//BGT - Branch if Greater Than
	//BGE - Branch if Greater Than or Equal To
	//BLT - Branch if Less Than
	//BLE - Branch if Less Than or Equal To
	//BEQ - Branch if Equal (x == y)
	//BNE - Branch if Not Equal (x != y)

	//If you comment out the BGT, it won't change the code since it will fall through
	BGT L1 		//if (x > y) {...}
	BLE L2		//else {...}

L1: ADD R0, R0, #1 //x = x + 1
	ADD R0, #1     //x = x + 1, alternate skin
	ADD R0, R0, #1
	ADD R0, R0, #1
	ADD R0, R0, #1
	ADD R0, R0, #1
	ADD R0, R0, #1
	ADD R0, R0, #1
	ADD R0, R0, #1
	ADD R0, R0, #1
	ADD R0, R0, #1
	BAL done //This is kind of like the } at the end of an if statement

L2:
	SUB R0, #1 //There are usually two parameter versions that are like x--
	SUB R0, R0, #1 //x -= 1, alternate outfit
	SUB R0, #1
	SUB R0, #1
	SUB R0, #1
	SUB R0, #1
	SUB R0, #1
	SUB R0, #1
	SUB R0, #1
	SUB R0, #1
	BAL done //Not necessary, if you delete it it will continue to the BX LR line

done:
	BX LR  //Return from function, R0 is return value


/* If you want to do this with conditional moves instead...

int main() {
	int x = 32;
	int y = 20;
	if (x > y) x = 68;
	else x = -10;
	return x;
}

.global main
main:
	MOV R1, #32 //x = 32
	MOV R2, #20 //MP R1,R2
	CMP R1,R2
	MOVGT R0, #68
	MOVLE R0, #-10

	BX LR  //Return from function, R0 is return value
*/
