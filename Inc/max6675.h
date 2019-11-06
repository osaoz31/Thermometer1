
#ifndef __MAX6675_IT_H
#define __MAX6675_IT_H

	#include "main.h"

	#define Max6675            	1
	#define Max31855           	0

	#define DebugMax           	0

	#define SET_PIN_CS(x) 		HAL_GPIO_WritePin(SPI1_SS_GPIO_Port, SPI1_SS_Pin,(x));
	#define TC_DELAY(ms) 		HAL_Delay(ms);

	void 		init_max6675(SPI_HandleTypeDef * hspix);
	uint16_t    read_max6675(void);
	uint16_t    get_temperature_max6675(void);

#endif /* __MAX6675_IT_H */
