#!/bin/bash
if (( $# == 0 )); then
	echo "Usage: $0	"
	exit 2
fi
 
echo "Script name: $0 "
arr=("$@")
echo "Total arguments: $#"
echo "Last argument: ${!#}"

num1=1
num2=3

while (( num1<=num2 )); do
	echo "Attempt $num1 of $num2"
	"${arr[@]}" &
	pid=$!
	echo "PID: $pid" 
 	wait $pid
	exit_code=$?

	if (( exit_code == 0)); then
	echo "Success on attempt $num1"
	exit 0
	fi

	echo "Script own PID; $$"
	echo "Parent shell PID; $PPID"
	delay=$((RANDOM % 5 ))
	echo "Waiting $delay second"
	sleep $delay
	num1=$((num1+1))
done
exit $exit_code
