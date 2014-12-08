.data
.balign 4

msg: .asciz "Program calculates the future value\n"

yrsMsg: .asciz "Enter the number of years (1-20): "
intrMsg: .asciz "Enter the interest as a decimal 5-10%: "
pvMsg: .asciz "Enter the present value ($1000 -$5000): "

yrsIn: .word 0
intrIn: .float 0
pvIn: .float 0

yrsFrmt: .asciz "%d"
intrFrmt: .asciz "%f"
pvFrmt: .asciz "%f"

/* array hold the future value calculations */
.balign 4
fvArray: .skip 100

.text
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
     ldr r0, =intrMsg
     bl printf
     ldr r0, =intrFrmt
     ldr r1, =intrIn
     bl scanf 

     /* Get the present value */
     ldr r0, =pvMsg
     bl printf
     ldr r0, =pvFrmt
     ldr r1, =pvIn
     bl scanf

     pop {r4, r5, r6, r7, lr}
     bx lr
