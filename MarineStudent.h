#ifndef MARINETUDENT_H
#define MARINETUDENT_H
#include "Student.cpp"
class MarineStudent:public Student{
	private:
		int PE;
		int Physics;
		int English;
		int ProSta;
		int ChemicalOcean;
		int FluidMechanics;
		int LawSea;
		int MarineMathSta;
		int MarineMathPhy; 
		double Average;
		int Sum;
		double Credit;
	public:
		MarineStudent *next;
		Status Inputfp(FILE *fp);//从文件输入到链表 
		Status Inputuser(); //从用户输入到链表 
		//opera operator=(const Student&student);
		double GPA(int x);
		void CalCredit();
		void CalAverage();
		void CalSum();
		int GetScore(int i);
		void Cal();
		void Show();
		double GetCredit();
};
#endif
