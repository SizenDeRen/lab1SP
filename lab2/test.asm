section .data
    arr db 1,12,55,255,192,63,77,99,200,11
    count dd 0
    printf_format db "%d", 10, 0

section .text
    extern printf
    global main

main:
    ;initialize registers
    mov ecx, 0 ;initialize loop counter to 0
    mov bl, 0x6B ;initialize b to 01101011 in binary (hexadecimal representation)

loop:
    ;check if i < 10, if not, exit loop
    cmp ecx, 9 ;last index of arr is 9, so compare till 9
    jg exit_loop

    ;load arr[i] into al
    mov al, [arr + ecx]

    ;perform OR operation with 6Bh
    or al, bl

    ;store result in arr[i]
    mov [arr + ecx], al

    ;compare the result with 128, increase count if result is less than 128
    cmp al, 128
    jl less_than
    ;We use jl instead of jge, since we want to count all elements less than 128
    jmp loop_count

less_than:
    add dword[count], 1 ;increase count

loop_count:
    ;increase loop counter, repeat loop
    add ecx, 1
    jmp loop

exit_loop:
    ;print count
    mov rax, 0 ;mov 0 to rax instead of printf_format
    mov edi, printf_format ;arg1 - ptr to format string
    mov esi, count ;arg2 - count
    mov eax, 0 ;mov 0 to eax instead of 0
    call printf
    add rsp, 8

    ;exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80
