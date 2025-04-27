.section .text
.global exit

exit:
    # exit(int)
    # simple syscall to exit. we have in a0 the code, so just ecall
    li a7, 93
    ecall
