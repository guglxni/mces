	AREA RESET,CODE
	ENTRY
	MOV R0,#35
	MOV R1,#50
LOOP	
	CMP R0,R1
	BEQ EXIT
	BGT CUT
	SUB R1,R0
	B LOOP
CUT
	SUB R0,R1
	B LOOP
EXIT
	LDR R0,=GCD
	STR R1,[R0]
STOP B STOP
	AREA CODE,DATA
GCD SPACE 4
	END