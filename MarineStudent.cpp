#ifndef MARINESTUDENT_C
#define MARINESTUDENT_C
#include "MarineStudent.h"
#include "StuLink.cpp"
using namespace std;
int MarineStudent::GetScore(int i)
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
			return ProSta;
			break;
		}
		case 4:{
			return ChemicalOcean;
			break;
		}
		case 5:{
			return FluidMechanics;
			break;
		}
		case 6:{
			return LawSea;
			break;
		}
		case 7:{
			return MarineMathSta;
			break;
		}
		case 8:{
			return MarineMathPhy;
			break;
		}
		case 9:{
			return English;
			break;
		}
	}
}
void FileInput(FILE *fp,MarineStudent *p)
{
	fprintf(fp,"%s %s %d %d %d %d %d %d %d %d %d\n",p->Name,p->StudentNum,p->GetScore(1),p->GetScore(2),p->GetScore(3),p->GetScore(4),p->GetScore(5),p->GetScore(6),p->GetScore(7),p->GetScore(8),p->GetScore((9)));
}
void MarineStudent::Cal()
{
	CalSum();
	CalAverage();
	CalCredit();
}
double MarineStudent::GetCredit()
{
	return Credit;
}
Status MarineStudent::Inputfp(FILE *fp)
{
	if(fscanf(fp,"%s",Name)==1){
		fscanf(fp,"%s",StudentNum);
		fscanf(fp,"%d",&Physics);
		fscanf(fp,"%d",&PE);
		fscanf(fp,"%d",&ProSta);
		fscanf(fp,"%d",&ChemicalOcean);
		fscanf(fp,"%d",&FluidMechanics);
		fscanf(fp,"%d",&LawSea);
		fscanf(fp,"%d",&MarineMathSta);
		fscanf(fp,"%d",&MarineMathPhy);
		fscanf(fp,"%d",&English);
		return OK;
	}
	else return ERROR;
} 
Status MarineStudent::Inputuser()
{ 
	cout<<"����������"<<endl;
	cin>>Name;
	cout<<"������ѧ��"<<endl;
	cin>>StudentNum;
	cout<<"�������ѧ����ɼ�"<<endl;
	cin>>Physics;
	cout<<"�����������ɼ�"<<endl;
	cin>>PE;
	cout<<"���������ͳ�Ƴɼ�"<<endl;
	cin>>ProSta;
	cout<<"�����뻯ѧ����ѧ�ɼ�"<<endl;
	cin>>ChemicalOcean;
	cout<<"������������ѧ�ɼ�"<<endl;
	cin>>FluidMechanics;
	cout<<"�����뺣��ѧ�ɼ�"<<endl;
	cin>>LawSea;
	cout<<"�����뺣���е�����ͳ�Ƴɼ�"<<endl;
	cin>>MarineMathSta;
	cout<<"�����뺣���е���ѧ�������ɼ�"<<endl;
	cin>>MarineMathPhy;
	cout<<"������Ӣ��ɼ�"<<endl;
	cin>>English;
	return OK;	
}
void MarineStudent::Show()
{
	Cal(); 
	cout<<"\t\t\t\t������"<<Name<<endl<<"\t\t\t\tѧ�ţ�"<<StudentNum<<endl<<"\t\t\t\t��ѧ����"<<Physics<<endl;
	cout<<"\t\t\t\t������"<<PE<<endl<<"\t\t\t\t����ͳ�ƣ�"<<ProSta<<endl<<"\t\t\t\t��ѧ����ѧ"<<ChemicalOcean<<endl;
	cout<<"\t\t\t\t������ѧ�ɼ���"<<FluidMechanics<<endl ;
	cout<< "\t\t\t\t����ѧ��"<<LawSea<<endl<< "\t\t\t\t�����е�����ͳ�ƣ�"<<MarineMathSta<<endl;
	cout<<"\t\t\t\t�����е���ѧ��������"<<MarineMathPhy<<endl;
	cout<<"\t\t\t\tӢ�"<<English<<endl;
	cout<<"\t\t\t\t�ܷ֣�"<<Sum<<endl<<"\t\t\t\tƽ���֣�"<<Average<<endl<<"\t\t\t\t���㣺"<<Credit<<endl;
}
void MarineStudent::CalSum()
{
	Sum=Physics+PE+ProSta+ChemicalOcean+FluidMechanics+LawSea+English+MarineMathSta+MarineMathPhy;
}
void MarineStudent::CalAverage()
{
	CalSum();
	Average=Sum/9;
} 
double MarineStudent::GPA(int x)
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
void MarineStudent::CalCredit()
{
	double p,pe,el,o,ds,cn,mms,mmp,e;
	p=GPA(Physics)*4;
	pe=GPA(PE)*1;
	el=GPA(ProSta)*3;
	o=GPA(ChemicalOcean)*2;
	ds=GPA(FluidMechanics)*4;
	cn=GPA(LawSea)*2;
	mms=GPA(MarineMathSta)*2;
	mmp=GPA(MarineMathPhy)*3;
	e=GPA(English)*4;
	Credit=(p+pe+el+o+ds+cn+mms+mmp+e)/25;
} 
Status StuLink::InitList_L(MarineStudent**L)
{
	(*L)=(MarineStudent*)malloc(sizeof(MarineStudent));//����һ��ͷ���Ŀռ� 
	if(!(*L))exit(OVERFLOW);//��֤�Ƿ�ɹ� 
	(*L)->next=NULL;//ͷ������һ��ָ����ָ��NULL 
	return OK;
}
Status StuLink::ClearList_L(MarineStudent*L)//���޸�L�����ֵ�����Բ���ָ���ָ�� 
{
	MarineStudent *pre,*p;
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
void StuLink::DestroyList_L(MarineStudent**L)//��ClearList��ͬ���ǣ���ֱ��free(L) 
{
	MarineStudent* p;
	p=(*L);
	while(p){
		p=(*L)->next;
		free(*L);
		(*L)=p;
	}
} 
Status StuLink::ListEmpty(MarineStudent*L)
{
	if(L!=NULL&&L->next==NULL)return TRUE;//ע�⻹��L��=NULL
	else return FALSE; 
}
int StuLink::ListEmpty_L(MarineStudent*L)
{
	int i=0;
	MarineStudent* p;
	if(L)//���ж�ͷ���L�Ƿ���� 
	{
		p=L->next;
		while(p){
			i++;
			p=p->next;
		}
	}
	return i;
}
int StuLink::ListLength_L(MarineStudent*L)
{
	int count=0;
	MarineStudent*p=L->next;
	while(p){
		p=p->next;
		count++;
	}
	return count;
} 
Status StuLink::GetElem_L(MarineStudent*L,ElemType *e,int i)//���޸� 
{
	int n=0;
	MarineStudent* p=L;
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
int StuLink::LocateElem_L(MarineStudent*L,ElemType e)//���޸� 
{
	int i=0;
	MarineStudent* p;
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
Status StuLink::Search(MarineStudent*L,char s[])
{
	MarineStudent *p;
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
	if(!j)cout<<"\t\t\t\tû�����ѧ����"<<endl; 
	return OK;
}
Status StuLink::PriorElem(MarineStudent*L,ElemType *cur_e,ElemType *pre_e)//���޸� 
{
	MarineStudent *p,*q;
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
Status StuLink::NextElem_L(MarineStudent*L,ElemType *cur_e,ElemType *next_e)//���޸� 
{
	MarineStudent *p,*q;
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
Status StuLink::ListInsert_L(MarineStudent*L,int i)
{
	MarineStudent *p,*q;
	q=(MarineStudent*)malloc(sizeof(MarineStudent));
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
Status StuLink::ListInsert_L(MarineStudent*L,FILE *fp)
{
	MarineStudent *q,*p;
	q=(MarineStudent*)malloc(sizeof(MarineStudent));
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
Status StuLink::ListDelete_L(MarineStudent*L,int i,ElemType *e)//������ 
{
	MarineStudent *p,*q;
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
Status StuLink::ListDelete_L(MarineStudent *L,char s[])
{
	int n;
	MarineStudent *p,*q;
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
		cout<<"û�����ѧ����"<<endl;
		return ERROR;
	}
}
Status StuLink::ListDelete_L(MarineStudent *L,int i)
{
	int n;
	MarineStudent *p,*q;
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
Status StuLink::CreateList_HL(FILE *fp,MarineStudent**L,int n)//������ 
{
	int i;
	MarineStudent* p;
	ElemType tmp;
	(*L)=(MarineStudent*)malloc(sizeof(MarineStudent));
	if(!(*L)){
		printf("OVERFLOW\n");
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
	for(i=1;i<=n;i++){
		p=(MarineStudent*)malloc(sizeof(MarineStudent));
		if(p->Inputfp(fp)){
			p->Cal();
			p->next=(*L)->next;
			(*L)->next=p;
		}
		else return ERROR;
	}
	return OK;
}
Status StuLink::CreateList_TL(FILE *fp,MarineStudent**L,int n)//������ 
{
	int i;
	MarineStudent* p,*q;
	(*L)=(MarineStudent*)malloc(sizeof(MarineStudent));
	if(!(*L))exit(OVERFLOW);
	(*L)->next=NULL;
	for(i=1;i<=n;i++){
		if(i==1){
		q=(MarineStudent*)malloc(sizeof(MarineStudent));
		if(q->Inputfp(fp)){
			q->Cal();
			(*L)->next=q;
		}
	}
	else{
		p=(MarineStudent*)malloc(sizeof(MarineStudent));
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
Status StuLink::CreateList_HL(FILE *fp,MarineStudent**L)
{
	int i;
	MarineStudent* p;
	ElemType tmp;
	(*L)=(MarineStudent*)malloc(sizeof(MarineStudent));
	if(!(*L)){
		printf("OVERFLOW\n");
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
	while(1){
		p=(MarineStudent*)malloc(sizeof(MarineStudent));
		if(p->Inputfp(fp)==ERROR)break;
		p->Cal();
		p->next=(*L)->next;
		(*L)->next=p;
	}
	return OK;
}
Status StuLink::CreateList_TL(FILE *fp,MarineStudent**L)
{
	int i;
	MarineStudent* p,*q;
	(*L)=(MarineStudent*)malloc(sizeof(MarineStudent));
	if(!(*L))exit(OVERFLOW);
	(*L)->next=NULL;
	q=(MarineStudent*)malloc(sizeof(MarineStudent));
	q->Inputfp(fp);
	q->Cal();
	(*L)->next=q;
	while(1){
		p=(MarineStudent*)malloc(sizeof(MarineStudent));
		if(p->Inputfp(fp)==ERROR)break;
		p->Cal();
		q->next=p;
		q=q->next;
	} 
	q->next=NULL;
	return OK;
}
void StuLink::ShowLink(MarineStudent *L,int i)
{
	MarineStudent *p;
	p=L->next;
	for(;i>=1;i--){
		p->Show();
		cout<<endl<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
		p=p->next;
	}
}
void StuLink::ShowLink(MarineStudent *L)
{
	MarineStudent *p;
	p=L->next;
	while(p){
		p->Show();
		cout<<endl<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
		p=p->next;
	}
}
Status StuLink::SortLink_PL(MarineStudent*L)
{
	int i,j;
	double ep,eq;
	int n=ListLength_L(L);
	if(ListEmpty(L))return ERROR;
	MarineStudent*k,*p,*q;
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
Status StuLink::SortLink_RL(MarineStudent*L)
{
	int i,j;
	double ep,eq;
	int n=ListLength_L(L);
	if(ListEmpty(L))return ERROR;
	MarineStudent*k,*p,*q;
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
Status StuLink::ScreenLink(MarineStudent*L,double e1,double e2)
{
	MarineStudent *p;
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
Status StuLink::ScreenLink_High(MarineStudent*L,double e)
{
	MarineStudent *p;
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
int StuLink::ShowRanking_R(MarineStudent *L,char s[])
{
	int rank=1;
	MarineStudent *p;
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
		cout<<"\t\t\t\tû�����ѧ����"<<endl;
	}
	return 0; 
}
int StuLink::ShowRanking_P(MarineStudent *L,char s[])
{
	int rank=1;
	MarineStudent *p;
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
		cout<<"\t\t\t\tû�����ѧ����"<<endl;
	}
	return 0; 
}
void StuLink::ShowAllRank(MarineStudent *L)
{
	int rank=1;
	MarineStudent *p;
	if(SortLink_RL(L)){
		p=L->next;
		while(p){
			cout<<rank<<"��"<<p->Name<<endl;
			rank++; 
			p=p->next;
		}
	}
}
#endif
