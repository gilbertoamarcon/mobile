#include <stdio.h>
#include <stdlib.h>
#if PI
#include <wiringPi.h>
#endif

// Velocity file
#define VEL_PATH 	"vel"
#define B_SIZE 		15

// Velocity limit
#define MAX_VEL 	100

// Output pin numbers
#define PIN_L		21
#define PIN_R		20

// Low padding (us)
#define PERIOD		20000

int main(int argc, char *argv[]){

	int vel_l		= 0;
	int vel_r		= 0;

	int delay_l		= 0;
	int delay_r		= 0;
	int delay_diff	= 0;
	int delay_rem	= 0;

	#if PI
	wiringPiSetupGpio();
	pinMode(PIN_L, OUTPUT);
	pinMode(PIN_R, OUTPUT);
	#endif

	FILE *file = NULL;
	char buffer[B_SIZE];
	for(;;){

		file = fopen(VEL_PATH,"r");		
		if(file != NULL){
			fgets(buffer, B_SIZE, (FILE*)file);
			vel_l = atoi(buffer);
			fgets(buffer, B_SIZE, (FILE*)file);
			fclose(file);
			vel_r= atoi(buffer);
		}
		printf("%d %d\n",vel_l,vel_r);

		if( vel_l > MAX_VEL) vel_l =  MAX_VEL;
		if( vel_r > MAX_VEL) vel_r =  MAX_VEL;
		if(-vel_l > MAX_VEL) vel_l = -MAX_VEL;
		if(-vel_r > MAX_VEL) vel_r = -MAX_VEL;

		delay_l		= (int)(1500+5*vel_l);
		delay_r		= (int)(1500+5*vel_r);
		delay_diff	= delay_r-delay_l;
		delay_rem	= (delay_diff>0)?PERIOD-delay_r:PERIOD-delay_l;

		#if PI
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
		#endif
	}

	return 0;
}
