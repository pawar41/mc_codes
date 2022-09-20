
	org 00h
	ljmp start		;jump to start on reset


delay:				 ;delay routine approx. 1.5 seconds
    mov r3,#0x0B
	mov r4,#0x0
	mov r5,#0x0
loop:
	djnz r5, loop
	djnz r4, loop
	djnz r3, loop
	RET

start:
	mov P0, #00h
	mov P1, #00h
	mov P2, #00h
	mov P3, #00h
	acall delay
	mov P0, #0FFh
	mov P1, #0FFh
	mov P2, #0FFh
	mov P3, #0FFh
	acall delay
	sjmp start

 END
