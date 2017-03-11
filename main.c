#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

// Default spinning time (ms)
#define DEF_TIME 1000

// Output pin numbers
#define PIN_L	21
#define PIN_R	20

// Low padding (us)
#define PERIOD	20000

int main(int argc, char *argv[]){

	int delay_l		= 0;
	int delay_r		= 0;
	int num_loops	= 0;
	int delay_diff	= 0;
	int delay_rem	= 0;

	if(argc < 3)
		return 0;

	if(argc < 4)
		num_loops	= DEF_TIME/20;
	else
		num_loops	= atoi(argv[3])/20;

	delay_l		= (int)(1500-5*atoi(argv[1]));
	delay_r		= (int)(1500-5*atoi(argv[2]));
	delay_diff	= delay_r-delay_l;
	delay_rem	= (delay_diff>0)?PERIOD-delay_r:PERIOD-delay_l;

	wiringPiSetupGpio();

	pinMode(PIN_L, OUTPUT);
	pinMode(PIN_R, OUTPUT);

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
