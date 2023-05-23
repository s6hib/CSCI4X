//make this in asm
//void asm_rainfall(arr,&retval);

.global asm_rainfall
asm_rainfall:

    PUSH {LR} // save the Link Register, which holds the return address
    PUSH {R4-R12} // save the registers R4-R12

    // initialize everything
    MOV R4, R0 // move the first argument, arr, to register R4
    MOV R5, R1 // move the second argument, retval, to register R5
    MOV R7, #0 // set R7 (counter variable for the loop) to 0
    MOV R8, #0 // set R8 (accumulator variable for the rainfall) to 0
    MOV R9, #0 // set R9 (counter variable for the sunny days) to 0
    MOV R10, #0 // set R10 (counter variable for the rainy days) to 0
    MOV R11, #0 // set R11 (maximum rainfall) to 0

loop: 
	LDR R6, =#366 // load the constant value 366 into R6
    CMP R7, R6 // compare R7 (the loop counter) to 365
    BGE final // if R7 >= 365, go to the final label
    MOV R6, #4 // move the constant value 4 into R6
    MUL R6, R6, R7 // multiply R6 (4) by R7 (the loop counter) and store the result in R6
    LDR R6, [R4,R6] // load the value at the memory address R4+R6 into R6
    ADD R7, R7, #1 // increment the loop counter R7 by 1
    CMP R6, #-1 // compare R6 to -1
    BEQ final // if R6 == -1, go to the final label
    CMP R6, #0 // compare R6 to 0
    BEQ sunny // if R6 == 0, go to the sunny label
    CMP R6, #-1 // compare R6 to -1
    BLT loop // if R6 < -1, go back to the loop label
    ADD R10, R10, #1 // increment the counter for rainy days R10 by 1
    ADD R8, R8, R6 // add the rainfall value R6 to the accumulator variable R8
    CMP R11, R6 // compare R11 to R6 (the maximum rainfall so far)
    MOVLE R11, R6 // if R6 <= R11, set R11 to R6
    BAL loop // go back to the loop label

sunny:
	ADD R9, R9, #1 // increment the counter for sunny days R9 by 1
    BAL loop // go back to the loop label until the loop ends

final: 
	STR R8, [R5, #12] // store the total rainfall in the output structure at R5+12
    STR R9, [R5] // store the number of sunny days in the output structure at R5
    STR R10, [R5, #4] // store the number of rainy days in the output structure at R5+4
    ADD R9, R9, R10 // add the number of sunny days R9
	STR R9, [R5, #8] // store total_days in output structure
    STR R11, [R5, #20] // store rain_max in output structure
    MOV R0, R8 // move rain_total to R0 for division calculation
    MOV R1, R9 // move total_days to R1 for division calculation
    CMP R1, #0  // check if total_days is zero (avoid division by zero)
    BLNE division // if not zero, jump to division function
    STR R0, [R5, #12] // if zero, set rain_total to 0 in output structure
    MOV R0, R8 // move rain_total to R0 for division calculation
    MOV R1, R10 // move rain_days to R1 for division calculation
    CMP R1, #0 // check if rain_days is zero (avoid division by zero)
    BLNE division // if not zero, jump to division function
    STR R0, [R5, #16] // if zero, set rain_average to 0 in output structure
    BAL done // jump to done label

done:
    POP {R4-R12} //Restore saved registers
    POP {PC} //Return to Link Register

