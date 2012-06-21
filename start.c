#include "registers.h"
#include "start.h"

extern const uint32_t _etext;
extern const uint32_t _sdata;
extern const uint32_t _edata;
extern const uint32_t _sbss;
extern const uint32_t _ebss;
extern const uint32_t _estack;


#define HSE_STARTUP_TIMEOUT     (uint16_t) (0x0500)         /* Time out for HSE start up */
/* PLL Options - See RM0090 Reference Manual pg. 95 */
#define PLL_M      8            /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N */
#define PLL_N      336
#define PLL_P      2            /* SYSCLK = PLL_VCO / PLL_P */
#define PLL_Q      7            /* USB OTG FS, SDIO and RNG Clock =  PLL_VCO / PLLQ */


__attribute__((section(".vectors"))) void(*vector_table[])(void) = {
    (void(*)(void))&_estack,            /* stack top address */
    reset,               /* 1 Reset */
    chill,               /* 2 NMI */
    chill,               /* 3 HardFault */
    chill,               /* 4 MemManage */
    chill,               /* 5 BusFault */
    chill,               /* 6 UsageFault */
    chill,               /* 7 RESERVED */
    chill,               /* 8 RESERVED */
    chill,               /* 9 RESERVED*/
    chill,               /* 10 RESERVED */
    chill,               /* 11 SVCall */
    chill,               /* 12 Debug Monitor */
    chill,               /* 13 RESERVED */
    chill,               /* 14 PendSV */
    chill,//systick_handler,    /* 15 SysTick */
    chill,               /* 16 External Interrupt(0) */
    chill,               /* 17 External Interrupt(1) */
    chill,               /* 18 External Interrupt(2) */
    chill                /* 19 */
};

void chill(void){
    while(1){
        /* Maybe blink a light o' doom here or something */
    }
}

void cstart(void){
    /* Use symbols provided by linker to get data contents from nonvolatile memory (at end of .text) and copy to .data in RAM */
    uint32_t* nvdata = &_etext;
    uint32_t* data =  &_sdata;
    while(data < &_edata){
        *(data++) = *(nvdata++);
    }
    /* Now zero .bss, for all global/static stuff that has no initial value */
    data = &_sbss;
    while(data < &_ebss){
        *(data++) = 0;
    }
}

void reset(void){
    cstart();
    clocks();
    main();
    while(1){
        __asm__("nop"); //main should never return. but you never know...
    }
}

void clocks(void) {
    /********* Reset clock registers ************/
    /* Set HSION bit */
    RCC_CR |= (uint32_t)0x00000001;
    /* Reset CFGR register */
    RCC_CFGR = 0x00000000;
    /* Reset HSEON, CSSON and PLLON bits */
    RCC_CR &= (uint32_t)0xFEF6FFFF;
    /* Reset PLLCFGR register */
    RCC_PLLCFGR = 0x24003010;
    /* Reset HSEBYP bit */
    RCC_CR &= (uint32_t)0xFFFBFFFF;
    /* Disable all interrupts */
    RCC_CIR = 0x00000000;
    /******* Set up the clock *************/
    volatile uint32_t StartUpCounter = 0, HSEStatus = 0;
    /* Enable HSE */
    RCC_CR |= RCC_CR_HSEON;
    /* Wait till HSE is ready and if Time out is reached exit */
    do {
        HSEStatus = RCC_CR & RCC_CR_HSERDY;
        StartUpCounter++;
    } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
    if ((RCC_CR & RCC_CR_HSERDY) != 0) {
        HSEStatus = (uint32_t)0x01;
    }
    else {
        HSEStatus = (uint32_t)0x00;
    }
    if (HSEStatus == (uint32_t)0x01) {
        /* Enable high performance mode, System frequency up to 168 MHz */
        RCC_APB1ENR |= RCC_APB1ENR_PWREN;
        PWR_CR |= PWR_CR_VOS;  
        /* HCLK = SYSCLK / 1*/
        RCC_CFGR |= RCC_CFGR_HPRE_DIV1;
        /* PCLK2 = HCLK / 2*/
        RCC_CFGR |= RCC_CFGR_PPRE2_DIV2;
        /* PCLK1 = HCLK / 4*/
        RCC_CFGR |= RCC_CFGR_PPRE1_DIV4;
        /* Configure the main PLL */
        /* PLL Options - See RM0090 Reference Manual pg. 95 */
        RCC_PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
                       (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24);
        /* Enable the main PLL */
        RCC_CR |= RCC_CR_PLLON;
        /* Wait till the main PLL is ready */
        while((RCC_CR & RCC_CR_PLLRDY) == 0) {
        }
        /* Configure Flash prefetch, Instruction cache, Data cache and wait state */
        FLASH_ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_5WS;
        /* Select the main PLL as system clock source */
        RCC_CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC_CFGR |= RCC_CFGR_SW_PLL;
        /* Wait till the main PLL is used as system clock source */
        while ((RCC_CFGR & (uint32_t) RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL); {
        }
    }
    else { 
        /* If HSE fails to start-up, the application will have wrong clock configuration. */
        chill();
    }
    /* Enable the CCM RAM clock */
    RCC_AHB1ENR |= (1 << 20);
}
