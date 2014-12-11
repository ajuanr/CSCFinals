.data
.balign 4
msg: .asciz "Enter an x value, 0-255: "

.balign 4
xFrmt: .asciz "%d"

.balign 4
xIn: .word 0

.balign 4
rsltMsg: .asciz "The value 0.073x^2 + 0.86x is %d\n"

.text
.global problem4
problem4:
    push {r4, lr}

    ldr r0, =msg
    bl printf

 ldr r0, =xFrmt
    mov r1, sp
    bl scanf

    ldr r0, [sp]               /* r0 = x *        8 bits,       */
    ldr r1, =0x12B             /* r1 = a *       12 bits, >>12  */
    ldr r2, =0xE04             /* r2 = b *       12 bits, >>12  */

    mov r4, r0                 /* temp = x *      8 bits        */ 

    mul r0, r4, r0             /* x^2      *     16 bits, BP- 0 */
    mul r0, r1, r0             /* r0=a*x^2 *     20 bits, BP- 12 */

    mov r0, r0, lsr#10         /*                10 bits, BP- 2 */

    mul r4, r2, r4             /* r4 = b*x *     20 bits, BP- 12 */
   
    mov r4, r4, lsr#10         /*                10 bits, BP-  2 */

    add r0, r0, r4             /*                20 bits, BP- 2 */

    mov r0, r0, lsr#2

    mov r1, r0
    ldr r0, =rsltMsg
    bl printf

    pop {r4, lr}
    bx lr

