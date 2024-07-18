#ifndef MATHSTUDENT_H
#define MATHSTUDENT_H
#include "Student.cpp"
class MathStudent:public Student{
	private:
		int PE;
		int English;
		int Calculus;
		int DifferEqua;
		int LinearAlgebra;
		double Average;
		int Sum;
		double Credit;
	public:
		MathStudent *next;
		Status Inputfp(FILE *fp);//从文件输入到链表 
		Status Inputuser(); //从用户输入到链表 
		//opera operator=(const Student&student);
		double GPA(int x);
		int GetScore(int i);
		void CalCredit();
		void CalAverage();
		void CalSum();
		void Cal();
		void Show();
		double GetCredit();
};
#endif
