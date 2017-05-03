#!/bin/bash
key=w
vel=0
vfwd=(0 40 45 50 55 60 65 70 80 100)
vbwd=(0 8 10 12 15 20 25 30 50 100)
vtfw=(0 60 65 70 75 80 85 90 95 100)
vtbw=(0 20 25 30 40 60 70 80 90 100)
vele=(0 100 100 100 100 100 100 100 100 100)
while true; do
	read -n 1 resp
	case $resp in
		w)
			key=w
			;;
		s)
			key=s
			;;
		a)
			key=a
			;;
		d)
			key=d
			;;
		q)
			key=q
			;;
		e)
			key=e
			;;
		z)
			key=z
			;;
		x)
			key=x
			;;
		9)
			vel=1
			;;
		8)
			vel=2
			;;
		7)
			vel=3
			;;
		6)
			vel=4
			;;
		5)
			vel=5
			;;
		4)
			vel=6
			;;
		3)
			vel=7
			;;
		2)
			vel=8
			;;
		1)
			vel=9
			;;
		0)
			vel=0
			;;
	esac
	case $key in
		w)
			printf " ${vfwd[vel]}\n${vfwd[vel]}\n0" > vel
			;;
		s)
			printf " -${vbwd[vel]}\n-${vbwd[vel]}\n0" > vel
			;;
		a)
			printf " -${vtbw[vel]}\n${vtfw[vel]}\n0" > vel
			;;
		d)
			printf " ${vtfw[vel]}\n-${vtbw[vel]}\n0)" > vel
			;;
		z)
			printf " 0\n0\n ${vele[vel]}" > vel
			;;
		x)
			printf " 0\n0\n-${vele[vel]}" > vel
			;;
	esac
done
