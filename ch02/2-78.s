	.file	"2-78.c"
	.text
	.globl	divide_power2
	.type	divide_power2, @function
divide_power2:
.LFB24:
	.cfi_startproc
	movl	%esi, %ecx
	movl	%edi, %eax
	sarl	$31, %eax
	movl	$1, %edx
	sall	%cl, %edx
	subl	$1, %edx
	andl	%eax, %edx
	leal	(%rdi,%rdx), %eax
	sarl	%cl, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	divide_power2, .-divide_power2
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$4, %esi
	movl	$-12340, %edi
	call	divide_power2
	movl	%eax, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
