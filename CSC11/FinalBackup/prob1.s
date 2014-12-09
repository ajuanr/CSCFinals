/* Guess a number between 1 and 1000 */
.data
.balign 4
newLine: .asciz "\n"

.balign 4
gesMsg: .asciz "Enter a number between 1 and 1000: "

.balign 4
tooHigh: .asciz "Too high. Try again.\n"

.balign 4
tooLow: .asciz "Too low.Try again.\n"

.balign 4
correct: .asciz "You guess was correct!\n"

.balign 4
reveal: .asciz "Too many guesses. The number was %d.\n"

.balign 4
inGuess: .word 0

.balign 4
gesFrmt: .asciz "%d"

.balign 4
againMsg: .asciz "Would you like to play again(y)? "

.balign 4
againForm: .asciz " %c"

.balign 4
againChoice: .word 0

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

.global problem1
problem1:
    push {r4, lr}

    /* seed the random number generator */
    mov r0, #0
    bl time
    bl srand

    play:
    ldr r0, =newLine
    bl printf

    mov r0, #1
    mov r1, #1000
    bl random                       /* random returns num in r0*/
    mov r4, r0                      /* save the number in r4 */

    mov r5, #10                    /* initialize counter */
    guessLoop:
    cmp r5, #0
    beq tooMany                    /* only 10 guesses allowed */

    ldr r0, =gesMsg
    bl printf

    ldr r0, =gesFrmt              /* get the guess */
    mov r1, sp
    bl scanf

    ldr r1, [sp]
    
    sub r5, r5, #1                 /* decrement counter */

    cmp r1, r4                     /* compare guess with random number */
    bgt high
    blt low
    beq done

    high:
        ldr r0, =newLine
        bl printf
        ldr r0, =tooHigh
        bl printf
        b guessLoop

    low:
        ldr r0, =newLine
        bl printf
        ldr r0, =tooLow
        bl printf
        b guessLoop

    done:
        ldr r0, =newLine
        bl printf
        ldr r0, =correct
        bl printf
        b playAgain

    tooMany:
        ldr r0, =newLine
        bl printf
        ldr r0, =reveal
        mov r1, r4
        bl printf

    playAgain:
        ldr r0, =againMsg
        bl printf

        ldr r0, =againForm
        ldr r1, =againChoice
        bl scanf

        ldr r1, =againChoice
        ldr r1, [r1]
        cmp r1, #'y'
        beq play

    exit:
        pop {r4, lr}
        bx lr

