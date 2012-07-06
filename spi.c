#include "registers.h"

/*  FROM DATUMS-SHEET -- During discontinuous communications, there is a 2 APB clock period delay between the
    write operation to SPI_DR and the BSY bit setting. As a consequence, it is mandatory to
    wait first until TXE=1 and then until BSY=0 after writing the last data.  */

void init_spi2(void){
    RCC_APB1ENR |= SPI2_APB1EN;
    GPIOE_MODER |= (1 << (MPU6000_CS*2));
    GPIOE_ODR |= (1 << MPU6000_CS);
    SPI2_CR1 |= (1 << SSM) | (0x2 << 3) | (1 << MSTR) | (1 << CPOL);
    SPI2_CR2 |= (1 << TXDMAEN) | (1 << RXDMAEN);
    SPI2_CR1 |= (1 << SPE); //Enable it after config, AND PRAY.
}
