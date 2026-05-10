; Experiment No: 02
; Date: 2/3/26
; Write a program to find the factorial of a number
; Example: n = 7, 7x6x5x4x3x2x1 = 5040d = 13B0H
; Check result in R0 or R3 register = 13B0H

    AREA FACTORIAL, CODE, READONLY  ; Area directive instructs assembler to assemble a new code section
ENTRY                               ; Assembler to assemble a new code
START
    MOV R0, #7              ; Store 7 in R0
    MOV R1, R0              ; Move 7 to R1

LOOP
    SUBS R1, R1, #1         ; Subtraction
    CMP R1, #1              ; Comparison
    BEQ STOP                ; Branch if equal to STOP
    MUL R3, R0, R1          ; Multiplication
    MOV R0, R3              ; Result, R0 = 13B0H
    BNE LOOP                ; Branch to the loop if not equal

STOP
XSS B XSS
    END                     ; Mark end of the file
