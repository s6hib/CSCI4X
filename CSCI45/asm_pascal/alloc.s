/*
int* alloc_array(const int ROWS, const int COLS) {
        return (int*) malloc(sizeof(int)*ROWS*COLS); //4 bytes x ROWS x COLS alloced
    }
*/

.global alloc_array2
alloc_array2:
	
	PUSH {LR}
	PUSH {R4-R12}

	MUL R0, R1, R0
	LSL R0, #2
	BL sbrk

	POP {R4-R12}
	POP {PC}
