/*
 * SPI_Program.c
 *
 *  Created on: Oct 12, 2020
 *      Author: Omar Fahmy
 */

/* LIB LAYER */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"
/* MCAL LAYER */
#include "SPI_Private.h"
#include "SPI_Configure.h"


void (*GLOB_VidSPIPtrCallBack)(void) = NULL;

/************************************************************************************/
/* 						  PUBLIC FUNCTIONS IMPLEMENTATION	  						*/
/************************************************************************************/

u8 SPI_U8Init(void)
{
#if MODE == MASTER
	/* Select Master SPI mode */
	SET_BIT(SPCR_REGISTER, MSTR);
	/* Clock Speed Configuration */
#if CLOCK_SPEED == NO_DOUBLE_SPEED_PRESCALER_4
	CLR_BIT(SPSR_REGISTER, SPI2X);
	CLR_BIT(SPCR_REGISTER, SPR1);
	CLR_BIT(SPCR_REGISTER, SPR0);
#elif CLOCK_SPEED == NO_DOUBLE_SPEED_PRESCALER_16
	CLR_BIT(SPSR_REGISTER, SPI2X);
	CLR_BIT(SPCR_REGISTER, SPR1);
	SET_BIT(SPCR_REGISTER, SPR0);
#elif CLOCK_SPEED == NO_DOUBLE_SPEED_PRESCALER_64
	CLR_BIT(SPSR_REGISTER, SPI2X);
	SET_BIT(SPCR_REGISTER, SPR1);
	CLR_BIT(SPCR_REGISTER, SPR0);
#elif CLOCK_SPEED == NO_DOUBLE_SPEED_PRESCALER_128
	CLR_BIT(SPSR_REGISTER, SPI2X);
	SET_BIT(SPCR_REGISTER, SPR1);
	SET_BIT(SPCR_REGISTER, SPR0);
#elif CLOCK_SPEED == DOUBLE_SPEED_PRESCALER_2
	SET_BIT(SPSR_REGISTER, SPI2X);
	CLR_BIT(SPCR_REGISTER, SPR1);
	CLR_BIT(SPCR_REGISTER, SPR0);
#elif CLOCK_SPEED == DOUBLE_SPEED_PRESCALER_8
	SET_BIT(SPSR_REGISTER, SPI2X);
	CLR_BIT(SPCR_REGISTER, SPR1);
	SET_BIT(SPCR_REGISTER, SPR0);
#elif CLOCK_SPEED == DOUBLE_SPEED_PRESCALER_32
	SET_BIT(SPSR_REGISTER, SPI2X);
	SET_BIT(SPCR_REGISTER, SPR1);
	CLR_BIT(SPCR_REGISTER, SPR0);
#elif CLOCK_SPEED == DOUBLE_SPEED_PRESCALER_64
	SET_BIT(SPSR_REGISTER, SPI2X);
	SET_BIT(SPCR_REGISTER, SPR1);
	SET_BIT(SPCR_REGISTER, SPR0);
#else
#error "Invalid SPI clock speed configuration"
#endif
	/* Clock Polarity Configuration */
#if CLOCK_POLARITY == RISING_LEADING_FALLING_TRAILING
	CLR_BIT(SPCR_REGISTER, CPOL);
#elif CLOCK_POLARITY == FALLING_LEADING_RISING_TRAILING
	SET_BIT(SPCR_REGISTER, CPOL);
#else
#error "Invalid clock polarity configuration"
#endif
#elif MODE == SLAVE
	/* Select slave SPI mode */
	CLR_BIT(SPCR_REGISTER, MSTR);
#else
#error "Invalid SPI mode configuration"
#endif
	/* Enable SPI peripheral */
	SET_BIT(SPCR_REGISTER, SPE);
	/* Data Order Configuration */
#if DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR_REGISTER, DORD);
#elif DATA_ORDER == MSB_FIRST
	CLR_BIT(SPCR_REGISTER, DORD);
#else
#error "Invalid SPI data order configuration"
#endif
	/* Clock Phase Configuration */
#if CLOCK_PHASE == SAMPLE_AT_LEADING_SETUP_AT_TRAILING
	CLR_BIT(SPCR_REGISTER, CPHA);
#elif CLOCK_PHASE == SETUP_AT_LEADING_SAMPLE_AT_TRAILING
	SET_BIT(SPCR_REGISTER, CPHA);
#else
#error "Invalid clock phase configuration"
#endif
	return NO_ERROR;
}

u8 SPI_U8MasterTransmitSlavePrepare(const u8 LOC_U8SendData)
{
	SPDR_REGISTER = LOC_U8SendData;
	return NO_ERROR;
}

u8 SPI_U8PollingOnFlag(void)
{
	/* Wait until transmission is completed */
	while ( !GET_BIT(SPSR_REGISTER, SPIF) );

	return NO_ERROR;
}

u8 SPI_U8GetReceivedData(u8* const LOC_U8Data)
{
	if (LOC_U8Data != NULL)
	{
		*LOC_U8Data = SPDR_REGISTER;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}


u8 SPI_U8EnableInterrupt(void)
{
	SET_BIT(SPCR_REGISTER, SPIE);
	return NO_ERROR;
}

u8 SPI_U8DisableInterrupt(void)
{
	CLR_BIT(SPCR_REGISTER, SPIE);
	return NO_ERROR;
}

u8 SPI_U8SetCallBack( void (*ptrToFun) (void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidSPIPtrCallBack = ptrToFun;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}
/************************************************************************************/


/************************************************************************************/
/* 						  PRIVATE FUNCTIONS IMPLEMENTATION  						*/
/************************************************************************************/

void __vector_12(void)
{
	if (GLOB_VidSPIPtrCallBack != NULL)
	{
		(*GLOB_VidSPIPtrCallBack)();
	}
}
/************************************************************************************/
