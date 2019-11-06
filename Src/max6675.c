/*
 * max6675.c
 *
 *  Created on: Nov 1, 2019
 *      Author: prog1
 */
#include <stdio.h>

#include "main.h"
#include "max6675.h"

SPI_HandleTypeDef * hspi;

void init_max6675(SPI_HandleTypeDef * hspix)
{
	hspi = hspix;
}

uint16_t    read_max6675(void)
{
	uint8_t q = 0, q_byte = 2;
	uint8_t buffer[q_byte];
	uint16_t value = 0;

	//if (DebugMax)
	//printf("Read max6675 \r\n");

	SET_PIN_CS(0);//HAL_GPIO_WritePin(SPI1_SS_GPIO_Port, SPI1_SS_Pin, 0);
	TC_DELAY(1);

	HAL_SPI_Receive(hspi, &buffer[0], 2, 1000);

	/*
	while (q < q_byte)
	{
		HAL_SPI_Receive(hspi, &buffer[0], 1, 10000);
		//printf(" b0 = %u;", buffer[0]);
		HAL_SPI_Receive(hspi, &buffer[1], 1, 10000);
		//printf(" b1 = %u;", buffer[1]);
		q++;
	}	q = 0;
	*/

	while (q < q_byte)
	{
		value <<= 8;
		value |= buffer[q];
		//printf(" buffer[x] = %#x;\r\n", buffer[q]);
		q++;
	}	q = 0;
	//printf(" value = %#lx;", value);

	SET_PIN_CS(1);//HAL_GPIO_WritePin(SPI1_SS_GPIO_Port, SPI1_SS_Pin, 1);

	return value;
}

uint16_t    get_temperature_max6675(void)
{
	uint16_t  v = 0;

	//if (DebugMax) printf("\r\nRead Temperature Celcius");

	v = read_max6675();

	if (v & 0x4)
	{
		v = 0;
		if (DebugMax) printf("\r\n Error max6675! \r\n");
	}
	else
	{
		v = (v*250) >> 3; //v *= 250;v >>= 3;
	}

	return v;
}
/*
uint8_t    get_temperature_celcius(TemperatureStruct * uT)
{
	uint32_t  v = 0;
	uint32_t  vin = 0;
	uint32_t  vex = 0;

	uint32_t  t_int = 0;
	uint32_t  t_ext = 0;
	//int sign = 1;

	if ((DebugUsart)&&(DebugMax)) printf("\r\nRead Temperature Celcius");
	v = read_spi_32bit();

	if (!v) {uT->er = 1; if ((DebugUsart)&&(DebugMax)) printf("ERROR SPI\r\n ");}
	else
	{
		if (v & 0x4)
		{
			uT->er = 1;
			if ((DebugUsart)&&(DebugMax)) printf("\r\nERROR1;\r\n");
		}
		else
		{
			uT->ex.level = (v*250) >> 3; //v *= 250;v >>= 3;
			uT->in.level = 0;
		}
	}

	return uT->er;
}
*/
