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
	cout<<"密码错误！\n系统将在五秒后自动关闭"<<endl;
	_beginthread(TimeThread,0,NULL);
	for(;;);
	exit(0);
} 
void Exit()
{
	system("cls"); 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*                                      *"<<endl;
	cout<<"\t\t\t\t\t*         感谢您使用本系统！           *"<<endl;
	cout<<"\t\t\t\t\t*       系统将在五秒后自动关闭         *"<<endl;
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
	cout<<"\t\t\t\t\t*      欢迎使用学生成绩管理系统        *"<<endl;
	cout<<"\t\t\t\t\t*                                      *"<<endl;
	cout<<"\t\t\t\t\t****************************************"<<endl;
	//暂停，清屏 
	system("pause");
	system("cls"); 
	cout<<"\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*            系统内所含学科            *"<<endl;
	cout<<"\t\t\t\t\t*            1.计算机类                *"<<endl;
	cout<<"\t\t\t\t\t*            2.电子信息类              *"<<endl;
	cout<<"\t\t\t\t\t*            3.数学与应用数学          *"<<endl;
	cout<<"\t\t\t\t\t*            4.海洋科学                *"<<endl; 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\n\t\t\t\t\t请选择您的专业："; 
} 

void Function_stu()
{
	system("cls");
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*          您可以使用以下功能          *"<<endl;
	cout<<"\t\t\t\t\t*          1.查询排名                  *"<<endl;
	cout<<"\t\t\t\t\t*          2.查找学生                  *"<<endl;
	cout<<"\t\t\t\t\t*          3.退出                      *"<<endl; 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\n\t\t\t\t\t请输入您想使用的功能编号: ";
}

void Function_adm()
{
	system("cls"); 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\t\t\t\t\t*          您可以使用以下功能          *"<<endl;
	cout<<"\t\t\t\t\t*          1.显示全部学生成绩          *"<<endl;
	cout<<"\t\t\t\t\t*          2.显示全部学生排名          *"<<endl;
	cout<<"\t\t\t\t\t*          3.筛选学生                  *"<<endl;
	cout<<"\t\t\t\t\t*          4.添加学生                  *"<<endl;
	cout<<"\t\t\t\t\t*          5.删除学生                  *"<<endl;
	cout<<"\t\t\t\t\t*          6.查询排名                  *"<<endl;
	cout<<"\t\t\t\t\t*          7.查找学生                  *"<<endl;
	cout<<"\t\t\t\t\t*          8.退出                      *"<<endl; 
	cout<<"\t\t\t\t\t****************************************"<<endl;
	cout<<"\n\t\t\t\t\t请输入您想使用的功能编号:";
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
			cout<<"\n\n\n\n\t\t\t\t\t\t请输入登录密码：";
			cin>>password;
			getchar();
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t您以用户身份登录成功！"<<endl; 
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
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t排名为："<<r<<endl;
						}
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
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
				cout<<"\n\n\n\n\t\t\t\t\t您以管理员身份登录成功！"<<endl; 
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
							cout<<"输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"请输入筛选的区间"<<endl;
							cout<<"最低分为"<<endl; 
							cin>>e1;
							cout<<"最高分为"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"筛选成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"添加成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
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
							cout<<"请输入想要删除的学生姓名或学号"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"删除成功！"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t排名为："<<r<<endl;
							}
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t请输入想要查找的学生的学号或姓名:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t输入错误！请按回车键重试"<<endl;
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
			cout<<"\n\n\n\n\t\t\t\t\t\t请输入登录密码：";
			cin>>password;
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t您以用户身份登录成功！"<<endl; 
				system("pause");
				system("cls");
				while(fn!=3){
					Function_stu();
					cin>>fn;
					if(fn==1){
						system("cls");
						char s[NAME_LENGTH];
						int r;
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t排名为："<<r<<endl;
						}
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
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
				cout<<"\n\n\n\n\t\t\t\t\t您以管理员身份登录成功！"<<endl; 
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
							cout<<"输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"请输入筛选的区间"<<endl;
							cout<<"最低分为"<<endl; 
							cin>>e1;
							cout<<"最高分为"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"筛选成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"添加成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
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
							cout<<"请输入想要删除的学生姓名或学号"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"删除成功！"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t排名为："<<r<<endl;
							}
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t请输入想要查找的学生的学号或姓名:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t输入错误！请按回车键重试"<<endl;
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
			cout<<"\n\n\n\n\t\t\t\t\t\t请输入登录密码：";
			cin>>password;
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t您以用户身份登录成功！"<<endl;  
				system("pause");
				system("cls");
				while(fn!=3){
					Function_stu();
					cin>>fn;
					if(fn==1){
						system("cls");
						char s[NAME_LENGTH];
						int r;
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t排名为："<<r<<endl;
						}
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
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
				cout<<"\n\n\n\n\t\t\t\t\t您以管理员身份登录成功！"<<endl; 
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
							cout<<"输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"请输入筛选的区间"<<endl;
							cout<<"最低分为"<<endl; 
							cin>>e1;
							cout<<"最高分为"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"筛选成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"添加成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
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
							cout<<"请输入想要删除的学生姓名或姓名"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"删除成功！"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t排名为："<<r<<endl;
							}
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t请输入想要查找的学生的学号或姓名:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t输入错误！请按回车键重试"<<endl;
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
			cout<<"\n\n\n\n\t\t\t\t\t\t请输入登录密码：";
			cin>>password;
			if(!strcmp(password,PU)){
				system("cls");
				int fn=1;
				cout<<"\n\n\n\n\t\t\t\t\t您以用户身份登录成功！"<<endl;  
				system("pause");
				system("cls");
				while(fn!=3){
					Function_stu();
					cin>>fn;
					if(fn==1){
						system("cls");
						char s[NAME_LENGTH];
						int r;
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						r=Link.ShowRanking_P(student,s);
						if(r!=0){
							cout<<"\t\t\t\t排名为："<<r<<endl;
						}
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
						getchar(); 
					} 
					else if(fn==2){
						system("cls");
						char s[NAME_LENGTH ];
						cout<<"\n\n\n\n\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
						cin>>s; 
						getchar();
						Link.Search(student,s);
						cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
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
				cout<<"\n\n\n\n\t\t\t\t\t您以管理员身份登录成功！"<<endl; 
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
							cout<<"输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 2:{
							system("cls");
							Link.ShowAllRank(student);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 3:{
							system("cls");
							double e1,e2;
							cout<<"请输入筛选的区间"<<endl;
							cout<<"最低分为"<<endl; 
							cin>>e1;
							cout<<"最高分为"<<endl;
							cin>>e2;
							getchar();
							if(Link.ScreenLink(student,e1,e2))
								cout<<"筛选成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();					
							break;
						}
						case 4:{ 
							system("cls");
							if(Link.ListInsert_L(student,fp))
								cout<<"添加成功！"<<endl;
							cout<<"输入回车返回上一个界面"<<endl;
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
							cout<<"请输入想要删除的学生姓名或学号"<<endl;
							cin>>na;
							if(Link.ListDelete_L(student,na))
								cout<<"删除成功！"<<endl;
							p=student->next;
							while(p){
								FileInput(fp1,p);
								p=p->next;
							}
							fclose(fp1);
							cout<<"输入回车返回上一个界面"<<endl;
							getchar();
							getchar();								
							break;
						} 
						case 6:{
							system("cls");
							char s[NAME_LENGTH];
							int r;
							cout<<"\t\t\t\t请输入想要查询排名的学生的学号或姓名:";
							cin>>s; 
							getchar();
							r=Link.ShowRanking_P(student,s);
							if(r!=0){
								cout<<"\t\t\t\t排名为："<<r<<endl;
							}
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar(); 
							break;
						}
						case 7:{
							system("cls");
							char s[NAME_LENGTH ];
							cout<<"\t\t\t\t请输入想要查找的学生的学号或姓名:";
							cin>>s; 
							getchar();
							Link.Search(student,s);
							cout<<"\t\t\t\t输入回车返回上一个界面"<<endl;
							getchar();
							break;
						}
						case 8:{
							fclose(fp);
							Exit();
							break;
						}
						default:{
							cout<<"\t\t\t\t输入错误！请按回车键重试"<<endl;
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
