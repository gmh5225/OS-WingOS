
![Banner](screen_shot/wingOS.png)

![sample](screen_shot/sample4_26_12_2020png.png)

### Building
for building you can take a look at the [Build guide](./Build_guide.md)
### Services

It works with the concept of 'services' ,
everything is a service and maybe later replacable with a user application, 
WingOS has 6 syscalls : 
```cpp

enum syscall_codes
{
    NULL_SYSCALL = 0,
    SEND_SERVICE_SYSCALL            = 1,        // send a message to a service

    READ_SERVICE_SYSCALL            = 2,        // read all message that you have

    GET_RESPONSE_SERVICE_SYSCALL    = 3,        // if the message sended has been responded

    GET_PROCESS_GLOBAL_DATA         = 4,        // get process global data, if arg1 (target) is nullptr, return self global data, else return a process global data return -1 if there is an error
    
    SEND_PROCESS_SYSCALL_PID        = 5,        // this is used to send a message to a process and not a service
    MEMORY_ALLOC                    = 6,        // alloc some pages
    MEMORY_FREE                     = 7, 
};
```
the user application communicates with the kernel through kernel services : 
    - graphic_buffer_service
    - kernel_process_service
    - memory_service
    - print_service // may be changed
    - ps2_device_service
    - time_service
    ...

the user can create services too, like the graphic_system_service app, in app/graphic_system_service/

it is easy and fast.

oh and the kernel supports smp multithreading <3

and some services are called ORS (On Request Service)

ORS are only active when they receive a message.

To build WingOS, go to Build_guide.md <3
### Implemented things :
 - com
 - gdt
 - idt
 - *pic* / ioapic
 - paging (pmm + vmm)
 - memory (thank lib alloc)
 - smp
 - multiprocessing
 - smp multiprocessing
 - ioapic timer
 - madt 
 - apic 
 - acpi
 - basic ATA driver
 - echfs support
 - program launcher (only elf64 programs for the moment)
 - really basic pci table parser
 - process message
 - little gui system
 - ps2 mouse driver
 - basic e1000 driver
 - basic rtl8139 driver
 - AHCI support
 - Sata AHCI
 - \[insert something here]
 
 
