#include "registers.h"


void init_dma1(void){
    DMA1_S0CR &= !(1 << DMA_EN);            /* clear EN to prep for configuration */
    while( (1 << DMA_EN) & DMA1_S0CR){};    /* Actually cleared when transfer completes, so wait. */
    /* Clear all leftover interrupt flags, if any */
    DMA1_LIFCR |= (1 << CTCIF0) | (1 << CHTIF0) | (1 << CTEIF0) | (1 << CDMEIF0) | (1 << CFEIF0);
    DMA1_S0PAR = &SPI2_DR;
}


