#pragma once
#include <arch/64bit.h>
#include <arch/arch.h>
#include <arch/gdt.h>
#include <arch/interrupt.h>
#include <int_value.h>
#define LOCAL_DATA_DMSR 0xC0000100
struct local_data
{

    void *me;
    uint64_t stack_base;
    uint64_t current_processor_id;
    idtr_t idt;
    gdtr_t gdt;
    tss_t tss;

    void (*apictimer_handler)(InterruptStackFrame *);
    uint8_t stack_data[8192] __attribute__((aligned(4096)));
} __attribute__((packed));
void set_current_data(local_data *dat);
local_data *get_current_data();
local_data *get_current_data(int id);
