;program for decade increment  

 
.include "/home/satheeshsk/m328Pdef.inc"

ldi r16, 0b00111100 ;identifying output pins 2,3,4,5
out DDRD,r16		;declaring pins as output

ldi r21, 0b00000000  ; input for W
ldi r22, 0b00000000  ; input for X
ldi r23, 0b00000000  ; input for Y
ldi r24, 0b00000001  ; input for Z

; W complement
mov r16, r21
rcall comp
mov r25, r16; store W' in r25

; X complement
mov r16, r22
rcall comp
mov r26, r16 ; store X'

; Y complement
mov r16, r23
rcall comp
mov r27, r16 ; store Y'

; Z complement
mov r16, r24
rcall comp
mov r28,r16 ; store Z'

mov r29, r21
and r29, r26 ; WX'
and r29 , r28 ; B = WX'Z'

mov r15, r25 ; move W' to a temp reg
and r15, r22 ; W'X
or r29, r15 ; B = WX'Z' + W'X

mov r30, r21 
and r30, r22 ;  WX
and r30, r27 ; WXY'

mov r15, r25 ; move W' to a temp reg
and r15, r23 ; W'Y

or r30, r15 ; C = WXY' + W'Y
mov r15, r26 ; X'
and r15, r23 ; X'Y
or r30, r15 ; C = WXY'+W'Y+X'Y

mov r31,r21
and r31, r22  ; WX
and r31, r23  ; WXY

mov r15, r25 ; move W' to a temp reg
and r15, r24 ; W'Z
or r31, r15  ; D = WXY + W'Z 

; A = W' in r25, B in r29, C in r30, D in r31

;left shift D by 5 bits
mov r16, r31
ldi r20, 0b00000101
rcall loopw
mov r31, r16
andi r31, 0b00111100

;left shift C by 4 bits
mov r16, r30
ldi r20, 0b00000100
rcall loopw
mov r30, r16
andi r30 ,0b00011100

;left shift B by 3 bits
mov r16, r29
ldi r20, 0b00000011
rcall loopw
mov r29, r16
andi r29, 0b00001100

;left shift A by 2 bits
mov r16, r25
ldi r20, 0b00000010
rcall loopw
mov r25, r16
andi r25, 0b00000100


ldi r16,0b00000000	
or r16, r25 ; mov A,B,C,D into r16
or r16, r29
or r16, r30
or r16, r31


out PORTD, r16 ; writing output to pins 2,3,4,5

Start:
rjmp Start

;loop for bit shifting
loopw:	lsl r16			;left shift
	dec r20			;counter --
	brne	loopw	;if counter != 0
	ret

;comp routine begins
comp:
	mov r0,r16			;using r0 for computations
	ldi r16,0b00000001	;loading 1
	
	eor r16,r0			;A'=A XOR 1
	ret 				;returning from comp


