#!/bin/bash
raspivid -n -t 0 -hf -ih -fps 60 -o - | nc -k -l 2222 &
# setsid ~/mobile/cam_server.sh &
setsid ~/mobile/bin/driver &
