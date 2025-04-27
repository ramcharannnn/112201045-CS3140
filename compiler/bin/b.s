	.file	1 "b.sil"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.text
.data
.align 2
array_bounds_error: .asciiz "Array index out of bounds!\n"
div_by_zero_msg: .asciiz "Division by zero error!\n"
.align 2
a: .space 16
.text
.globl main
main:
	addiu $sp,$sp,-40
	sw $fp,36($sp)
	sw $ra,32($sp)
	move $fp,$sp
handle_array_bounds_error:
    la $a0, array_bounds_error
    li $v0, 4
    syscall
    li $v0, 10
    syscall

div_error:
    la $a0, div_by_zero_msg
    li $v0, 4
    syscall
    li $v0, 10
    syscall
    li $t5, 0
la $t3, a
sll $t5, $t5, 2
addu $t3, $t3, $t5
lw $t3, 0($t3)
    li $t5, 1
la $t4, a
sll $t5, $t5, 2
addu $t4, $t4, $t5
lw $t4, 0($t4)
    add $t1, $t3, $t4
    li $t3, 2
la $t2, a
sll $t3, $t3, 2
addu $t2, $t2, $t3
lw $t2, 0($t2)
    add $t0, $t1, $t2
    li $t1, 3
li $t2, 4
bge $t1, $t2, array_error
bltz $t1, array_error
	sll $t1,$t1,2
	la $t1,a
	add $t1,$t1,$t1
	sw $t0,0($t1)
    li $t1, 3
la $t0, a
sll $t1, $t1, 2
addu $t0, $t0, $t1
lw $t0, 0($t0)
	move $a0, $t0
	li $v0, 1
	syscall
	li $a0, 10
	li $v0, 11
	syscall
addiu $sp, $sp, -32
sw $fp, 28($sp)
sw $ra, 24($sp)
	li $v0,10
	syscall
