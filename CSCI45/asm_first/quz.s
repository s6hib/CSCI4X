//Write the C++ equivalent of this code:
//int quz(int x, int y, int z, int w) { return (x-y)*(z+w) - (x-y)*(-1*z + -1*w); }
//Par: 7 strokes

.global quz
quz:
	SUB R4, R0, R1
	ADD R5, R2, R3
	MUL R6, R5, R4

	NEG R7, R2
	NEG R8, R3
	ADD R9, R7, R8
	MUL R10, R4, R9

	SUB R0, R6, R10



	BX LR
