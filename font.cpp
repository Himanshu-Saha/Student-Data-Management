#include<iostream>
#include "admin.h"
using namespace std;
void Login();

int main()
{
    int n;
    while(1)
    {
        system("clear");
        cout<<setw(50)<<"WELCOME TO STUDENTS MANAGEMENT SYSTEM "<<endl<<endl;
         cout<<"------------------------------------------------------------------"<<endl;
        cout<<" This is a Simple Student Management System Developed for Educational Purpose \n using c++ . Student Management System is a basic C++ program for education establishments\n to manage student data. Student Management Systems provide capabilities for entering\n student test and other assessment scores, build student schedules, and manage many other \n student-related data needs in a school. In this Student Management System project, user \n  can create, display, search, modify and delete student record from a binary file."<<endl<<"\n\n";

        cout<<"For Login Press 1 and Enter "<<endl;
        cout<<"For Exit Press 0 and Enter " <<endl;
        cout<<"\n\n\n";
        cout<<setw(30)<<"[1] Login";
        cout<<setw(29)<<"[0] Exit"<<endl;
        try
        {
            cin>>n;
            if(n!=1 && n!=0){throw n;}
        }
        catch (int n)
        {
            cerr<<"Invalid Input"<<endl;
            continue;
        }
        switch(n)
        {
            case 0:
            exit(0);
            case 1:
            Login();
        }
    }
}
void Login()
{
    while(1)
    {
        system("clear");
        int n;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"Press 1 for login as user / Students for viewing result.........." <<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"Press 2 for login as Admin (Super User) ..............."<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"Press 3 to go to home Section................"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"Press 0 for Exit out of the program............."<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;

        cout<<"\n\n";
        cout<<setw(30)<<"[1] User"<<endl;
        cout<<setw(31)<<"[2] Admin"<<endl;
        cout<<setw(30)<<"[3] Home"<<endl;
        cout<<setw(30)<<"[0] Exit"<<endl;
        try
        {
            cin>>n;
            if(n!=1 && n!=0 && n!=2 && n!=3){throw n;}
        }
        catch (int n)
        {
            cerr<<"Invalid Input"<<endl;
            continue;
        }
        switch(n)
        {
            case 0:
            exit(0);
            case 1:
            login_user();
            Login();
            case 2:
            system("clear");
            char pwd[10];
            cout<<setw(30)<<"Admin  "<<endl;
            cout<<setw(30)<<"Password : "<<endl;
            cin>>pwd;
            if(strcmp(pwd,"a")==0)
            {
                cout<<"login successfull"<<endl;
                admin_page();
            }
            else cerr<<"invalid"<<endl;
            Login();
            case 3:
            main();
        }
    }
}
