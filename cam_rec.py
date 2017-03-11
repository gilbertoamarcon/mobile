import sys
from picamera import PiCamera
from time import sleep

if len(sys.argv) < 2:
	dur = 1
else:
	dur = float(sys.argv[1])
	
	
if len(sys.argv) < 4:
	w = 1920
	h = 1080
else:
	w = int(sys.argv[2])
	h = int(sys.argv[3])

camera = PiCamera()

camera.resolution = (w,h)

camera.start_recording('../Videos/video.h264')
try:
	sleep(dur)
except KeyboardInterrupt:
	camera.stop_recording()
	sys.exit()
camera.stop_recording()
