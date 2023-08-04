#!/bin/bash
# Problem: Demo on Complex Shell Script
# Write a menu driven program to create Employee Record.
# The Record should contain: Employee Name, Employee Number, and Telephone Number.
# The script should be able to delete a record,
# search and display a specific employee details,
# sort the record and list the complete record.

while [ 1 ]
do
    clear
    echo "Press 1 to create a record"
    echo "Press 2 to delete record"
    echo "Press 3 to search record"
    echo "Press 4 to display a record"
    echo "Press 5 to sort records"
    echo "Press 6 to list all record"
    echo "Press 7 to exit"
    echo "Enter your choice (1-7):"

    read num

    case "$num" in
        1)
            #create code
            ;;
        2)
            #create code
            ;;
        3)
            #create code
            ;;
        4)
            #create code
            ;;
        5)
            #create code
            ;;
        6)
            #create code
            ;;
        7)
            break
            ;;
        *)
            echo "Invalid choice. Please enter a valid option (1-7)."
            ;;
    esac
done
