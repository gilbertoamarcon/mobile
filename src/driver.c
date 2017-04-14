#include <stdio.h>
#include <stdlib.h>
#if PI
#include <wiringPi.h>
#endif

#define PIN_S		19
#define PIN_D		16

int main(int argc, char *argv[]){

	// Pin output config
	#if PI
	wiringPiSetupGpio();
	pinMode(PIN_S, OUTPUT);
	pinMode(PIN_D, OUTPUT);
	digitalWrite(PIN_D, HIGH);
	#endif

	// Main loop
	for(;;){

		// Writing pins
		#if PI
		// Stepper
		digitalWrite(PIN_S, HIGH);
		delayMicroseconds(10000);
		digitalWrite(PIN_S, LOW);
		delayMicroseconds(10000);
		#endif

	}

	return 0;
}
