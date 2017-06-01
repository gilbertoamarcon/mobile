#!/bin/bash

## PiCam Remote Video 

# PC:
# nc -l 5001 | mplayer -fps 24 -cache 1024 -

# Pi:
# raspivid -t 999999 -w 1280 -h 720 -fps 20 -o - | nc 192.168.178.22 5001

# Run this from the teleoping computer.
nc -l 5001 | mplayer -fps 24 -cache 1024 -

