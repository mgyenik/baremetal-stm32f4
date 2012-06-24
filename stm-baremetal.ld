/* Baremetal linker script. Derivative of the one for F4OS */

/* Specify the memory areas */
MEMORY
{
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 1024K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 112K
  ETHRAM (xrw)    : ORIGIN = 0x2001C000, LENGTH = 16K
  CCMRAM (xrw)    : ORIGIN = 0x10000000, LENGTH = 64K
}

/* Highest address of the kernel stack */
_estack = 0x10010000;    /* end of 64K CCM RAM */

/* Heap */
_suserheap = 0x20000000;    /* beginning of 112K SRAM */
_euserheap = 0x2001BFFC;    /* end of 112K SRAM */
_skernelheap = _ebss;
_ekernelheap = 0x10007FFC;

SECTIONS {
    .vectors 0x0 :
    {
        KEEP(*(.vectors))
        . = ALIGN(4);
    }

    .text :
    {
        . = ALIGN(4);
        _stext = .;
        *(.text*)
        . = ALIGN(8);

        _etext = .;
    } > FLASH

    _sidata = .;
    .data : AT ( _sidata )
    {
        . = ALIGN(4);
        _sdata = .;        /* create a global symbol at data start */
        *(.data*)           /* .data sections */

        . = ALIGN(4);
        _edata = .;        /* define a global symbol at data end */
    } > CCMRAM

    /* Uninitialized data section */
    _sibss = .;
    .bss : AT ( _sibss )
    {
        . = ALIGN(4);
        _sbss = .;         /* define a global symbol at bss start */
        *(.bss*)

        . = ALIGN(4);
    } > CCMRAM
    _ebss = .;         /* define a global symbol at bss end */
}

PROVIDE(end = .);
_end            = .;
