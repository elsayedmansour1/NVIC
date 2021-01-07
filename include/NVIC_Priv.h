#ifndef	NVIC_PRIVATE_H
#define	NVIC_PRIVATE_H

#define	NVIC_BASE_ADD	(0xE000E100)

#define	NVIC_ISER0		*((volatile u32*)(NVIC_BASE_ADD+0x000))
#define	NVIC_ISER1		*((volatile u32*)(NVIC_BASE_ADD+0x004))

#define	NVIC_ICER0		*((volatile u32*)(NVIC_BASE_ADD+0x080))
#define	NVIC_ICER1		*((volatile u32*)(NVIC_BASE_ADD+0x084))

#define	NVIC_ISPR0		*((volatile u32*)(NVIC_BASE_ADD+0x100))
#define	NVIC_ISPR1		*((volatile u32*)(NVIC_BASE_ADD+0x104))

#define	NVIC_ICPR0		*((volatile u32*)(NVIC_BASE_ADD+0x180))
#define	NVIC_ICPR1		*((volatile u32*)(NVIC_BASE_ADD+0x184))

#define	NVIC_IABR0		*((volatile u32*)(NVIC_BASE_ADD+0x200))
#define	NVIC_IABR1		*((volatile u32*)(NVIC_BASE_ADD+0x204))

#define	NVIC_IPR  		 ((volatile u8*)(NVIC_BASE_ADD+0x400 ))


/*******************************************************************/
			/*Priority Group*/
#define Group_16_Sub_0		3
#define Group_8_Sub_2		4
#define Group_4_Sub_4		5
#define Group_2_Sub_8		6
#define Group_0_Sub_16		7
/*******************************************************************/
#endif
