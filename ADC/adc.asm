/*
	Interfacing ADC card with Micro51S Board
	Connect CN4 on ADC card to CN3 on Micro51S Board
	Connect CN3 on ADC card to CN4 on Micro51S Board
	Connect LED card to CN2
	ADC0808			8051
	SEL_A			P1.0
	SEL_B			P1.1
	SEL_C			P1.2
	ALE				P1.3
	START			P1.4
	EOC				P1.5
	OE				P1.6
	CLK				P1.7
	ADC_DATA		PORT2
*/
			 

	ADCPORT equ P2
	LEDPORT equ P0

	SEL_A	equ P1^0
	SEL_B	equ P1^1
	SEL_C	equ P1^2
	ALE		equ P1^3
	START	equ P1^4
	EOC		equ P1^5
	OE		equ P1^6

	org 0x00
	ljmp main		;jump to start on reset

read_adc:
	mov  P1, R0	
	setb EOC
	setb ALE
	setb START
	clr  ALE
	clr  START
loop1:
	jb   EOC, loop1
loop2:
	jnb  EOC, loop2
	setb OE
	mov a, ADCPORT
	clr  OE
	ret

main:
	mov ADCPORT, #0FFh
	mov P1, #00h	
loop3:
	acall read_adc
	mov LEDPORT, a
	sjmp loop3

	END