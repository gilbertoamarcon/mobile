#!/bin/bash

# Velocity values
vfwd=(0 100 80 70 65 60 55 50 45 40)
vbwd=(0 100 50 30 25 20 15 12 10 8)
vtfw=(0 100 95 90 85 80 75 70 65 58)
vtbw=(0 100 90 80 70 60 40 30 25 18)

# Elevator values
pele=(15 16 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 15 16)

# Value keys
ckey=0
ekey=1

# Operation modes
opmode=w 
eside=0 # Elevator even(0) odd(1)

# Output buffers
lvel=0
rvel=0
eheight=1

while true; do

	# Reading from keyboard
	read -n 1 resp

	# Reading operation mode keys
	if [[ $resp == [a-z] ]] || [[ $resp == [A-Z] ]] ; then
		opmode=$resp
	fi

	# Value
	if [[ $resp == [0-9] ]] ; then
		if [[ $opmode == z ]] ||  [[ $opmode == x ]] || [[ $opmode == Z ]] ||  [[ $opmode == X ]] ; then
			ekey=$resp # Elevator key
		else
			ckey=$resp # Car key
		fi
	fi

	# Operation modes
	case $opmode in
		w|W)
			lvel=${vfwd[ckey]}
			rvel=${vfwd[ckey]}
			;;
		s|S)
			lvel=-${vbwd[ckey]}
			rvel=-${vbwd[ckey]}
			;;
		a|A)
			lvel=-${vtbw[ckey]}
			rvel=${vtfw[ckey]}
			;;
		d|D)
			lvel=${vtfw[ckey]}
			rvel=-${vtbw[ckey]}
			;;
		z|Z)
			eside=0
			;;
		x|X)
			eside=1
			;;
	esac


	# Printing out to file
	eheight=${pele[$((ekey*2+eside))]}
	printf " $lvel\n$rvel\n$eheight" > vel

done


