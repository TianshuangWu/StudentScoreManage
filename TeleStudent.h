#ifndef TELESTUDENT_H
#define TELESTUDENT_H
#include "Student.cpp"
class TeleStudent:public Student{
	private:
		int Physics;
		int PE;
		int English;
		int CircuitAnalysis;
		int ProSta;
		int Maths;
		int Metalworking;
		double Average;
		int Sum;
		double Credit;
	public:
		TeleStudent *next;
		Status Inputfp(FILE *fp);//���ļ����뵽���� 
		Status Inputuser(); //���û����뵽���� 
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
