.data
inFrmt: .asciz "%d"

inNum: .word 0

rtMsg: "Enter number whose root you want: "

.balign 4
numRead:  "Num read is %d\n"

.text
.global main
main:
    push {r4,r5, r6, lr}

    ldr r0, =rtMsg:
    bl printf

    ldr r0, =inFrmt
    ldr r1, =inNum
    bl scanf

    ldr r0, =numRead
    ldr r1, =inNum
    ldr r1, [r1]
    bl printf
      

    pop {r4, r5, r6,  lr}
    bx lr
 
