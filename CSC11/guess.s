/* Guess a number between 1 and 1000 */
.data
.balign 4
gesMsg: .asciz "Enter a number between 1 and 1000: "

.balign 4
tooHigh: .asciz "Your guess of %d was too high.\n"

.balign 4
tooLow: .asciz "Your guess of %d was too low.\n"

.balign 4
inGuess: .word 0

.balign 4
gesFrmt: .asciz "%d"

.text

/* pass min value in r0
 * pass max value in r1 
 * return number in  r0 */
random:
    push {r4, r5, r6, lr}

    mov r4,r0                         /* Save min in r4 */
    mov r5, r1                        /* Save max in r5 */

    bl rand                           /* Call rand */
    
    mov r1, r0, asr #1                /* In case random return is negative */
    mov r2, r5
    bl divMod                         /* Call divMod function to get remainder */
                                          /* divmod returns in r1, r1 */

    mov r0, r1                        /* return result in r0 */
    add r0, r0, r4

    pop {r4, r5, r6, lr}                      /* Pop the top of the stack and put it in lr */
    bx lr                             /* Leave main */
/* Exit random number generator */


.global main
main:
    push {lr}
    sub sp,sp, #4

    ldr r0, =gesMsg
    bl printf

    ldr r0, =gesFrmt
    mov r1, sp
    bl scanf

    ldr r1, [sp]

    ldr r0, =tooHigh
    bl printf



    add sp, sp, #4
    pop {lr}
    bx lr

