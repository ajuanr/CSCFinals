.data
.balign 4
inFrmt: .asciz "%d"

.balign 4
inNum: .word 0

.balign 4
rtMsg: .asciz "Enter number(1-10,000) whose root you want: "

.balign 4
numRead: .asciz "Num read is %d\n"

.balign 4
rootIs: .asciz "Square root is %f\n"

.balign 4
half: .float 0.5

/* for nums 1-10000 sqrt is 0-100 */
.balign 4
xNot: .float 50

.text
.global problem3
problem3:
    push {r4, r5, r6, lr}

    ldr r0, =rtMsg
    bl printf

    ldr r0, =inFrmt
    ldr r1, adr_inNum
    bl scanf

    ldr r0, =numRead
    ldr r1, adr_inNum
    ldr r1, [r1]
    bl printf

    vmov s10, r1                 /* s10 holds the num S*/

    vcvt.f32.s32 s10, s10        /* convert number to float */


    /* for printing */
    vcvt.f64.f32 d0, s12
    vmov r2, r3, d0
    ldr r0, =rootIs
    bl printf

    ldr r0, =half
    vldr s11, [r0]               /* s11 holds 1/2 */

    mov r5, #10                   /* r5 holds counter */
    bLoop:
    ldr r0, =xNot
    vldr s12, [r0]               /* s12 holds initial guess xNot */

    /* this xi = (xi-1 + S/xi-1)/2 */
    vmov s13, s12
    vdiv.f32 s12, s10, s12 
    vadd.f32 s12, s12, s13
    vmul.f32 s12, s12, s11

    ldr r0, =xNot                /* save the value for next iteration */
    vstr s12, [r0]

    sub r5, r5, #1
    cmp r5, #0
    bne bLoop
      
    /* for printing */
    vcvt.f64.f32 d0, s12
    vmov r2, r3, d0
    ldr r0, =rootIs
    bl printf

    pop {r4, r5, r6,  lr}
    bx lr

adr_inNum: .word inNum 
