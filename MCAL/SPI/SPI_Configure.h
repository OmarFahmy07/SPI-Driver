/*
 * SPI_Configure.h
 *
 *  Created on: Oct 12, 2020
 *      Author: Omar Fahmy
 */

#ifndef MCAL_SPI_SPI_CONFIGURE_H_
#define MCAL_SPI_SPI_CONFIGURE_H_


/*****************************************************************************/
/*      		  			  OPTIONS FOR SPI MODE:			 			 	 */
/*       				 	  	 MASTER - SLAVE						     	 */
/*****************************************************************************/
#define MODE						SLAVE
/*****************************************************************************/


/*****************************************************************************/
/*				 OPTIONS FOR CLOCK POLARITY (FOR MASTER MODE ONLY):	     	 */
/*     RISING_LEADING_FALLING_TRAILING - FALLING_LEADING_RISING_TRAILING	 */
/*****************************************************************************/
#define CLOCK_POLARITY 				RISING_LEADING_FALLING_TRAILING
/*****************************************************************************/


/*****************************************************************************/
/*				 OPTIONS FOR CLOCK SPEED (FOR MASTER MODE ONLY):	     	 */
/* 			NO_DOUBLE_SPEED_PRESCALER_4 - NO_DOUBLE_SPEED_PRESCALER_16 		 */
/* 		   NO_DOUBLE_SPEED_PRESCALER_64 - NO_DOUBLE_SPEED_PRESCALER_128		 */
/* 			   DOUBLE_SPEED_PRESCALER_2 - DOUBLE_SPEED_PRESCALER_8 		 	 */
/* 			  DOUBLE_SPEED_PRESCALER_32 - DOUBLE_SPEED_PRESCALER_64		 	 */
/*****************************************************************************/
#define CLOCK_SPEED					NO_DOUBLE_SPEED_PRESCALER_16
/*****************************************************************************/


/*****************************************************************************/
/*				 			OPTIONS FOR CLOCK PHASE:	     	 			 */
/* SETUP_AT_LEADING_SAMPLE_AT_TRAILING - SAMPLE_AT_LEADING_SETUP_AT_TRAILING */
/*****************************************************************************/
#define CLOCK_PHASE 				SETUP_AT_LEADING_SAMPLE_AT_TRAILING
/*****************************************************************************/


/*****************************************************************************/
/*      		  			  OPTIONS FOR DATA ORDER:			 			 */
/*       				 	  LSB_FIRST - MSB_FIRST						     */
/*****************************************************************************/
#define DATA_ORDER					MSB_FIRST
/*****************************************************************************/



#endif /* MCAL_SPI_SPI_CONFIGURE_H_ */
