#This code darkens your code 50%
.global sdarken
sdarken:
    PUSH {LR}
    PUSH {R4-R12}        @This preserves the R4 through R12 from the calling function

	@R0 is *in
	@R1 is *out
	@R2 is width
	@R3 is height - becomes later the target memory address to stop
	MULS R4,R2,R3 @R4 will hold how many bytes to process - this is enough for the red part
	BLE quit @If image is zero size, quit
	ADD R4, R4, R4, LSL #1 @R4 *= 3 - this will make it big enough for all four colors
	ADD R3, R0, R4 @Target memory address. When R0 exceeds this, we're done
	@TODO: Make sure the size of the array is divisible by 128 bits

/* g++ version:
	MOV R2,#0
.L481:
    add ip, r0, r2
    vld1.8  {d0,d1}, [ip]
    add ip, r1, r2
    add r2, r2, #128
    vshr.u8 q0, q0, #1
    cmp r2, r4
    vst1.8  {d0,d1}, [ip]
    blt .L481
	BAL quit
*/


loop:
	VLDMIA R0!,{d0-d3} //Load 256 bits into q0 and q1
	CMP R0,R3 //See if we're done. R3 is pointer to end of the array
	VSHR.U8 q0,q0,#1 //First 128 bits shift right one bit, in 8 bit channels
	VSHR.U8 q1,q1,#1 //Second 128 bits shift right one bit
	VSTMIA R1!,{d0-d3} //Store 256 bits into *out
	BLE loop

	@Alternative Option 1 - 1024 bits at a time version
	@VLDMIA R0!,{q0-q7} //1024 bit load
	@VSHR.U8 q0,q0,#1 //First 128 bits right shift one bit, in 8 bit channels
	@VSHR.U8 q1,q1,#1 //Next 128 bits
	@VSHR.U8 q2,q2,#1 //Next 128 bits, etc.
	@VSHR.U8 q3,q3,#1
	@VSHR.U8 q4,q4,#1
	@VSHR.U8 q5,q5,#1
	@VSHR.U8 q6,q6,#1
	@VSHR.U8 q7,q7,#1
	@VSTMIA R1!,{q0-q7} //1024 bit store

	@Option 2 - Load 256 bits at once using VLD instead of VLDMIA
	@vld1.u8 {q0,q1}, [R0]!
	@vshr.u8 q0,q0,#1 //Right shift 16 chars at a time, 1 bit
	@vshr.u8 q1,q1,#1 //Right shift 16 chars at a time, 1 bit
	@vst1.u8 {q0,q1}, [R1]!

	@Option 3 - Load 128 bits at once
	@vld1.u8 {q0}, [R0]!
	@vshr.u8 q0,q0,#1 //Right shift 16 chars at a time, 1 bit
	@vst1.u8 {q0}, [R1]!
	@BAL loop

quit:
    POP {R4-R12}         @Restore R4 through R12 for the calling function
	POP {PC}             @Return from a function
