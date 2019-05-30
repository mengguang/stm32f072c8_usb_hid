/*
 * misc_utils.c
 *
 *  Created on: Feb 26, 2019
 *      Author: mengguang
 */


#include "misc_utils.h"
#include "SEGGER_RTT.h"

int _write(int file, char *ptr, int len) {
	(void) file; /* Not used, avoid warning */
	SEGGER_RTT_Write(0, ptr, len);
	return len;
}

void digitalWrite(gpio_t gpio, uint8_t val) {
	if(val == HIGH) {
		HAL_GPIO_WritePin(gpio.port, gpio.pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(gpio.port, gpio.pin, GPIO_PIN_RESET);
	}
}

void digitalToggle(gpio_t gpio) {
	if(digitalRead(gpio) == HIGH) {
		digitalWrite(gpio,LOW);
	} else {
		digitalWrite(gpio,HIGH);
	}
}

uint8_t digitalRead(gpio_t gpio) {
	GPIO_PinState ps;
	ps = HAL_GPIO_ReadPin(gpio.port, gpio.pin);
	if(ps == GPIO_PIN_SET) {
		return HIGH;
	} else {
		return LOW;
	}
}

void delay(uint32_t ms) {
	HAL_Delay(ms);
}

void mcu_reset() {
	printf("Reset MCU.\n");
	delay(1000);
	NVIC_SystemReset();
}
