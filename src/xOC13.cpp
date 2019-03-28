/*
	This is a library for the OC13
	Relay Out Low Voltage

	The board uses I2C for communication.
	The board communicates with the following I2C device:
	* 	PCA9554A
	
	Data Sheets:
	PCA9554A - http://www.ti.com/lit/ds/symlink/pca9554a.pdf
*/

#include <xOC13.h>

/********************************************************
 	Constructor
*********************************************************/
xOC13::xOC13()
{
	PCA9554A_I2C_ADDRESS = 0x38;
}

xOC13::xOC13(uint8_t addr)
{
	PCA9554A_I2C_ADDRESS = addr;
}

/********************************************************
 	Configure OC13
*********************************************************/
bool xOC13::begin(void)
{
	begin(PCA9554A_ALL_OUTPUTS_OFF);
}

bool xOC13::begin(bool state)
{
	write(0,state);
	write(1,state);
	write(2,state);
	write(3,state);
	write(4,state);
	xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_CONFIG, PCA9554A_CONF_OUTPUT);
	return true;
}

/********************************************************
 	Write to PIN
*********************************************************/
void xOC13::write(uint8_t channel, bool state)
{	
	uint8_t port_status = getStatus();
	channel = (uint8_t)(channel<<1);

	if(state == true){
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, (channel | port_status));
	}else if(state == false){
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, ((~channel) & port_status));
	}

/********************************************************
 	Get output pin Status
*********************************************************/
uint8_t xOC13::getStatus(void)
{
	uint8_t pin_state = xCore.read8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT); 
	return pin_state;
}



