/*先用Student类仿照ComputerStudent类派生出其他专业 ， 
然后标重载的函数形参要改成其他专业的形参 */ 
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
