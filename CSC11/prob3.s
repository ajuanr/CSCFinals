.data
inFrmt: .asciz "%d"

inNum: .word 0

rtMsg: .asciz "Enter number whose root you want: "

.balign 4
numRead: .asciz "Num read is %d\n"

.balign 4
floatRead: .asciz "Float is %f\n"

.balign 4
half: .float 0.5

/* for nums 1-10000 sqrt is 0-100 */
.balign 4
xNot: .float 50

.text
.global main
main:
    push {r4,r5, r6, lr}

    ldr r0, =rtMsg
    bl printf

    ldr r0, =inFrmt
    ldr r1, adr_inNum
    bl scanf

    ldr r0, =numRead
    ldr r1, adr_inNum
    ldr r1, [r1]
    bl printf

    ldr r1, adr_inNum
    ldr r1, [r1]
    vmov s10, r1                 /* s10 holds the num */

    vcvt.f32.s32 s10, s10        /* convert number to float */

    ldr r0, =half
    vldr s11, [r0]               /* s11 holds 1/2 */
    ldr r0, =xNot
    vldr s12, [r0]               /* s12 holds initial guess xNot */

    vdiv.f32 s10, s10, s12 
    vadd.f32 s10, s10, s12
    vmul.f32 s10, s11, s10


    /* for printing */
    vcvt.f64.f32 d0, s10

    vmov r2, r3, d0
    ldr r0, =floatRead
    bl printf
      

    pop {r4, r5, r6,  lr}
    bx lr

adr_inNum: .word inNum 
