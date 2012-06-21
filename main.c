#include "registers.h"
#include "main.h"


void init_leds(void){
    RCC_AHB1ENR |= (1 << 4);
    GPIOE_MODER = (1 << (RED*2)) |(1 << (YELLOW*2)) |(1 << (GREEN*2)) ;
}

int main(void){
    long delay = 2000000;
    init_leds();
    while(1){
        delay = 2000000;
        while(--delay){};
        MPLED_ODR ^= (1 << GREEN);
    }
}    
