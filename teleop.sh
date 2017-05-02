#!/bin/bash
vel=0
key=w
vfwd=(0 5 10 15 20 40 60 80 90 100)
vbwd=(0 5 10 15 20 40 60 80 90 100)
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
			vel=9
			;;
		8)
			vel=8
			;;
		7)
			vel=7
			;;
		6)
			vel=6
			;;
		5)
			vel=5
			;;
		4)
			vel=4
			;;
		3)
			vel=3
			;;
		2)
			vel=2
			;;
		1)
			vel=1
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
			printf " -${vbwd[vel]}\n${vfwd[vel]}\n0" > vel
			;;
		d)
			printf " ${vfwd[vel]}\n-${vbwd[vel]}\n0)" > vel
			;;
		# q)
		# 	printf " $(($vel*2))\n$(($vel*3))\n0" > vel
		# 	;;
		# e)
		# 	printf " $(($vel*3))\n$(($vel*2))\n0" > vel
		# 	;;
		z)
			printf " 0\n0\n ${vfwd[vel]}" > vel
			;;
		x)
			printf " 0\n0\n-${vfwd[vel]}" > vel
			;;
	esac
done
