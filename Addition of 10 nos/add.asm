		org 00h
		sjmp start

start:	mov a, #00h		   	;to store result of addition
		mov R0, #00h		;for counting purpose
loop:	add a, R0
		inc R0
		cjne R0, #0Bh, loop	 ;loop only from 0 to 10
		mov R0, a			 ;store addition result in R0
here:	sjmp here
		END
