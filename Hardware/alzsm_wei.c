#include "alzsm_wei.h"

//ʱ��ѡ����
void zsm_select_clock(uint8_t c)
{
    if(c == 1)      //ѡ��PLL��Ϊϵͳʱ��  168M
    {
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= RCC_CFGR_SW_PLL;
    }
    if(c == 2)      //ѡ��HSI��Ϊϵͳʱ��  16M
    {
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= RCC_CFGR_SW_HSI;
    }
    if(c == 3)      //ѡ��HSE��Ϊϵͳʱ��  8M
    {
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= RCC_CFGR_SW_HSE;
    }
}

/******************************�ⲿ�ж�����******************************************************/
/**
  * @brief  Configures EXTI Line0 (connected to PA0 pin) in interrupt mode
  * @param  None
  * @retval None 
  * ��Ҫ�޸ĵ�����, 
    GPIO    �˿ں�(PA-PG)   ����������(��������,��������,����Ҫ)  ��Ӧ�ٶ�
    �ж�    ģʽ��ѡ��(ѡ���ж�,�¼�)   ������ʽ(������/�½���/˫����)
    NVIC    ��ռ���ȼ�     ��Ӧ���ȼ�           
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
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;            //������Ӧ
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;            //ʹ����������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Connect EXTI Line0 to PA0 pin */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

    /* Configure EXTI Line0 */
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;                          //�ⲿ�ж�0
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                 //ģʽΪ�ж�
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;              //�����ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //ʹ��
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set EXTI Line0 Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;                    //���ⲿ�ж�0������ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;        //��ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;               //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //ʹ�ܸ�ͨ��
    NVIC_Init(&NVIC_InitStructure);
}






/**
  * @brief  Configures EXTI Line3 (connected to PA3 pin) in interrupt mode
  * @param  None
  * @retval None 
  * ��Ҫ�޸ĵ�����, 
    GPIO    �˿ں�(PA-PG)   ����������(��������,��������,����Ҫ)  ��Ӧ�ٶ�
    �ж�    ģʽ��ѡ��(ѡ���ж�,�¼�)   ������ʽ(������/�½���/˫����)
    NVIC    ��ռ���ȼ�     ��Ӧ���ȼ�           
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
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;            //������Ӧ
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //ʹ����������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    /* Connect EXTI Line3 to PA3 pin */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);

    /* Configure EXTI Line3 */
    EXTI_InitStructure.EXTI_Line = EXTI_Line3;                          //�ⲿ�ж�3
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                 //ģʽΪ�ж�
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;              //�����ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //ʹ��
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set EXTI Line3 Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;                    //���ⲿ�ж�3������ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;        //��ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;               //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //ʹ�ܸ�ͨ��
    NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  Configures EXTI Line4 (connected to PA4 pin) in interrupt mode
  * @param  None
  * @retval None 
  * ��Ҫ�޸ĵ�����, 
    GPIO    �˿ں�(PA-PG)   ����������(��������,��������,����Ҫ)  ��Ӧ�ٶ�
    �ж�    ģʽ��ѡ��(ѡ���ж�,�¼�)   ������ʽ(������/�½���/˫����)
    NVIC    ��ռ���ȼ�     ��Ӧ���ȼ�           
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
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;            //������Ӧ
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //ʹ����������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    /* Connect EXTI Line4 to PA4 pin */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);

    /* Configure EXTI Line4 */
    EXTI_InitStructure.EXTI_Line = EXTI_Line4;                          //�ⲿ�ж�4
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                 //ģʽΪ�ж�
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;              //�����ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;                           //ʹ��
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set EXTI Line4 Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;                    //���ⲿ�ж�3������ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;        //��ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;               //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                     //ʹ�ܸ�ͨ��
    NVIC_Init(&NVIC_InitStructure);
}



