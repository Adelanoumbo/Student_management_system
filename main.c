#include"headers.h"
int main(){
    studentList myList = NULL;
    displayMenu();
    int choice;
    double passingGrade;
    student stud;
    do
    {
        printf("\nChoose an action to be performed\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            readStudent();
            insertRandom(&myList,stud);
            break;
        case 2:
            printf("Enter the student's reference number\n");
            getchar();
            gets(stud.referenceNumber);
            deleteStudent(&myList,stud);
            break;
        case 3:
            printf("The list of all students:\n");
            displayList(myList);
            break;
        case 5:
            printf("Enter the student's reference number\n");
            getchar();
            gets(stud.referenceNumber);
           if  (searchStudent(myList,stud)==1)
            printf("The student with the reference number %s is found",stud.referenceNumber);
           else
            printf("The student with the reference number %s is not found",stud.referenceNumber);
            break;
        case 6:
            printf("please enter the passing grade\n" );
            scanf("%lf",&passingGrade);
            studentList sList=successfulStudents(&myList,passingGrade);
            printf("The list of successful students:\n");
            displayList(sList);
            break;
        case 7:
            printf("The best student is:\n");
            displayStudent(bestStudent(myList));
            break;
         case 8:
            printf("The weakest student is:\n");
            displayStudent(weakestStudent(myList));
            break;
         case 9:
             printf("The average grade is:%lf\n ",averageGrade(myList));
             break;
         case 10:
             printf("Students with grade more than average:\n");
             displayList(studentsWithGradeMoreThanAverage(&myList));
              break;
         case 11:
            exit(1);
            break;
         default:
            printf("invalid choice. Choose something else");
            displayMenu();
        }
    }while(choice!=11);

    return 0;
}
