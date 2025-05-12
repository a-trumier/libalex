.section .text
.global syscall

syscall:
    # the biggest thing about this syscall is that there are optional parameters
    # so you can do any syscall. this means that we have to move a0 to a7 
    # (which is the code) then push all the other ones back. we can safely
    # assume that a7 is not populated.

    # with this stub, we can allow the programmer to do any syscall they want.
    mv a7, a0
    mv a0, a1
    mv a1, a2
    mv a2, a3
    mv a3, a4
    mv a4, a5
    mv a5, a6
    ecall
    ret
