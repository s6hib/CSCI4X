//Write the assembly equivalent of this C++ code:
//int baz(int x, int y, int z) { return 5*x + 5*x*y + 5*x*y*z; }
//Par: 11 strokes

.global baz
baz:
	ADD R3, R0, R0, LSL #2
    MUL R4, R3, R1
    MUL R5, R4, R2
    ADD R0, R3, R4
    ADD R0, R0, R5

BX LR
