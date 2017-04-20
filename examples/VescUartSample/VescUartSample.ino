/*
 Name:		VescUartSample.ino
 Created:	9/26/2015 10:12:38 PM
 Author:	AC
*/

// the setup function runs once when you press reset or power the board
// To use VescUartControl stand alone you need to define a config.h file, that should contain the Serial or you have to comment the line
// #include Config.h out in VescUart.h

//Include libraries copied from VESC
#include "SamVESC.h"
#include "datatypes.h"

// #define DEBUG

unsigned long count;
SamVESC vesc1(Serial1);
struct bldcMeasure measuredValues;


void setup() {
	
	//Setup UART port
	Serial1.begin(115200);
#ifdef DEBUG
	//SEtup debug port
	Serial.begin(115200);
	#endif
}


	
// the loop function runs over and over again until power down or reset
void loop() {
	//int len=0;
	//len = ReceiveUartMessage(message);
	//if (len > 0)
	//{
	//	len = PackSendPayload(message, len);
	//	len = 0;
	//}
	
	if (vesc1.VescUartGetValue(measuredValues)) {
		Serial.print("Loop: "); Serial.println(count++);
		vesc1.SerialPrint(measuredValues);
	}
	else
	{
		Serial.println("Failed to get data!");
	}
	
}




