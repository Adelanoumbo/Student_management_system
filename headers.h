#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct s {
    char name[50];
    char referenceNumber[50];
    int age;
    char level[50];
    double grade;
}student;

typedef struct n{
    student data;
    struct n * next;
}node;

typedef node * studentList;

void insertHead(studentList *, student);

void insertRandom(studentList *, student);

void displayList(studentList);

int searchStudent(studentList, student);

void update(studentList,student,student);

void updateRandom(studentList *,student,student);

void deleteStudent(studentList *, student);

int compare(student, student);

void displayStudent(student);

studentList successfulStudents(studentList*,double );

student weakestStudent(studentList);

void readStudent();

student bestStudent(studentList);

double averageGrade(studentList);

studentList studentsWithGradeMoreThanAverage(studentList*);
void displayMenu ();



#endif // HEADERS_H_INCLUDED
