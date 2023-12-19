#include <stdio.h>

//create the student structure
struct Student
{
    int Roll_No;
    char Name[50];
    int Semester;
    float english_mark, math_mark, bio_mark;
};

void readDetails(int, struct Student*);
void display(int, struct Student*);
void studentWiseTotal(struct Student s[]);
void subWiseTotal(struct Student s[]);

int main()
{
    // create an array of 5 students
    struct Student s[5];

    //Call the function to read student details 5 times for each student in the array of students
    for (int i = 0; i < 5; i++)
    {
        readDetails(i, &s[i]);//pass student number(i) and address of the student structure to pointer
    }
    
    // Call the function that displays the student details 5 times
    for (int i = 0; i < 5; i++)
    { 
        display(i, &s[i]);
    }

    studentWiseTotal(s);//pass array of students

    subWiseTotal(s);//pass array of students

    return 0;
}

void readDetails(int i, struct Student *p)// Function that reads the student details using pointer p
{
    printf("\n****** ENTER STUDENT %d DETAILS ******", i + 1);
    printf("\nEnter Name : ");
    scanf("%s", p->Name);
    printf("Enter Roll_No : ");
    scanf("%d", &p->Roll_No);
    printf("Enter Semester : ");
    scanf("%d", &p->Semester);
    printf("Enter English Marks : ");
    scanf("%f", &p->english_mark);
    printf("Enter Math Marks : ");
    scanf("%f", &p->math_mark);
    printf("Enter Biology Marks : ");
    scanf("%f", &p->bio_mark);
}

void display(int i, struct Student *p)// Function that displays the student details using pointer p
{
    printf("\n\n****** STUDENT %d DETAILS ******", i + 1);
    printf("\nName : ");
    printf("%s", p->Name);
    printf("\nRoll_No : ");
    printf("%d", p->Roll_No);
    printf("\nSemester : ");
    printf("%d", p->Semester);
    printf("\nEnglish Mark : ");
    printf("%f", p->english_mark);
    printf("\nMath Mark : ");
    printf("%f", p->math_mark);
    printf("\nBiology Mark : ");
    printf("%f", p->bio_mark);
}

void studentWiseTotal(struct Student s[])
{
    //for each student add marks of three subject and display
    printf("\n\n***** STUDENTWISE TOTAL MARKS *****");
    for (int i = 0; i < 5; i++)
    {
        float total = s[i].english_mark + s[i].math_mark + s[i].bio_mark;
        printf("\nStudent %d Total marks = %f",i+1,total);
    }
}

void subWiseTotal(struct Student s[]){
    float english_total=0, math_total=0, bio_total=0;

    //add english marks of all student, math marks of all students and bio markks of all student separately
    // display all three in the end
    for (int i = 0; i < 5; i++)
    {
        english_total += s[i].english_mark;
        math_total += s[i].math_mark;
        bio_total += s[i].bio_mark;
    }
    printf("\n\n***** SUBJECTWISE TOTAL MARKS *****");
    printf("\nEnglish Total Marks = %f",english_total);
    printf("\nMath Total Marks = %f",math_total);
    printf("\nBiology Total Marks = %f",bio_total);
}