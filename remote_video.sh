#!/bin/bash

# Run this from the teleoping computer.
# First arg is the IP address of the Pi
mplayer -fps 200 -demuxer h264es ffmpeg://tcp://$1:2222
