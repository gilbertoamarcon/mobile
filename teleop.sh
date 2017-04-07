#!/bin/bash
bwd=2
vela=0
velb=0
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
			vela=100
			;;
		8)
			vela=90
			;;
		7)
			vela=80
			;;
		6)
			vela=70
			;;
		5)
			vela=60
			;;
		4)
			vela=50
			;;
		3)
			vela=40
			;;
		2)
			vela=30
			;;
		1)
			vela=20
			;;
		0)
			vela=0
			;;
		p)
			velb=0
			;;
		o)
			velb=1
			;;
		i)
			velb=2
			;;
		u)
			velb=3
			;;
		y)
			velb=4
			;;
		t)
			velb=5
			;;
		r)
			velb=6
			;;
	esac
	vel=$((vela-velb))
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
			printf " $(($vel/3))\n$(($vel))" > vel
			;;
		e)
			printf " $(($vel))\n$(($vel/3))" > vel
			;;
	esac
done
