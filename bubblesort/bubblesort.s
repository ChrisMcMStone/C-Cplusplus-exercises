	.file	"bubblesort.c"
	.intel_syntax noprefix
	.text
	.globl	sort
	.type	sort, @function
sort:
.LFB2:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-24], rdi
	mov	DWORD PTR [rbp-28], esi
	mov	DWORD PTR [rbp-12], 0
	jmp	.L2
.L6:
	mov	DWORD PTR [rbp-8], 0
	jmp	.L3
.L5:
	mov	eax, DWORD PTR [rbp-8]
	cdqe
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rdx
	mov	edx, DWORD PTR [rax]
	mov	eax, DWORD PTR [rbp-8]
	cdqe
	add	rax, 1
	lea	rcx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rcx
	mov	eax, DWORD PTR [rax]
	cmp	edx, eax
	jle	.L4
	mov	eax, DWORD PTR [rbp-8]
	cdqe
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rdx
	mov	eax, DWORD PTR [rax]
	mov	DWORD PTR [rbp-4], eax
	mov	eax, DWORD PTR [rbp-8]
	cdqe
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-24]
	add	rdx, rax
	mov	eax, DWORD PTR [rbp-8]
	cdqe
	add	rax, 1
	lea	rcx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-24]
	add	rax, rcx
	mov	eax, DWORD PTR [rax]
	mov	DWORD PTR [rdx], eax
	mov	eax, DWORD PTR [rbp-8]
	cdqe
	add	rax, 1
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-24]
	add	rdx, rax
	mov	eax, DWORD PTR [rbp-4]
	mov	DWORD PTR [rdx], eax
.L4:
	add	DWORD PTR [rbp-8], 1
.L3:
	mov	eax, DWORD PTR [rbp-12]
	mov	edx, DWORD PTR [rbp-28]
	sub	edx, eax
	mov	eax, edx
	sub	eax, 1
	cmp	eax, DWORD PTR [rbp-8]
	jg	.L5
	add	DWORD PTR [rbp-12], 1
.L2:
	mov	eax, DWORD PTR [rbp-12]
	cmp	eax, DWORD PTR [rbp-28]
	jl	.L6
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	sort, .-sort
	.section	.rodata
.LC0:
	.string	"%d, "
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	DWORD PTR [rbp-20], edi
	mov	QWORD PTR [rbp-32], rsi
	cmp	DWORD PTR [rbp-20], 1
	jne	.L8
	mov	eax, 0
	jmp	.L9
.L8:
	mov	eax, DWORD PTR [rbp-20]
	sub	eax, 1
	cdqe
	sal	rax, 2
	mov	rdi, rax
	call	malloc
	mov	QWORD PTR [rbp-8], rax
	mov	DWORD PTR [rbp-12], 0
	jmp	.L10
.L11:
	mov	eax, DWORD PTR [rbp-12]
	cdqe
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-8]
	add	rdx, rax
	mov	eax, DWORD PTR [rbp-12]
	cdqe
	add	rax, 1
	lea	rcx, [0+rax*8]
	mov	rax, QWORD PTR [rbp-32]
	add	rax, rcx
	mov	rax, QWORD PTR [rax]
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	sub	eax, 48
	mov	DWORD PTR [rdx], eax
	add	DWORD PTR [rbp-12], 1
.L10:
	mov	eax, DWORD PTR [rbp-20]
	sub	eax, 1
	cmp	eax, DWORD PTR [rbp-12]
	jg	.L11
	mov	eax, DWORD PTR [rbp-20]
	lea	edx, [rax-1]
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, edx
	mov	rdi, rax
	call	sort
	mov	DWORD PTR [rbp-12], 0
	jmp	.L12
.L13:
	mov	eax, DWORD PTR [rbp-12]
	cdqe
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-8]
	add	rax, rdx
	mov	eax, DWORD PTR [rax]
	mov	esi, eax
	mov	edi, OFFSET FLAT:.LC0
	mov	eax, 0
	call	printf
	add	DWORD PTR [rbp-12], 1
.L12:
	mov	eax, DWORD PTR [rbp-20]
	sub	eax, 1
	cmp	eax, DWORD PTR [rbp-12]
	jg	.L13
	mov	edi, 10
	call	putchar
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	free
	mov	eax, 0
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
