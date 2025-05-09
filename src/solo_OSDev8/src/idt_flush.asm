global idt_flush

idt_flush:
    mov eax, [esp + 4] ; Get address of IDT pointer
    lidt [eax]         ; Load it into IDTR
    ret
