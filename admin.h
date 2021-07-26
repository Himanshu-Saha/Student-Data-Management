#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include "class.h"
using namespace std;
void user_interface(char str[10],char name[15]);
void add_students();
void delete_students();
void add_marks();
void view_Profile();
void admin_page()
{
  while(1){
  system("clear");
  cout<<setw(44)<<"[1]Add New Student"<<endl;
  cout<<setw(43)<<"[2]Remove Student"<<endl;
  cout<<setw(38)<<"[3]Add Marks"<<endl;
  cout<<setw(45)<<"[4]View All Student"<<endl;
  cout<<setw(44)<<"[5]Clear All Data"<<endl;
  cout<<setw(36)<<"[0]Log Out"<<endl;
  int n;
  cin>>n;
  char c;
  switch(n)
  {
    case 0:
      return;
    case 1:
      add_students();
      break;
    case 2:
      delete_students(); 
      break;
    case 3:
      add_marks();
      break;
    case 4:
      view_Profile();
      cin.ignore(5,'\n');
      cout<<"Press any key"<<endl;
      c=getchar();
      break;
    case 5:
      cout<<"Are you sure want to clear data?"<<endl;
      cout<<"[1]YES"<<endl<<"[2]NO"<<endl;
      int n;
      cin>>n;
      char c;
      if(n==1){
      ofstream file1("login_user.txt",ios::trunc);
      if(!file1.is_open())
      {
        cerr<<"error1"<<endl;
        cin.ignore(5,'\n');
      cout<<"Press any key"<<endl;
      c=getchar();
        return;
      }
      ofstream file2("data.txt",ios::trunc);
      if(!file1.is_open())
      {
        cerr<<"error2"<<endl;
        cin.ignore(5,'\n');
      cout<<"Press any key"<<endl;
      c=getchar();
        return;
      }
      ofstream file3("marks.txt",ios::trunc);
      if(!file1.is_open())
      {
        cerr<<"error3"<<endl;
        cin.ignore(5,'\n');
      cout<<"Press any key"<<endl;
      c=getchar();
        return;
      }
      file1.close();
      file2.close();
      file3.close();
      cout<<"Deleted Successfully"<<endl;}
      cin.ignore(5,'\n');
      cout<<"Press any key"<<endl;
      c=getchar();
      break;
  }}
}
void add_students()
{
  system("clear");
    cout<<"enter no. of student"<<endl;
    int n;
    cin>>n;
    admin ad;
    ad.add_student(n);
    cout<<"Added successfully"<<endl;
    char c;
    cin.ignore(5,'\n');
      cout<<"Press enter to continue"<<endl;
      c=getchar();
}
void delete_students()
{
  system("clear");
    cout<<"enter roll no. of student"<<endl;
    char str[15];
    cin>>str;
    admin ad;
    ad.remove_student(str);
    cout<<"removed successfully"<<endl;
    char c;
    cin.ignore(5,'\n');
      cout<<"Press enter to continue"<<endl;
      c=getchar();
}
void view_Profile()
{
  system("clear");
    admin ad;
    ad.all_data();
}
void add_marks()
{
  system("clear");
  cout<<"enter no. of student"<<endl;
  int n;
  cin>>n;
  admin ad;
  ad.marks(n);
  cout<<"Added successfully"<<endl;
    char c;
    cin.ignore(5,'\n');
      cout<<"Press enter to continue"<<endl;
      c=getchar();
}
void login_user()
{
    system("clear");
    bool ok=false,name=false;
    char data[10],user_name[10],password[10],name_user[10];
    ifstream file("login_user.txt");
    if(!file.is_open())
    {
        cerr<<"error encountered"<<endl;
        login_user();
    }
    cout<<setw(30)<<"Username : "<<endl;
    cin>>user_name;
    while (file>>data)
    {
        if(strcmp(data,user_name)==0)
        {
            name=true;
            file>>data;
            cout<<"Name: "<<data<<endl;
            strcpy(name_user,data);
            cout<<setw(30)<<"Password : "<<endl;
            cin>>password;
            file>>data;
            if(strcmp(data,password)==0)
            {
                cout<<"login successfull"<<endl;
                ok=true;break;
            }
            else cout<<"failed"<<endl;
            break;
        }
    }
    char c;
    if(name==false){cout<<"not found"<<endl;
    cin.ignore(5,'\n');
      cout<<"Press any key"<<endl;
      c=getchar();
      return;}
    file.close();
    if(ok==true)
    {
      user_interface(user_name,name_user);
      return;
    }
}
void user_interface(char str[10],char name[15])
{
  char c;
  while(1){
        system("clear");
        cout<<"Welcome "<<name<<endl;
        cout<<setw(50)<<"[1] Data"<<endl;
        cout<<setw(51)<<"[2] Marks"<<endl;
        cout<<setw(54)<<"[3] Complain"<<endl;
        cout<<setw(53)<<"[0] Log out"<<endl;
        int t;
        cin>>t;
        student std;
        switch (t)
        {
        case 1:
        std.show_data(str);
        cin.ignore(5,'\n');
        c=getchar();
        break;
        case 2:
        std.show_marks(str); 
        cin.ignore(5,'\n');
        c=getchar();
        break;
        case 3:
        cout<<"In Progress"<<endl;
        break;
        case 0:
        return;
        default:
        cout<<"Invalid"<<endl;
        }
        }
}
