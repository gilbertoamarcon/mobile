#!/bin/bash

# Usage: ./init_teleop pc-ip
# Ex: ./init_teleop 192.168.0.100

#raspivid -t 999999 -w 1280 -h 720 -fps 20 -o - | nc $1 5001 &
raspivid -n -t 999999 -w 1280 -h 720 -fps 20 -o - | nc $1 5001 &
setsid ~/mobile/bin/driver &
