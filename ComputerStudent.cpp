#ifndef COMPUTERSTUDENT_C
#define COMPUTERSTUDENT_C
#include "ComputerStudent.h"
#include "StuLink.cpp"
using namespace std;
int ComputerStudent::GetScore(int i)
{
	switch(i){
		case 1:{
			return Physics;
			break;
		}
		case 2:{
			return PE;
			break;
		}
		case 3:{
			return Electronics;
			break;
		}
		case 4:{
			return OS;
			break;
		}
		case 5:{
			return DataStructure;
			break;
		}
		case 6:{
			return ComputerNetwork;
			break;
		}
		case 7:{
			return English;
			break;
		}
	}
}
void FileInput(FILE *fp,ComputerStudent *p)
{
	fprintf(fp,"%s %s %d %d %d %d %d %d %d\n",p->Name,p->StudentNum,p->GetScore(1),p->GetScore(2),p->GetScore(3),p->GetScore(4),p->GetScore(5),p->GetScore(6),p->GetScore(7));
}
void ComputerStudent::Cal()
{
	CalSum();
	CalAverage();
	CalCredit();
}
double ComputerStudent::GetCredit()
{
	return Credit;
}
Status ComputerStudent::Inputfp(FILE *fp)
{
	if(fscanf(fp,"%s",Name)==1){
		fscanf(fp,"%s",StudentNum);
		fscanf(fp,"%d",&Physics);
		fscanf(fp,"%d",&PE);
		fscanf(fp,"%d",&Electronics);
		fscanf(fp,"%d",&OS);
		fscanf(fp,"%d",&DataStructure);
		fscanf(fp,"%d",&ComputerNetwork);
		fscanf(fp,"%d",&English);
		return OK;
	}
	else return ERROR;
} 
Status ComputerStudent::Inputuser()
{ 
	cout<<"请输入姓名"<<endl;
	cin>>Name;
	cout<<"请输入学号"<<endl;
	cin>>StudentNum;
	cout<<"请输入物理成绩"<<endl;
	cin>>Physics;
	cout<<"请输入体育成绩"<<endl;
	cin>>PE;
	cout<<"请输入电子技术基础成绩"<<endl;
	cin>>Electronics;
	cout<<"请输入操作系统成绩"<<endl;
	cin>>OS;
	cout<<"请输入数据结构成绩"<<endl;
	cin>>DataStructure;
	cout<<"请输入计算机网路成绩"<<endl;
	cin>>ComputerNetwork;
	cout<<"请输入英语成绩"<<endl;
	cin>>English;
	return OK;	
}
void ComputerStudent::Show()
{
	Cal(); 
	cout<<"\t\t\t\t姓名："<<Name<<endl<<"\t\t\t\t学号："<<StudentNum<<endl<<"\t\t\t\t大学物理："<<Physics<<endl;
	cout<<"\t\t\t\t体育："<<PE<<endl<<"\t\t\t\t电子技术基础："<<Electronics<<endl<<"\t\t\t\t操作系统："<<OS<<endl;
	cout<<"\t\t\t\t数据结构："<<DataStructure<<endl;
	cout<<"\t\t\t\t计算机网络："<<ComputerNetwork<<endl<<"\t\t\t\t英语："<<English<<endl;
	cout<<"\t\t\t\t总分："<<Sum<<endl<<"\t\t\t\t平均分："<<Average<<endl<<"\t\t\t\t绩点："<<Credit<<endl;
}
void ComputerStudent::CalSum()
{
	Sum=Physics+PE+Electronics+OS+DataStructure+ComputerNetwork+English;
}
void ComputerStudent::CalAverage()
{
	CalSum();
	Average=Sum/7;
} 
double ComputerStudent::GPA(int x)
{
	if(x==100)return 5.0;
	else if(x<=99&&x>=96)return 4.8;
	else if(x<=95&&x>=93)return 4.5;
	else if(x<=92&&x>=90)return 4.0;
	else if(x<=89&&x>=86)return 3.8;
	else if(x<=85&&x>=83)return 3.5;
	else if(x<=82&&x>=80)return 3.0;
	else if(x<=79&&x>=76)return 2.8;
	else if(x<=75&&x>=73)return 2.5;
	else if(x<=72&&x>=70)return 2.0;
	else if(x<=69&&x>=66)return 1.8;
	else if(x<=65&&x>=63)return 1.5;
	else if(x<=62&&x>=60)return 1.0;
	else return 0;
}
void ComputerStudent::CalCredit()
{
	double p,pe,el,o,ds,cn,e;
	p=GPA(Physics)*4;
	pe=GPA(PE)*1;
	el=GPA(Electronics)*5;
	o=GPA(OS)*4;
	ds=GPA(DataStructure)*4;
	cn=GPA(ComputerNetwork)*4;
	e=GPA(English)*3;
	Credit=(p+pe+el+o+ds+cn+e)/25;
} 
Status StuLink::InitList_L(ComputerStudent**L)
{
	(*L)=(ComputerStudent*)malloc(sizeof(ComputerStudent));//申请一个头结点的空间 
	if(!(*L))exit(OVERFLOW);//验证是否成功 
	(*L)->next=NULL;//头结点的下一个指针域指向NULL 
	return OK;
}
Status StuLink::ClearList_L(ComputerStudent*L)//不修改L本身的值，所以不用指针的指针 
{
	ComputerStudent *pre,*p;
	if(!L)return ERROR;
	pre=L->next;
	while(pre){
		p=pre->next;
		free(pre);
		pre=p;
	}
	L->next=NULL;
	return OK;
}
void StuLink::DestroyList_L(ComputerStudent**L)//与ClearList不同的是，可直接free(L) 
{
	ComputerStudent* p;
	p=(*L);
	while(p){
		p=(*L)->next;
		free(*L);
		(*L)=p;
	}
} 
Status StuLink::ListEmpty(ComputerStudent*L)
{
	if(L!=NULL&&L->next==NULL)return TRUE;//注意还有L！=NULL
	else return FALSE; 
}
int StuLink::ListEmpty_L(ComputerStudent*L)
{
	int i=0;
	ComputerStudent* p;
	if(L)//先判断头结点L是否存在 
	{
		p=L->next;
		while(p){
			i++;
			p=p->next;
		}
	}
	return i;
}
int StuLink::ListLength_L(ComputerStudent*L)
{
	int count=0;
	ComputerStudent*p=L->next;
	while(p){
		p=p->next;
		count++;
	}
	return count;
} 
Status StuLink::GetElem_L(ComputerStudent*L,ElemType *e,int i)//待修改 
{
	int n=0;
	ComputerStudent* p=L;
	double ep;
	while(n<i){
		if(p==NULL)return ERROR;
		n++;
		p=p->next;
	}
	ep=p->GetCredit();
	*e=ep;
	return OK;
}
int StuLink::LocateElem_L(ComputerStudent*L,ElemType e)//待修改 
{
	int i=0;
	ComputerStudent* p;
	double ep;
	p=L->next;
	while(p){
		ep=p->GetCredit();
		if(ep!=e){
			i++;
			p=p->next;
		}
		else break;
	}
	return i;
}
Status StuLink::Search(ComputerStudent*L,char s[])
{
	ComputerStudent *p;
	int j=0;
	if(!L)return ERROR;
	p=L->next;
	while(p){
		if(!strcmp(s,p->Name)||!strcmp(s,p->StudentNum)){
			j=1;
			p->Show();
		}
		p=p->next; 
	}
	if(!j)cout<<"\t\t\t\t没有这个学生！"<<endl; 
	return OK;
}
Status StuLink::PriorElem(ComputerStudent*L,ElemType *cur_e,ElemType *pre_e)//待修改 
{
	ComputerStudent *p,*q;
	double ep,eq;
	p=L;
	if(p){
		q=L->next;
		while(q){
			eq=q->GetCredit();
			if(eq!=*cur_e){
				p=q;
				q=q->next;
			}
			else break;
		}
		if(q){
			ep=p->GetCredit();
			*cur_e=ep;
			return OK;
		}
		else return ERROR;
	}
	return ERROR;
}
Status StuLink::NextElem_L(ComputerStudent*L,ElemType *cur_e,ElemType *next_e)//待修改 
{
	ComputerStudent *p,*q;
	double ep,eq;
	if(L)
	{
		p=L->next;
		while(p&&p->next)
		{
			q=p->next;
			ep=p->GetCredit();
			eq=q->GetCredit();
			if(q&&ep==*cur_e)
			{
				*next_e=eq;
				return OK;
			}
			else if(q&&ep!=*cur_e){
				p=q;
			}
			else break;
		 } 
	 } 
	 return ERROR;
}
Status StuLink::ListInsert_L(ComputerStudent*L,int i)
{
	ComputerStudent *p,*q;
	q=(ComputerStudent*)malloc(sizeof(ComputerStudent));
	if(!q)exit(OVERFLOW); 
	q->Inputuser();
	q->Cal();
	q->next=NULL;
	int n=1;
	if(L){
		p=L->next;
		while(n<i-1){
			if(p){
				i++;
				p=p->next;
			}
			else return ERROR;
		}
		q->next=p->next;
		p->next=q;
	} 
	return ERROR;
}
Status StuLink::ListInsert_L(ComputerStudent*L,FILE *fp)
{
	ComputerStudent *q,*p;
	q=(ComputerStudent*)malloc(sizeof(ComputerStudent));
	if(!q)exit(OVERFLOW); 
	q->Inputuser();
	q->Cal();
	q->next=NULL;
	if(L){
		p=L;
		q->next=p->next;
		p->next=q;
		FileInput(fp,q);
		return TRUE;
	} 
	return ERROR;
}
Status StuLink::ListDelete_L(ComputerStudent*L,int i,ElemType *e)//待重载 
{
	ComputerStudent *p,*q;
	double ep,eq;
	int j=1;
	if(L){
		p=L->next;
		while(p&&j<i-1){
			p=p->next;
			j++;
		}
		if(!p)return ERROR;
		q=p->next;
		eq=q->GetCredit();
		*e=eq;
		p->next=q->next;
		free(q);
		return OK;
	}
	return ERROR;
}
Status StuLink::ListDelete_L(ComputerStudent *L,char s[])
{
	int n;
	ComputerStudent *p,*q;
	if(L){
		p=L;
		while(p->next){
			if(!strcmp(p->next->Name,s)||!strcmp(p->next->StudentNum,s)){
				q=p->next;
				p->next=q->next;
				free(q);
				return OK;
			}
			p=p->next;
		}
		cout<<"没有这个学生！"<<endl;
		return ERROR;
	}
}
Status StuLink::ListDelete_L(ComputerStudent *L,int i)
{
	int n;
	ComputerStudent *p,*q;
	if(L){
		p=L;
		for(n=1;n<=i-1;n++){
			p=p->next;
		}
		if(!p)return ERROR;
		q=p->next;
		p->next=q->next;
		free(q);
		return OK;
	}
	return ERROR;
}
//Status ListTraverse_L(LinkList L,Status visit);
Status StuLink::CreateList_HL(FILE *fp,ComputerStudent**L,int n)//待重载 
{
	int i;
	ComputerStudent* p;
	ElemType tmp;
	(*L)=(ComputerStudent*)malloc(sizeof(ComputerStudent));
	if(!(*L)){
		printf("OVERFLOW\n");
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
	for(i=1;i<=n;i++){
		p=(ComputerStudent*)malloc(sizeof(ComputerStudent));
		if(p->Inputfp(fp)){
			p->Cal();
			p->next=(*L)->next;
			(*L)->next=p;
		}
		else return ERROR;
	}
	return OK;
}
Status StuLink::CreateList_TL(FILE *fp,ComputerStudent**L,int n)//待重载 
{
	int i;
	ComputerStudent* p,*q;
	(*L)=(ComputerStudent*)malloc(sizeof(ComputerStudent));
	if(!(*L))exit(OVERFLOW);
	(*L)->next=NULL;
	for(i=1;i<=n;i++){
		if(i==1){
		q=(ComputerStudent*)malloc(sizeof(ComputerStudent));
		if(q->Inputfp(fp)){
			q->Cal();
			(*L)->next=q;
		}
	}
	else{
		p=(ComputerStudent*)malloc(sizeof(ComputerStudent));
		if(p->Inputfp(fp)){
			p->Cal();
			q->next=p;
			q=q->next;
		}
		else return ERROR;
		}
	} 
	q->next=NULL;
	return OK;
}
Status StuLink::CreateList_HL(FILE *fp,ComputerStudent**L)
{
	int i;
	ComputerStudent* p;
	ElemType tmp;
	(*L)=(ComputerStudent*)malloc(sizeof(ComputerStudent));
	if(!(*L)){
		printf("OVERFLOW\n");
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
	while(1){
		p=(ComputerStudent*)malloc(sizeof(ComputerStudent));
		if(p->Inputfp(fp)==ERROR)break;
		p->Cal();
		p->next=(*L)->next;
		(*L)->next=p;
	}
	return OK;
}
Status StuLink::CreateList_TL(FILE *fp,ComputerStudent**L)
{
	int i;
	ComputerStudent* p,*q;
	(*L)=(ComputerStudent*)malloc(sizeof(ComputerStudent));
	if(!(*L))exit(OVERFLOW);
	(*L)->next=NULL;
	q=(ComputerStudent*)malloc(sizeof(ComputerStudent));
	q->Inputfp(fp);
	q->Cal();
	(*L)->next=q;
	while(1){
		p=(ComputerStudent*)malloc(sizeof(ComputerStudent));
		if(p->Inputfp(fp)==ERROR)break;
		p->Cal();
		q->next=p;
		q=q->next;
	} 
	q->next=NULL;
	return OK;
}
void StuLink::ShowLink(ComputerStudent *L,int i)
{
	ComputerStudent *p;
	p=L->next;
	for(;i>=1;i--){
		p->Show();
		cout<<endl<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
		p=p->next;
	}
}
void StuLink::ShowLink(ComputerStudent *L)
{
	ComputerStudent *p;
	p=L->next;
	while(p){
		p->Show();
		cout<<endl<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
		p=p->next;
	}
}
Status StuLink::SortLink_PL(ComputerStudent*L)
{
	int i,j;
	double ep,eq;
	int n=ListLength_L(L);
	if(ListEmpty(L))return ERROR;
	ComputerStudent*k,*p,*q;
	for(i=1;i<=n;i++){
		k=L;
		p=L->next;
		q=p->next;
		for(j=1;j<=n-i;j++){
			ep=p->GetCredit();
			eq=q->GetCredit();
			if(ep>=eq){
				k->next=q;
				p->next=q->next;
				q->next=p;
			}
			k=k->next;
			p=k->next;
			q=k->next->next;
		}
	}
	return OK; 
}
Status StuLink::SortLink_RL(ComputerStudent*L)
{
	int i,j;
	double ep,eq;
	int n=ListLength_L(L);
	if(ListEmpty(L))return ERROR;
	ComputerStudent*k,*p,*q;
	for(i=1;i<=n;i++){
		k=L;
		p=L->next;
		q=p->next;
		for(j=1;j<=n-i;j++){
			ep=p->GetCredit();
			eq=q->GetCredit();
			if(ep<=eq){
				k->next=q;
				p->next=q->next;
				q->next=p;
			}
			k=k->next;
			p=k->next;
			q=k->next->next;
		}
	}
	return OK; 
}
Status StuLink::ScreenLink(ComputerStudent*L,double e1,double e2)
{
	ComputerStudent *p;
	double ep;
	int count=1,length;
	length=ListLength_L(L);
	if(!ListEmpty_L(L))return ERROR;
	p=L->next;
	while(p){
		ep=p->GetCredit();
		if(ep<=e1||ep>=e2){
			p=p->next;
			ListDelete_L(L,count);
			count--;
		}
		else p=p->next;
		count++;
	}
}
Status StuLink::ScreenLink_High(ComputerStudent*L,double e)
{
	ComputerStudent *p;
	double ep;
	int count=1,length;
	length=ListLength_L(L);
	if(!ListEmpty_L(L))return ERROR;
	p=L->next;
	while(p){
		ep=p->GetCredit();
		if(ep<=e){
			p=p->next;
			ListDelete_L(L,count);
			count--;
		}
		else p=p->next;
		count++;
	}
}
int StuLink::ShowRanking_R(ComputerStudent *L,char s[])
{
	int rank=1;
	ComputerStudent *p;
	if(SortLink_PL(L)){
		p=L->next;
		while(p){
			if(!strcmp(p->Name,s)||!strcmp(p->StudentNum,s))
				return rank;
			else {
				rank++; 
				p=p->next;
			}
		}
		cout<<"\t\t\t\t没有这个学生！"<<endl;
	}
	return 0; 
}
int StuLink::ShowRanking_P(ComputerStudent *L,char s[])
{
	int rank=1;
	ComputerStudent *p;
	if(SortLink_RL(L)){
		p=L->next;
		while(p){
			if(!strcmp(p->Name,s)||!strcmp(p->StudentNum,s))
				return rank;
			else {
				rank++; 
				p=p->next;
			}
		}
		cout<<"\t\t\t\t没有这个学生！"<<endl;
	}
	return 0; 
}
void StuLink::ShowAllRank(ComputerStudent *L)
{
	int rank=1;
	ComputerStudent *p;
	if(SortLink_RL(L)){
		p=L->next;
		while(p){
			cout<<rank<<"、"<<p->Name<<endl;
			rank++; 
			p=p->next;
		}
	}
}
#endif
