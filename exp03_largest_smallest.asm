; Experiment No: 03
; Write a program to find the largest/smallest number in an array of 32-bit numbers
; VALUE1 = 44, 22, 55, 33, AA, CC, 99
; R5 is loop counter = 6 (N-1 comparisons)
; R2 holds the largest value
; R2(largest) = 44 -> 55 -> 55 -> AA -> CC -> CC

    AREA LARGEST, CODE, READONLY    ; Mark first instruction to execute
ENTRY
START
    MOV R5, #6              ; Initialize counter to 6 (7-1)
    LDR R1, =VALUE1         ; Load address of first value
    LDR R2, [R1], #4        ; Word align to array elements

LOOP
    LDR R4, [R1], #4        ; Word align to array element
    CMP R2, R4              ; Compare numbers
    BHI LOOP1               ; If first number > then go to Loop1
    MOV R2, R4              ; If first number is < move contents of R4 to R2

LOOP1
    SUBS R5, R5, #1         ; Decrementing counter
    CMP R5, #0              ; Compare with 0
    BNE LOOP                ; Loop till array ends
    LDR R4, =RESULT         ; Load address of result
    STR R2, [R4]            ; Store the result in R2

XSS
    B XSS

; Array of 3-bit numbers (N=7)
VALUE1
    DCD 0x44444444
    DCD 0x22222222
    DCD 0x55555555
    DCD 0x33333333
    DCD 0xAAAAAAAA
    DCD 0xCCCCCCCC
    DCD 0x99999999

    AREA DATA2, DATA, READWRITE
RESULT
    DCD 0x0             ; Store the result at the given address

    END                 ; Mark end of the file
