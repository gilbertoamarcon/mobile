import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(18, GPIO.OUT)
pwm = GPIO.PWM(18, 100)
pwm.start(5)

duty = float(angle) / 10.0 + 2.5
pwm.ChangeDutyCycle(duty)
