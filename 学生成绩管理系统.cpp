#include"ComputerStudent.cpp"
#include"TeleStudent.cpp"
#include"MathStudent.cpp"
#include"MarineStudent.cpp"
#include<iostream>
#include<windows.h>
#include <process.h> 
#define PASSWORD 7
DWORD nTimeOut = 5000;
const char PU[PASSWORD]="123456";
const char PM[PASSWORD]="654321";
void TimeThread(void* pArguments)
{
	Sleep(nTimeOut);
	exit(0);
}
void WrongPassWord()
{
	cout<<"�������\nϵͳ����������Զ��ر�"<<endl;
	_beginthread(TimeThread,0,NULL);
	for(;;);
	exit(0);
} 
void Exit()
{
	system("cls"); 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*                                      *"<<endl;
	cout<<"\t\t\t\t\t*         ��л��ʹ�ñ�ϵͳ��           *"<<endl;
	cout<<"\t\t\t\t\t*       ϵͳ����������Զ��ر�         *"<<endl;
	cout<<"\t\t\t\t\t*                                      *"<<endl;
	cout<<"\t\t\t\t\t****************************************"<<endl;
	_beginthread(TimeThread,0,NULL);
	for(;;);
	exit(0);
} 
void Welcome()
{
	cout<<"\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*                                      *"<<endl;
	cout<<"\t\t\t\t\t*      ��ӭʹ��ѧ���ɼ�����ϵͳ        *"<<endl;
	cout<<"\t\t\t\t\t*                                      *"<<endl;
	cout<<"\t\t\t\t\t****************************************"<<endl;
	//��ͣ������ 
	system("pause");
	system("cls"); 
	cout<<"\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*            ϵͳ������ѧ��            *"<<endl;
	cout<<"\t\t\t\t\t*            1.�������                *"<<endl;
	cout<<"\t\t\t\t\t*            2.������Ϣ��              *"<<endl;
	cout<<"\t\t\t\t\t*            3.��ѧ��Ӧ����ѧ          *"<<endl;
	cout<<"\t\t\t\t\t*            4.�����ѧ                *"<<endl; 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\n\t\t\t\t\t��ѡ������רҵ��"; 
} 

void Function_stu()
{
	system("cls");
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*          ������ʹ�����¹���          *"<<endl;
	cout<<"\t\t\t\t\t*          1.��ѯ����                  *"<<endl;
	cout<<"\t\t\t\t\t*          2.����ѧ��                  *"<<endl;
	cout<<"\t\t\t\t\t*          3.�˳�                      *"<<endl; 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\n\t\t\t\t\t����������ʹ�õĹ��ܱ��: ";
}

void Function_adm()
{
	system("cls"); 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*          ������ʹ�����¹���          *"<<endl;
	cout<<"\t\t\t\t\t*          1.��ʾȫ��ѧ���ɼ�          *"<<endl;
	cout<<"\t\t\t\t\t*          2.��ʾȫ��ѧ������          *"<<endl;
	cout<<"\t\t\t\t\t*          3.ɸѡѧ��                  *"<<endl;
	cout<<"\t\t\t\t\t*          4.���ѧ��                  *"<<endl;
	cout<<"\t\t\t\t\t*          5.ɾ��ѧ��                  *"<<endl;
	cout<<"\t\t\t\t\t*          6.��ѯ����                  *"<<endl;
	cout<<"\t\t\t\t\t*          7.����ѧ��                  *"<<endl;
	cout<<"\t\t\t\t\t*          8.�˳�                      *"<<endl; 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\n\t\t\t\t\t����������ʹ�õĹ��ܱ��:";
}

using namespace std;
int main()
{
	int j;
	Welcome();
	cin>>j; 
	system("cls");
	char password[PASSWORD];
	switch(j){
		case 1:{
			ComputerStudent *student;
			StuLink Link;
			FILE *fp;
			fp=fopen("Computerstudent.txt","r+");
			if(!fp){
				cout<<"FALSE"<<endl;
				exit(OVERFLOW);
			}
			Link.CreateList_TL(fp,&student);
			cout<<"\n\n\n\n\t\t\t\t\t\t�������¼���룺";
			cin>>password;
			getchar();
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t�����û���ݵ�¼�ɹ���"<<endl; 
				system("pause");
				system("cls");
				while(fn!=3){
					Function_stu();
					cin>>fn;
					getchar();
					if(fn==1){
						system("cls");
						char s[NAME_LENGTH];
						int r;
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
						}
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					}
					else if(fn==3){
						fclose(fp);
						Exit();
					};
				}
			}
			else if(!strcmp(password,PM)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t���Թ���Ա��ݵ�¼�ɹ���"<<endl; 
				system("pause");
				system("cls");
				while(fn!=8){
					Function_adm();
					cin>>fn;
					getchar();
					switch(fn){
						case 1:{
							system("cls");
							Link.ShowLink(student);
							cout<<"����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"������ɸѡ������"<<endl;
							cout<<"��ͷ�Ϊ"<<endl; 
							cin>>e1;
							cout<<"��߷�Ϊ"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"ɸѡ�ɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"��ӳɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();							
							break;
						}
						case 5:{
							system("cls");
							FILE *fp1;
							ComputerStudent *p;
							p=student->next;
							fp1=fopen("ComputerStudent.txt","w");
							char na[NAME_LENGTH];
							cout<<"��������Ҫɾ����ѧ��������ѧ��"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"ɾ���ɹ���"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
							}
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t��������Ҫ���ҵ�ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t��������밴�س�������"<<endl;
							getchar();
							break;
						}
					}
				}
			}
			else {
				WrongPassWord(); 
			}
		}
		case 2:{
			TeleStudent *student;
			StuLink Link;
			FILE *fp;
			fp=fopen("Telestudent.txt","r+");
			if(!fp){
				cout<<"FALSE"<<endl;
				exit(OVERFLOW);
			}
			Link.CreateList_TL(fp,&student);
			cout<<"\n\n\n\n\t\t\t\t\t\t�������¼���룺";
			cin>>password;
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t�����û���ݵ�¼�ɹ���"<<endl; 
				system("pause");
				system("cls");
				while(fn!=3){
					Function_stu();
					cin>>fn;
					if(fn==1){
						system("cls");
						char s[NAME_LENGTH];
						int r;
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
						}
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					}
					else if(fn==3){
						fclose(fp);
						Exit();
					}
				}
			}
			else if(!strcmp(password,PM)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t���Թ���Ա��ݵ�¼�ɹ���"<<endl; 
				system("pause");
				system("cls");
				while(fn!=8){
					Function_adm();
					cin>>fn;
					getchar();
					switch(fn){
						case 1:{
							system("cls");
							Link.ShowLink(student);
							cout<<"����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"������ɸѡ������"<<endl;
							cout<<"��ͷ�Ϊ"<<endl; 
							cin>>e1;
							cout<<"��߷�Ϊ"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"ɸѡ�ɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"��ӳɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();							
							break;
						}
						case 5:{
							system("cls");
							FILE *fp1;
							TeleStudent *p;
							p=student->next;
							fp1=fopen("TeleStudent.txt","w");
							char na[NAME_LENGTH];
							cout<<"��������Ҫɾ����ѧ��������ѧ��"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"ɾ���ɹ���"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
							}
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t��������Ҫ���ҵ�ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t��������밴�س�������"<<endl;
							getchar();
							break;
						}						
					}
				}
			}
			else {
				WrongPassWord(); 
			}						
		}
		case 3:{
			MathStudent *student;
			StuLink Link;
			FILE *fp;
			fp=fopen("Mathstudent.txt","r+");
			if(!fp){
				cout<<"FALSE"<<endl;
				exit(OVERFLOW);
			}
			Link.CreateList_TL(fp,&student);
			cout<<"\n\n\n\n\t\t\t\t\t\t�������¼���룺";
			cin>>password;
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t�����û���ݵ�¼�ɹ���"<<endl;  
				system("pause");
				system("cls");
				while(fn!=3){
					Function_stu();
					cin>>fn;
					if(fn==1){
						system("cls");
						char s[NAME_LENGTH];
						int r;
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
						}
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					}
					else if(fn==3) {
						fclose(fp);
						Exit();
					}
				}
			}
			else if(!strcmp(password,PM)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t���Թ���Ա��ݵ�¼�ɹ���"<<endl; 
				system("pause");
				system("cls"); 
				while(fn!=8){
					Function_adm();
					cin>>fn;
					getchar();
					switch(fn){
						case 1:{
							system("cls");
							Link.ShowLink(student);
							cout<<"����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"������ɸѡ������"<<endl;
							cout<<"��ͷ�Ϊ"<<endl; 
							cin>>e1;
							cout<<"��߷�Ϊ"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"ɸѡ�ɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"��ӳɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();							
							break;
						}
						case 5:{
							system("cls");
							FILE *fp1;
							MathStudent *p;
							p=student->next;
							fp1=fopen("MathStudent.txt","w");
							char na[NAME_LENGTH];
							cout<<"��������Ҫɾ����ѧ������������"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"ɾ���ɹ���"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
							}
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t��������Ҫ���ҵ�ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t��������밴�س�������"<<endl;
							getchar();
							break;
						}						
					}
				}
			}
			else {
				WrongPassWord();
			}						
		}
		case 4:{
			MarineStudent *student;
			StuLink Link;
			FILE *fp;
			fp=fopen("MarineStudent.txt","r+");
			if(!fp){
				cout<<"FALSE"<<endl;
				exit(OVERFLOW);
			}
			Link.CreateList_TL(fp,&student);
			cout<<"\n\n\n\n\t\t\t\t\t\t�������¼���룺";
			cin>>password;
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t�����û���ݵ�¼�ɹ���"<<endl;  
				system("pause");
				system("cls");
				while(fn!=3){
					Function_stu();
					cin>>fn;
					if(fn==1){
						system("cls");
						char s[NAME_LENGTH];
						int r;
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
						}
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t����س�������һ������"<<endl;
						getchar(); 
					}
					else if(fn==3){
						fclose(fp);
						Exit();
					}
				}
			}
			else if(!strcmp(password,PM)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t���Թ���Ա��ݵ�¼�ɹ���"<<endl; 
				system("pause");
				system("cls");
				while(fn!=8){
					Function_adm();
					cin>>fn;
					getchar();
					switch(fn){
						case 1:{
							system("cls");
							Link.ShowLink(student);
							cout<<"����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"������ɸѡ������"<<endl;
							cout<<"��ͷ�Ϊ"<<endl; 
							cin>>e1;
							cout<<"��߷�Ϊ"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"ɸѡ�ɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"��ӳɹ���"<<endl;
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();							
							break;
						}
						case 5:{
							system("cls");
							FILE *fp1;
							MarineStudent *p;
							p=student->next;
							fp1=fopen("MarineStudent.txt","w");
							char na[NAME_LENGTH];
							cout<<"��������Ҫɾ����ѧ��������ѧ��"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"ɾ���ɹ���"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"����س�������һ������"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t��������Ҫ��ѯ������ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t����Ϊ��"<<r<<endl;
							}
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t��������Ҫ���ҵ�ѧ����ѧ�Ż�����:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t����س�������һ������"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t��������밴�س�������"<<endl;
							getchar();
							break;
						}						
					}
				}
			}
			else {
				WrongPassWord(); 
			}						
		}
	}
	return 0;
}
