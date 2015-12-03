.global _start

.data

num1:
	.space 8

num2:
	.space 8

.text

_start:

movl $num1+4, %ebx
movl $num2+4, %ecx
addl (%ecx) , %eax
addl (%ebx) , %eax
jnc not_carryout

addl $1,%edx

not_carryout:
subl $4 , %ebx
subl $4 , %ecx
addl (%ecx) , %edx
addl (%ebx) , %edx














done:
movl %eax,%eax
