#include<bits/stdc++.h>
using namespace std;
void login_user()
{
    bool ok=false,name=false;
    char data[10],user_name[10],password[10];
    ifstream file("user_ID.txt");
    if(file.is_open())
    {
        cerr<<"error encountered"<<endl;
        exit(0);
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
    if(name==false){cout<<"not found"<<endl;return;}
    file.close();
    if(ok==true)
    {
        cout<<setw(50)<<"[1] Data"<<endl;
        cout<<setw(50)<<"[3] Marks"<<endl;
        cout<<setw(50)<<"[4] Complain"<<endl;
        cout<<setw(30)<<"[5] Log out"<<endl;
        cout<<setw(29)<<""<<endl;
        int t;
        cin>>t;
        switch (t--)
        {
        case 1:
        void show_data();  
        case 2:
        void edit_data();  
        case 3:
        void marks(); 
        case 4:
        void complain();   
        case 5:
        return; 
        }
    }
}