#include "function.h"
#include <iostream>
#include "md5.h"
#include <fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;



string user, line , salt;

void logUser()
{
    int able;
    ifstream infile;
    ofstream input;
    string name2;

    able =0;
    cout<<"Enter username: ";
    cin>> user;
    attempt_log(user);

    infile.open(".\\etc\\blacklist.txt");
    while(!infile.eof())
    {
        getline(infile,name2);
        if (user ==name2)
        {
            cout<<"User "<<user<<" have been locked please contact admin to unlock."<<endl;
            cin.ignore();
            option();
        }
    }
    infile.close();


    infile.open(".\\etc\\salt.txt");
    while(!infile.eof())
    {
        getline(infile,line,':');
        getline(infile,salt);
        if (user ==line)
        {
            salt =salt;
            able ++;
            break;
        }
    }
    infile.close();
    if (able <=0)
    {
        cout<<"User Not Found"<<endl;
        cin.ignore();
        option();
    }



    if(capTCHA()==true)
    {
        logPass();
    }
    else
    {
        cout<<"wrong captcha"<<endl;
        option();
    }


}

void logPass ()
{
    ifstream infile;
    ofstream input;
    string dump, shadow1,userc;
    int able2=0,able =0;
pass:
    string shadow="";
    string passwd="";
    int ch;
    cout<<"Enter password: \n";
    while(ch=getch())
    {
        if (ch == 13)///check if user press RETURN key
        {
            break;
        }
        else if (ch==8)
        {
            if(passwd.length()>0)
            {
                cout<<"\b \b";
                passwd.erase(passwd.length()-1);
            }
        }
        else
        {
            cout<<"";
            passwd+= ch;
        }
    }
    shadow = md5(passwd+salt);


    infile.open(".\\etc\\shadow.txt");
    while(!infile.eof())
    {
        getline(infile,dump,':');
        getline(infile,shadow1,':');
        getline(infile,userc);

        if (shadow==shadow1)
        {
            if(root()==true)
            {
                system("CLS");
                cout<<user<<" are root user"<<endl;
                cout<<"\n"<<user<<" found in salt.txt and shadow.txt"<<endl;
                cout<<"Salt retrieved: "<<salt<<endl;
                cout<<"Hash value: "<<shadow1<<endl;
                able2=0;
                cout<<"\nAuthentication for user "<<user<<" complete."<<endl;
                cout<<"The clearance for "<<user<<" is root."<<endl;
                success_log(user);
                root_home(user,userc);
                break;
            }
            else
            {
                system("CLS");
                cout<<"\n"<<user<<" found in salt.txt and shadow.txt"<<endl;
                cout<<"Salt retrieved: "<<salt<<endl;
                cout<<"Hash value: "<<shadow1<<endl;
                able2=0;
                cout<<"\nAuthentication for user "<<user<<" complete."<<endl;
                cout<<"The clearance for "<<user<<" is "<<userc<<"."<<endl;
                success_log(user);
                home(user,userc);
                break;
            }

        }
        else
            able2++;
    }
    infile.close();
    if (able2>0)
    {
        cout<<"Incorrect password"<<endl;
        able++;

    }
    if (able >=3)
    {
        cout<<"User "<<user<<" have been locked please contact admin to unlock."<<endl;
        input.open(".\\etc\\blacklist.txt",ios::app);
        input<<user<<endl;
        cin.ignore();
        lock_acc(user);
        option();
    }
    else if (able >0&& able<=2)
        goto pass;


}

bool root()
{
    ifstream ins,ifs;
    string dump,group,group2,name2;
    ins.open(".\\etc\\groupShadow.txt");
    ifs.open(".\\etc\\passwd.txt");
    while(!ifs.eof())
    {
        getline(ifs,name2,':');
        getline(ifs,dump,':');
        getline(ifs,dump,':');
        getline(ifs,group2,':');
        getline(ifs,dump);
        if(name2 == user)
        {
            if (group2=="9999")
            {
                return true;
            }
            else
                return false;
        }
    }

}


