import sys
from picamera import PiCamera
from time import sleep

if len(sys.argv) < 2:
	filename = '../Pictures/pic.jpeg'
else:
	filename = sys.argv[1]	
	
if len(sys.argv) < 4:
	w = 320
	h = 240
else:
	w = int(sys.argv[2])
	h = int(sys.argv[3])

camera = PiCamera()
camera.resolution = (w, h)
sleep(2)
camera.capture(filename)