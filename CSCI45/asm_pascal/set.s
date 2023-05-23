/*
 //NOTE: Load the fifth parameter via: LDR r4, [sp]
    void set(int *arr, int COLS, int y, int x, int val) {
        arr[y*COLS+x] = val;
    }
*/

.global set2
set2:

	LDR R12, [sp]

	PUSH {LR}
	PUSH {R4-R12}

	MLA R5, R1, R2, R3
	STR R12, [R0, R5, LSL #2]

	POP {R4-R12}
	POP {PC}
