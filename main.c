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

	if(argc < 4){
		printf("Please, provide the number of loops.\n");
		return 0;
	}
	int num_loops = atoi(argv[1]);
	int velL = atoi(argv[2]);
	int velR = atoi(argv[3]);

	wiringPiSetupGpio();

	pinMode(PIN_L, OUTPUT);
	pinMode(PIN_R, OUTPUT);

	printf("Controller running. Press CTRL+C to quit.\n");

	for(int i = 0; i < num_loops; i++){
		digitalWrite(PIN_L, HIGH);
		digitalWrite(PIN_R, HIGH);
		if(velR > velL){
			delayMicroseconds(velL);
			digitalWrite(PIN_L, LOW);
			delayMicroseconds(velR-velL);
			digitalWrite(PIN_R, LOW);
			delayMicroseconds(PERIOD-velR);
		}else{
			delayMicroseconds(velR);
			digitalWrite(PIN_R, LOW);
			delayMicroseconds(velL-velR);
			digitalWrite(PIN_L, LOW);
			delayMicroseconds(PERIOD-velL);
		}
	}

	return 0;
}
