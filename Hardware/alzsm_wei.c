#include "alzsm_wei.h"

//时钟选择函数
void zsm_select_clock(uint8_t c)
{
    if(c == 1)      //选择PLL作为系统时钟  168M
    {
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= RCC_CFGR_SW_PLL;
    }
    if(c == 2)      //选择HSI作为系统时钟  16M
    {
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= RCC_CFGR_SW_HSI;
    }
    if(c == 3)      //选择HSE作为系统时钟  8M
    {
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= RCC_CFGR_SW_HSE;
    }
}

/******************************外部中断配置******************************************************/
/**
  * @brief  Configures EXTI Line0 (connected to PA0 pin) in interrupt mode
  * @param  None
  * @retval None 
  * 需要修改的内容, 
    GPIO    端口号(PA-PG)   上下拉电阻(上拉电阻,下拉电阻,不需要)  响应速度
    中断    模式的选择(选择中断,事件)   触发方式(上升沿/下降沿/双边沿)
    NVIC    抢占优先级     响应优先级           
  */
void EXTILine0_Config(void)
{
    EXTI_InitTypeDef   EXTI_InitStructure;
    GPIO_InitTypeDef   GPIO_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;

    /* Enable GPIOA clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    /* Enable SYSCFG clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    /* Configure PA0 pin as input floating */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;            //高速响应
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;            //使能下拉电阻
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Connect EXTI Line0 to PA0 pin */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

    /* Configure EXTI Line0 */
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;                          //外部中断0
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                 //模式为中断
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;              //上升沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //使能
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set EXTI Line0 Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;                    //打开外部中断0的请求通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;        //抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;               //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //使能该通道
    NVIC_Init(&NVIC_InitStructure);
}






/**
  * @brief  Configures EXTI Line3 (connected to PA3 pin) in interrupt mode
  * @param  None
  * @retval None 
  * 需要修改的内容, 
    GPIO    端口号(PA-PG)   上下拉电阻(上拉电阻,下拉电阻,不需要)  响应速度
    中断    模式的选择(选择中断,事件)   触发方式(上升沿/下降沿/双边沿)
    NVIC    抢占优先级     响应优先级           
  */
void EXTILine3_Config(void)
{
    EXTI_InitTypeDef   EXTI_InitStructure;
    GPIO_InitTypeDef   GPIO_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;

    /* Enable GPIOA clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    /* Enable SYSCFG clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    /* Configure PA3 pin as input floating */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;            //高速响应
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //使能上拉电阻
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    /* Connect EXTI Line3 to PA3 pin */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);

    /* Configure EXTI Line3 */
    EXTI_InitStructure.EXTI_Line = EXTI_Line3;                          //外部中断3
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                 //模式为中断
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;              //上升沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //使能
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set EXTI Line3 Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;                    //打开外部中断3的请求通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;        //抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;               //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //使能该通道
    NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  Configures EXTI Line4 (connected to PA4 pin) in interrupt mode
  * @param  None
  * @retval None 
  * 需要修改的内容, 
    GPIO    端口号(PA-PG)   上下拉电阻(上拉电阻,下拉电阻,不需要)  响应速度
    中断    模式的选择(选择中断,事件)   触发方式(上升沿/下降沿/双边沿)
    NVIC    抢占优先级     响应优先级           
  */
void EXTILine4_Config(void)
{
    EXTI_InitTypeDef   EXTI_InitStructure;
    GPIO_InitTypeDef   GPIO_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;

    /* Enable GPIOA clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    /* Enable SYSCFG clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    /* Configure PA4 pin as input floating */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;            //高速响应
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //使能上拉电阻
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    /* Connect EXTI Line4 to PA4 pin */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);

    /* Configure EXTI Line4 */
    EXTI_InitStructure.EXTI_Line = EXTI_Line4;                          //外部中断4
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                 //模式为中断
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;              //上升沿触发
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //使能
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set EXTI Line4 Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;                    //打开外部中断3的请求通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;        //抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;               //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //使能该通道
    NVIC_Init(&NVIC_InitStructure);
}



