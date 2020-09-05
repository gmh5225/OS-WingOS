#include <arch/process.h>
#include <com.h>
#include <device/pit.h>
#include <int_value.h>
#include <kernel.h>
#include <stivale_struct.h>
#include <utility.h>
/*
    pour le moment tout ce qui est ici est un test
    for the moment everything here is for test
*/
void _start(stivale_struct *bootloader_data)
{
    asm volatile("sti");
    uint32_t d = 100;

    uint32_t *dd = (uint32_t *)bootloader_data->framebuffer_addr;
    printf(" frame buffer address %x", bootloader_data->framebuffer_addr);
    uint64_t update_tick = 0;
    uint64_t started_sec = 0;
    unlock_process();
    while (true)
    {
        for (uint64_t i = 0; i < bootloader_data->framebuffer_width *
                                     bootloader_data->framebuffer_height;
             i++)
        {
            dd[i] = d;
        }
        update_tick++;
        if (PIT::the()->passed_sec != started_sec)
        {
            started_sec = PIT::the()->passed_sec;
            printf("fps  : %x", update_tick);
            update_tick = 0;
        }

        d++;
    }
}
