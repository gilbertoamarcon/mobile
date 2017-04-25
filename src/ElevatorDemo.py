#!/usr/bin/env python
import RPi.GPIO as GPIO
import time 

# Speed: 0-5000
# Dir: "UP", "DOWN"
# 100 steps ~= 1mm

GPIO.setmode(GPIO.BCM)
GPIO.setup(16, GPIO.OUT)
GPIO.setup(19, GPIO.OUT)
GPIO.setup(13, GPIO.IN)
GPIO.output(19, GPIO.LOW)
state = 0


def motorAction(dir, spd, steps):
	if spd != 0:
		if dir == "UP":
			GPIO.output(19, GPIO.LOW)
		else:
			GPIO.output(19, GPIO.HIGH)
		for i in range(0,steps):
			GPIO.output(16, GPIO.HIGH)
			time.sleep(1.0/spd)
			GPIO.output(16, GPIO.LOW)
			time.sleep(1.0/spd)

while(True):
	if GPIO.input(13) == 1:
		state += 1
		if state > 3:
			state = 0
		
	if (state == 0):
		motorAction("STOP", 0, 0)
		time.sleep(1)
	elif (state == 1):
		motorAction("UP",2000,1000)
		time.sleep(1)
	elif (state == 2):
		motorAction("DOWN",5000,2000)
		time.sleep(1)
	elif (state == 3):
		motorAction("UP",6000,1000)
		time.sleep(1)


GPIO.cleanup()


