
org 0x100

    xor     ax, ax
    mov     es, ax

    cli                         ; update ISR address w/ ints disabled
    push    word [es:9*4+2]     ; preserve ISR address
    push    word [es:9*4]
    mov     word [es:9*4], irq1isr
    mov     [es:9*4+2],cs
    sti

    call    test0

    cli                         ; update ISR address w/ ints disabled
    pop     word [es:9*4]       ; restore ISR address
    pop     word [es:9*4+2]
    sti

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;;;;;check the enter key ;;;;;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	l1: mov ah, 0 ; service 0 – get keystroke 
	int 0x16 ; call BIOS keyboard service 
	cmp al, 13 ; is the ENTER key pressed 
	jne l1 ; if no, check for next key 
	mov ax, 0x4c00 ; terminate program 
	int 0x21 
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ret

test0:
    mov     ah, 9
    mov     dx, msg1
    int     0x21                ; print "Press and hold SPACE"

test1:
    mov     al, [kbdbuf + 39H]    ; check SPACE key state (SPACE scan code = 39H)
    or      al, al
    jz      test1               ; wait until it's nonzero (pressed/held)

    mov     dx, msg2

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;Color the first half as Blue;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	MOV AH, 06h    ; Scroll up function
	XOR AL, AL     ; Clear entire screen
	XOR CX, CX     ; Upper left corner CH=row, CL=column
	MOV DX, 1827H  ; lower right corner DH=row, DL=column 
	MOV BH, 1Eh    ; YellowOnBlue
	INT 10H
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    int     0x21                ; print "SPACE pressed, release SPACE"

test2:
    mov     al, [kbdbuf + 39H]    ; check SPACE key state  (SPACE scan code = 39H)
    or      al, al
    jnz     test2               ; wait until it's zero (released/not pressed)

    mov     dx, msg3            ; print "SPACE released"

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;;;Color the 2nd half as green ;;;;;;;;;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	XOR CX, 0028H     ; Upper left corner CH=row, CL=column
	MOV DX, 184FH  ; lower right corner DH=row, DL=column 
	MOV BH, 28h    ; YellowOnBlue
	INT 10H
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    int     0x21

    ret

irq1isr:
    pusha

    ; read keyboard scan code
    in      al, 0x60

    ; update keyboard state
    xor     bh, bh
    mov     bl, al
    and     bl, 0x7F            ; bx = scan code
    shr     al, 7               ; al = 0 if pressed, 1 if released
    xor     al, 1               ; al = 1 if pressed, 0 if released
    mov     [cs:bx+kbdbuf], al

    ; send EOI to XT keyboard
    in      al, 0x61
    mov     ah, al
    or      al, 0x80
    out     0x61, al
    mov     al, ah
    out     0x61, al

    ; send EOI to master PIC
    mov     al, 0x20
    out     0x20, al

    popa
    iret


kbdbuf:
    times   128 db 0

msg1 db "Press and hold SPACE", 13, 10, "$"
msg2 db "SPACE pressed, release SPACE", 13, 10, "$"
msg3 db "SPACE released", 13, 10, "$"