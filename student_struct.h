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
    students[i].avarage_marks = students[i].total_marks / 4.0;
    // strcpy(students[i].full_name,scanf("%s",students[i].full_name));
    printf("Full Name: ");
    scanf("%s", students[i].full_name);
    printf("Grade: ");
    students[i].grade = (students[i].avarage_marks >= 90) ? 'A' :
                        (students[i].avarage_marks >= 80) ? 'B' :
                        (students[i].avarage_marks >= 70) ? 'C' :
                        (students[i].avarage_marks >= 60) ? 'D' : 'F';
}
}

void display_all_students() 
{


    printf("ID\tFull Name\tAge\tTotal Marks\tAverage Marks\tGrade\n");
    printf("------------------------------------------------------------------------\n");

    for(int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t%d\t%.2f\t\t%.2f\t\t%c\n",
               students[i].id,
               students[i].full_name,
               students[i].age,
               students[i].total_marks,
               students[i].avarage_marks,
               students[i].grade);

    printf("------------------------------------------------------------------------\n");
    }
}
float calculate_class_average()
{
    float total = 0.0;
    for(int i = 0; i < 5; i++)
    {
        total += students[i].total_marks;
    }
    return total / 5.0;
}
int searchStudent()
{

    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);

    for(int i = 0; i < 5; i++)
    {
        if(students[i].id == search_id)
        {
            printf("Student found:\n");
            printf("ID: %d\t", students[i].id);
            printf("Full Name: %s\t", students[i].full_name);
            printf("Age: %d\t", students[i].age);
            printf("Total Marks: %.2f\t", students[i].total_marks);
            printf("Average Marks: %.2f\t", students[i].avarage_marks);
            printf("Grade: %c\n", students[i].grade);
            return i; // Return index of found student
        }
    }
    printf("Student with ID %d not found.\n", search_id);
    return -1; // Indicate not found
}
void sortStudents()
{
    // Bubble sort based on total_marks
    for(int i = 0; i < 5 - 1; i++)
    {
        for(int j = 0; j < 5 - i - 1; j++)
        {
            if(students[j].total_marks < students[j + 1].total_marks)
            {
                // Swap students[j] and students[j + 1]
                struct student_struct temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
void updateStudent(){
    int index = searchStudent();
    if(index != -1)
    {
        printf("Enter new details for student ID %d:\n", students[index].id);
        printf("Total Marks: ");
        scanf("%f",&students[index].total_marks);
        students[index].avarage_marks = students[index].total_marks / 4.0;
        printf("Full Name: ");
        scanf("%s", students[index].full_name);
        printf("Age: ");
        scanf("%d",&students[index].age);
        printf("Grade: ");
        students[index].grade = (students[index].avarage_marks >= 90) ? 'A' :
                                (students[index].avarage_marks >= 80) ? 'B' :
                                (students[index].avarage_marks >= 70) ? 'C' :
                                (students[index].avarage_marks >= 60) ? 'D' : 'F';
    }
}
void saveToFile(){
    FILE *file = fopen("students_data.txt", "w");
    if(file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    for(int i = 0; i < 5; i++)
    {
        fprintf(file, "%d,%s,%d,%.2f,%.2f,%c\n",
                students[i].id,
                students[i].full_name,
                students[i].age,
                students[i].total_marks,
                students[i].avarage_marks,
                students[i].grade);
    }
    fclose(file);
    printf("Data saved to file successfully.\n");
}
void loadFromFile(){
    FILE *file = fopen("students_data.txt", "r");
    if(file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    for(int i = 0; i < 5; i++)
    {
        fscanf(file, "%d,%49[^,],%d,%f,%f,%c\n",
               &students[i].id,
               students[i].full_name,
               &students[i].age,
               &students[i].total_marks,
               &students[i].avarage_marks,
               &students[i].grade);
    }
    fclose(file);
    printf("Data loaded from file successfully.\n");
}
void initialize_students_for_test(){
    // Student 1
students[0].id = 1;
students[0].total_marks = 350.5;
strcpy(students[0].full_name, "Alice Johnson");
students[0].age = 20;
students[0].avarage_marks = 87.6;
students[0].grade = 'A';

// Student 2
students[1].id = 2;
students[1].total_marks = 320.0;
strcpy(students[1].full_name, "Bob Smith");
students[1].age = 21;
students[1].avarage_marks = 80.0;
students[1].grade = 'B';

// Student 3
students[2].id = 3;
students[2].total_marks = 290.5;
strcpy(students[2].full_name, "Charlie Brown");
students[2].age = 19;
students[2].avarage_marks = 72.6;
students[2].grade = 'C';

// Student 4
students[3].id = 4;
students[3].total_marks = 365.0;
strcpy(students[3].full_name, "Diana Miller");
students[3].age = 22;
students[3].avarage_marks = 91.2;
students[3].grade = 'A';

// Student 5
students[4].id = 5;
students[4].total_marks = 305.0;
strcpy(students[4].full_name, "Ethan Wilson");
students[4].age = 20;
students[4].avarage_marks = 76.3;
students[4].grade = 'B';

} 
   