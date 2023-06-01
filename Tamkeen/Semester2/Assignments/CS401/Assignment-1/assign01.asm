[org 0x0100] ; a program to add ten numbers 
mov bx,vuid; point bx to first number  MC200400003
mov cx,9; load count of vuid in cx 
mov ax,0; initialize sum to zero 
l1:
add ax, [bx]; add number to ax 
add bx, 2; advance bx to next number 
sub cx, 1; numbers to be added reduced 
jnz l1; if numbers remain add next 
mov [total], ax; write back sum in memory 
mov ax,0x4c00
int 0x21; terminate program 
;MC200400003
vuid: dw 2, 0, 0, 4, 0, 0, 0, 0, 3
total: dw 0