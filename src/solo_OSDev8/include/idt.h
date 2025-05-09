#pragma once
#include "libc/stdint.h"

// Interrupt Descriptor Table (IDT) structure

#define IDT_ENTRIES 256 // Number of IDT entries

struct idt_entry {
    uint16_t base_low;     // Lower 16 bits of ISR address
    uint16_t selector;     // Kernel code segment selector
    uint8_t  zero;         // Always 0
    uint8_t  flags;   
    uint16_t base_high;    // Upper 16 bits of ISR address
} __attribute__((packed));

// Used to load the IDT with the lidt instruction
struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Functions to set and load the IDT
void idt_init();
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);
void idt_install(void);
