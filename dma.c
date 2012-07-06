#include "registers.h"


void init_dma1_s4(unsigned char * buf){
    DMA1_S4CR &= !(1 << DMA_EN);            /* clear EN to prep for configuration */
    while( (1 << DMA_EN) & DMA1_S4CR){};    /* Actually cleared when transfer completes, so wait. */
    /* Clear all leftover interrupt flags, if any */
    DMA1_HIFCR |= (1 << CTCIF4) | (1 << CHTIF4) | (1 << CTEIF4) | (1 << CDMEIF4) | (1 << CFEIF4);
    DMA1_S4PAR  = (uint32_t)&SPI2_DR;
    DMA1_S4M0AR = (uint32_t)buf;
    DMA1_S4NDTR = 5;
    DMA1_S4CR  |= (1 << PFCTRL) | (1 << DMA_DIR) | (1 << MINC) | (2 << PL) | (4 << CHSEL);
    DMA1_S4CR  |= (1 << DMA_EN);
}


