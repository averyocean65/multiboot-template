#include "vga/text/terminal.h"

void kernel_early_main() {
    init_terminal();
}

void kernel_main() {
    printf("Welcome to the multiboot-template!\n");
    printf("This VGA Text interface supports up to 16 colors!\n");

    printf("Here's an example:\n");
    for(int i = 0; i < 0xF; i++) {
        /* If i is 0, change the background color to white, if not make it black */
        int bg = (i != 0x0) ? 0x0 : 0xF;

        /* Change the color and print */
        color = vga_entry_color(i, bg);
        printcf('#');
    }
    printf("\n");
}

void kernel_end() {
    __asm__ ("hlt");
}