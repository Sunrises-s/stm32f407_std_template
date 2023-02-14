/*
�ļ�����: alzsm_wei
ʹ�÷�Χ: STM32F407оƬ
���ܽ���: ���ݱ�׼��, ��һЩ�򵥵�С��װ
�޸�ʱ��: 2023��2��10��   �����ʽ: Chinese GB2312
*/

//include header files
#include "stm32f4xx.h"                  // Device header

//λ������
#define PAout(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOA->ODR - 0x40000000)*32 + n*4)
#define PBout(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOB->ODR - 0x40000000)*32 + n*4)
#define PCout(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOC->ODR - 0x40000000)*32 + n*4)
#define PDout(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOD->ODR - 0x40000000)*32 + n*4)
#define PEout(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOE->ODR - 0x40000000)*32 + n*4)
#define PFout(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOF->ODR - 0x40000000)*32 + n*4)
#define PGout(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOG->ODR - 0x40000000)*32 + n*4)
#define PAin(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOA->IDR - 0x40000000)*32 + n*4)
#define PBin(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOB->IDR - 0x40000000)*32 + n*4)
#define PCin(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOC->IDR - 0x40000000)*32 + n*4)
#define PDin(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOD->IDR - 0x40000000)*32 + n*4)
#define PEin(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOE->IDR - 0x40000000)*32 + n*4)
#define PFin(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOF->IDR - 0x40000000)*32 + n*4)
#define PGin(n) *(volatile uint32_t *)(0x42000000+((uint32_t)&GPIOG->IDR - 0x40000000)*32 + n*4)


//�ⲿ���ú���
void zsm_select_clock(uint8_t c);//ʱ��ѡ��
void EXTILine0_Config(void);
void EXTILine3_Config(void);
void EXTILine4_Config(void);
