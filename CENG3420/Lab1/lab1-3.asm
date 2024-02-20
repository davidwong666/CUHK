.data
array: .space 400
n: .word 0
space: .ascii " "

.text
.globl main

main:
	la a1, n		# a1 is the address of n
	li a7, 5
	ecall
	sw a0, 0(a1)		# store n into a1
	lw a1, 0(a1)		# get the value of n to a1
	
	li t1, 0		#loop counter i = 0
	la a2, array		# a2 is the address of the array
	li t2, 0		# initialize t2 = 0
	
loop:
	add a3, a2, zero	# a3 stores the address of the array
	add a3, a3, t2		# get the offset for the corresponding element
	li a7, 5		# get the int array from user input
	ecall
	
	sw a0, 0(a3)		# store the user input in the array
	addi t1, t1, 1		# i++
	slli t2, t1, 2		# offset of the next element
	bne t1, a1, loop	# if i != n then continue to loop
	beq t1, a1 , end_loop	# if i >= n then end loop

end_loop:
	li t3, 1		# initialize i = 1
outer_loop:
	addi t4, t3, -1		# Initialize j = i
	blt t3, a1, inner_loop	# If i < n, jump to inner_loop
	j print             	# Otherwise, jump to print

inner_loop:
	slli t5, t4, 2    	# Multiply j by 4 (word size)
	add t5, t5, a2   	# Add the base address of array to j
	
	lw t6, 0(t5)       	# Load array[j] into t6
	lw t0, 4(t5)     	# Load array[j+1] into t0
	
	ble t6, t0, skip_swap   # If array[j] <= array[j+1], skip the swap
	
	sw t0, 0(t5)       	# Store array[j+1] into array[j]
	sw t6, 4(t5)     	# Store array[j] into array[j+1]
	
	addi t4, t4, -1   	# Decrement j by 1
	bge t4, zero , inner_loop  	# If j >= 0, jump to inner_loop

skip_swap:
	addi t3, t3, 1    	# Increment i by 1
	j outer_loop        	# Jump to outer_loop

print:
	li t1, 0             	# Initialize counter to 0
	li t3, 0

print_loop:
	bge t1, a1, end_print  # Exit loop if counter >= n
	la a2, array
	slli t3, t1, 2       	# Multiply the counter by 4 to get the offset
	add t3, a2, t3       	# Add the offset to the address of the array
	lw a0, 0(t3)         	# Load the value of the array element into a0
	li a7, 1             	# Set the ecall code for printing an integer
	ecall                	# Print the value
	
	la a0, space		# print " " between the integers
	li a7, 4
	ecall

	addi t1, t1, 1       	# Increment the counter
	j print_loop         	# Jump back to the beginning of the loop
  
end_print:
	li a7, 10   		# ecall code for exit
	ecall
