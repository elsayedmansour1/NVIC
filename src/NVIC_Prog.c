/******************************************************************/
/*             >>DATE:29/11/2020                                  */
/*             >>AUTHOR:ELSAYED MANSOUR SHALABY                   */
/*             >>VERSION:0.1                                      */
/******************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"NVIC_INT.h"
#include"NVIC_Priv.h"
#include"NVIC_Config.h"

void MNVIC_VidInit			(void)
{
	//base address for SCB 0xE000ED00
	#define SCB_IARCR   *((volatile u32*)(0xE000ED00+0x0C))
	#if	Priority_Group==Group_16_Sub_0
		SCB_IARCR|=8<<Group_16_Sub_0;
	#elif	Priority_Group==Group_8_Sub_2
		SCB_IARCR|=8<<Group_8_Sub_2;
	#elif	Priority_Group==Group_4_Sub_4
		SCB_IARCR|=8<<Group_4_Sub_4;
	#elif	Priority_Group==Group_2_Sub_8
		SCB_IARCR|=8<<Group_2_Sub_8;
	#elif	Priority_Group==Group_0_Sub_16
		SCB_IARCR|=8<<Group_0_Sub_16;
	#endif
}
void MNVIC_VidSetInterruptPriority(u8 Copy_u8PeripheralID,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority)
{
	
	u8 Copy_u8Temp=0;

	if(Copy_u8PeripheralID<60)
	{
	#if	Priority_Group==Group_16_Sub_0
		if(Copy_u8GroupPriority<=16 && Copy_u8SubPriority==0)
		{
			Copy_u8Temp|=Copy_u8GroupPriority<<6;
			Copy_u8Temp|=Copy_u8SubPriority  <<4;
		}
	#elif	Priority_Group==Group_8_Sub_2
		if(Copy_u8GroupPriority<=8 && Copy_u8SubPriority<=2)
		{
			Copy_u8Temp|=Copy_u8GroupPriority<<6;
			Copy_u8Temp|=Copy_u8SubPriority  <<4;
		}
	#elif	Priority_Group==Group_4_Sub_4
			if(Copy_u8GroupPriority<=4 && Copy_u8SubPriority<=4)
		{
			Copy_u8Temp|=Copy_u8GroupPriority<<6;
			Copy_u8Temp|=Copy_u8SubPriority  <<4;
		}
	#elif	Priority_Group==Group_2_Sub_8
			if(Copy_u8GroupPriority<=2 && Copy_u8SubPriority<=8)
		{
			Copy_u8Temp|=Copy_u8GroupPriority<<6;
			Copy_u8Temp|=Copy_u8SubPriority  <<4;
		}
	#elif	Priority_Group==Group_0_Sub_16
			if(Copy_u8GroupPriority==0 && Copy_u8SubPriority<=16)
		{
			Copy_u8Temp|=Copy_u8GroupPriority<<6;
			Copy_u8Temp|=Copy_u8SubPriority  <<4;
		}
	#else	#error "Wrong Choose Priority Group "
	#endif
			NVIC_IPR[Copy_u8PeripheralID]=Copy_u8Temp;

	}
	else
	{
		
	}
}
void MNVIC_U8InteruptEnable(u8 Copy_u8IntNumber)
{

	if(Copy_u8IntNumber<32)
	{
	NVIC_ISER0=(1<<Copy_u8IntNumber);	

	}
	else if(Copy_u8IntNumber<60)
	{
	Copy_u8IntNumber-=32;
	NVIC_ISER1=(1<<Copy_u8IntNumber);	

	}
	else
	{
		

	}

}
void MNVIC_U8InteruptDisable(u8 Copy_u8IntNumber)
{

	if(Copy_u8IntNumber<32)
	{
	NVIC_ICER0=(1<<Copy_u8IntNumber);	

	}
	else if(Copy_u8IntNumber<60)
	{
	Copy_u8IntNumber-=32;
	NVIC_ICER1=(1<<Copy_u8IntNumber);	

	}
	else
	{
		

	}

}
void MNVIC_U8InteruptPendingEnable(u8 Copy_u8IntNumber)
{

	if(Copy_u8IntNumber<32)
	{
	NVIC_ISPR0=(1<<Copy_u8IntNumber);	

	}
	else if(Copy_u8IntNumber<60)
	{
	Copy_u8IntNumber-=32;
	NVIC_ISPR1=(1<<Copy_u8IntNumber);	

	}
	else
	{
		

	}

}
void MNVIC_U8InteruptPendingDisable(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<32)
	{
	NVIC_ICPR0=(1<<Copy_u8IntNumber);	
	}
	else if(Copy_u8IntNumber<60)
	{
	Copy_u8IntNumber-=32;
	NVIC_ICPR1=(1<<Copy_u8IntNumber);	
	}
	else
	{

	}
}
u8 MNVIC_u8InteruptGetActiveValue(u8 Copy_u8IntNumber)
{
	u8 Loc_u8ActiveValue;
	if(Copy_u8IntNumber<32)
	{
	Loc_u8ActiveValue=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	

	}
	else if(Copy_u8IntNumber<60)
	{
	Copy_u8IntNumber-=32;
	Loc_u8ActiveValue=GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	

	}
	else
	{	

	}
	return Loc_u8ActiveValue;
}
