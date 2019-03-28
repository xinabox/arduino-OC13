/*************************************************************
	This is an examples for the OC13
	5 channel Relay Out Low Voltage
	
	You can buy one on our store!
	-----> https://xinabox.cc/products/OC13/
	
	This example instructs the OC13 to turn its output ports
	on and off
	
	The sensor communicates over the I2C Bus.
	
*************************************************************/

/********************* Library Includes *********************/
#include <xOC13.h> // https://github.com/xinabox/arduino-OC13
#include <xCore.h> 

/****************** Global sensor objects *******************/
xOC13 OC13;

/********************* SYSTEM VARIABLES *********************/
const int DELAY_TIME = 2000;

/*********************** Sketch Code ************************/
void setup() {
	// Start the Serial Monitor
	Serial.begin(115200);

	#ifdef ESP8266
		Wire.pins(2,14);
	#endif
		
	// Start the I2C Communication
	Wire.begin();
	
	// Start the OC03 port expander
	OC13.begin();

	Serial.println("OC13 Test");
}

void loop() {
	// turn outputs on 
	for (int i = 0; i < 5; i++) {
		OC13.write(i, HIGH);
		delay(DELAY_TIME);
	}

	// turn outputs off
	for (int i = 5; i > 0; i--) {
		OC13.write(i, LOW);
		delay(DELAY_TIME);
	}	
}