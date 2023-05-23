/*
    //Section A - Getters and Setters, C Style
    int get(int *arr, int COLS, int y, int x) {
        //NOTE: We are not bounds checking on the bottom of the array!
        //This is because we're not passing in ROWS
        if (y < 0 or x < 0 or x >= COLS) return 0;
        return arr[y*COLS+x];
    }
*/

.global get2
get2:

	PUSH {LR}
	PUSH {R4-R12}

	CMP R2, #0
	BLT return
	
	CMP R3, #0
	BLT return

	CMP R3, R1
	BGE return

	MLA R4, R2, R1, R3
	
	LDR R0, [R0, R4, LSL #2]

	BAL done

return:
	MOV	R0, #0

done:
	POP {R4-R12}
	POP {PC}
