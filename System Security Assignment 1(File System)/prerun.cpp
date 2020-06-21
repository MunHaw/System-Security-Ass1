#include "function.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "md5.h"
#include <time.h>
#include <conio.h>

using namespace std;

void txt()
{
    system("mkdir etc");
    system ("mkdir filestore");
    system("mkdir logs");
    ofstream outs;
    system("CLS");
    fstream insouts;
    insouts.open(".\\etc\\salt.txt",ios::in);
    if(!insouts)
    {
        insouts.open(".\\etc\\salt.txt",ios::out|ios::app);
    }
    insouts.close();
    insouts.open(".\\logs\\logs.txt",ios::in);
    if(!insouts)
    {
        insouts.open(".\\logs\\logs.txt",ios::out|ios::app);
    }
    insouts.close();
    insouts.open(".\\etc\\shadow.txt",ios::in);
    if(!insouts)
    {
        insouts.open(".\\etc\\shadow.txt",ios::out|ios::app);
    }
    insouts.close();
        insouts.open(".\\etc\\blacklist.txt",ios::in);
    if(!insouts)
    {
        insouts.open(".\\etc\\blacklist.txt",ios::out|ios::app);
    }
    insouts.close();
    insouts.open(".\\etc\\passwd.txt",ios::in);
    if(!insouts)
    {
        insouts.open(".\\etc\\passwd.txt",ios::out|ios::app);
    }
    insouts.close();
    insouts.open(".\\etc\\groupShadow.txt",ios::in);
    if(!insouts)
    {
        insouts.open(".\\etc\\groupShadow.txt",ios::out|ios::app);
        string x="1001";
        insouts<<x<<":normal:"<<"1234"<<endl;
        admin();
    }
    insouts.close();
    insouts.open(".\\filestore\\filestore.txt",ios::in);
    if(!insouts)
    {
        insouts.open(".\\filestore\\filestore.txt",ios::out|ios::app);
        store();
    }
    insouts.close();
    insouts.open(".\\filestore\\filestoretemp.txt",ios::out);
    insouts.close();


}

int userid()
{
    ifstream ins;
    string dump,use;
    int x;
    int able=0;
    ins.open(".\\etc\\passwd.txt");
    while(!ins.eof())
    {
        getline(ins,dump,':');
        getline(ins,dump,':');
        getline(ins,use,':');
        getline(ins,dump);
        able++;
    }
    ins.close();
        //cout<<use<<endl;

    stringstream use1(use);
    use1>>x;
    x=x+1;
    if (able<=1)
    {
        x=1001;
    }

    return x;

}

bool group_check(string id)
{
    ifstream ins;
    string id2,dump,dump1;
    int able =0;
    ins.open(".\\etc\\groupShadow.txt");
    while(!ins.eof())
    {
        getline(ins,id2,':');
        getline(ins,dump,':');
        getline(ins,dump1);
        if (id2==id)
        {
            if(id == "1001")
            {
                able =0;
                return true;
            }
            else
            {
redo:
                 int ch;
                 string passwd;

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
                if (passwd == dump1)
                {
                    able =0;
                    return true;
                }
                else
                {
                    cout<<"Wrong password"<<endl;
                    goto redo;
                }
            }
        }
        else
        {
           able++;
        }

    }
   if (able>0)
    {
        cout<<"Group dosen't exist"<<endl;
        return false;
    }

}


void admin()
{
    ofstream outs;
    outs.open(".\\etc\\groupShadow.txt",ios::app);
    string x="9999";
    outs<<x<<":root:"<<"DSS"<<endl;

}

void store()
{
    ofstream outs;
    outs.open(".\\filestore\\filestore.txt",ios::app);
    outs<<".\\filestore\\filestore.txt:root"<<endl;
    outs<<".\\etc\\passwd.txt:2"<<endl;
    outs<<".\\etc\\salt.txt:root"<<endl;
    outs<<".\\etc\\shadow.txt:root"<<endl;
    outs<<".\\logs\\logs.txt:root"<<endl;
    outs<<".\\etc\\blacklist.txt:root"<<endl;
    outs<<".\\etc\\groupShadow.txt:root"<<endl;
    outs.close();

}


