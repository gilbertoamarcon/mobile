#!/bin/bash
len=750
com=s
while true; do
	read -n 1 resp
	case $resp in
		w)
			./fwd.sh  100 $len
			;;
		s)
			./fwd.sh -100 $len
			;;
		a)
			./spin.sh -100 $len
			;;
		d)
			./spin.sh  100 $len
			;;
		q)
			./spin.sh -100 300
			;;
		e)
			./spin.sh  100 300
			;;
	esac
done