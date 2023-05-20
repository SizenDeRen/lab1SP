arr:
  .byte 1, 2, 3, 4, 5, 6, 7, 8, 9, 255
output_msg:
  .string "Количество элементов, меньших числа 128: %d\n"

.globl _start
_start:
  movl $arr, %esi     
  movl $10, %ecx      
  movl $0, %eax    
loop:
  cmpl $0, %ecx       
  jz end_loop         
  movb (%esi), %bl    
  orb $0x6B, %bl
  andb $0x80, %bl     
  jz increment        
  addl $1, %esi       
  subl $1, %ecx       
  jmp loop            
increment:
  addl $1, %eax       
  addl $1, %esi       
  subl $1, %ecx       
  jmp loop            
end_loop:
  pushl %eax          
  pushl $output_msg   
  call printf         
  addl $8, %esp       
  movl $1, %eax       
  xorl %ebx, %ebx     
  int $0x80           
