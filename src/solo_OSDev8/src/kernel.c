#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include "libc/string.h"
#include <multiboot2.h>
#include "gdt.h"

struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

int main(uint32_t magic, struct multiboot_info* mb_info_addr) {

    gdt_install();

    char* str = "Hello World from solo_OSDev8!";
    size_t len = strlen(str);

    //wirte to video memory
    char* video_memory = (char*)0xB8000;
    //write hello world to video memory
    for (size_t i = 0; i < len; i++) {
        video_memory[i * 2] = str[i]; 
        video_memory[i * 2 + 1] = 0x3; 
    }

    return 0;

}