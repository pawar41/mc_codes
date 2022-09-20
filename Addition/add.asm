	
	AREA simple,CODE, readonly
	ENTRY
	LDR R1, NUM1
	LDR R2, NUM2
	ADD R3, R1, R2
S	B S

	AREA storage,data, readonly
NUM1 DCD 0x10
NUM2 DCD 0x15
	
	END 
	

