#!/bin/bash

if (( $# < 3 )); then
    echo "Usage: $0 <filename> <operation> <value>"
    exit 1
fi
filename="$1"

check_file_exists() {
    if [[ ! -f "$filename" ]]; then
        echo "File $filename does not exist."
        exit 1
    fi
}

name_array=()
mapfile -t -O "${#name_array[@]}" name_array < <(perl -F':' -lane 'print $F[0]' "$filename")
grade_array=()
mapfile -t  -O "${#grade_array[@]}" grade_array < <(perl -F':' -lane 'print $F[1]' "$filename")

add(){
    local value="$1"
    if (( value < 1 )); then
    echo "Value must be a positive integer."
    exit 1
    fi
    for (( i=0; i<value; i++ )); do
    read -p "Enter student name: " name
    while grep -q "^$name:" "$filename"; do
        echo "Student name already exists. Please enter a different name."
        read -p "Enter student name: " name
    done
    name_array+=("$name")   
    read -p "Enter grade: " grade
    while (( grade < 0 || grade > 100 )); do
        echo "Invalid grade. Grade must be between 0 and 100."
        read -p "Enter grade: " grade
    done
    echo "$name:$grade" >> "$filename"
    grade_array+=("$grade")
    done
}

display_all_students(){


    echo "===Student List==="
    cat -n "$filename" | sed 's/:/-/g'
    
}

search_student(){

    local name="$1"
    searching_name=$(grep -i "^$name:" "$filename")
    if [[ -n "$searching_name" ]]; then
        echo "Student found!"
        echo "Name: $name"
        echo "Grade: $(echo "$searching_name" | cut -d':' -f2)"
    else
        echo "Student not found."
        exit 1
    fi

}

average_grade(){

    local info="$1"
    if [[ "$info" != "all" ]]; then
        echo "Invalid argument. Please use 'all' to calculate the average grade of all students."
        exit 1
    fi
    total_students=$(wc -l < "$filename")
    if (( total_students == 0 )); then
        echo "No students to calculate average."
        return
    fi
    sum_grade=$(perl -F':' -lane '$sum += $F[1]; END { print $sum }' "$filename")
    local average=$(( $sum_grade / $total_students ))
    echo "Average grade of all students: $average"

}

top_student(){

    local info="$1"
    if [[ "$info" != "all" ]]; then
        echo "Invalid argument. Please use 'all' to find the top student."
        exit 1
    fi
    top_student=$(sort -t':' -k2,2nr "$filename" | head -n 1)
    highest_grade=$(echo "$top_student" | cut -d':' -f2)
    echo "Top student:"
    echo "Name: $(echo "$top_student" | cut -d':' -f1 | tr ':' '-')"

}

failed_students(){

    local info="$1"
    if [[ "$info" != "all" ]]; then
        echo "Invalid argument. Please use 'all' to display failed students."
        exit 1
    fi
    echo "Failed students:"
    perl -F':' -lane 'print $F[0] if $F[1] < 50' "$filename" | tr ':' '-'

}

show_by_grade(){

    local info="$1"


    if [[ "$info" == "A" ]]; then
        perl -F':' -lane 'print $F[0] if $F[1] >= 90' "$filename" | tr ':' '-'
    elif [[ "$info" == "B" ]]; then
        perl -F':' -lane 'print $F[0] if $F[1] >= 80 && $F[1] < 90' "$filename" | tr ':' '-'
    elif [[ "$info" == "C" ]]; then
        perl -F':' -lane 'print $F[0] if $F[1] >= 70 && $F[1] < 80' "$filename" | tr ':' '-'
    elif [[ "$info" == "D" ]]; then
        perl -F':' -lane 'print $F[0] if $F[1] >= 50 && $F[1] < 70' "$filename" | tr ':' '-'
    elif [[ "$info" == "F" ]]; then
        perl -F':' -lane 'print $F[0] if $F[1] < 50' "$filename" | tr ':' '-'
    else    
        echo "Invalid grade. Please use A, B, C, D, or F."
        exit 1
    fi 
}

states_all(){
cat << EOF
===== Statistics =====
Number of students: $(wc -l < "$filename")
Average grade: $(perl -F':' -lane '$sum += $F[1]; END { print $sum / $. }' "$filename")
Highest grade: $(sort -t':' -k2,2nr "$filename" | head -n 1 | cut -d':' -f2)
Lowest grade: $(sort -t':' -k2,2n "$filename" | head -n 1 | cut -d':' -f2)
Passed: $(perl -F':' -lane ' $c++ if $F[1] >= 50; END { print $c+0 }' "$filename" )  
Failed: $(perl -F':' -lane ' $c++ if $F[1] < 50; END { print $c+0 }' "$filename" )

A: $(perl -F':' -lane ' $c++ if $F[1] >= 90; END { print $c+0 }' "$filename" )
B: $(perl -F':' -lane ' $c++ if $F[1] >= 80 && $F[1] < 90; END { print $c+0 }' "$filename" )
C: $(perl -F':' -lane ' $c++ if $F[1] >= 70 && $F[1] < 80; END { print $c+0 }' "$filename" )
D: $(perl -F':' -lane ' $c++ if $F[1] >= 60 && $F[1] < 70; END { print $c+0 }' "$filename" )
F: $(perl -F':' -lane ' $c++ if $F[1] < 60; END { print $c+0 }' "$filename" )
EOF     
}

menu(){

cat << EOF
===== Student Manager Menu =====
1. Add student
2. List students
3. Search student
4. Calculate average
5. Find top student
6. Display failed students
7. Display students by grade
8. Show statistics
9. Exit
EOF

read -p "Choose an option: " choice
}

main(){
check_file_exists

    local op="$2"
    local val="$3"

if [[ "$op" == "menu" && "$val" == "start" ]]; then
while true; do
    menu
    case $choice in
        1) read -p "How many students to add? " count
           add "$count" ;;
        2) display_all_students ;;
        3) read -p "Enter student name to search: " search_name
           search_student  "$search_name" ;;
        4) average_grade "all" ;;
        5) top_student "all" ;;
        6) failed_students "all" ;;
        7) read -p "Enter grade to display: " grade
           show_by_grade "$grade" ;;
        8) states_all ;;
        9) echo "Exiting..."; exit 0 ;;
        *) echo "Invalid option. Please try again." ;;
    esac
done
elif [[ "$op" == "stats" ]]; then
    states_all
elif [[ "$op" == "add" ]]; then
    add "$val"
elif [[ "$op" == "list" ]]; then
    display_all_students 
elif [[ "$op" == "search" ]]; then
    search_student "$val"
elif [[ "$op" == "average" ]]; then
    average_grade "$val"
elif [[ "$op" == "top" ]]; then
    top_student "$val"
elif [[ "$op" == "failed" ]]; then
    failed_students "$val"
elif [[ "$op" == "grade" ]]; then
    show_by_grade "$val"
else
    echo "Invalid operation. Please use 'menu', 'stats', 'add', 'list', 'search', 'average', 'top', 'failed', or 'grade'."
    exit 1
fi
}

main "$@"


