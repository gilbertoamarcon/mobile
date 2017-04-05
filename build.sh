#!/bin/bash
if [ $# -eq 1 ]; then
	gcc -o bin/driver src/driver.c -std=c99 -D PI=0
else
	gcc -o bin/driver src/driver.c -std=c99 -D PI=1 -lwiringPi
fi
