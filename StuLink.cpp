#ifndef STULINK_C
#define STULINK_C
#include"Student.cpp"
#include"TeleStudent.h"
#include"ComputerStudent.h"
#include"MathStudent.h" 
#include"MarineStudent.h"
class StuLink{
	public:
		Status InitList_L(ComputerStudent**L);//��ʼ������ 
		Status InitList_L(TeleStudent**L);
		Status InitList_L(MathStudent**L);
		Status InitList_L(MarineStudent**L);
		Status ClearList_L(ComputerStudent*L);//������� 
		Status ClearList_L(TeleStudent*L);
		Status ClearList_L(MathStudent*L);
		Status ClearList_L(MarineStudent*L);
		void DestroyList_L(ComputerStudent**L); 
		void DestroyList_L(TeleStudent**L);
		void DestroyList_L(MathStudent**L);
		void DestroyList_L(MarineStudent**L);
		Status ListEmpty(ComputerStudent*L);
		Status ListEmpty(TeleStudent*L);
		Status ListEmpty(MathStudent*L);
		Status ListEmpty(MarineStudent*L);
		int ListEmpty_L(ComputerStudent*L);//�ж������Ƿ�Ϊ��
		int ListEmpty_L(TeleStudent*L);
		int ListEmpty_L(MathStudent*L); 
		int ListEmpty_L(MarineStudent*L);
		int ListLength_L(ComputerStudent*L);//������ 
		int ListLength_L(TeleStudent*L);
		int ListLength_L(MathStudent*L);
		int ListLength_L(MarineStudent*L);
		Status GetElem_L(ComputerStudent*L,ElemType *e,int i);//���� 
		Status GetElem_L(TeleStudent*L,ElemType *e,int i);
		Status GetElem_L(MathStudent*L,ElemType *e,int i);
		Status GetElem_L(MarineStudent*L,ElemType *e,int i);
		int LocateElem_L(ComputerStudent*L,ElemType e);//���� 
		int LocateElem_L(TeleStudent*L,ElemType e);
		int LocateElem_L(MathStudent*L,ElemType e);
		int LocateElem_L(MarineStudent*L,ElemType e);
		Status Search(ComputerStudent*L,char s[]);//���� ������ 
		Status Search(TeleStudent*L,char s[]);
		Status Search(MathStudent*L,char s[]);
		Status Search(MarineStudent*L,char s[]);
		Status PriorElem(ComputerStudent*L,ElemType *cur_e,ElemType *pre_e);//����
		Status PriorElem(TeleStudent*L,ElemType *cur_e,ElemType *pre_e);
		Status PriorElem(MathStudent*L,ElemType *cur_e,ElemType *pre_e);
		Status PriorElem(MarineStudent*L,ElemType *cur_e,ElemType *pre_e);
		Status NextElem_L(ComputerStudent*L,ElemType *cur_e,ElemType *next_e);//���� 
		Status NextElem_L(TeleStudent*L,ElemType *cur_e,ElemType *next_e);
		Status NextElem_L(MathStudent*L,ElemType *cur_e,ElemType *next_e);
		Status NextElem_L(MarineStudent*L,ElemType *cur_e,ElemType *next_e);
		Status ListInsert_L(ComputerStudent*L,int i);//���� ������ 
		Status ListInsert_L(TeleStudent*L,int i);
		Status ListInsert_L(MathStudent*L,int i);
		Status ListInsert_L(MarineStudent*L,int i);
		Status ListInsert_L(ComputerStudent *L,FILE *fp);
		Status ListInsert_L(TeleStudent *L,FILE *fp);
		Status ListInsert_L(MathStudent *L,FILE *fp);
		Status ListInsert_L(MarineStudent *L,FILE *fp);
		Status ListDelete_L(ComputerStudent*L,int i,ElemType *e);
		Status ListDelete_L(TeleStudent*L,int i,ElemType *e);
		Status ListDelete_L(MathStudent*L,int i,ElemType *e);
		Status ListDelete_L(MarineStudent*L,int i,ElemType *e);
		Status ListDelete_L(ComputerStudent*L,int i);
		Status ListDelete_L(TeleStudent*L,int i);
		Status ListDelete_L(MathStudent*L,int i);
		Status ListDelete_L(MarineStudent*L,int i);
		Status ListDelete_L(ComputerStudent*L,char s[]);//ɾ�� ������ 
		Status ListDelete_L(TeleStudent*L,char s[]);
		Status ListDelete_L(MathStudent*L,char s[]);
		Status ListDelete_L(MarineStudent*L,char s[]);
		Status CreateList_HL(FILE *fp,ComputerStudent**L,int n);//��ͷ���봴�� ������ 
		Status CreateList_HL(FILE *fp,TeleStudent**L,int n);
		Status CreateList_HL(FILE *fp,MathStudent**L,int n);
		Status CreateList_HL(FILE *fp,MarineStudent**L,int n);
		Status CreateList_TL(FILE *fp,ComputerStudent**L,int n);
		Status CreateList_TL(FILE *fp,TeleStudent**L,int n);
		Status CreateList_TL(FILE *fp,MathStudent**L,int n);
		Status CreateList_TL(FILE *fp,MarineStudent**L,int n);
		Status CreateList_HL(FILE *fp,ComputerStudent**L);//��β���봴�������� 
		Status CreateList_HL(FILE *fp,TeleStudent**L);
		Status CreateList_HL(FILE *fp,MathStudent**L);
		Status CreateList_HL(FILE *fp,MarineStudent**L);
		Status CreateList_TL(FILE *fp,ComputerStudent**L);
		Status CreateList_TL(FILE *fp,TeleStudent**L);
		Status CreateList_TL(FILE *fp,MathStudent**L);
		Status CreateList_TL(FILE *fp,MarineStudent**L);
		Status SortLink_PL(ComputerStudent*L); //�Ӹߵ������� ������ 
		Status SortLink_PL(TeleStudent*L);
		Status SortLink_PL(MathStudent*L);
		Status SortLink_PL(MarineStudent*L);
		Status SortLink_RL(ComputerStudent*L);//�ӵ͵����������� 
		Status SortLink_RL(TeleStudent*L);
		Status SortLink_RL(MathStudent*L);
		Status SortLink_RL(MarineStudent*L);
		Status ScreenLink(ComputerStudent*L,double e1,double e2);//ɸѡ���͵� ������ 
		Status ScreenLink(TeleStudent*L,double e1,double e2);
		Status ScreenLink(MathStudent*L,double e1,double e2);
		Status ScreenLink(MarineStudent*L,double e1,double e2);
		Status ScreenLink_High(ComputerStudent*L,double e);//ɸѡ���ߵģ����� 
		Status ScreenLink_High(TeleStudent*L,double e);
		Status ScreenLink_High(MathStudent*L,double e);
		Status ScreenLink_High(MarineStudent*L,double e);
		void ShowLink(ComputerStudent *L,int i); //չʾ������ 
		void ShowLink(TeleStudent *L,int i);
		void ShowLink(MathStudent *L,int i);
		void ShowLink(MarineStudent *L,int i);
		void ShowLink(ComputerStudent *L);
		void ShowLink(TeleStudent *L);
		void ShowLink(MathStudent *L);
		void ShowLink(MarineStudent *L);
		int ShowRanking_R(ComputerStudent *L,char s[]);//��ʾ�������������� 
		int ShowRanking_R(TeleStudent *L,char s[]);
		int ShowRanking_R(MathStudent *L,char s[]);
		int ShowRanking_R(MarineStudent *L,char s[]);
		int ShowRanking_P(ComputerStudent *L,char s[]);//��ʾ��������������
		int ShowRanking_P(TeleStudent *L,char s[]);
		int ShowRanking_P(MathStudent *L,char s[]);
		int ShowRanking_P(MarineStudent *L,char s[]); 
	    void ShowAllRank(ComputerStudent *L);
	    void ShowAllRank(TeleStudent *L);
	    void ShowAllRank(MathStudent *L);
        void ShowAllRank(MarineStudent *L);
};
#endif
