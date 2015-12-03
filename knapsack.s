.global knapsack

.equ wordsize, 4

.text


knapsack:

#cur_value    +24
#capacity     +20
#num_items    +16
#values       +12
#weights      +8
#ret          +4
#ebp 
#esi           -4
#edi           -8
#ebx          -12
#best_value   -16
push %ebp
movl %esp, %ebp

push %esi
push %edi
push %ebx


movl $0 , %ecx
movl 24(%ebp) , %eax
push %eax   # best_value = cur_value  -16(%ebp)



for_s:
push %ecx
cmpl 16(%ebp),%ecx

jge endfor
 #edx = capacity
movl 8(%ebp), %esi
movl 20(%ebp), %edx
subl (%esi,%ecx,wordsize), %edx

cmpl $0, %edx
jl endif


movl 12(%ebp),%eax
movl (%eax,%ecx,wordsize),%eax
addl 24(%ebp),%eax
push %eax

movl 20(%ebp),%eax
movl 8(%ebp) , %ebx
movl (%ebx,%ecx,wordsize),%ebx
subl %ebx,%eax
push %eax




movl 16(%ebp), %eax
subl  %ecx, %eax
subl $1 , %eax
push %eax

	
push %ecx
movl %ecx, %eax
movl $4, %ecx
imull %ecx
pop %ecx
addl 12(%ebp), %eax
addl $wordsize , %eax
push %eax

push %ecx
movl %ecx, %eax
movl $4, %ecx
imull %ecx
pop %ecx
addl 8(%ebp), %eax
addl $wordsize , %eax
push %eax


call knapsack

addl $20,%esp #????
cmpl -16(%ebp),%eax
jl endif

knap_greater:
movl %eax, -16(%ebp)


endif:
pop %ecx
incl %ecx
jmp for_s
endfor:

movl  -16(%ebp), %eax
 #???????????
pop %ebx
pop %ebx
pop %edi
pop %esi

movl %ebp, %esp
pop %ebp



ret










