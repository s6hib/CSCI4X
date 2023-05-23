.global fun1
fun1:
    PUSH {LR}             @This is how you function
    PUSH {R4-R12}        @Remember?

    //Write your code here
vcvt.u32.f64 s0, d0
vmov.u32 r0, s0
ANDS r0, r0, #1
LDR r4, =D_1_1
LDR r5, =DN_1_1
VLDR.F64 D2, [r4]
VLDR.F64 D3, [r5]
BEQ skip

//fallthrough
VMUL.F64 D0, D0, D3
BAL quit1

skip:
VMUL.F64 D0, D0, D2

quit1:
    //NOTE: Return your value in D0
    POP {R4-R12}         @Restore R4 through R12 for the calling function
    POP {PC}             @Return from a function



.global fun2
fun2:
    PUSH {LR}             @This is how you function
    PUSH {R4-R12}        @Remember?

    //Write your code here
    vcmp.f64 d0, d1
    VMRS APSR_nzcv, FPSCR
    BLT jumpLess

    //if not jumped, must be in greater than case
    VMUL.f64 d0, d0, d1
    BAL quit2

jumpLess:
    VDIV.f64 d0, d0, d1

quit2:
    POP {R4-R12}         @Restore R4 through R12 for the calling function
    POP {PC}             @Return from a function




.global fun3
fun3:
    PUSH {LR}             @This is how you function
    PUSH {R4-R6}          @Remember?

    // Initialize loop counter
    mov r6, #5

    // Store z in d7 (has to be converted to double)
    vcvt.f64.f32 d7, s4

    LDR R5,=D_1_1
    VLDR D3,[R5]

    LDR R5,=D_4
    VLDR D4,[R5]

loop:
    // Calculate x
    VABS.f64 d0, d0
    VSQRT.f64 d0, d0
    VSUB.f64 d0, d0, d7

    // Calculate y
    VMUL.f64 d1, d1, d4
    VSUB.f64 d1, d1, d7

    // Calculate z
    VADD.f64 d7, d7, d3

    // Loop stuff
    SUBS R6, R6, #1
    BGT loop

    // Add return value
    VADD.f64 D0, D0, D1

quit3:
    POP {R4-R6}         @Restore R4 through R6 for the calling function
    POP {PC}             @Return from a function


.data
F_ZERO: .float 0
D_ZERO: .double 0
D_1_1: .double 1.1
DN_1_1: .double -1.1
D_4: .double 4
