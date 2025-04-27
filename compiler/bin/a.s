	.file	1 "a.sil"
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
a: .space 4
.align 2
b: .space 4
.text
.globl main
main:
	addiu $sp,$sp,-40
	sw $fp,36($sp)
	sw $ra,32($sp)
	move $fp,$sp
