#define PERIPH_BASE         ((unsigned long)0x40000000) 
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x10000)
#define GPIOC_BASE          (APB2PERIPH_BASE + 0x1000)

typedef struct
{
	unsigned long GPIOC_CRL  ;
	unsigned long GPIOC_CRH  ;
	unsigned long GPIOC_IDR  ;
	unsigned long GPIOC_ODR  ;
	unsigned long GPIOC_BSRR ;
	unsigned long GPIOC_BRR  ;
}GPIOC_TypeDef;

#define GPIOC 				((GPIOC_TypeDef*)GPIOC_BASE)

typedef struct
{
	unsigned long CR;
	unsigned long CFGR;
	unsigned long CIR;
	unsigned long APB2RSTR;
	unsigned long APB1RSTR;
	unsigned long AHBENR;
	unsigned long APB2ENR;
	unsigned long APB1ENR;
	unsigned long BDCR;
	unsigned long CSR;
} RCC_TypeDef;

#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define RCC                   ((RCC_TypeDef *) RCC_BASE)

void delay()
{
	volatile unsigned long i;
	for (i = 0; i < 400000; i++);
}

int main()
{
	RCC->APB2ENR |= 0x00000010;
	GPIOC->GPIOC_CRL &= ~(0xF);
	GPIOC->GPIOC_CRL |= (0<<2)|(2<<0);
	GPIOC->GPIOC_ODR &= ~(1);
	while (1)
	{
		GPIOC->GPIOC_ODR |= 1;
		delay();
		GPIOC->GPIOC_ODR &= ~(1);
		delay();
	}
	return 0;
}	