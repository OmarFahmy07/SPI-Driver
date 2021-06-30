/*
 * main.c
 *
 *  Created on: Oct 12, 2020
 *      Author: Omar Fahmy
 */

/***********************************************************************************/
/*								  SLAVE MAIN CODE								   */
/***********************************************************************************/

#include "../HAL/LCD/LCD_Interface.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"

#include "../MCAL/Global Interrupt/GI_Interface.h"

u8 Local_u8ReturnedData, Local_u8SendData = 0;

void ISR (void);

int main(void)
{
	LCD_U8Init();
	/* SPI Init */
	SPI_U8Init();
	SPI_U8EnableInterrupt();
	SPI_U8SetCallBack(ISR);
	GI_U8Enable();
	/* Set Direction output for MOSI,SCLK */
	/* Set Direction input for  MISO,SS and set pull up resistor for SS in Master */
	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT); // MOSI
	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT); // MISO
	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT); // SS
	SPI_U8MasterTransmitSlavePrepare(Local_u8SendData);

	while(1)
	{
		LCD_U8SetPosition(LCD_FIRST_ROW, LCD_FIRST_COLUMN);
		LCD_U8SendNumber(Local_u8ReturnedData);
	}
	return 0;
}

void ISR (void)
{
	SPI_U8GetReceivedData(&Local_u8ReturnedData);
	SPI_U8MasterTransmitSlavePrepare(++Local_u8SendData);
}

/***********************************************************************************/
/*								MASTER MAIN CODE								   */
/***********************************************************************************/

/*
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/Global Interrupt/GI_Interface.h"

#include <util/delay.h>

u8 received, flag = 0;

void ISR (void);

int main(void)
{
	SPI_U8Init();
	SPI_U8EnableInterrupt();
	SPI_U8SetCallBack(ISR);
	GI_U8Enable();

	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT); // MOSI
	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT); // CLOCK
	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT); // MISO
	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT); // SS
	DIO_U8SetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_OUTPUT); // LED

	while(1)
	{
		for (u8 x = 3; x < 7; x++)
		{
			SPI_U8MasterTransmitSlavePrepare(x);
			while (flag == 0);
			flag = 0;
			_delay_ms(1000);
		}
	}
	return 0;
}

void ISR (void)
{
	SPI_U8GetReceivedData(&received);
	if (received == 5)
	{
		DIO_U8SetPinValue(DIO_PORTD, DIO_PIN0, DIO_PIN_HIGH);
	}
	else
	{
		DIO_U8SetPinValue(DIO_PORTD, DIO_PIN0, DIO_PIN_LOW);
	}
	flag = 1;
}
*/
