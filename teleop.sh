#!/bin/bash
bwd=2
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
		q)
			dir=q
			;;
		e)
			dir=e
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
			printf " -$(($vel*2))\n-$(($vel*2))" > vel
			;;
		a)
			printf " -$(($vel*2))\n$vel" > vel
			;;
		d)
			printf " $vel\n-$(($vel*2))" > vel
			;;
		q)
			printf " $(($vel/2))\n$(($vel))" > vel
			;;
		e)
			printf " $(($vel))\n$(($vel/2))" > vel
			;;
	esac
done
