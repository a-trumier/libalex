.section .text
.global _start

_start:
    # first, we need to call main to start our c code.
    jal ra, main

    # since the return value of main <<should>> be in a0, we can safely
    # exit with a syscall.
    la a7, 93
    ecall

    # in some weird wacko world Linux didn't kill us, just hang.
    j spin

spin:
    # this little trick from xv6 gents. Love it!
    j spin

    
