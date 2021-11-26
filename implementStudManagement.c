#include"headers.h"

void insertHead(studentList * list, student s){
    studentList myNode;
    myNode = (studentList)malloc(sizeof(node));
    myNode->data = s;
    if(*list == NULL){
        *list = (studentList)malloc(sizeof(node));
        myNode->next = NULL;
        *list = myNode;
    }
    else{
       myNode->next = (studentList)malloc(sizeof(node));
       myNode->next = *list;
       *list = myNode;
    }

};

void displayList(studentList list){
    studentList tmp = list;
    printf("\nList of students: ");
    while(tmp != NULL){
        displayStudent(tmp -> data);
        tmp = tmp -> next;
    }
    printf("\nDone.");
};

int searchStudent(studentList list, student s){
    studentList tmp = list;
    while(tmp != NULL){
        if(strcmp((tmp -> data).referenceNumber, s.referenceNumber) == 0)
            return 1;
        tmp = tmp -> next;
    }
    return 0;
};

void update(studentList list, student oldValue , student newValue){
    if(searchStudent(list,oldValue) == 1){
        studentList tmp = list;
        while(tmp != NULL){
            if(strcmp((tmp -> data).referenceNumber, oldValue.referenceNumber) == 0)
            {
                tmp -> data = newValue;
            }
            tmp = tmp -> next;
        }
    }
};

void updateRandom(studentList *list, student oldValue , student newValue){
    deleteStudent(list,oldValue);
    insertRandom(list,newValue);
};

void deleteStudent(studentList * list, student s){
    if(searchStudent(*list,s) == 1){
        if((*list) -> next == NULL){
            *list = NULL;
            return;
        }else if(strcmp(((*list) -> data).referenceNumber, s.referenceNumber) == 0)
              {
                    studentList tmp = *list;
                    *list = tmp -> next;
                    tmp -> next = NULL;
                    return;
              }else {
                  studentList tmp = *list;
                  while((tmp -> next != NULL) &&
                        (strcmp((tmp -> data).referenceNumber, s.referenceNumber) != 0)){
                       tmp = tmp -> next;
                  }
                  studentList tmp2 = tmp -> next;
                  tmp -> next = tmp2 -> next;
                  tmp2 -> next = NULL;
              }
    }
};

void insertRandom(studentList * list, student s){
    studentList myNode;
    myNode = (studentList)malloc(sizeof(node));
    myNode->data = s;
    if(*list == NULL){
        *list = (studentList)malloc(sizeof(node));
        myNode->next = NULL;
        *list = myNode;
    }
    else if(compare((*list) -> data , s) > 0){
       myNode->next = (studentList)malloc(sizeof(node));
       myNode->next = *list;
       *list = myNode;
    }else {
        studentList tmp = *list;
        while((tmp -> next!= NULL) && (compare(tmp -> next -> data, s) < 0) ){
            tmp = tmp -> next;
        }
        if(tmp -> next == NULL){
            tmp -> next = (studentList)malloc(sizeof(node));
            myNode->next = NULL;
            tmp -> next = myNode;
        }else{
            myNode->next = tmp -> next;
            tmp -> next = myNode;
        }
    }

};

int compare(student s1, student s2){
    return strcmp(s1.name, s2.name);
};

void displayStudent(student s){
    printf("\nname: %s age: %d reference number: %s level: %s grade: %lf\n", s.name,s.age,s.referenceNumber,s.level,s.grade);
};
studentList successfulStudents(studentList *list,double passingGrade)
{
    studentList studentsWhoPassed=NULL;
    studentList tmp =*list;
    while (tmp!=NULL)
    {
        if(tmp->data.grade>=passingGrade)
        {
           insertRandom(&studentsWhoPassed,tmp->data);
            tmp=tmp->next;

        }
    }
   return studentsWhoPassed;
};
student weakestStudent(studentList list)
{
    studentList tmp=list;
    double min=tmp->data.grade;
    studentList  tmp2=tmp->next;
    student weakest;
    while(tmp!=NULL)
    {
        if((min-tmp2->data.grade)>0.0)
        {
            min=tmp2->data.grade;
            tmp2  =tmp->next;
        }
         tmp=tmp->next;
    }
    weakest=tmp2->data;
    return weakest;
};
student bestStudent(studentList list)
{
    studentList tmp=list;
    double max=tmp->data.grade;
    studentList tmp2=tmp->next;
    student best;
    while(tmp!=NULL)
    {
        if((max-tmp2->data.grade)<0.0)
        {
            max=tmp2->data.grade;
            tmp2  =tmp->next;
        }
        tmp=tmp->next;
    }
    best=tmp2->data;
    return best;
};
double averageGrade(studentList list)
{
    studentList tmp=list;
    int count=0;
    double sum=0.0,average;
    while (tmp!=NULL)
    {
        sum+=tmp->data.grade;
        tmp=tmp->next;
        count++;
    }
    average=sum/count;
    return average;
};
studentList studentsWithGradeMoreThanAverage(studentList *list)
 {
  studentList averageAndGoodStudents=NULL;
    studentList tmp =*list;
    while (tmp!=NULL)
    {
        if(tmp->data.grade>=averageGrade(*list))
        {
           insertRandom(&averageAndGoodStudents,tmp->data);

        }
        tmp=tmp->next;
    }
   return averageAndGoodStudents;
 };
void displayMenu ()
{
    printf(" ***** WELCOME USER*****\n");
    printf("The Following are some actions which can be performed by our application:\n");
    printf("1: INSERT a student. \n2: DELETE  student. \n3: DISPLAY the list of students.\n");
    printf("4: UPDATE information concerning a student.\n5: SEARCH for a student\n");
    printf("6: SUCCESSFUL students \n7: BEST student\n8: WEAKEST student\n9: AVERAGE grade of student");
    printf("\n10: Students with grade greater than or equal to average grade\n11: EXIT");

};
void readStudent()
{
    student stud;
    printf("You are to insert a student\n");
    puts("Enter the student's name");
    getchar();
    gets(stud.name);
    printf("Enter the student's reference number\n");
    gets(stud.referenceNumber);
    printf("Enter the student's level \n");
    gets(stud.level);
    printf("Enter the student's age\n");
    scanf("%d",&stud.age);
    printf("Enter the student's grade\n");
    scanf("%lf",&stud.grade);
};
