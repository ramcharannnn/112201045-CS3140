.file   1 "output.sil"
    .section .mdebug.abi32
    .previous
    .nan    legacy
    .module fp=xx
    .module nooddspreg
    .abicalls
    .text
.data
.align 2
array_bounds_error: .asciiz "Array index out of bounds!\n"
div_by_zero_msg: .asciiz "Division by zero error!\n"

.section .bss, "aw", @nobits
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
.set noreorder
.cpload $25
.set reorder
addiu $sp, $sp, -40
sw $31, 36($sp)
sw $fp, 32($sp)
move $fp, $sp

# Read a, b
lw $t0, %got(a)($gp)
li $v0, 5
syscall
sw $v0, 0($t0)
lw $t0, %got(b)($gp)
li $v0, 5
syscall
sw $v0, 0($t0)

# Write a, b (with space)
lw $t0, %got(a)($gp)
lw $a0, 0($t0)
li $v0, 1
syscall
li $a0, 32
li $v0, 11
syscall
lw $t0, %got(b)($gp)
lw $a0, 0($t0)
li $v0, 1
syscall
li $a0, 10
li $v0, 11
syscall

# Read new a
lw $t0, %got(a)($gp)
li $v0, 5
syscall
sw $v0, 0($t0)

# Write a, b (ensure b is unchanged)
lw $t0, %got(a)($gp)
lw $a0, 0($t0)
li $v0, 1
syscall
li $a0, 32
li $v0, 11
syscall
lw $t0, %got(b)($gp)
lw $a0, 0($t0)
li $v0, 1
syscall
li $a0, 10
li $v0, 11
syscall

# Read new b
lw $t0, %got(b)($gp)
li $v0, 5
syscall
sw $v0, 0($t0)

# Write a, b (ensure a is unchanged)
lw $t0, %got(a)($gp)
lw $a0, 0($t0)
li $v0, 1
syscall
li $a0, 32
li $v0, 11
syscall
lw $t0, %got(b)($gp)
lw $a0, 0($t0)
li $v0, 1
syscall
li $a0, 10
li $v0, 11
syscall

move $sp, $fp
lw $31, 36($sp)
lw $fp, 32($sp)
addiu $sp, $sp, 40
li $v0, 10
syscall
.end main
.size main, .-main

handle_array_bounds_error:
    lw $a0, %got(array_bounds_error)($gp)
    li $v0, 4
    syscall
    li $v0, 10
    syscall

div_error:
    lw $a0, %got(div_by_zero_msg)($gp)
    li $v0, 4
    syscall
    li $v0, 10
    syscall