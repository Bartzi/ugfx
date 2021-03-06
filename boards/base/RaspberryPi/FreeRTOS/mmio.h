/* mmio.h - access to MMIO registers */
 
#ifndef MMIO_H
#define MMIO_H
 
#include <stdint.h>
 
// write to MMIO register
static GFXINLINE void mmio_write(gU32 reg, gU32 data) {
    gU32 *ptr = (gU32*)reg;
    asm volatile("str %[data], [%[reg]]"
	     : : [reg]"r"(ptr), [data]"r"(data));
}
 
// read from MMIO register
static GFXINLINE gU32 mmio_read(gU32 reg) {
    gU32 *ptr = (gU32*)reg;
    gU32 data;
    asm volatile("ldr %[data], [%[reg]]"
		 : [data]"=r"(data) : [reg]"r"(ptr));
    return data;
}
 
#endif // #ifndef MMIO_H
