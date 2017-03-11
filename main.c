#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

// Output pin numbers
#define PIN_L	21
#define PIN_R	20

// Low padding (us)
#define PERIOD	20000

// High pulse (us)
#define VEL		1200

int main(int argc, char *argv[]){

	if(argc < 2){
		printf("Please, provide the number of loops.\n");
		return 0;
	}
	int num_loops = atoi(argv[1]);

	wiringPiSetupGpio();

	pinMode(PIN_L, OUTPUT);
	pinMode(PIN_R, OUTPUT);

	printf("Controller running. Press CTRL+C to quit.\n");

	for(int i = 0; i < num_loops; i++){
		digitalWrite(PIN_L, HIGH);
		digitalWrite(PIN_R, HIGH);
		delayMicroseconds(VEL);
		digitalWrite(PIN_L, LOW);
		digitalWrite(PIN_R, LOW);
		delayMicroseconds(PERIOD-VEL);
	}

	return 0;
}
