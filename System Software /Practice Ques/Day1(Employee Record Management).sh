#!/bin/bash
# Problem: Demo on Complex Shell Script
# Write a menu driven program to create Employee Record.
# The Record should contain: Employee Name, Employee Number, and Telephone Number.
# The script should be able to delete a record,
# search and display a specific employee details,
# sort the record and list the complete record.

function create_record(){
    read -p "Enter Employee Name: " ename
    read -p "Enter Employee Number: " eno
    read -p "Enter Telephone Number: " tno

    if grep -q "^.*:$eno:.*$" employee_records.txt; then
        echo "Employee number $eno already exists. Cannot create duplicate records."
    else 
        echo "$ename:$eno:$tno" >> employee_records.txt
        echo "Employee Record created successfully!"
    fi
}

function delete_record(){
    read -p "Enter the Employee Number to delete:" eno
    grep -v "^.*:$eno:.*$" employee_records.txt > temp.txt
    mv temp.txt employee_records.txt
    echo "Employee Record deleted successfully!!!"
}

while true;
do
    clear
    echo "Press 1 to create a record"
    echo "Press 2 to delete record"
    echo "Press 3 to search record"
    echo "Press 4 to display a record"
    echo "Press 5 to sort records"
    echo "Press 6 to list all record"
    echo "Press 7 to exit"
    read -p "Enter your choice (1-7): " choice

    case $choice in
        1)
            create_record
            ;;
        2)
            delete_record
            ;;
        3)
            search_record
            ;;
        4)
            display_employee_details
            ;;
        5)
            sort_records
            ;;
        6)
            list_records
            ;;
        7)
            echo "Exiting..."
            exit 0;
            ;;
        *)
            echo "Invalid choice. Please enter a valid option (1-7)."
            ;;
    esac

    echo
done
