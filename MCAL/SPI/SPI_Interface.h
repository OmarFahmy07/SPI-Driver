/*
 * SPI_Interface.h
 *
 *  Created on: Oct 12, 2020
 *      Author: Omar Fahmy
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/************************************************************************************/
/* 								FUNCTIONS PROTOTYPE					 				*/
/************************************************************************************/

/************************************************************************************/
/* Description: initializes the SPI peripheral				  						*/
/* Input      : nothing 		                                                    */
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 SPI_U8Init(void);
/************************************************************************************/

/************************************************************************************/
/* Description: in master mode, this function initiates communication with a slave	*/
/* by sending the byte passed in as an argument. In slave mode, this function		*/
/* prepares the data that is to be sent to the master whenever the master starts	*/
/* communication				  													*/
/* Input      : data to be sent       												*/
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 SPI_U8MasterTransmitSlavePrepare(const u8 LOC_U8SendData);
/************************************************************************************/

/************************************************************************************/
/* Description: polls on the SPI Transmission Complete flag to indicate that a		*/
/* transmission has been completed successfully. This function applies for both		*/
/* master and slave modes.															*/
/* Input      : data to be sent       												*/
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 SPI_U8PollingOnFlag(void);
/************************************************************************************/

/************************************************************************************/
/* Description: in slave mode, this function receives the data sent by the master.	*/
/* In master mode, this function receives the data sent by the slave.				*/
/* Input      : pointer to a variable to receive the data in                        */
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 SPI_U8GetReceivedData(u8* const LOC_U8Data);
/************************************************************************************/

/************************************************************************************/
/* Description: enables interrupt for SPI peripheral.			 					*/
/* Input      : nothing			                                                    */
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 SPI_U8EnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: disables interrupt for SPI peripheral.			 					*/
/* Input      : nothing			                                                    */
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 SPI_U8DisableInterrupt(void);
/************************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the SPI Transmission Complete interrupt.				 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: error checking								  						   */
/***********************************************************************************/
extern u8 SPI_U8SetCallBack( void (*ptrToFun) (void) );
/************************************************************************************/

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
