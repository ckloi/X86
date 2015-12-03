.global _start
.equ bytesize , 1
.equ wordsize , 4
.data
string1:
	.space 100
string2:
	.space 100
result:
	.space 10000
row_length:
	.long 0

col_length:
	.long 0
temp:
	.long 0
temp1:
	.long 0
temp2:
	.long 0
temp3:
	.long 0
diagonal:
	.long 0


.text


_start:

movl $string1,%edi
movl $0,%ecx

find:
cmpb $0 , (%edi,%ecx,bytesize)
jz endfind
incl %ecx
jmp find
endfind:

movl %ecx,row_length

movl $string2,%edi
movl $0,%ecx

find1:
cmpb $0 , (%edi,%ecx,bytesize)
jz endfind1
incl %ecx
jmp find1
endfind1:

movl %ecx,col_length



movl $string1, %esi
movl $string2, %eax
movl $result , %ebx
movl $0 , %ecx 
addl $1,row_length
addl $1,col_length



init1:
     cmpl col_length,%ecx
     jge end_init1
     
     movl %ecx , (%ebx,%ecx,wordsize)
     incl %ecx
     jmp init1

end_init1:
movl $0,%ecx
movl %eax,temp
movl $0,%eax
init2:
     cmpl row_length,%eax
     jge end_init2
     movl %eax , %edi
     imull col_length 
     movl %edi , (%ebx,%eax,wordsize)
     movl %edi , %eax
     incl %eax
     jmp init2

end_init2:
movl temp , %eax

movl $1,%ecx
movl %eax , temp
movl %esi , temp1

row_forloop:
	cmpl row_length,%ecx
	jge end_row_forloop
	movl $1,%edi 
col_forloop:
	cmpl col_length,%edi
	jge end_col_forloop
	subl $1 ,%ecx
	subl $1 ,%edi
	movb (%esi,%ecx,bytesize) , %dl
	cmpb %dl , (%eax,%edi,bytesize)
	jnz false
        
	  
	
	movl %ecx , %eax
	imull col_length
	addl %edi, %eax
	movl %eax , diagonal
	
	addl $1 , %ecx
	addl $1 , %edi	
	movl %ecx , %eax
	imull col_length
	addl %edi, %eax
	movl diagonal, %edx
	movl (%ebx,%edx,wordsize) , %esi
	movl %esi , (%ebx,%eax,wordsize)
	
	movl temp , %eax
	movl temp1, %esi
	incl %edi
	jmp col_forloop

	#movl temp, %eax
	#movl temp1, %esi
	#movl temp2, %eax
	# EAX = IJ EDX = [I-1][J-1]
	
false:
	movl %ecx , %eax
	imull col_length
	addl %edi, %eax
	movl %eax , diagonal  #diagonal = i-1 ,j-1

	addl $1 , %ecx
	addl $1 , %edi	
	movl %ecx , %eax
	imull col_length
	addl %edi, %eax
	movl %eax , temp2   #temp2 = i j

	subl $1 , %ecx
	movl %ecx , %eax
	imull col_length
	addl %edi, %eax
	movl %eax , %esi   # esi = i-1 j
	movl diagonal, %edx
	movl (%ebx,%esi,wordsize),%eax
	cmpl %eax , (%ebx,%edx,wordsize)
	jl firstsmaller

	addl $1 , %ecx
	subl $1 , %edi 
	movl %ecx , %eax
	imull col_length
	addl %edi, %eax
	movl %eax , diagonal
	movl diagonal, %edx
	movl (%ebx,%esi,wordsize),%eax
	cmpl %eax , (%ebx,%edx,wordsize)
	jl smallest

	movl %esi , %edx
	jmp smallest
	


	
	
	

firstsmaller:
		
		
	addl $1 , %ecx
	subl $1 , %edi
	movl %ecx , %eax
	imull col_length
	addl %edi, %eax
	movl %eax , %esi
	movl diagonal,%edx
	movl (%ebx,%esi,wordsize),%eax
	cmpl %eax , (%ebx,%edx,wordsize)
	jl smallest

	movl %esi , %edx



smallest:

	
	movl temp2 , %eax
	movl (%ebx,%edx,wordsize) , %edx
	movl %edx,(%ebx,%eax,wordsize)
	addl $1 , (%ebx,%eax,wordsize)
	
	addl $1 , %edi
	movl temp, %eax
	movl temp1, %esi
	incl %edi
	jmp col_forloop
	end_col_forloop:
	incl %ecx
	jmp row_forloop
end_row_forloop:




movl row_length , %eax
subl $1, %eax
movl col_length , %ecx
subl $1, %ecx
imull col_length
addl %ecx, %eax


movl (%ebx,%eax,wordsize), %eax

done:

movl %eax,%eax
