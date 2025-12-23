#include <stdio.h>
#include "student_struct.h"
int main()
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
           switch(expression)
           {
           case 1:
            initialize_students();
            break;
           case 2:
            display_all_students();
            break;
           case 3:
            searchStudent();
            break;
           case 4:
            /* code */
            break;
           case 5:
            /* code */
            break;
           case 6:
            /* code */
            break;
           case 7:
            /* code */
            break;
           case 8:
            /* code */
            break;  
           case 9:
            /* code */
            break;           
           default:
            break;
           }
 
    return 0;
}