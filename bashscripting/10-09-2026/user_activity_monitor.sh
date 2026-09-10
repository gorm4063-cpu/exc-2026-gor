#!/bin/bash

timestamp=$(date "+%Y-%m-%d_%H%M%S")

read -p "Please enter your name for login:" user
USERS_FILE="Users.txt"
mkdir -p REPORT_FOLDER

echo "$user" >> "$USERS_FILE"



Menu(){

	echo "===== USER ACTIVITY MONITOR ====="
	echo "1. Show Current User"
	echo "2. Show Logged_in Users"
	echo "3. Check Specific User"
	echo "4. Save Activity Report"
	echo "5. Show Report History"
	echo "6. Exit"
    echo ""
}

Show_current_user(){
    
    echo "Current user: $user"     

}

Show_loggedIN_users(){

    cat "$USERS_FILE" 
    
}


Check_specific_user(){
    
    read -p "Enter username:" user0
    if  grep -q "^$user0$" "$USERS_FILE" ; then
        echo "User $user0 is currently logged in."
        return 0
        else
            echo "User $user0 is not currently logged in."
            return 1
    fi

}

Save_activity_report(){
    local report_file="REPORT_FOLDER/USER_REPORT_$timestamp.txt"
    {
    echo "===== SYSTEM USER REPORT =====" 
    echo "Date:$timestamp" 
    echo -e "\n"  
    echo "Current User:$user"
    echo "Logged-In Users:"
    cat "$USERS_FILE"
    echo -e "\n"
    echo "Number of Logged-In Users:$(wc -l < "$USERS_FILE")"
    } > "$report_file"
    
    if [ -f "$report_file" ]; then
        echo "Report saved successfully"
        echo "SUCCESS - Reporte created: reports/($user)_report_$timestamp.txt" >> REPORT_FOLDER/report_status.txt
        else
            echo "Failed to save report"
            echo "[$timestamp] ERROR - Could not create reports directory" >> REPORT_FOLDER/report_status.txt

    fi        
}



Show_report_history(){

    if [ ! -s "REPORT_FOLDER/report_status.txt" ]; then
        echo "No report history found"
        else
            cat "REPORT_FOLDER/report_status.txt"
    fi
}

while true; do
    echo ""
    Menu
    read -p "Choose an option:" option
    echo ""
    case "$option" in
    1) Show_current_user 
    ;;
    2)Show_loggedIN_users 
    ;;
    3)Check_specific_user
    ;;
    4)Save_activity_report
    ;;
    5)Show_report_history
    ;;
    6)
        echo "Goodbye!"
        exit 0
    ;;    
    *)
        echo "Invalid input"
    ;;

    esac

done    