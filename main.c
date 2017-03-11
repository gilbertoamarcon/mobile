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

	int num_loops	= atoi(argv[1]);
	int delay_l		= 1500+(int)atoi(argv[2]);
	int delay_r		= 1500+(int)atoi(argv[3]);
	int delay_diff	= delay_r-delay_l;
	int delay_rem	= (delay_diff>0)?PERIOD-delay_r:PERIOD-delay_l;
	
	printf("ARGS: %d AND %d\n",delay_l,delay_r);

	wiringPiSetupGpio();

	pinMode(PIN_L, OUTPUT);
	pinMode(PIN_R, OUTPUT);

	printf("Controller running. Press CTRL+C to quit.\n");

	for(int i = 0; i < num_loops; i++){
		digitalWrite(PIN_L, HIGH);
		digitalWrite(PIN_R, HIGH);
		if(delay_diff > 0){
			delayMicroseconds(delay_l);
			digitalWrite(PIN_L, LOW);
			delayMicroseconds(delay_diff);
			digitalWrite(PIN_R, LOW);
		}else{
			delayMicroseconds(delay_r);
			digitalWrite(PIN_R, LOW);
			delayMicroseconds(-delay_diff);
			digitalWrite(PIN_L, LOW);
		}
		delayMicroseconds(delay_rem);
	}

	return 0;
}
