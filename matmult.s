.global matMult
.equ wordsize, 4

.text 
matMult:
# col b   +28
# row b   +24
# b       +20
# col a   +16
# row a   +12
# a       +8
# return  +4
# %ebp
# %esi    -4
# %ebx    -8
# %edi    -12
#temp     -16


push %ebp

movl %esp, %ebp

push %esi
push %ebx
push %edi
push $0


movl 12(%ebp),%eax
shll $2,%eax
push %eax
call malloc
addl $wordsize,%esp
#esi holds the address of c
movl %eax,%esi

movl $0, %ecx

rowa_for:
cmpl 12(%ebp),%ecx
jge end_rowa_for

movl 28(%ebp),%eax
shll $2,%eax
push %ecx
push %eax
call malloc
addl $wordsize, %esp
pop %ecx

movl %eax,(%esi,%ecx,wordsize)




movl $0, %edx
colb_for:
cmpl 28(%ebp),%edx
jge end_colb_for
movl $0, -16(%ebp)

movl $0, %ebx
cola_for:
cmpl 16(%ebp),%ebx
jge end_cola_for

push %eax
push %edx
#a[i][k]*b[k][j];
movl 8(%ebp), %edi
movl (%edi,%ecx,wordsize),%edi
movl (%edi,%ebx,wordsize),%eax
movl 20(%ebp), %edi
movl (%edi,%ebx,wordsize),%edi
movl (%edi,%edx,wordsize),%edi

imull %edi

addl -16(%ebp),%eax

movl %eax,%edi
pop %edx
pop %eax
movl %edi , -16(%ebp)
incl %ebx
jmp cola_for
end_cola_for:
movl %edi , (%eax,%edx,wordsize)

incl %edx
jmp colb_for
end_colb_for:
incl %ecx
jmp rowa_for
end_rowa_for:

movl %esi,%eax

pop %edi
pop %edi
pop %ebx
pop %esi

movl %ebp,%esp
pop %ebp
ret

