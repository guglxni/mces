	AREA RESET,CODE
	ENTRY
	LDR R0,=NUMS
	MOV R4,#10
	MOV R2,#0
CONT
	LDR R3,[R0]
	ADD R2,R3
	ADD R0,#4
	SUBS R4,#1
	BNE CONT
	MOV R4,#10
	MOV R5,#0
LOOP
	SUBS R2,R4
	ADDPL R5,R5,#1
	BPL LOOP
	
	LDR R6,=ANS
	STR R5,[R0]
	
STOP B STOP

NUMS DCD 5,11,6,9,3,1,59,45,10,34

	AREA MEMORY,DATA
ANS SPACE 4

END