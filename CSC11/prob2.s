.data
.balign 4
msg: .asciz "Program calculates the future value\n"

.balign 4
yrsMsg: .asciz "Enter the number of years (1-20): "
.balign 4
rateMsg: .asciz "Enter the interest as a decimal 5-10%: "
.balign 4
pvMsg: .asciz "Enter the present value ($1000 -$5000): "

.balign 4
yrsIn: .word 0
.balign 4
rateIn: .float 0
.balign 4
pvIn: .float 0

.balign 4
yrsFrmt: .asciz "%d"
.balign 4
rateFrmt: .asciz "%f"
.balign 4
pvFrmt: .asciz "%f"

.balign 4
tstMsg: .asciz "Value is  %f\n"

.balign 4
intMsg: .asciz "Int is %d\n"

/* to calculate future value */
.balign 4
one: .float 1.0

/* array hold the future value calculations */
.balign 4
fvArray: .skip 100


/* test array */
.balign 4
tstArray: 
       .float 1.0, 2.0, 3.0, 4.0, 5.0, 6.0

.text

/* Calculate the future value
 * FV = PV*(1+i)^n
 * NOTE: doest not work when n is zero
 *
 * numYears in       r0
 * present val in    s0
 * rate in           s1
 * return fv in      s0
 */
futrVal:
     push {r4-r6, lr}
     vpush {s15-s18}

     mov r4, r0                  /* r4 holds the number of years */
     vmov s14, s0                /* s14 holds present value */
     vmov s15, s1                /* s15 holds interest rate */

     ldr r6, =one
     vldr s16, [r6]              /* s16 holds 1.0 */

     vadd.f32 s16, s16, s15
 
     vmov s17, s16               /* copy s16 for multiplication */

     mov r5, #1                  /* put counter in r5 */

     powLoop:
         cmp r5, r4
         beq  finish 
         vmul.f32 s16, s17, s16
         add r5, r5, #1
         b powLoop

     finish:
     vadd.f32 s16, s16, s14

     vmov s0, s16             /* save in r0 for exit */

     vpop {s15-s18}
     pop {r4-r6, lr}
     bx lr
/* exit futrVal */

/* Fill the array with future values
 * numYears in       r0
 * present val in    s0
 * rate in           s1
 * array in          r1
 */ 
fillArray:
    push {r4-r8, lr}
    vpush {s16}

    mov r4, r0                  /* r4 holds the number of years */
    vmov s15, s0                /* s14 holds present value */
    vmov s16, s1                /* s15 holds interest rate */
    mov r5, r1                  /* r5 holds the output array */

    mov r6, #1                  /* r6 holds counter */
    add r8, r4, #1              /* ensure correct number of loops */
    mov r7, #0
    fillLoop:
        cmp r6, r8
        beq exitFill
  
        /* calculate the future value */
        mov r0, r6 
        vmov s0, s15
        vmov s1, s16
        bl futrVal

        vmov s15, s0             /* update  present value */

        @vmov r7, s15
        vstr s15, [r5, r7]
        @str r7, [r5, r6, lsl#2]
        add r6, r6, #1
        add r7, r7, #4
        b fillLoop

    exitFill:
        vpop {s16}
        pop {r4-r8, lr}
        bx lr

/* print an array of floats
 * num of elements in r0
 * array in           r1
 */
printArray:
    push {r4-r8, lr}

    mov r4, r0                /* r4 is num elements */
    mov r5, r1                /* r5 is array */


    mov r6, #1                /* r6 is counter */
    mov r7, #0                /* offset for vldr */
    printLoop:
       cmp r6, r4
       beq exit

       vldr s8, [r5,r7]   /* get the number */

        vcvt.f64.f32 d0, s8
        vmov r2, r3, d0
        ldr r0, =tstMsg
        bl printf
        add r6, r6, #1
        add r7, r7, #1

        b printLoop

    exit:
       pop {r4-r8, lr}
       bx lr

.global main
main:
     push {r4, r5, r6, lr}

     /* Get the number of years */
     ldr r0, =yrsMsg
     bl printf
     ldr r0, =yrsFrmt
     ldr r1, =yrsIn
     bl scanf

     /* Get the interest */
     ldr r0, =rateMsg
     bl printf
     ldr r0, =rateFrmt
     ldr r1, =rateIn
     bl scanf 

     /* Get the present value */
     ldr r0, =pvMsg
     bl printf
     ldr r0, =pvFrmt
     ldr r1, =pvIn
     bl scanf

     ldr r0, =yrsIn
     ldr r0, [r0]
     ldr r1, =pvIn
     vldr s0,[r1]
     ldr r2, =rateIn
     vldr s1, [r2]
     ldr r1, =fvArray
     bl fillArray     

     ldr r0, =yrsIn
     ldr r0, [r0]
     ldr r1, =fvArray
@     ldr r1, =tstArray
     bl printArray

     pop {r4, r5, r6, lr}
     bx lr

