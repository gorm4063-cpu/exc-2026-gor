#!/bin/bash

BALANCE_FILE="balance.txt"
if [ -f "BALANCE_FILE" ]; then
	balance=$(cat "BALANCE_FILE")
	else
		balance=1000
		echo "$balance=1000" > "BALANCE_FILE"
fi		
while true; do
echo -e "\nWelcom to bank account\nOptions:\n 1)Check Balance\n 2)Deposit Money\n 3)Withdraw Money\n 4)Exit\n "
echo "Please input option number"
read userinput

	case "$userinput" in
	 1)       	
		echo "Your balance is-$balance \n"
		echo "input e for Exit or m for options menu||"
		read userinput2
		if [ "$userinput2" == "e" ]; then
			echo "Goodbye !"
			exit 0
		elif [ "$userinput2" == "m" ]; then
			continue
		else
			echo "Invalid input"	
		fi
		;;
	2)
		echo "Enter deposit amount:"
		read money
		if (( money < 0 )); then
			echo "Amount must be greater than 0"
		else 
			balance=$((balance + money)) 
			echo -e "Deposit successful.\n"
			echo "Your current balance is: $balance"
			echo "$balance" > "BALANCE_FILE"
		fi
		;;
	3)	
		echo "Enter withdrawal amount:"
		read withdrawmoney
		if (( withdrawmoney < 0 || withdrawmoney > balance )); then
			echo "The amount of money must be greater than 0 and less than balance"
			
		else	
			balance=$((balance - withdrawmoney))
			echo -e "Withdrawal successful.\n"
			echo "Current balance:$balance"
			echo "$balance" > "BALANCE_FILE"	
		fi
		;;
	4)	
		echo "Goodbye!"
		exit 0
		;;
	*)
	echo "Invalid input"
	;;
esac
done