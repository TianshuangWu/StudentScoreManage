/*����Student�����ComputerStudent������������רҵ �� 
Ȼ������صĺ����β�Ҫ�ĳ�����רҵ���β� */ 
#ifndef COMPUTERSTUDENT_H 
#define COMPUTERSTUDENT_H
#include "Student.cpp"
class ComputerStudent:public Student{
	private:
		int Physics;
		int PE;
		int English;
		int Electronics;
		int OS;
		int DataStructure;
		int ComputerNetwork;
		double Average;
		int Sum;
		double Credit;
	public:
		ComputerStudent *next;
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
