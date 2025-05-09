; Assembly code to flush the GDT and reload the segment registers.
global gdt_flush

gdt_flush:
    mov eax, [esp + 4]    ; address of the GDT pointer
    lgdt [eax]            ; load GDT

    mov ax, 0x10          ; data segment selector
    mov ds, ax            
    mov es, ax            
    mov fs, ax            
    mov gs, ax            
    mov ss, ax            

    jmp 0x08:.flush       ; reload CS
.flush:
    ret                   
