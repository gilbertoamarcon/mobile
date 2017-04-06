import sys
from picamera import PiCamera
from time import sleep

if len(sys.argv) < 2:
	dur = 1
else:
	dur = float(sys.argv[1])

camera = PiCamera()

camera.start_preview()
sleep(dur)
camera.stop_preview()
