import sys
from picamera import PiCamera
from time import sleep

if len(sys.argv) < 2:
	dur = 1
else:
	dur = float(sys.argv[1])

if len(sys.argv) < 3:
	filename = '../Video/video.h264'
else:
	filename = sys.argv[2]	
	
if len(sys.argv) < 5:
	w = 320
	h = 240
else:
	w = int(sys.argv[3])
	h = int(sys.argv[4])

camera = PiCamera()

camera.resolution = (w,h)

sleep(2)
camera.start_recording(filename)
try:
	sleep(dur)
except KeyboardInterrupt:
	camera.stop_recording()
	sys.exit()
camera.stop_recording()
