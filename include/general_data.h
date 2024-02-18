/*
 * general_data.h
 *
 *  Created on: 11 февр. 2024 г.
 *      Author: axtea
 */

#ifndef GENERAL_DATA_H_
#define GENERAL_DATA_H_

enum CAR_STATUS
{
	BUSY = 0,
	FREE,
	BROKEN
};

enum CLIENT_STATUS
{
	CAR_IS_NOT_RENTAL = 0,
	CAR_IS_RENTAL = 1,
	BLACKLIST = 3,	 		// внесен в черный список
};



#endif /* GENERAL_DATA_H_ */
