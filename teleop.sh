#!/bin/bash
v=0
val=w
while true; do
	read -n 1 resp
	case $resp in
		w)
			val=w
			;;
		s)
			val=s
			;;
		a)
			val=a
			;;
		d)
			val=d
			;;
		p)
			v=100
			;;
		o)
			v=90
			;;
		i)
			v=80
			;;
		u)
			v=70
			;;
		y)
			v=60
			;;
		t)
			v=50
			;;
		r)
			v=40
			;;
		l)
			v=30
			;;
		k)
			v=20
			;;
		j)
			v=10
			;;
		h)
			v=0
			;;
	esac
	case $val in
		w)
			printf " $v\n$v" > vel
			;;
		s)
			printf " -$v\n-$v" > vel
			;;
		d)
			printf " $v\n-$v" > vel
			;;
		a)
			printf " -$v\n$v" > vel
			;;
	esac
done
