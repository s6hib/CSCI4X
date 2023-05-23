//This code averages the R,G,B values for each point to make it greyscale
.global greyscale
greyscale:
    PUSH {LR}
    PUSH {R4-R12}        @This preserves the R4 through R12 from the calling function

	@R0 is *in
	@R1 is *out
	@R2 is width
	@R3 is height
	MULS R4,R2,R3 @R4 will hold how many bytes to process - this is enough for the red part
	MOV R3, #21845 //Used in the multiply below
	BLE quit @If image is zero size, quit
	ADD R5, R0, R4 @R5 is the start of the green plane for input
	ADD R6, R5, R4 @R6 is the start of the blue plane for input
	ADD R7, R1, R4 @R7 is the start of the green plane for output
	ADD R8, R7, R4 @R8 is the start of the blue plane for output
	MOV R9, #0 //Your i

	@TODO: Make sure the size of the array is divisible by 128 bits

loop:
	LDRB R10, [R0,R9] //Loads red value
	LDRB R11, [R5,R9] //Loads green value
	LDRB R12, [R6,R9] //Loads blue value
	ADD R2, R10, R11 //Adds red and green
	ADD R2, R10, R12 //Add in blue
	//Do the average here, divide R2 by 3
	//Bad way:
	//MOV R2, R2, LSR #1 //Divide by 2, which is not a good average
	//Better way:
	//Multiply by 85 then divide by 256
	MUL R2, R2, R3 //Multiply by 21845
	MOV R2, R2, LSR #16 //Divide by 65536

	STRB R2, [R1,R9] //Store the red value
	STRB R2, [R7,R9] //Store the green value
	STRB R2, [R8,R9] //Store the blue value
	
	ADD R9, R9, #1
	CMP R9,R4
	BLT loop

quit:
    POP {R4-R12}         @Restore R4 through R12 for the calling function
	POP {PC}             @Return from a function
