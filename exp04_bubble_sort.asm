; Experiment No: 04
; Write a program to arrange a series of 32-bit numbers in ascending/descending order
; Used Bubble Sort algorithm
; N = 4, values: 44, 11, 33, 22
; No of passes = 3 (N-1) - outer loop, counter used: R9
; No of comparisons in each pass = N-1 (i.e., 3 in first pass)
; Inner loop counter used: R5
; Copy data from CODE area to DATA area, counter used: R8

    AREA ASCENDING, CODE, READONLY
ENTRY                               ; Mark first instruction to execute
START
    MOV R8, #4              ; Initialize counter to 4 (N=4)
    LDR R2, =CVALUE         ; Address of code region
    LDR R3, =DVALUE         ; Address of data region

LOOP0
    LDR R1, [R2], #4        ; Loading values from code region
    STR R1, [R3], #4        ; Storing values to data region
    SUBS R8, R8, #1         ; Decrement counter
    CMP R8, #0              ; Compare counter to 0
    BNE LOOP0               ; Loop back till array ends

    MOV R9, #3              ; Initialize outer loop counter to 3
OUTLOOP
    MOV R5, #3              ; Initialize inner loop counter to 3
    LDR R1, =DVALUE         ; Load address of first value

INLOOP
    LDR R2, [R1], #4        ; Word align to array element
    LDR R3, [R1]            ; Load second number
    CMP R2, R3              ; Compare numbers
    BLT SKIP                ; If first number < then go to SKIP
    STR R2, [R1], #-4       ; Interchange number R2 & R3
    STR R3, [R1]            ; Interchange number R2 & R3
    ADD R1, #4              ; Restore the pointer

SKIP
    SUBS R5, R5, #1         ; Decrement inner counter
    CMP R5, #0              ; Compare counter to 0
    BNE INLOOP              ; Inner loop

    SUBS R9, R9, #1         ; Decrement outer counter
    CMP R9, #0              ; Compare counter to 0
    BNE OUTLOOP             ; If flag is not zero then go to start

XSS
    B XSS

; Array of 32-bit numbers (N=4) in code area
CVALUE
    DCD 0x44444444
    DCD 0x11111111
    DCD 0x33333333
    DCD 0x22222222

    AREA DATA, DATA, READWRITE
DVALUE
    DCD 0x00000000

    END                     ; Mark end of the file
