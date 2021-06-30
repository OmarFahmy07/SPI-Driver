/*
 * GI_Register.h
 *
 *  Created on: Sep 14, 2020
 *      Author: Omar Fahmy
 */

#ifndef GI_PRIVATE_H_
#define GI_PRIVATE_H_

/**************************************************************************************/
/* 	 						  Status register address								  */
/**************************************************************************************/
#define SREG	*((volatile u8*)0x5F)
/**************************************************************************************/

/**************************************************************************************/
/* 						    Global Interrupt Enable bit 							  */
/**************************************************************************************/
#define I 7
/**************************************************************************************/
#endif /* GI_PRIVATE_H_ */
