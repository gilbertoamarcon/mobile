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
#define PIN_L		20
#define PIN_R		21
#define PIN_D		19
#define PIN_S		16

// Low padding period (us)
#define PERIOD_PAD	20000

// Zero vel period (us)
#define PERIOD_ZER	1500

// Stepper scale factor
#define STEP_SF		2.5*1e6/100

// Elevator Parameters
#define TOTAL_TICKS	23750
#define TOTAL_STEPS	16
#define TICK_STEP	TOTAL_TICKS/TOTAL_STEPS

int main(int argc, char *argv[]){

	// 0-100% wheel velocity
	int vel_l		= 0;
	int vel_r		= 0;

	// Signal delays
	int delay_l		= PERIOD_ZER;
	int delay_r		= PERIOD_ZER;
	int delay_diff	= 0;
	int delay_rem	= PERIOD_PAD-PERIOD_ZER;
	int delay_e		= (int)(STEP_SF/75);

	// Elevator variables
	int curr_step	= 1;
	int goal_step	= 1;
	int eticks 		= 0;

	// Pin output config
	#if PI
	wiringPiSetupGpio();
	pinMode(PIN_L, OUTPUT);
	pinMode(PIN_R, OUTPUT);
	pinMode(PIN_D, OUTPUT);
	pinMode(PIN_S, OUTPUT);
	#endif
	
	// File buffers
	FILE *file = NULL;
	char buffer_l[B_SIZE];
	char buffer_r[B_SIZE];
	char buffer_e[B_SIZE];
	
	// Arbitrarily move the elevator
	if(argc > 1){
		if(argv[1][0] == 'u')
			digitalWrite(PIN_D, HIGH);
		else
			digitalWrite(PIN_D, LOW);
		for(int i = 0; i < TOTAL_TICKS; i++){
			if(i%100 == 0) printf("%5d\n",i);
			delayMicroseconds(delay_e);
			digitalWrite(PIN_S, HIGH);
			delayMicroseconds(delay_e);
			digitalWrite(PIN_S, LOW);
		}
	}

	// Main loop
	for(;;){

		// Updating velocity from file
		file = fopen(VEL_PATH,"r");
		if(file != NULL){

			// Reading file
			fgets(buffer_l, B_SIZE, (FILE*)file);
			fgets(buffer_r, B_SIZE, (FILE*)file);
			fgets(buffer_e, B_SIZE, (FILE*)file);
			fclose(file);

			// Parsing file
			vel_l		= atoi(buffer_l);
			vel_r		= atoi(buffer_r);
			goal_step	= atoi(buffer_e);

			// Enforcing velocity limits
			if( vel_l > MAX_VEL) vel_l =  MAX_VEL;
			if( vel_r > MAX_VEL) vel_r =  MAX_VEL;
			if( goal_step > MAX_VEL) goal_step =  MAX_VEL;
			if(-vel_l > MAX_VEL) vel_l = -MAX_VEL;
			if(-vel_r > MAX_VEL) vel_r = -MAX_VEL;
			if(-goal_step > MAX_VEL) goal_step = -MAX_VEL;

			// Computing time delays
			delay_l		= (int)(PERIOD_ZER-5*vel_l);
			delay_r		= (int)(PERIOD_ZER-5*vel_r);
			delay_diff	= delay_r-delay_l;
			delay_rem	= (delay_diff>0)?PERIOD_PAD-delay_r:PERIOD_PAD-delay_l;
		}

		// Writing pins
		#if PI
		if(goal_step == curr_step){
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
		else{
			if(goal_step > curr_step)
				digitalWrite(PIN_D, HIGH);
			if(goal_step < curr_step)
				digitalWrite(PIN_D, LOW);
			eticks = TICK_STEP*(int)abs(goal_step-curr_step);
			for(int i = 0; i < eticks; i++){
				delayMicroseconds(delay_e);
				digitalWrite(PIN_S, HIGH);
				delayMicroseconds(delay_e);
				digitalWrite(PIN_S, LOW);
			}
			curr_step = goal_step;
			printf("curr_step: %2d\n",curr_step);
		}
		#endif
	}
	return 0;
}
