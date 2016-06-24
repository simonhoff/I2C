.section .init
.globl _start
_start:

ldr r0, =0x20200000

mov r1 , #1
lsl r1 , #18
str r1 , [r0,#40]

loop$:



mov r2 , #0x3F0000		; Start of delay
waitl$:
sub r2 , #1
cmp r2 , #0
bne waitl$				; End of delay

b loop$					; Back to start of loop