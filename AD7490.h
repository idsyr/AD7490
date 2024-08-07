#ifndef AD7490_H
#define AD7490_H

#include "stdint.h"

typedef struct {
	uint8_t write      :1; //1
	uint8_t seq        :1;
	uint8_t channel    :4;
	uint8_t power_mode :2;
	uint8_t shadow     :1; //2 
	uint8_t dout       :1;
	uint8_t range      :1;
	uint8_t coding     :5;
} AD7490_settings_t;

typedef void(*transmit_handler_t)(uint16_t query);

void AD7490_init_after_power_up(transmit_handler_t transmit_handler);
void AD7490_data_query(transmit_handler_t transmit_handler, uint8_t channel);







#endif
