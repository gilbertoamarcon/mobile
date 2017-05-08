#!/bin/bash

# Update package manager
sudo apt-get update
sudo apt-get upgrade

# Update firmware
sudo rpi-update

# load v4l module (necessary if using v4l2 directly. Not needed if using 
# raspivid)
sudo modprobe bcm2835-v4l2
