#include "AD7490.h"

static AD7490_settings_t AD7490_settings = {
	.write      = 1,
	.seq        = 0,
	.channel    = 0,
	.power_mode = 3,
	.shadow     = 0,   
	.dout       = 0,
	.range      = 0,
	.coding     = 1,
};


void AD7490_init_after_power_up(transmit_handler_t transmit_handler){
	uint16_t init_data = 0xFFFF;
	transmit_handler(init_data); 
	transmit_handler(init_data); 
}


void AD7490_data_query(transmit_handler_t transmit_handler, uint8_t channel){
	AD7490_settings.channel = channel;
	uint16_t* query = (uint16_t*)&AD7490_settings;
	transmit_handler(*query);
}
 
