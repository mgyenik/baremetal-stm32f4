/* STM32F4 Registers and Memory Locations */
/* Same good ol' file that's in the F4OS project. No need to reinvent the wheel. */

typedef unsigned long uint32_t;
typedef unsigned int uint16_t;

extern const uint32_t _skernel;
extern const uint32_t _ekernel;

/* Board specific */
#define MPU6000_CS          10

/* Make a SVC call */
#define _svc(x)     asm volatile ("svc  %0  \n" :: "i" (x))
/* Memory Map */
#define FLASH_BASE          (uint32_t) (0x08000000)                     /* Flash Memory Base Address */
#define RAM_BASE            (uint32_t) (0x20000000)                     /* RAM Base Address */
#define ETHRAM_BASE         (uint32_t) (0x2001C000)                     /* ETHRAM Base Address */
#define CCMRAM_BASE         (uint32_t) (0x10000000)                     /* CCMRAM Base Address - Accessable only to CPU */

/* Peripheral Map */
#define PERIPH_BASE         (uint32_t) (0x40000000)                     /* Peripheral base address */
#define APB1PERIPH_BASE     (PERIPH_BASE)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)

#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x0400)                  /* GPIO Port D base address */
#define GPIOD_BASE          (AHB1PERIPH_BASE + 0x0C00)                  /* GPIO Port D base address */
#define GPIOE_BASE          (AHB1PERIPH_BASE + 0x1000)                  /* GPIO Port D base address */
#define PWR_BASE            (APB1PERIPH_BASE + 0x7000)                  /* Power Control base address */
#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800)                  /* Reset and Clock Control base address */
#define FLASH_R_BASE        (AHB1PERIPH_BASE + 0x3C00)                  /* Flash registers base address */

/* System Control Map */
#define SCS_BASE            (uint32_t) (0xE000E000)                     /* System Control Space Base Address */
#define SCB_BASE            (SCS_BASE + 0x0D00)                         /* System Control Block Base Address */
#define MPU_BASE            (SCB_BASE + 0x0090)                         /* MPU Block Base Address */
#define SYSTICK_BASE        0xE000E010
#define USART2_BASE         0x40004400

/* GPIO Port D (GPIOD) */
#define GPIOD_MODER         *(volatile uint32_t *) (GPIOD_BASE + 0x00)  /* Port D mode register */
#define LED_ODR             *(volatile uint32_t *) (GPIOD_BASE + 0x14)  /* LED Output Data Register */
/* GPIO Port E (GPIOE) */
#define GPIOB_MODER         *(volatile uint32_t *) (GPIOB_BASE + 0x00)  /* Port B mode register */
#define GPIOB_ODR           *(volatile uint32_t *) (GPIOB_BASE + 0x14)  /* Output Data Register */
#define GPIOE_MODER         *(volatile uint32_t *) (GPIOE_BASE + 0x00)  /* Port E mode register */
#define MPLED_ODR           *(volatile uint32_t *) (GPIOE_BASE + 0x14)  /* LED Output Data Register */
#define GPIOE_ODR           MPLED_ODR
#define RED                 5
#define YELLOW              6
#define GREEN               7
/* USART 2 */
#define USART2_SR           *(volatile uint32_t *) (USART2_BASE + 0x00)
#define USART2_DR           *(volatile uint32_t *) (USART2_BASE + 0x04)
#define USART2_BRR          *(volatile uint32_t *) (USART2_BASE + 0x08)
#define USART2_CR1          *(volatile uint32_t *) (USART2_BASE + 0x0C)
#define USART2_CR2          *(volatile uint32_t *) (USART2_BASE + 0x10)
#define USART2_CR3          *(volatile uint32_t *) (USART2_BASE + 0x14)
#define USART2_GTPR         *(volatile uint32_t *) (USART2_BASE + 0x18)

/* SPI 2 */
#define SPI2_APB1EN         0x00004000
#define SPI2                0x40003800
#define SPI2_CR1            *(volatile uint32_t *) (SPI2 + 0x00)
#define SPI2_CR2            *(volatile uint32_t *) (SPI2 + 0x04)
#define SPI2_SR             *(volatile uint32_t *) (SPI2 + 0x08)
#define SPI2_DR             *(volatile uint32_t *) (SPI2 + 0x0c)
#define SPI2_CRCPR          *(volatile uint32_t *) (SPI2 + 0x10)
#define SPI2_RXCRCR         *(volatile uint32_t *) (SPI2 + 0x14)
#define SPI2_TXCRCR         *(volatile uint32_t *) (SPI2 + 0x18)
#define SPI2_I2SCFGR        *(volatile uint32_t *) (SPI2 + 0x1c)
#define SPI2_I2SPR          *(volatile uint32_t *) (SPI2 + 0x20)
#define BIDIMODE            15
#define BIDIOE              14
#define CRCEN               13
#define CRCNEXT             12
#define DFF                 11
#define RXONLY              10
#define SSM                 9
#define SSI                 8
#define LSBFIRST            7
#define SPE                 6
#define BR                  3
#define MSTR                2
#define CPOL                1
#define CPHA                0
#define TXEIE               7
#define RXNEIE              6
#define ERRIE               5
#define FRF                 4
#define SSOE                2
#define TXDMAEN             1
#define RXDMAEN             0
#define TIFRFE              8
#define BSY                 7
#define OVR                 6
#define MODF                5
#define CRCERR              4
#define UDR                 3
#define CHSIDE              2
#define TXE                 1
#define RXNE                0

/* DMA */
#define DMA1                0x40026000
#define DMA1_LISR           *(volatile uint32_t *)(DMA1 + 0x0000)
#define DMA1_HISR           *(volatile uint32_t *)(DMA1 + 0x0004) 
#define DMA1_LIFCR          *(volatile uint32_t *)(DMA1 + 0x0008) 
#define DMA1_HIFCR          *(volatile uint32_t *)(DMA1 + 0x000C) 
#define DMA1_S0CR           *(volatile uint32_t *)(DMA1 + 0x0010) 
#define DMA1_S0NDTR         *(volatile uint32_t *)(DMA1 + 0x0014)
#define DMA1_S0PAR          *(volatile uint32_t *)(DMA1 + 0x0018)
#define DMA1_S0M0AR         *(volatile uint32_t *)(DMA1 + 0x001C)
#define DMA1_S0M1AR         *(volatile uint32_t *)(DMA1 + 0x0020)
#define DMA1_S4CR           *(volatile uint32_t *)(DMA1 + 0x0070) 
#define DMA1_S4NDTR         *(volatile uint32_t *)(DMA1 + 0x0074)
#define DMA1_S4PAR          *(volatile uint32_t *)(DMA1 + 0x0078)
#define DMA1_S4M0AR         *(volatile uint32_t *)(DMA1 + 0x007C)
#define DMA1_S4M1AR         *(volatile uint32_t *)(DMA1 + 0x0080)
#define DMA1_S4FCR          *(volatile uint32_t *)(DMA1 + 0x0084)
#define TCIF7               27
#define HTIF7               26
#define TEIF7               25
#define DMEIF7              24
#define FEIF7               22
#define TCIF6               21
#define HTIF6               20
#define TEIF6               19
#define DMEIF6              18
#define FEIF6               16
#define TCIF5               11
#define HTIF5               10
#define TEIF5               9
#define DMEIF5              8
#define FEIF5               6
#define TCIF4               5
#define HTIF4               4
#define TEIF4               3
#define DMEIF4              2
#define FEIF4               0
#define CTCIF3              27
#define CHTIF3              26
#define TEIF3               25
#define CDMEIF3             24
#define CFEIF3              22
#define CTCIF2              21
#define CHTIF2              20
#define CTEIF2              19
#define CDMEIF2             18
#define CFEIF2              16
#define CTCIF1              11
#define CHTIF1              10
#define CTEIF1              9
#define CDMEIF1             8
#define CFEIF1              6
#define CTCIF0              5
#define CHTIF0              4
#define CTEIF0              3
#define CDMEIF0             2
#define CFEIF0              0
#define CTCIF7              27
#define CHTIF7              26
#define CTEIF7              25
#define CDMEIF7             24
#define CFEIF7              22
#define CTCIF6              21
#define CHTIF6              20
#define CTEIF6              19
#define CDMEIF6             18
#define CFEIF6              16
#define CTCIF5              11
#define CHTIF5              10
#define CTEIF5              9
#define CDMEIF5             8
#define CFEIF5              6
#define CTCIF4              5
#define CHTIF4              4
#define CTEIF4              3
#define CDMEIF4             2
#define CFEIF4              0
#define CHSEL               25
#define MBURST              23
#define PBURST              21
#define CT                  19
#define DBM                 18
#define PL                  16
#define PINCOS              15
#define MSIZE               13
#define PSIZE               11
#define MINC                10
#define PINC                9
#define CIRC                8
#define DMA_DIR             6
#define PFCTRL              5
#define TCIE                4
#define HTIE                3
#define TEIE                2
#define DMEIE               1
#define DMA_EN              0
#define TCIF3               27
#define HTIF3               26
#define TEIF3               25
#define DMEIF3              24
#define FEIF3               22
#define TCIF2               21
#define HTIF2               20
#define TEIF2               19
#define DMEIF2              18
#define FEIF2               16
#define TCIF1               11
#define HTIF1               10
#define TEIF1               9
#define DMEIF1              8
#define FEIF1               6
#define TCIF0               5
#define HTIF0               4
#define TEIF0               3
#define DMEIF0              2
#define FEIF0               0
#define FEIE                7
#define FS                  3
#define DMDIS               2
#define FTH                 0
/* Power Control (PWR) */
#define PWR_CR              *(volatile uint32_t *) (PWR_BASE + 0x00)    /* Power Control Register */
#define PWR_CSR             *(volatile uint32_t *) (PWR_BASE + 0x04)    /* Power Control/Status Register */

/* Reset and Clock Control (RCC) */
#define RCC_CR              *(volatile uint32_t *) (RCC_BASE + 0x00)    /* Clock Control Register */
#define RCC_PLLCFGR         *(volatile uint32_t *) (RCC_BASE + 0x04)    /* PLL Configuration Register */
#define RCC_CFGR            *(volatile uint32_t *) (RCC_BASE + 0x08)    /* Clock Configuration Register */
#define RCC_CIR             *(volatile uint32_t *) (RCC_BASE + 0x0C)    /* Clock Interrupt Register */
#define RCC_AHB1ENR         *(volatile uint32_t *) (RCC_BASE + 0x30)    /* AHB1 Enable Register */
#define RCC_APB1ENR         *(volatile uint32_t *) (RCC_BASE + 0x40)    /* APB1 Peripheral Clock Enable Register */

/* Flash Registers (FLASH) */
#define FLASH_ACR           *(volatile uint32_t *) (FLASH_R_BASE + 0x00)/* Flash Access Control Register */

/* System Control Block (SCB) */
#define SCB_VTOR            *(volatile uint32_t *) (SCB_BASE + 0x008)   /* Vector Table Offset Register */
#define SCB_CPACR           *(volatile uint32_t *) (SCB_BASE + 0x088)   /* Coprocessor (FPU) Access Control Register */
#define SCB_SHCSR           *(volatile uint32_t *) (SCB_BASE + 0x024)   /* System Handler Control and State Register */

/* SysTick Timer */
#define SYSTICK_CTL         *(volatile uint32_t *) (SYSTICK_BASE)        /* Control register for SysTick timer peripheral */
#define SYSTICK_RELOAD      *(volatile uint32_t *) (SYSTICK_BASE + 0x04) /* Value assumed by timer upon reload */
#define SYSTICK_VAL         *(volatile uint32_t *) (SYSTICK_BASE + 0x08) /* Current value of timer */
#define SYSTICK_CAL         *(volatile uint32_t *) (SYSTICK_BASE + 0x0C) /* Calibration settings/value register */

/* Memory Protection Unit (MPU) 
 * ST PM0214 (Cortex M4 Programming Manual) pg. 195 */
#define MPU_TYPER           *(volatile uint32_t *) (MPU_BASE + 0x00)    /* MPU Type Register - Describes HW MPU */
#define MPU_CTRL            *(volatile uint32_t *) (MPU_BASE + 0x04)    /* MPU Control Register */
#define MPU_RNR             *(volatile uint32_t *) (MPU_BASE + 0x08)    /* MPU Region Number Register */
#define MPU_RBAR            *(volatile uint32_t *) (MPU_BASE + 0x0C)    /* MPU Region Base Address Register */
#define MPU_RASR            *(volatile uint32_t *) (MPU_BASE + 0x10)    /* MPU Region Attribute and Size Register */



/* Bit Masks - See RM0090 Reference Manual for STM32F4 for details */
#define PWR_CR_VOS              (uint16_t) (0x4000)         /* Regulator voltage scaling output selection */

#define RCC_CR_HSEON            (uint32_t) (0x00010000)     /* Enable HSE */
#define RCC_CR_HSERDY           (uint32_t) (0x00020000)     /* HSE Ready */
#define RCC_CR_PLLON            (uint32_t) (0x01000000)     /* Main PLL Enable */
#define RCC_CR_PLLRDY           (uint32_t) (0x02000000)     /* Main PLL clock ready */

#define RCC_CFGR_SW             (uint32_t) (0x00000003)     /* SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_PLL         (uint32_t) (0x00000002)     /* PLL selected as system clock */
#define RCC_CFGR_SWS            (uint32_t) (0x0000000C)     /* SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_PLL        (uint32_t) (0x00000008)     /* PLL used as system clock */
#define RCC_CFGR_HPRE_DIV1      (uint32_t) (0x00000000)     /* SYSCLK not divided (highest frequency) */
#define RCC_CFGR_PPRE2_DIV2     (uint32_t) (0x00008000)     /* HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4     (uint32_t) (0x00001400)     /* HCLK divided by 4 */

#define RCC_PLLCFGR_PLLSRC_HSE  (uint32_t) (0x00400000)     /* HSE oscillator selected as clock entry */

#define RCC_APB1ENR_PWREN       (uint32_t) (0x10000000)     /* Power Interface Clock Enable */

#define FLASH_ACR_ICEN          (uint32_t) (0x00000200)     /* Instruction Cache Enable */
#define FLASH_ACR_DCEN          (uint32_t) (0x00000400)     /* Data Cache Enable */
#define FLASH_ACR_LATENCY_5WS   (uint32_t) (0x00000005)     /* 5 Wait States Latency */

/* System Control Block */
#define SCB_SHCSR_MEMFAULTENA   (uint32_t) (1 << 16)        /* Enables Memory Management Fault */

/* Memory Protection Unit */
/* See pg. 183 in STM32F4 Prog Ref (PM0214) */
#define MPU_CTRL_ENABLE                 (uint32_t) (1 << 0)         /* Enables MPU */
#define MPU_CTRL_HFNMIENA               (uint32_t) (1 << 1)         /* Enables MPU during Hardfault, NMI, and Faultmask handlers */
#define MPU_CTRL_PRIVDEFENA             (uint32_t) (1 << 2)         /* Enable privileged software access to default memory map */

#define MPU_RASR_ENABLE                 (uint32_t) (1 << 0)         /* Enable region */
#define MPU_RASR_SIZE(x)                (uint32_t) (x << 1)         /* Region size (2^(x+1) bytes) */
#define MPU_RASR_SHARE_CACHE_WBACK      (uint32_t) (1 << 16) | (1 << 17) | (1 << 18)    /* Sharable, Cachable, Write-Back */
#define MPU_RASR_SHARE_NOCACHE_WBACK    (uint32_t) (1 << 16) | (0 << 17) | (1 << 18)    /* Sharable, Not Cachable, Write-Back */
#define MPU_RASR_AP_PRIV_NO_UN_NO       (uint32_t) (0 << 24)        /* No access for any */
#define MPU_RASR_AP_PRIV_RW_UN_NO       (uint32_t) (1 << 24)        /* No access for any */
#define MPU_RASR_AP_PRIV_RW_UN_RO       (uint32_t) (2 << 24)        /* Unprivileged Read Only Permissions */
#define MPU_RASR_AP_PRIV_RW_UN_RW       (uint32_t) (3 << 24)        /* All RW Permissions */
#define MPU_RASR_AP_PRIV_RO_UN_NO       (uint32_t) (5 << 24)        /* Privileged RO Permissions, Unpriv no access */
#define MPU_RASR_AP_PRIV_RO_UN_RO       (uint32_t) (6 << 24)        /* All RO Permissions */
#define MPU_RASR_XN                     (uint32_t) (1 << 28)        /* MPU Region Execute Never */
