/* Homework 2 - Assembly Fizzbuzz
 Your program must print the numbers from 1 to 100, except when:
 1) If the number is divisible by 15, print FizzBuzz instead, if not:
   2) If the number is divisible by 3, print Fizz instead
   3) If the number is divisible by 5, print Buzz instead
 I have provided you functions that will do the printing, you just need
 to do the control logic.

 Don't modify the C file at all, or your house will lose 50 points.

 Don't use R0 through R3 in this function (except in the one example below)
 They get overwritten every time you call a function.
 So use R4 through R10 for your logic

Any line marked with DM ("Don't Modify") should probably be left alone.
The rest of the source code is just example source code and can be deleted or changed.
*/




.global fizzbuzz         @DM - Don't modify
fizzbuzz:                @DM - Don't modify
   	PUSH {LR}            @DM: Preserve LR for the calling function
    PUSH {R4-R11}        @DM: This preserves the R4 through R12 from the calling function

  	
	MOV R4, #0   	// initialize
	
	MOV R5, #3   	// used to check for fizz
	MOV R6, #5   	// used to check for buzz
	MOV R7, #15  	// used to check for both
    

start:
	ADD R4, R4, #1  // R4++

	CMP R4, R7      // check for both
	BEQ fizzbuzzed  // if equal, go to fizzbuzzed

	CMP R4, R5		// check for fizz
	BEQ fizz		// if equal, go to fizz

	CMP R4, R6		// check for buzz
	BEQ buzz		// if equal, go to buzz

regular:			// this will print a regular number that isn't divisible by anything
	MOV R0, R4		// R0 = R4
	BL print_number // print R0
	BAL start		// go back to the start


fizz:				// if sent here, print out fizz 
	BL print_fizz	// print fizz
	ADD R5, R5, #3	// add another 3 to R5 for the next set of numbers
	BAL start		// go back to the start

fizzbuzzed:				// if sent here, print fizzbuzz
	BL print_fizzbuzz	// print fizzbuzz
	ADD R7, R7, #15
	ADD R6, R6, #5
	ADD R5, R5, #3		// add another 3, 5, and 15 to each reg for the next set of numbers
	BAL start			// go back to the start

buzz:				// if sent here, print buzz
	BL print_buzz	// print buzz
	ADD R6, R6, #5	// add another 5 for the next set

// important that we have this line under buzz since we can use it to check if we've reached 100
// this is because if we keep adding to 5 if will become 100 eventually, which is when we should stop

	CMP R4, #100 	// check if R4 is at 100 yet
	BNE start		// if it isn't we need to go back to the start and keep going, if it is then we're done

return:
    POP {R4-R11}         @DM: Restore R4 through R12 for the calling function
    POP {PC}             @DM: Return from a function
