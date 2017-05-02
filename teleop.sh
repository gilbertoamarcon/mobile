#!/bin/bash
vel=0
key=w
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
			vel=100
			;;
		8)
			vel=90
			;;
		7)
			vel=80
			;;
		6)
			vel=60
			;;
		5)
			vel=40
			;;
		4)
			vel=20
			;;
		3)
			vel=15
			;;
		2)
			vel=10
			;;
		1)
			vel=5
			;;
		0)
			vel=0
			;;
	esac
	case $key in
		w)
			printf " $(($vel*2))\n$(($vel*2))\n0" > vel
			;;
		s)
			printf " -$vel\n-$vel\n0" > vel
			;;
		a)
			printf " -$(($vel/2))\n$(($vel*2))\n0" > vel
			;;
		d)
			printf " $(($vel*2))\n-$(($vel/2))\n0)" > vel
			;;
		q)
			printf " $(($vel*2))\n$(($vel*3))\n0" > vel
			;;
		e)
			printf " $(($vel*3))\n$(($vel*2))\n0" > vel
			;;
		z)
			printf " 0\n0\n $vel" > vel
			;;
		x)
			printf " 0\n0\n-$vel" > vel
			;;
	esac
done
