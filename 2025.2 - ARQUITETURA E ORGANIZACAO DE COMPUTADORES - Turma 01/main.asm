SECTION .data
    msg db 'Hello, world!', 0x0a

SECTION .text
GLOBAL main
extern printf

main:
    PUSH msg
    call printf
    add esp, 4

    ret