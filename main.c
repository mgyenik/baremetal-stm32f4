#include "registers.h"
#include "main.h"
#include "spi.h"
#include "dma.h"

void init_leds(void){
    RCC_AHB1ENR |= (1 << 4);
    GPIOE_MODER = (1 << (RED*2)) |(1 << (YELLOW*2)) |(1 << (GREEN*2)) ;
}

int main(void){
    long delay = 2000000;
    unsigned char lol[5] = {0xAA, 0x55, 0x01, 0x02, 0x03};
    init_leds();
    init_dma1_s4(lol);
    init_spi2();
    while(1){
        delay = 2000000;
        while(--delay){};
        MPLED_ODR |= (1 << GREEN);
        delay = 2000000;
        while(--delay){};
        MPLED_ODR |= (1 << YELLOW);
        delay = 2000000;
        while(--delay){};
        MPLED_ODR |= (1 << RED);
        delay = 2000000;
        while(--delay){};
        MPLED_ODR = 0;
    }
}
