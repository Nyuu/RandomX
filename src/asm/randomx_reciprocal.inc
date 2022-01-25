	mov edx, 1
	mov r8, rcx
	xor eax, eax
	bsr rcx, rcx
	shl rdx, cl
	div r8
	ret
	
	
	RCX ( ECX ( CX (CH CL)  ) ) # DATA
	RDX # DATA
	RAX ( EAX ) # ACC
	
	move dst, src 
	xor dst, src ; set 0
	bsr src, dst# ZF flag affected
	shl k, dst
	div ACC, src
	ret
