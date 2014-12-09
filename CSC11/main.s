/* To Compile
	gcc -c prob1.s
	gcc -c prob2.s
	gcc -c prob3.s
        gcc -c prob4.s
        gcc -c divMod.s
	gcc prob1.o prob2.o prob3.o prob4.o divMod.o main.s -o mdTrm
	./mdTrm
*/
.data
 
messageM1: .asciz "\n\nMenu for the Final\n"
messageM2: .asciz "Type 1 for problem 1\n"
messageM3: .asciz "Type 2 for problem 2\n"
messageM4: .asciz "Type 3 for problem 3\n"
messageM7: .asciz "Type 4 for problem 4\n"
messageM5: .asciz "Type anything else to exit \n\n"
formatM:   .asciz "%d"
messageM6: .asciz "The Final is Completed!!!\n"

.text
 
.globl main
main:
    push {lr}                 /* str lr, [sp,#-4]! Push lr onto the top of the stack */
    sub sp, sp, #4               /* Make room for one 4 byte integer in the stack */
                                 /* In these 4 bytes we will keep the number */
                                 /* entered by the user */
                                 /* Note that after that the stack is 8-byte aligned */
	menu:
		ldr r0, ad_M1                
		bl printf                    /* Call printf */
		ldr r0, ad_M2                
		bl printf                    /* Call printf */
		ldr r0, ad_M3                
		bl printf                    /* Call printf */
		ldr r0, ad_M4                
		bl printf                    /* Call printf */
		ldr r0, ad_M7                
		bl printf                    /* Call printf */
		ldr r0, ad_M5                
		bl printf                    /* Call printf */
 
		ldr r0, ad_fM                /* Set &format as the first parameter of scanf */
		mov r1, sp                   /* Set the top of the stack as the second parameter */
									 /* of scanf */
		bl scanf                     /* Call scanf */
 
		ldr r0, [sp]                 /* Load the integer read by scanf into r0 */
		cmp r0,#1					 /* Choose the problem to execute */
		beq p1
		cmp r0,#2
		beq p2
		cmp r0,#3
		beq p3
		cmp r0,#4
		beq p4
		b end
    
		p1:
			bl problem1                  /* Call Problem1  */
			b menu
	
		p2:
			bl problem2                  /* Call Problem2  */
			b menu
	
		p3:
			bl problem3                  /* Call Problem3  */
			b menu
		p4:
			bl problem4                  /* Call Problem4  */
			b menu
 
	end:
    
	ldr r0, ad_M6                /* Set &message2 as the first parameter of printf */
    bl printf                    /* Call printf */
 
    add sp, sp, #+4              /* Discard the integer read by scanf */
    pop {lr}                  /* ldr lr, [sp], #+4 Pop the top of the stack and put it in lr */
    bx lr                        /* Leave main */
 
ad_M1: .word messageM1
ad_M2: .word messageM2
ad_M3: .word messageM3
ad_M4: .word messageM4
ad_M5: .word messageM5
ad_M6: .word messageM6
ad_M7: .word messageM7
ad_fM: .word formatM
