#ifndef STUDENT_H 
#define STUDENT_H
#include<cstdio> 
#include<iostream>
#include<cstdlib>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define TRUE 1
#define FALSE 0
#define NAME_LENGTH 20
#define STUDENT_NUM_LENGTH 15
typedef int Status;
typedef double ElemType;
void FileInput(FILE *fp,int n);//用户输入到文件 
class Student{
	public:
		char Name[NAME_LENGTH];
		char StudentNum[STUDENT_NUM_LENGTH];
};
#endif
