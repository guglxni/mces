	AREA RESET,CODE
	ENTRY
	MOV R4,#0
	MOV R3,#0
	LDR R0,=INPUT
	LDR R6,=OUTPUT
LOOP	
	LDR R2,[R0],#4
	ADD R4,R2
	ADD R3,#1
	CMP R3,#5
	BNE LOOP
	MOV R2,#5
	MOV R3,#0
CONT
	SUBS R4,R4,R2
	ADD R3,R3,#1
	BPL CONT
	SUB R3,#1
	STR R3,[R6]
	
INPUT DCD &01,&02,&03,&04,&05
	AREA MEMORY,DATA
OUTPUT SPACE 4
	