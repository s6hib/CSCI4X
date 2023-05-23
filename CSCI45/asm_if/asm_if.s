	.global asm_if		@DM - Don't modify
asm_if:					@DM - Don't modify


ORRS R0, R0, R1
ORRGTS R0, R2, R3
MOVGT R0, #1

BX LR

