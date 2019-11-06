/*
 * max6675.c
 *
 *  Created on: Nov 1, 2019
 *      Author: prog1
 */

#include "main.h"
#include "max6675.h"

uint8_t i = 0;

uint32_t    read_max6675(void)
{
	//uint8_t q = 0, q_byte = 2;
	//uint8_t buffer[2];
	uint32_t value = 0;

	//if ((DebugUsart)&&(DebugMax))
	//printf("Read max6675 \r\n");
	/*
	HAL_GPIO_WritePin(SPI1_SS_GPIO_Port, SPI1_SS_Pin, 0);
	HAL_Delay(1);

	while (q != q_byte) q = io_read(spi1_io, &buffer[0], q_byte); //if ((DebugUsart)&&(DebugMax)) printf(".");
	//printf("2\r\n");

	q = 0;

	while (q < q_byte)
	{
		value <<= 8;
		value |= buffer[q];
		//printf(" buffer[x] = %#x;\r\n", buffer[q]);
		q++;
	}
	//printf(" value = %#lx;", value);

	gpio_set_pin_level(TEMP_SS, 1);
*/
	return value;
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
