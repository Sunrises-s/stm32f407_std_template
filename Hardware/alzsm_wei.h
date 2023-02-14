/*
文件名称: alzsm_wei
使用范围: STM32F407芯片
功能介绍: 根据标准库, 做一些简单的小封装
修改时间: 2023年2月10日   编码格式: Chinese GB2312
*/

//include header files
#include "stm32f4xx.h"                  // Device header

//位带操作
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


//外部调用函数
void zsm_select_clock(uint8_t c);//时钟选择
void EXTILine0_Config(void);
void EXTILine3_Config(void);
void EXTILine4_Config(void);
