 .section	.rodata
LC0:
      .ascii "Hello,World\0"
      .text
.globl main
main:
pushq %rbp
movq %rsp,%rbp
subq $16,%rsp
leaq LC0(%rip),%rdi
movl $0,%eax
call puts
movl $0,%eax

leave
ret