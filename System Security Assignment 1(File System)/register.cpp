#include <iostream>
#include <fstream>
#include "function.h"
#include <ctime>
#include <conio.h>
#include <string>
#include "md5.h"
using namespace std;


void reg()
{
    attempt_reg();
    ifstream infile;
    ofstream outs;
    string name,line,salt,des,group;
    string passwd;

    int able;
    cout<<"Username: ";

    cin>>name;
    infile.open(".\\etc\\salt.txt");
    while(!infile.eof())
    {
        getline(infile,line,':');
        getline(infile,salt);
        if (name ==line)
        {
            able++;
            break;
        }

        else
        {
            able =0;
        }

    }
    infile.close();
    if (able <=0)
    {
        wrong:
        if (capTCHA()==true)
        {
            do
            {
                passwd ="";
                getPass(passwd);
            }while (testPass(passwd) != true);

            while (getPass2(passwd)!=true)
            {
                cout<<"\nPassword dosen't match"<<endl;
            }
        }
        else
        {
            cout<<"Wrong Captcha"<<endl;
            goto wrong;
        }

        cout<<"Enter user description: ";
        cin.ignore();
        getline(cin,des);

    do
    {
        cout<<"Enter group id(if you dont have one just enter 1001): ";
        cin>>group;
    }while (group_check(group)!=true);


    }

    else
    {
        cout<<"Username already exist"<<endl;
        option();
    }

    saltfunC(name,salt);
    outs.open(".\\etc\\salt.txt",ios::app);
    outs<<name<<":"<<salt<<endl;
    outs.close();
    outs.open(".\\etc\\shadow.txt",ios::app);
    outs<<name<<":"<<md5(passwd+salt)<<":2"<<endl;
    outs.close();
    outs.open(".\\etc\\passwd.txt",ios::app);
    outs<<name<<":x:"<<userid()<<":"<<group<<":"<<des<<":.\\home\\"<<name<<":bin/bash"<<endl;
    outs.close();
    string file;
    file ="mkdir .\\home\\"+name;
    system(file.c_str());
    system("CLS");
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"User "<<name<<" have been created with user clearance 2"<<endl;
    cout<<"User "<<name<<" directory is located at .\\home\\"<<name<<endl;
    success_reg(name);
    cin.ignore();
}



void saltfunC(string name, string &salt)
{
    salt="";
    ofstream outs;
    static const char alphanum[] = "0123456789";

    int stringLength = sizeof(alphanum)-1;
    srand(time(0));
    for(unsigned int i = 0; i < 8; ++i)
    {
        salt += alphanum[rand() % stringLength];
    }
}

void getPass(string &passwd)
{
    int ch;

    cout<<"\nEnter password: "<<endl;
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
}

bool getPass2 (string passwd1)
{
    string passwd;
    int ch;

    cout<<"\nEnter password again: "<<endl;
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
    if (passwd1 == passwd)
        return true;
    else
        return false;

}


bool testPass(string pass)
{
	int x =0;
	bool aUpper = false,
		 aLower = false,
		 aDigit = false,
		 aCtrl = true,
		 aLength = false,
		 aSpecial = false; //!@#$%^&*()
	for ( int i = 0 ; i<pass.length() ; i++ )
    {
        if ( isupper(pass[i]) )
            aUpper = true ;
        else if ( islower(pass[i]) )
			aLower = true ;
        else if ( isdigit(pass[i]) )
			aDigit = true ;
        else if (iscntrl(pass[i])  )
            aCtrl =false;
        else if (ispunct(pass[i])  )
            aSpecial =true;

        x++;
    }
    if (x==8)
    {
        aLength = true;
    }
    if ( aUpper && aLower && aDigit &&aCtrl && aLength &&  aSpecial)
		return true;
	else
		return false ;
}
