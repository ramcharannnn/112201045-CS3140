	.file	1 "a.sil"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.text
.section .rdata
.align 2
$LC0:
	.ascii "%d\000"
$LC1:
	.ascii "%d\012\000"
.data
.align 2
array_bounds_error: .asciiz "Array index out of bounds!\n"
div_by_zero_msg: .asciiz "Division by zero error!\n"
.globl a
.align 2
.type a, @object
.size a, 4
a:
.space 4
.globl b
.align 2
.type b, @object
.size b, 4
b:
.space 4
.text
.align 2
.globl main
.set nomips16
.set nomicromips
.ent main
.type main, @function
main:
.frame $fp, 40, $31
.mask 0xc0000000, -4
.fmask 0x00000000, 0
addiu $sp, $sp, -40
sw $31, 36($sp)
sw $fp, 32($sp)
move $fp, $sp
.cprestore 16
la $t0, a
move $5, $t0
la $4, $LC0
jal __isoc99_scanf
la $t0, b
move $5, $t0
la $4, $LC0
jal __isoc99_scanf
    la $t1, a
    lw $t0, 0($t1)
move $5, $t0
la $4, $LC1
jal printf
    la $t1, b
    lw $t0, 0($t1)
move $5, $t0
la $4, $LC1
jal printf
la $t0, a
move $5, $t0
la $4, $LC0
jal __isoc99_scanf
    la $t1, a
    lw $t0, 0($t1)
move $5, $t0
la $4, $LC1
jal printf
    la $t1, b
    lw $t0, 0($t1)
move $5, $t0
la $4, $LC1
jal printf
la $t0, b
move $5, $t0
la $4, $LC0
jal __isoc99_scanf
    la $t1, a
    lw $t0, 0($t1)
move $5, $t0
la $4, $LC1
jal printf
    la $t1, b
    lw $t0, 0($t1)
move $5, $t0
la $4, $LC1
jal printf
move $sp, $fp
lw $31, 36($sp)
lw $fp, 32($sp)
addiu $sp, $sp, 40
li $v0, 10
syscall
.end main
.size main, .-main
handle_array_bounds_error:
	la $a0, array_bounds_error
	li $v0,4
	syscall
	li $v0,10
	syscall
div_error:
	la $a0, div_by_zero_msg
	li $v0,4
	syscall
	li $v0,10
	syscall
