/*
void free_array(int *arr) {
        free(arr);
    }
*/

.global free_array2
free_array2:
	PUSH {LR}
	PUSH {R4-R12}

	LDR R0, [R0]
	MOV R4, #-1
	MUL R0, R0, R4

	BL malloc

	POP {R4-R12}
	POP {PC}
