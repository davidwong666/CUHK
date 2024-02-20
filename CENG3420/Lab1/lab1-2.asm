.data
array: .word -1 22 8 35 5 4 11 2 1 78
space: .ascii " "

.text
.globl main

main:
	la a0, array
	li a1, 10
	li t3, 1			# Initialize i = 1

outer_loop:
	addi t4, t3, -1			# Initialize j = i
	blt t3, a1, inner_loop		# If i < n, jump to inner_loop
	j print				# Otherwise, jump to print

inner_loop:
	slli t5, t4, 2			# Multiply j by 4 (word size)
	add t5, t5, a0			# Add the base address of v to j
	
	lw t6, 0(t5)			# Load v[j] into t6
	lw t0, 4(t5)			# Load v[j+1] into t0
	
	ble t6, t0, skip_swap		# If v[j] <= v[j+1], skip the swap
	
	sw t0, 0(t5)			# Store v[j+1] into v[j]
	sw t6, 4(t5)			# Store v[j] into v[j+1]
	
	addi t4, t4, -1			# Decrement j by 1
	bge t4, zero , inner_loop	# If j >= 0, jump to inner_loop

skip_swap:
	addi t3, t3, 1			# Increment i by 1
	j outer_loop			# Jump to outer_loop

print:
	li a1, 0             		# Initialize counter to 0
	li a2, 10			# Initialize count to 10

print_loop:
	bge a1, a2, end_print  		# Exit loop if counter >= 10
	la a0, array
	slli t3, a1, 2      		# Multiply the counter by 4 to get the offset
	add t3, a0, t3       		# Add the offset to the address of the array
	lw a0, 0(t3)         		# Load the value of the array element into a0
	li a7, 1             		# Set the ecall code for printing an integer
	ecall                		# Print the value
	
	la a0, space			# print " " between the integers
	li a7, 4
	ecall

	addi a1, a1, 1       		# counter++
	j print_loop         		# loop

end_print:
	li a7, 10   			# ecall code for exit
	ecall
