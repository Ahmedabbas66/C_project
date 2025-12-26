#include <stdio.h>
#include "student_struct.h"
int main()
{
  //  initialize_students_for_test();
    int choice;
    choice =1;
    while (choice)
    {
        int expression;
        printf("==========================================\n"
               "STUDENT MANAGEMENT SYSTEM\n"
               "==========================================\n"
               " 1.	ENTER STUDENT DATA\n"
               " 2.	DISPLAY ALL STUDENTS\n"
               " 3.	SEARCH FOR STUDENT\n"
               " 4.	SORT STUDENTS BY MARKS\n"
               " 5.	CALCULATE CLASS STATISTICS\n"
               " 6.	SAVE DATA TO FILE\n"
               " 7.	LOAD DATA FROM FILE\n"
               " 8.	UPDATE STUDENT RECORD\n"
               " 9.	EXIT\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &expression);

        switch (expression)
        {
        case 1:
            initialize_students();
            continue;

        case 2:
            display_all_students();
            continue;

        case 3:
            searchStudent();
            continue;
        case 4:
            sortStudents();
            continue;
        case 5:
            sortStudents();
            printf("Class Average: %.2f\t", calculate_class_average());
            printf("Highest Marks: %.2f\t", students[0].total_marks);
            printf("Lowest Marks: %.2f\n", students[4].total_marks);
            printf("==========================================\n");
            continue;
        case 6:
            saveToFile();
            continue;
        case 7:
            loadFromFile();
            continue;
        case 8:
            updateStudent();
            continue;
        case 9:
            printf("Exiting program.\n");
              choice = 0;
        default:
            printf("Invalid choice. Please try again.\n");
            continue;
        }
    }

    return 0;
}