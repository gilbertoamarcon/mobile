import sys
import curses, time

#--------------------------------------
def input_char():
    try:
        win = curses.initscr()
        while True: 
            ch = win.getch()
            if ch in range(32, 127): break
            time.sleep(0.05)
    except: raise
    finally:
        curses.endwin()
    return chr(ch)
#--------------------------------------

bwd=2
wide=0.5
vela=0
velb=0
vel_l=0
vel_r=0
vel=0
dir='w'

# Main loop
while True:

	# Input parsing
	resp = input_char()
	if resp=='w' or resp=='s' or resp=='a' or resp=='d' or resp=='q' or resp=='e':
		dir=resp
	if resp > '0' and resp < '9':
		vela=10*int(resp)
	if resp == 'p':
		velb=0
	if resp == 'o':
		velb=1
	if resp == 'i':
		velb=2
	if resp == 'u':
		velb=4
	if resp == 'y':
		velb=6
	if resp == 't':
		velb=8
	if resp == 'r':
		velb=10

	# Final velocity
	vel = vela-velb

	# Directions
	if dir == 'w':
		vel_l = vel
		vel_r = vel
	if dir == 's':
		vel_l = -bwd*vel
		vel_r = -bwd*vel
	if dir == 'a':
		vel_l = -bwd*vel
		vel_r = vel
	if dir == 'd':
		vel_l = vel
		vel_r = -bwd*vel
	if dir == 'q':
		vel_l = wide*vel
		vel_r = vel
	if dir == 'e':
		vel_l = vel
		vel_r = wide*vel

	# Updating file
	f = open('vel', 'w')
	f.write(" %d\n%d"%(vel_l,vel_r))
	f.close()
