;program for decade increment with input values from arduino input  

 
.include "/home/satheeshsk/m328Pdef.inc"

ldi r17, 0b11111100 ; identifying input pins 8,9 as inputs and 13 as output
out DDRB,r17		; declaring pins as specified

ldi r16, 0b00001100 ;identifying output pins 2,3
out DDRD,r16		;declaring pins as output

Start:

;generate clock on pin 13

ldi r17, 0b00100000
out PORTB, r17

;creat a delay
call wait 

in r17,PINB

ldi r23, 0b00000001  ; input for W - 8th in
ldi r24, 0b00000010  ; input for X  - 9th pin

and r23, r17
and r24, r17


;right shift X by 1 bits
mov r16, r24
ldi r20, 0b00000001
rcall loopr
mov r24, r16

;No right shift needed for W
;mov r16, r23
;ldi r20, 0b00000100
;rcall loopr
;mov r23, r16

; W complement
mov r16, r23
rcall comp
mov r27, r16 ; store W'

; X complement
mov r16, r24
rcall comp
mov r28,r16 ; store X'

mov r29, r23
and r29, r28 ; WX'

mov r15, r27 ; move W' to a temp reg
and r15, r24 ; W'X
or r29, r15 ; B = WX' + W'X

; Now, B = X' is in r28 and A is in r29


;left shift B by 3 bits
mov r16, r28
ldi r20, 0b00000011
rcall loopw
mov r28, r16
andi r28, 0b00001100

;left shift A by 2 bits
mov r16, r29
ldi r20, 0b00000010
rcall loopw
mov r29, r16
andi r29, 0b00000100


ldi r16,0b00000000	
or r16, r28 ; mov A,B into r16
or r16, r29

;generate clock 0 on pin 13

ldi r17, 0b00000000
out PORTB, r17

;creat a delay
call wait

out PORTD, r16 ; writing output to pins 2,3

rjmp Start

;loop for bit shifting to left
loopw:	lsl r16			;left shift
	dec r20			;counter --
	brne	loopw	;if counter != 0
	ret

;loop for bit shifting to right
loopr:	lsr r16			;right shift
	dec r20			;counter --
	brne	loopr	;if counter != 0
	ret

;comp routine begins
comp:
	mov r0,r16			;using r0 for computations
	ldi r16,0b00000001	;loading 1
	
	eor r16,r0			;A'=A XOR 1
	ret 				;returning from comp


;delay routine
wait:
  push r16		;save register contents
  push r17		
  push r18		

  ldi r16, 0x20		;loop 0x400000 times
  ldi r17, 0x00		;12 million cycles
  ldi r18, 0x00		;0.7s at 16 MHz

w0:
  
  dec r18
  brne w0
  dec r17
  brne w0
  dec r16
  brne w0

  pop r18		;restore register contents
  pop r17	
  pop r16

  ret

