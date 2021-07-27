#include<bits/stdc++.h>
using namespace std;
class data
{
    public:
        char roll_no[10];
        char name[10];
        char branch[10];
        int year;
        
};
class mark
{
    public:
    char roll_no[10];
    int math=0,chemistry=0,oop=0,icse=0;
    int total=0; //cgpa
};
class admin:public data,mark
{
    public:
    void add_student(int i);
    void marks(int i);
    void remove_student(char str[10]);
    //void edit_data();
    void all_data();

};
class student:public data,mark
{
    public:
    void show_data(char str[10]);
    void show_marks(char str[10]);
    void complain();
};
void admin::add_student(int i)
{
    data std;
    fstream file("data.txt",ios::app);
    ofstream file1("login_user.txt",ios::app);
    while(i--)
    {
        system("clear");
        cout<<"Enter roll_no : ";
        cin>>std.roll_no;
        cout<<"Enter name : ";
        cin>>std.name;
        cout<<"Enter branch : ";
        cin>>std.branch;
        cout<<"Enter year : ";
        cin>>std.year;
        file.write((char*)&std,sizeof(std));
        file1<<std.roll_no<<" "<<setw(15)<<std.name<<" "<<std.roll_no[5]<<std.roll_no[6]<<endl;
    }
    file.close();
    file1.close();
}
void admin::marks(int j)
{
    mark academic;
    ofstream file("marks.txt",ios::app);
    while(j--){
    cout<<"roll no. : ";
    cin>>academic.roll_no;
    cout<<"maths marks : ";
    cin>>academic.math;
    cout<<"oop marks : ";
    cin>>academic.oop;
    cout<<"icse marks : ";
    cin>>academic.icse;
    cout<<"chemistry marks : ";
    cin>>academic.chemistry;
    academic.total=((academic.math)+(academic.oop)+(academic.chemistry)+(academic.icse))/4;
    file.write((char*)&academic,sizeof(academic));}
    file.close();
}
void admin::all_data()
{
    ifstream file1("data.txt");
    ifstream file2("marks.txt");
    file1.seekg(0,ios::end);
    file2.seekg(0,ios::end);
    data d;
    mark m;
    int f1=file1.tellg()/sizeof(d);
    int f2=file2.tellg()/sizeof(m);
    file1.seekg(0, ios::beg);
    file2.seekg(0, ios::beg);
    for(int i=0;i<f1;i++)
    {
        if(f1==0){
            cout<<"No data added"<<endl;
            break;
        }
        file1.read((char*)&d,sizeof(d));
        cout<<"Roll_no: "<<setw(10)<<d.roll_no<<"||  Name: "<<setw(10)<<d.name<<"||  Branch: "<<setw(6)<<d.branch<<"||  Year: "<<setw(6)<<d.year<<endl;
        for(int j=0;j<f2;j++)  
        {   
            file2.read((char*)&m,sizeof(m));
            if(strcmp(d.roll_no,m.roll_no)==0)
            {
                cout<<"Maths: "<<setw(4)<<m.math<<"||  ICSE: "<<setw(4)<<m.icse<<"||  OOP: "<<setw(4)<<m.oop<<"||  Chemistry: "<<setw(4)<<m.chemistry<<endl<<setw(15)<<"Total: "<<setw(4)<<m.total<<endl<<endl;
                break;
            }
        }
    }
    file1.close();
    file2.close();
}
void admin::remove_student(char str[10])
{
    ofstream temp("temp.txt",ios::trunc);
    if(!temp.is_open())
    {
        cerr<<"error1 ";
        return;
    }
    ifstream dat("data.txt");
    if(!dat.is_open())
    {
        cerr<<"error2 ";
        return;
    }
    data d;
    int f1=dat.tellg()/sizeof(d);
    for(int i=0;i<f1;i++)
    {
        dat.read((char*)&d,sizeof(d));
        if(strcmp(d.roll_no,str)==0){continue;}
        temp.write((char*)&d,sizeof(d));
    }
    dat.close();
    temp.close();
    int value1=remove("data.txt");
    int value2= rename("temp.txt","data.txt");
    if(value2==0)cout<<"successfully done"<<endl;
    mark m;
    ofstream temp2("temp2.txt",ios::trunc);
    if(!temp2.is_open())
    {
        cerr<<"error3 ";
        return;
    }
    ifstream mar("marks.txt");
    if(!mar.is_open())
    {
        cerr<<"error4 ";
        return;
    }
    int f2=mar.tellg()/sizeof(m);
    for(int i=0;i<f2;i++)
    {
        mar.read((char*)&m,sizeof(m));
        if(strcmp(m.roll_no,str)==0){continue;}
        temp2.write((char*)&m,sizeof(m));
    }
    mar.close();
    temp.close();
    int value3=remove("marks.txt");
    int value4= rename("temp2.txt","marks.txt");
    if(value4==0)cout<<"successfully done"<<endl;
}
void student::show_data(char str[10])
{    
    ifstream file1("data.txt");
    if(!file1.is_open())
    {
        cerr<<"error ";
        return;
    }
    file1.seekg(0,ios::end);
    data d;
    int f1=file1.tellg()/sizeof(d);
    file1.seekg(0, ios::beg);
    for(int i=0;i<f1;i++)
    {
        file1.read((char*)&d,sizeof(d));
        if(strcmp(d.roll_no,str)==0)
            {
                cout<<"Roll_no: "<<setw(10)<<d.roll_no<<"||  Name: "<<setw(10)<<d.name<<"||  Branch: "<<setw(6)<<d.branch<<"||  Year: "<<setw(6)<<d.year<<endl;
                break;
            }
    }
    file1.close();
}
void student::show_marks(char str[10])
{
    ifstream file("marks.txt");
    if(!file.is_open())
    {
        cerr<<"error10 ";
        return;
    }
    file.seekg(0,ios::end);
    mark m;
    int f1=file.tellg()/sizeof(m);
    file.seekg(0, ios::beg);
    for(int i=0;i<f1;i++)
    {
        file.read((char*)&m,sizeof(m));
        if(strcmp(m.roll_no,str)==0)
            {
                cout<<"Maths: "<<setw(4)<<m.math<<"||  ICSE: "<<setw(4)<<m.icse<<"||  OOP: "<<setw(4)<<m.oop<<"||  Chemistry: "<<setw(4)<<m.chemistry<<endl<<setw(15)<<"Total: "<<setw(4)<<m.total<<endl;
                break;
            }
    }
    file.close();
}
