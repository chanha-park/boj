#!/bin/bash

declare -i idxA
declare -i idxB
declare -i lenA
declare -i lenB
declare -i next
declare -i mid

function merge() {
	c=()

	lenA=$1
	lenB=$2

	a=(${@:3:$lenA})

	next=$(( $lenA + 3 ))

	b=(${@:$next})

	idxA=0
	idxB=0

	while [ $idxA -lt $lenA ] && [ $idxB -lt $lenB ]
	do
		if [ ${a[$idxA]} -gt ${b[$idxB]} ]
		then
			c+=(${b[$idxB]})
			idxB+=1
		else
			c+=(${a[$idxA]})
			idxA+=1
		fi
	done

	while [ $idxA -lt $lenA ]
	do
		c+=(${a[$idxA]})
		idxA+=1
	done

	while [ $idxB -lt $lenB ]
	do
		c+=(${b[$idxB]})
		idxB+=1
	done

	echo ${c[@]}
}

function mySort() {
	len=$1
	a=(${@:2})
	if [ "$len" -le 1 ]
	then
		echo ${a[@]}
	elif [ "$len" -eq 2 ]
	then
		if [ ${a[0]} -gt ${a[1]} ]
		then
			echo ${a[1]} ${a[0]}
		else
			echo ${a[0]} ${a[1]}
		fi
	else
		mid=$(( $(( $len + 1 )) /  2 ))
		half1=(${a[@]:0:$mid})
		half2=(${a[@]:$mid})
		half1=($(mySort $mid ${half1[@]}))
		half2=($(mySort $(( $len - $mid )) ${half2[@]}))
		echo $(merge "$mid" "$(( $len - $mid))" "${half1[@]}" "${half2[@]}")
	fi
}

a=()

read -r len

idx=0
while [ $idx -lt $len ]
do
	read -r tmp
	a+=($tmp)
	idx=$(( $idx + 1 ))
done

echo $(mySort $len "${a[@]}")
