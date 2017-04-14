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
#define PIN_S		19
#define PIN_D		16

// Low padding period (us)
#define PERIOD_PAD	20000

// Zero vel period (us)
#define PERIOD_ZER	1500

int main(int argc, char *argv[]){

	// 0-100% wheel velocity
	// int vel_l		= 0;
	// int vel_r		= 0;

	// // Signal delays
	// int delay_l		= PERIOD_ZER;
	// int delay_r		= PERIOD_ZER;
	// int delay_diff	= 0;
	// int delay_rem	= PERIOD_PAD-PERIOD_ZER;

	// Pin output config
	#if PI
	wiringPiSetupGpio();
	// pinMode(PIN_L, OUTPUT);
	// pinMode(PIN_R, OUTPUT);
	pinMode(PIN_S, OUTPUT);
	pinMode(PIN_D, OUTPUT);
	#endif
	
	// // File buffers
	// FILE *file = NULL;
	// char buffer_l[B_SIZE];
	// char buffer_r[B_SIZE];

	// Main loop
	for(;;){

		// // Updating velocity from file
		// file = fopen(VEL_PATH,"r");		
		// if(file != NULL){

		// 	// Reading file
		// 	fgets(buffer_l, B_SIZE, (FILE*)file);
		// 	fgets(buffer_r, B_SIZE, (FILE*)file);
		// 	fclose(file);

		// 	// Parsing file
		// 	vel_l = atoi(buffer_l);
		// 	vel_r = atoi(buffer_r);

		// 	// Enforcing velocity limits
		// 	if( vel_l > MAX_VEL) vel_l =  MAX_VEL;
		// 	if( vel_r > MAX_VEL) vel_r =  MAX_VEL;
		// 	if(-vel_l > MAX_VEL) vel_l = -MAX_VEL;
		// 	if(-vel_r > MAX_VEL) vel_r = -MAX_VEL;

		// 	// Computing time delays
		// 	delay_l		= (int)(PERIOD_ZER+5*vel_l);
		// 	delay_r		= (int)(PERIOD_ZER+5*vel_r);
		// 	delay_diff	= delay_r-delay_l;
		// 	delay_rem	= (delay_diff>0)?PERIOD_PAD-delay_r:PERIOD_PAD-delay_l;
		// }

		// Writing pins
		#if PI
		// Servos
		// digitalWrite(PIN_L, HIGH);
		// digitalWrite(PIN_R, HIGH);
		// if(delay_diff > 0){
		// 	delayMicroseconds(delay_l);
		// 	digitalWrite(PIN_L, LOW);
		// 	delayMicroseconds(delay_diff);
		// 	digitalWrite(PIN_R, LOW);
		// }else{
		// 	delayMicroseconds(delay_r);
		// 	digitalWrite(PIN_R, LOW);
		// 	delayMicroseconds(-delay_diff);
		// 	digitalWrite(PIN_L, LOW);
		// }
		// delayMicroseconds(delay_rem);

		// Stepper
		// digitalWrite(PIN_L, HIGH);
		// digitalWrite(PIN_R, HIGH);
		digitalWrite(PIN_S, HIGH);
		digitalWrite(PIN_D, HIGH);
		delayMicroseconds(100000);
		digitalWrite(PIN_S, LOW);
		delayMicroseconds(100000);
		#endif

	}

	return 0;
}
