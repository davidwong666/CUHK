.globl _start

.data
var1: .word 0
var2: .word 0
var3: .word 0
newline: .ascii"\n"

.text
_start:
	la t0, var1
	li a7, 5
	ecall
	sw a0, 0(t0)
	
	la t1, var2
	li a7, 5
	ecall
	sw a0, 0(t1)
	
	la t2, var3
	li a7, 5
	ecall
	sw a0, 0(t2)
	
	lw t3, 0(t0)
	addi t3, t3, 3
	sw t3, 0(t0)
	
	lw t4, 0(t1)
	slli t4, t4, 1
	sw t4, 0(t1)
	
	add t5, t3, t4
	lw t6, 0(t2)
	add t6, t6, t5
	sw t6, 0(t2)
	
	lw a0, 0(t0)
	li a7, 1
	ecall
	
	la a0, newline
	li a7, 4
	ecall

	lw a0, 0(t1)
	li a7, 1
	ecall
	
	la a0, newline
	li a7, 4
	ecall

	lw a0, 0(t2)
	li a7, 1
	ecall

	li a7, 10
	ecall
