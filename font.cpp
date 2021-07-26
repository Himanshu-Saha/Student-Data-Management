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
        cout<<setw(50)<<"WELCOME"<<endl<<endl;
        cout<<setw(30)<<"[1] Login"<<endl;
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