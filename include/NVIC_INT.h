#ifndef	NVIC_INTERFACE_H
#define	NVIC_INTERFACE_H

/*vector table priority*/
typedef enum
{
	VT_WWDG,
	VT_PVD,
	VT_TAMPER,
	VT_RTC,
	VT_FLASH,
	VT_RCC,
	VT_EXTI0,
	VT_EXTI1,
	VT_EXTI2,
	VT_EXTI3,
	VT_EXTI4,
	VT_DMA1_Channel1,
	VT_DMA1_Channel2,
	VT_DMA1_Channel3,
	VT_DMA1_Channel4,
	VT_DMA1_Channel5,
	VT_DMA1_Channel6,
	VT_DMA1_Channel7,
	VT_ADC1_2,
	VT_CAN1_TX,
	VT_CAN1_RX0,
	VT_CAN1_RX1,
	VT_CAN1_SCE,
	VT_EXTI9_5,
	VT_TIM1_BRK,
	VT_TIM1_UP,
	VT_TIM1_TRG,
	VT_TIM1_CC,
	VT_TIM2	,
	VT_TIM3	,
	VT_TIM4	,
	VT_I2C1_EV,
	VT_I2C1_ER,
	VT_I2C2_EV,
	VT_I2C2_ER,
	VT_SPI1	,
	VT_SPI2	,
	VT_USART1	,
	VT_USART2	,
	VT_USART3	,
	VT_EXTI15_10,
	VT_RTCAlarm,
	VT_OTG_FS_WKUP,
	VT_TIM5=50,
	VT_SPI3,
	VT_UART4,
	VT_UART5,
	VT_TIM6,
	VT_TIM7,
	VT_DMA2_Channel1,
	VT_DMA2_Channel2,
	VT_DMA2_Channel3,
	VT_DMA2_Channel4
}Eunm_Vector_Table;
typedef enum
{
	Group_Priority_0,
	Group_Priority_1,
	Group_Priority_2,
	Group_Priority_3,
	Group_Priority_4,
	Group_Priority_5,
	Group_Priority_6,
	Group_Priority_7,
	Group_Priority_8,
	Group_Priority_9,
	Group_Priority_10,
	Group_Priority_11,
	Group_Priority_12,
	Group_Priority_13,
	Group_Priority_14,
	Group_Priority_15,
	Group_Priority_16

}Group_Priority;
typedef enum
{
	Sub_Priority_0,
	Sub_Priority_1,
	Sub_Priority_2,
	Sub_Priority_3,
	Sub_Priority_4,
	Sub_Priority_5,
	Sub_Priority_6,
	Sub_Priority_7,
	Sub_Priority_8,
	Sub_Priority_9,
	Sub_Priority_10,
	Sub_Priority_11,
	Sub_Priority_12,
	Sub_Priority_13,
	Sub_Priority_14,
	Sub_Priority_15,
	Sub_Priority_16

}Sub_Priority;
void MNVIC_VidInit			(void);
void MNVIC_VidSetInterruptPriority(u8 Copy_u8PeripheralID,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority);
void MNVIC_U8InteruptEnable		(u8 Copy_u8IntNumber);
void MNVIC_U8InteruptDisable		(u8 Copy_u8IntNumber);
void MNVIC_U8InteruptPendingEnable	(u8 Copy_u8IntNumber);
void MNVIC_U8InteruptPendingDisable	(u8 Copy_u8IntNumber);
u8 MNVIC_u8InteruptGetActiveValue	(u8 Copy_u8IntNumber);


#endif
