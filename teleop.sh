#!/bin/bash
./bin/driver &
./cam_server.sh &
vel=0
dir=w
while true; do
	read -n 1 resp
	case $resp in
		w)
			dir=w
			;;
		s)
			dir=s
			;;
		a)
			dir=a
			;;
		d)
			dir=d
			;;
		9)
			vel=100
			;;
		8)
			vel=90
			;;
		7)
			vel=80
			;;
		6)
			vel=70
			;;
		5)
			vel=60
			;;
		4)
			vel=50
			;;
		3)
			vel=40
			;;
		2)
			vel=30
			;;
		1)
			vel=20
			;;
		0)
			vel=0
			;;
	esac
	case $dir in
		w)
			printf " $vel\n$vel" > vel
			;;
		s)
			printf " -$vel\n-$vel" > vel
			;;
		d)
			printf " $vel\n-$vel" > vel
			;;
		a)
			printf " -$vel\n$vel" > vel
			;;
	esac
done
