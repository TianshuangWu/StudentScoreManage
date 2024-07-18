#ifndef TELESTUDENT_C
#define TELESTUDENT_C
#include "TeleStudent.h" 
#include "StuLink.cpp" 
using namespace std;
int TeleStudent::GetScore(int i)
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
			return CircuitAnalysis;
			break;
		}
		case 4:{
			return ProSta;
			break;
		}
		case 5:{
			return Maths;
			break;
		}
		case 6:{
			return Metalworking;
			break;
		}
		case 7:{
			return English;
			break;
		}
	}
}
void FileInput(FILE *fp,TeleStudent *p)
{
	fprintf(fp,"%s %s %d %d %d %d %d %d %d\n",p->Name,p->StudentNum,p->GetScore(1),p->GetScore(2),p->GetScore(3),p->GetScore(4),p->GetScore(5),p->GetScore(6),p->GetScore(7));
}
void TeleStudent::Cal()
{
	CalSum();
	CalAverage();
	CalCredit();
}
double TeleStudent::GetCredit()
{
	return Credit;
}
Status TeleStudent::Inputfp(FILE *fp)
{
	if(fscanf(fp,"%s",Name)==1){
		fscanf(fp,"%s",StudentNum);
		fscanf(fp,"%d",&Physics);
		fscanf(fp,"%d",&PE);
		fscanf(fp,"%d",&CircuitAnalysis);
		fscanf(fp,"%d",&ProSta);
		fscanf(fp,"%d",&Maths);
		fscanf(fp,"%d",&Metalworking);
		fscanf(fp,"%d",&English);
		return OK;
	}
	else return ERROR;
} 
Status TeleStudent::Inputuser()
{ 
	cout<<"请输入姓名"<<endl;
	cin>>Name;
	cout<<"请输入学号"<<endl;
	cin>>StudentNum;
	cout<<"请输入物理成绩"<<endl;
	cin>>Physics;
	cout<<"请输入体育成绩"<<endl;
	cin>>PE;
	cout<<"请输入电路分析成绩"<<endl;
	cin>>CircuitAnalysis;
	cout<<"请输入概率统计成绩"<<endl;
	cin>>ProSta;
	cout<<"请输入高等数学成绩"<<endl;
	cin>>Maths;
	cout<<"请输入金工实习成绩"<<endl;
	cin>>Metalworking;
	cout<<"请输入英语成绩"<<endl;
	cin>>English;
	return OK;	
}	
void TeleStudent::Show()
{
	Cal(); 
	cout<<"\t\t\t\t姓名："<<Name<<endl<<"\t\t\t\t学号："<<StudentNum<<endl<<"\t\t\t\t物理："<<Physics<<endl;
	cout<<"\t\t\t\t体育："<<PE<<endl<<"\t\t\t\t电路分析："<<CircuitAnalysis<<endl<<"\t\t\t\t概率统计："<<ProSta<<endl;
	cout<<"\t\t\t\t高等数学："<<Maths<<endl;
	cout<<"\t\t\t\t金工实习："<<Metalworking<<endl<<"\t\t\t\t英语："<<English<<endl;
	cout<<"\t\t\t\t总分："<<Sum<<endl<<"\t\t\t\t平均分："<<Average<<endl<<"\t\t\t\t绩点："<<Credit<<endl;
}
void TeleStudent::CalSum()
{
	Sum=Physics+PE+CircuitAnalysis+ProSta+Maths+Metalworking+English;
}
void TeleStudent::CalAverage()
{
	CalSum();
	Average=Sum/7;
} 
double TeleStudent::GPA(int x)
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
void TeleStudent::CalCredit()
{
	double p,pe,el,o,ds,cn,e;
	p=GPA(Physics)*4;
	pe=GPA(PE)*1;
	el=GPA(CircuitAnalysis)*4;
	o=GPA(ProSta)*3;
	ds=GPA(Maths)*6;
	cn=GPA(Metalworking)*1;
	e=GPA(English)*3;
	Credit=(p+pe+el+o+ds+cn+e)/22;
} 
Status StuLink::InitList_L(TeleStudent**L)
{
	(*L)=(TeleStudent*)malloc(sizeof(TeleStudent));//申请一个头结点的空间 
	if(!(*L))exit(OVERFLOW);//验证是否成功 
	(*L)->next=NULL;//头结点的下一个指针域指向NULL 
	return OK;
}
Status StuLink::ClearList_L(TeleStudent*L)//不修改L本身的值，所以不用指针的指针 
{
	TeleStudent *pre,*p;
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
void StuLink::DestroyList_L(TeleStudent**L)//与ClearList不同的是，可直接free(L) 
{
	TeleStudent* p;
	p=(*L);
	while(p){
		p=(*L)->next;
		free(*L);
		(*L)=p;
	}
} 
Status StuLink::ListEmpty(TeleStudent*L)
{
	if(L!=NULL&&L->next==NULL)return TRUE;//注意还有L！=NULL
	else return FALSE; 
}
int StuLink::ListEmpty_L(TeleStudent*L)
{
	int i=0;
	TeleStudent* p;
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
int StuLink::ListLength_L(TeleStudent*L)
{
	int count=0;
	TeleStudent*p=L->next;
	while(p){
		p=p->next;
		count++;
	}
	return count;
} 
Status StuLink::GetElem_L(TeleStudent*L,ElemType *e,int i)//待修改 
{
	int n=0;
	TeleStudent* p=L;
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
int StuLink::LocateElem_L(TeleStudent*L,ElemType e)//待修改 
{
	int i=0;
	TeleStudent* p;
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
Status StuLink::Search(TeleStudent*L,char s[])
{
	TeleStudent *p;
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
Status StuLink::PriorElem(TeleStudent*L,ElemType *cur_e,ElemType *pre_e)//待修改 
{
	TeleStudent *p,*q;
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
Status StuLink::NextElem_L(TeleStudent*L,ElemType *cur_e,ElemType *next_e)//待修改 
{
	TeleStudent *p,*q;
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
Status StuLink::ListInsert_L(TeleStudent*L,int i)
{
	TeleStudent *p,*q;
	q=(TeleStudent*)malloc(sizeof(TeleStudent));
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
Status StuLink::ListInsert_L(TeleStudent*L,FILE *fp)
{
	TeleStudent *p,*q;
	q=(TeleStudent*)malloc(sizeof(TeleStudent));
	if(!q)exit(OVERFLOW); 
	q->Inputuser();
	q->Cal();
	q->next=NULL;
	int n=1;
	if(L){
		p=L;
		q->next=p->next;
		p->next=q;
		FileInput(fp,q);
		return OK;
	}
	return ERROR;
} 
Status StuLink::ListDelete_L(TeleStudent*L,int i,ElemType *e)//待重载 
{
	TeleStudent *p,*q;
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
Status StuLink::ListDelete_L(TeleStudent *L,char s[])
{
	int n;
	TeleStudent *p,*q;
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
Status StuLink::ListDelete_L(TeleStudent *L,int i)
{
	if(i<1)return ERROR;
	int n;
	TeleStudent *p,*q;
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
Status StuLink::CreateList_HL(FILE *fp,TeleStudent**L,int n)//待重载 
{
	int i;
	TeleStudent* p;
	ElemType tmp;
	(*L)=(TeleStudent*)malloc(sizeof(TeleStudent));
	if(!(*L)){
		printf("OVERFLOW\n");
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
	for(i=1;i<=n;i++){
		p=(TeleStudent*)malloc(sizeof(TeleStudent));
		if(p->Inputfp(fp)){
			p->Cal();
			p->next=(*L)->next;
			(*L)->next=p;
		}
		else return ERROR;
	}
	return OK;
}
Status StuLink::CreateList_TL(FILE *fp,TeleStudent**L,int n)//待重载 
{
	int i;
	TeleStudent* p,*q;
	(*L)=(TeleStudent*)malloc(sizeof(TeleStudent));
	if(!(*L))exit(OVERFLOW);
	(*L)->next=NULL;
	for(i=1;i<=n;i++){
		if(i==1){
		q=(TeleStudent*)malloc(sizeof(TeleStudent));
		if(q->Inputfp(fp)){
			q->Cal();
			(*L)->next=q;
		}
	}
	else{
		p=(TeleStudent*)malloc(sizeof(TeleStudent));
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
Status StuLink::CreateList_HL(FILE *fp,TeleStudent**L)
{
	int i;
	TeleStudent* p;
	ElemType tmp;
	(*L)=(TeleStudent*)malloc(sizeof(TeleStudent));
	if(!(*L)){
		printf("OVERFLOW\n");
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
	while(1){
		p=(TeleStudent*)malloc(sizeof(TeleStudent));
		if(p->Inputfp(fp)==ERROR)break;
		p->Cal();
		p->next=(*L)->next;
		(*L)->next=p;
	}
	return OK;
}
Status StuLink::CreateList_TL(FILE *fp,TeleStudent**L)
{
	int i;
	TeleStudent* p,*q;
	(*L)=(TeleStudent*)malloc(sizeof(TeleStudent));
	if(!(*L))exit(OVERFLOW);
	(*L)->next=NULL;
	q=(TeleStudent*)malloc(sizeof(TeleStudent));
	q->Inputfp(fp);
	q->Cal();
	(*L)->next=q;
	while(1){
		p=(TeleStudent*)malloc(sizeof(TeleStudent));
		if(p->Inputfp(fp)==ERROR)break;
		p->Cal();
		q->next=p;
		q=q->next;
	} 
	q->next=NULL;
	return OK;
}
void StuLink::ShowLink(TeleStudent *L,int i)
{
	TeleStudent *p;
	p=L->next;
	for(;i>=1;i--){
		p->Show();
		cout<<endl<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
		p=p->next;
	}
}
void StuLink::ShowLink(TeleStudent *L)
{
	TeleStudent *p;
	p=L->next;
	while(p){
		p->Show();
		cout<<endl<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
		p=p->next;
	}
}
Status StuLink::SortLink_PL(TeleStudent*L)
{
	int i,j;
	double ep,eq;
	int n=ListLength_L(L);
	if(ListEmpty(L))return ERROR;
	TeleStudent*k,*p,*q;
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
Status StuLink::SortLink_RL(TeleStudent*L)
{
	int i,j;
	double ep,eq;
	int n=ListLength_L(L);
	if(ListEmpty(L))return ERROR;
	TeleStudent*k,*p,*q;
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
Status StuLink::ScreenLink(TeleStudent*L,double e1,double e2)
{
	TeleStudent *p;
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
Status StuLink::ScreenLink_High(TeleStudent*L,double e)
{
	TeleStudent *p;
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
int StuLink::ShowRanking_R(TeleStudent *L,char s[])
{
	int rank=1;
	TeleStudent *p;
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
int StuLink::ShowRanking_P(TeleStudent *L,char s[])
{
	int rank=1;
	TeleStudent *p;
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
void StuLink::ShowAllRank(TeleStudent *L)
{
	int rank=1;
	TeleStudent *p;
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
