; Experiment No: 01
; Date: 23/2/26
; Write a program to find the square of a number (1 to 10) using a lookup table
; Given number is in R1, result is stored in R3 (e.g., 36d = 24H)

    AREA SQUARE, CODE, READONLY   ; Mark first instruction to execute
ENTRY
START
    LDR R0, =TABLE          ; Load start address of lookup table
    MOV R1, #6              ; Input number
    MOV R1, R1, LSL #0x2   ; Generate address corresponding to square of given number
    ADD R0, R0, R1          ; Load address of element in lookup table
    LDR R3, [R0]            ; Load the result into R3

XSS B XSS                   ; Infinite loop

; Lookup table containing squares of numbers from 0 to 10 (in hex)
TABLE
    DCD 0x00000000          ; Square of 0 = 0
    DCD 0x00000001          ; Square of 1 = 1
    DCD 0x00000004          ; Square of 2 = 4
    DCD 0x00000009          ; Square of 3 = 9
    DCD 0x00000010          ; Square of 4 = 16
    DCD 0x00000019          ; Square of 5 = 25
    DCD 0x00000024          ; Square of 6 = 36
    DCD 0x00000031          ; Square of 7 = 49
    DCD 0x00000040          ; Square of 8 = 64
    DCD 0x00000051          ; Square of 9 = 81
    DCD 0x00000064          ; Square of 10 = 100

END                         ; Mark end of file
