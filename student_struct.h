#include <stdio.h>
#include <string.h>
struct student_struct
{
    int id;
    float total_marks;
    char full_name[50];
    int age;
    float avarage_marks;
    char grade;



};

struct student_struct students[5];
void initialize_students()
{
    for(int i=0;i<5;i++)
{   
    printf("Enter details for student %d:\n", i + 1);
     printf("ID: ");
    scanf("%d",&students[i].id);
    printf("Total Marks: ");
    scanf("%f",&students[i].total_marks);
    int j=0;
    do{
        
        if (students[i].total_marks<0 || students[i].total_marks>400    )
        {
            printf("Invalid total marks. Please enter marks between 0 and 400:");
            scanf("%f",&students[i].total_marks);
            j=1;

        }
        else
        {
            j=0;
        }
        
    } while (j);
    

    
    printf("Age: ");
    scanf("%d",&students[i].age);
    int k=0;
    do
    {
    {
        
        if(students[i].age<17 || students[i].age>25)
        {
            printf("Invalid age. Please enter age between 17 and 25: ");
            scanf("%d",&students[i].age);
            k=1;
        }
        else
        {
            k=0;
        }
    }
    } while (k);
    


    
    printf("Average Marks: ");
    scanf("%f",&students[i].avarage_marks);
    // strcpy(students[i].full_name,scanf("%s",students[i].full_name));
    printf("Full Name: ");
    scanf("%s", students[i].full_name);
    printf("Grade: ");
    scanf("%c",&students[i].grade);
}
}

void display_all_students() 
{
    printf("ID\tFull Name\tAge\tTotal Marks\tAverage Marks\tGrade\n");
    printf("---------------------------------------------------------------\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\t%s\t%d\t%.2f\t%.2f\t%c\n",students[i].id,students[i].full_name,students[i].age,students[i].total_marks,students[i].avarage_marks,students[i].grade);
            printf("---------------------------------------------------------------\n");
    }
}