#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstring>
#include "function.h"
#include "md5.h"
using namespace std;

void root_home(string name,string userc)
{
start:
    string ans;
    cout<<"\n---------------------menu------------------------"<<endl;
    cout<<"(C)reate, (R)ead, (W)rite, (L)ist,(S)ave,(G)roup, "<<endl;
    cout<<"(B)lackList, (U)serClearance or (E)xit.";
    cout<<"\n---------------------menu------------------------"<<endl;
start2:
    cout<<name<<"~$:";
    cin>>ans;

    if (ans == "c" || ans =="C")
        root_create(name,userc);
    else if (ans == "c" || ans =="C")
        root_write(name,userc);
    else if (ans =="e" ||ans =="E")
        root_ex(name,userc);
    else if (ans=="r"||  ans=="R")
        root_read(name,userc);
    else if (ans=="s"||  ans=="S")
        root_Save(name,userc);
    else if (ans=="l"||  ans=="L")
        root_list_file(name,userc);
    else if (ans=="U"||ans =="u")
        userClearance(name,userc);
    else if (ans=="B"||ans =="b")
        blacklist(name,userc);
    else if (ans=="G"||ans =="g")
        group(name,userc);
    else if (ans=="W"||ans =="w")
        root_write(name,userc);
    else if (ans =="?")
    {
        root_help();
        goto start2;
    }
    else if (ans == "clear")
    {
        system("CLS");
        goto start;
    }

    else
    {
        cout<<"Having problem to access? type '?' show help "<<endl;
        goto start;
    }

}



void group(string name, string userc)
{
    ifstream ins;
    ofstream outs;
    int  id3, able10=0,able11=0;
    string id,dump,name2, ans,ans2,userans,id2;
    ins.open(".\\etc\\groupShadow.txt");
    cout<<"\n===============group================"<<endl;
    cout<<"ID\t\tGroup Name"<<endl;
    cout<<"-------------------------------------"<<endl;
    while(!ins.eof())
    {
        getline(ins,id,':');
        getline(ins,name2,':');
        getline(ins,dump);
        if(id !="")
            cout<<id<<"\t\t"<<name2<<endl;
    }
    ins.close();
start:
    cout<<"===================================="<<endl;
    cout<<"\nDo you want to make any changes((Y)es or(N)o): ";
    cin>>ans;
    if (ans =="y"||ans=="Y")
    {
start2:
        cout<<"(1)add group\n(2)add user to group\n(H)ome\n"<<name<<"~$: ";
        cin>>ans2;
        if (ans2 =="1")
        {
            int temp=0;
            string temp_g,pass;
            cout<<"Enter group id: ";
            cin>>id3;
            id2 = to_string(id3);
            ins.open(".\\etc\\groupShadow.txt");
            while(!ins.eof())
            {
                getline(ins,id,':');
                getline(ins,dump);
                if(id2!=id)
                {
                    temp ++;
                }
                else if (id2 ==id)
                {
                    temp=0;
                    cout<<"Group already exist"<<endl;
                    break;
                }
            }
            if (temp>0)
            {
                cout<<"Enter group name: ";
                cin>>temp_g;
                cout<<"Enter password for group: ";
                cin>>pass;
                outs.open(".\\etc\\groupShadow.txt",ios::app);
                outs<<id3<<":"<<temp_g<<":"<<pass<<endl;
                outs.close();
            }
        ins.close();
        root_home(name,userc);
        }
        else if (ans2 =="2")
        {
            string user20,dump20,dump21,dump22,group20,userans20,groupans20;

            ins.open(".\\etc\\passwd.txt");
            cout<<"\n========================================"<<endl;
            while(!ins.eof())
            {
                getline(ins,user20,':');
                getline(ins,dump20,':');
                getline(ins,dump20,':');
                getline(ins,group20,':');
                getline(ins,dump20);
                if(user20 !="")
                    cout<<user20<<" is currently at group "<<group20<<endl;
            }
            ins.close();
            cout<<"========================================"<<endl;
start20:
            cout<<"\nDo you want to make any changes((Y)es or(N)o): ";
            cin>>ans;
            outs.open(".\\etc\\passwdtemp.txt");
            outs.close();
            if(ans=="y"||ans=="Y")
            {
                cout<<"Enter username that you which to change his group: ";
                cin>>userans20;
                ins.open(".\\etc\\passwd.txt");
                while(!ins.eof())
                {
                    getline(ins,user20,':');
                    getline(ins,dump20,':');
                    getline(ins,dump21,':');
                    getline(ins,group20,':');
                    getline(ins,dump22);
                    if (userans20 ==user20)
                    {
                        able10=0;
start21:                able11++;
                        cout<<"Enter group id: ";
                        cin>>groupans20;
                        if(group_check(groupans20) == true)
                        {
                            outs.open(".\\etc\\passwdtemp.txt",ios::app);
                            outs<<userans20<<":"<<dump20<<":"<<dump21<<":"<<groupans20<<":"<<dump22<<endl;
                            outs.close();
                            cout<<"Change completed"<<endl;
                            cout<<"User "<<userans20<<" is now at group "<<groupans20<<endl;
                            group_log(name);
                            chgroup_acc(name,userans20);
                        }
                        else
                            goto start21;
                    }
                    else if (user20!="")
                    {
                        able10++;
                        outs.open(".\\etc\\passwdtemp.txt",ios::app);
                        outs<<user20<<":"<<dump20<<":"<<dump21<<":"<<group20<<":"<<dump22<<endl;
                        outs.close();
                    }
                }
                if(able10>0)
                {
                    if(able11>0)
                        able10=0;
                    else
                        cout<<"Username dose't exist"<<endl;
                }

            }

            else if (ans=="n"|| ans=="N")
            {
                root_home(name,userc);
            }
            else
            {
                cout<<"Invalid option"<<endl;
                goto start20;
            }
        ins.close();
        transfer("pass");
        root_home(name,userc);
        }
        else if (ans2 =="H" ||ans2=="h")
        {
            root_home(name,userc);
        }
        else
        {
            cout<<"Invalid option"<<endl;
            goto start2;
        }
    }
    else if (ans=="n"|| ans=="N")
    {
        root_home(name,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto start;
    }
}

void blacklist(string name,string userc)
{
    ifstream ins;
    ofstream outs;
    int able;
    string user2, ans,userans;
    ins.open(".\\etc\\blacklist.txt");
    cout<<"\n===============blacklist================"<<endl;
    while(!ins.eof())
    {
        getline(ins,user2);
        if(user2 !="")
            cout<<user2<<" is banned."<<endl;
    }
    ins.close();
start:
    cout<<"========================================"<<endl;
    cout<<"\nDo you want to make any changes((Y)es or(N)o): ";
    cin>>ans;
    if(ans=="y"||ans=="Y")
    {
        outs.open(".\\etc\\blacklisttemp.txt");
        outs.close();
        ins.open(".\\etc\\blacklist.txt");
        cout<<"Enter username that you wish to unban: ";
        cin>>userans;
        while(!ins.eof())
        {
            getline(ins,user2);
            if(userans == user2)
            {
                able=0;
                outs.open(".\\etc\\blacklisttemp.txt",ios::app);
                outs<<""<<endl;
                outs.close();
                cout<<"Changes completed."<<endl;
                cout<<"User "<<user2<<" have been unbanned."<<endl;
                unban_acc(name,userans);
            }
            else
            {
                if(user2 !="")
                {
                    able++;
                    outs.open(".\\etc\\blacklisttemp.txt",ios::app);
                    outs<<user2<<endl;
                    outs.close();
                }
            }
        }
        if (able>0)
        {
            cout<<"User dosen't exist."<<endl;
        }
        ins.close();
        transfer("blacklist");
        root_home(name,userc);
    }
    else if (ans=="n"|| ans=="N")
    {
        root_home(name,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto start;
    }

}

void userClearance(string name,string userc)
{
    ifstream ins;
    ofstream outs;
    int able,able2=0;
    string userc2,user, dump,ans,userans,clearans;
    ins.open(".\\etc\\shadow.txt");
    cout<<"\n========================================"<<endl;
    while(!ins.eof())
    {
        getline(ins,user,':');
        getline(ins,dump,':');
        getline(ins,userc2);
        if(user !="")
            cout<<user<<" with user clearance "<<userc2<<endl;
    }
    ins.close();
start:
    cout<<"========================================";
    cout<<"\nDo you want to make any changes((Y)es or(N)o): ";
    cin>>ans;
    if(ans=="y"||ans=="Y")
    {
        outs.open(".\\etc\\shadowtemp.txt");
        outs.close();
        cout<<"Enter username: ";
        cin>>userans;
        ins.open(".\\etc\\shadow.txt");
        while(!ins.eof())
        {
            getline(ins,user,':');
            getline(ins,dump,':');
            getline(ins,userc2);

            if(userans == user)
            {
                able=0;
                cout<<"Which user clearance do you want to change for "<<userans<<": ";
                cin>>clearans;
                outs.open(".\\etc\\shadowtemp.txt",ios::app);
                outs<<userans<<":"<<dump<<":"<<clearans<<endl;
                outs.close();
                cout<<"Changes completed."<<endl;
                cout<<"User "<<userans<<" is now with user clearance "<<clearans<<endl;
                chuserc_acc(name,userans);
                able2++;
            }
            else
            {
                if(user !="")
                {
                    able++;
                    outs.open(".\\etc\\shadowtemp.txt",ios::app);
                    outs<<user<<":"<<dump<<":"<<userc2<<endl;
                    outs.close();
                }

            }
        }
    if (able>0)
    {
        if (able2>0)
            able=0;
        else
            cout<<"User dosen't exist."<<endl;
    }

    ins.close();
    transfer("shadow");
    root_home(name,userc);
    }
    else if (ans=="n"|| ans=="N")
    {
        root_home(name,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto start;
    }
}

void transfer(string op)
{
    ofstream outs;
    ifstream ins;
    string read;
    if (op == "shadow")
    {
        outs.open(".\\etc\\shadow.txt",ios::out);
        ins.open(".\\etc\\shadowtemp.txt");
        while(!ins.eof())
        {
            getline(ins,read);
            if (read!="")
                outs<<read<<endl;
        }
    ins.close();
    outs.close();
    system("chdir .\\etc &&del shadowtemp.txt");
    }

    else if (op == "blacklist")
    {
        outs.open(".\\etc\\blacklist.txt",ios::out);
        ins.open(".\\etc\\blacklisttemp.txt");
        while(!ins.eof())
        {
            getline(ins,read);
            if (read!="")
                outs<<read<<endl;
        }
    ins.close();
    outs.close();
    system("chdir .\\etc &&del blacklisttemp.txt");


    }
    else if (op == "pass")
    {
        outs.open(".\\etc\\passwd.txt",ios::out);
        ins.open(".\\etc\\passwdtemp.txt");
        while(!ins.eof())
        {
            getline(ins,read);
            if (read!="")
                outs<<read<<endl;
        }
    ins.close();
    outs.close();
    system("chdir .\\etc &&del passwdtemp.txt");


    }


}

void root_list_file(string name, string userc)
{
    ifstream ifs;
    string dir,userc1;
    ifs.open(".\\filestore\\filestore.txt");
    while(!ifs.eof())
    {
        getline(ifs,dir,':');
        getline (ifs,userc1);
        cout<<dir<<endl;
    }
    root_home(name,userc);
}

void root_read(string name1, string userc)
{
    ifstream ins,ifs;
    string name,search_name,temp, ans,ansdir,ansdir1,ansdir2,ans3,dir,ansuc;
    int able10=0;
start:
    cout<<"You are currently at .\\home\\"<<name1<<endl;;
    cout<<"(1)Do you want to read outside of your home directory\n(2)Do you want to read inside of your home directory";
    cout<<"\n(3)Back to home"<<endl;
    cout<<name1<<"~$ ";
    cin>>ans;
    if (ans=="1")
    {
        system("DIR | find \"DIR\" ");
        cout<<"According to above choose a directory to go: ";
        cin>>ansdir2;
        do
        {
start10:
            cout<<"Do you want to continue(next directory): ";
            cin>>ans3;
            if (ans3 =="Y" ||ans3 =="y")
            {
                ansdir1 = "chdir .\\"+ansdir2+" && DIR | find \"DIR\" ";
                system(ansdir1.c_str());
                cout<<"According to above choose a directory to go: ";
                cin>>ansdir;
                ansdir2=ansdir2+"\\"+ansdir;
            }
            else if (ans3 =="N" ||ans3 =="n")
            {
                cout<<"Enter Filename: ";
                cin.ignore();
                getline(cin,name);
                search_name =".\\"+ansdir2+"\\"+name+".txt";
                ins.open(search_name);
                ifs.open(".\\filestore\\filestore.txt");
                while(!ifs.eof())
                {
                    getline(ifs,dir,':');
                    getline(ifs,ansuc);
                    if (dir!=search_name)
                    {
                        able10++;
                    }
                    else
                    {
                        cout<<"======================="<<endl;
                        cout<<"start of the file"<<endl;
                        cout<<"======================="<<endl;
                        while(!ins.eof())
                        {
                            getline(ins,temp);
                            cout<<temp<<endl;
                        }
                        cout<<"======================="<<endl;
                        cout<<"end of the file"<<endl;
                        cout<<"======================="<<endl;
                        read_log(name1);
                        ifs.close();
                        ins.close();
                        root_home(name1,userc);
                    }
                }
                if(able10>0)
                {
                    cout<<"File doesn't exist."<<endl;
                    ifs.close();
                    ins.close();
                    root_home(name1,userc);
                }
            }
            else
            {
                cout<<"Invalid option"<<endl;
                ifs.close();
                ins.close();
                goto start10;
            }
        }while (ans3 =="Y" ||ans3 =="y");


    }
    else if (ans =="2")
    {
        cout<<"File Name: ";
        cin.ignore();
        getline(cin,name);
        search_name = ".\\home\\"+name1+"\\"+name+".txt";
        ins.open(search_name);
        ifs.open(".\\filestore\\filestore.txt");
        while(!ifs.eof())
        {
            getline(ifs,dir,':');
            getline(ifs,ansuc);
            if (dir!=search_name)
            {
                able10++;
            }
            else
            {
                cout<<"======================="<<endl;
                cout<<"start of the file"<<endl;
                cout<<"======================="<<endl;
                while(!ins.eof())
                {
                    getline(ins,temp);
                    cout<<temp<<endl;
                }
                cout<<"\n======================="<<endl;
                cout<<"end of the file"<<endl;
                cout<<"======================="<<endl;
                read_log(name1);
                root_home(name1,userc);
            }
        }
        if(able10>0)
        {
            cout<<"File doesn't exist."<<endl;
            ifs.close();
            ins.close();
            root_home(name1,userc);
        }
    }
    else if (ans =="3")
    {
        ifs.close();
        ins.close();
        root_home(name1,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto start;
    }


    ins.close();
}


void root_Save (string name,string userc)
{
    ifstream ins;
    ofstream ofs;
    string temp;
    int x=0;
    ins.open(".\\filestore\\filestoretemp.txt");
    while(!ins.eof())
    {
        getline(ins,temp);
        if (temp !="")
        {
            ofs.open(".\\filestore\\filestore.txt",ios::app);
            ofs<<temp<<endl;
            cout<<"File ("<<temp<<") is already saved."<<endl;
            save_log(name);
            x++;
            ofs.close();
        }
    }
    if (x==0)
        cout<<"There is nothing to be save."<<endl;

    ofs.open(".\\filestore\\filestoretemp.txt");
    ofs.close();
    ins.close();
    root_home(name,userc);



}

void root_ex(string name,string userc)
{
    string ans;
    ifstream ins;
    string dump;
    int x=0;
    ins.open(".\\filestore\\filestoretemp.txt");
    while(!ins.eof())
    {
        getline(ins,dump);
        x++;
    }
    if (x>1)
    {
start:
        cout<<"There are file havent been save.Are you sure you want to shut down the FileServer? (S)ave, (Y)es or (N)o";
        cin>>ans;
        if (ans =="y"||ans =="Y")
        {
            close_system();
            exit (0);
        }
        else if (ans =="n"||ans=="N")
        {
            root_home(name,userc);
        }
        else if(ans=="s"||ans=="S")
        {
            root_Save(name,userc);
        }
        else
        {
            cout<<"Invalid option";
            goto start;
        }
    }
    else
    {
        cout<<"Shut down the FileServer? (Y)es or (N)o";
        cin>>ans;
        if (ans =="y"||ans =="Y")
        {
            close_system();
            exit (0);
        }
        else if (ans =="n"||ans=="N")
        {
            root_home(name,userc);
        }
    }


}

void root_write(string name1, string userc)
{
    string name,name2,dir,filec,search_name;
    ofstream ofs;
    ifstream ifs;
    string temp, ans,ansdir,ansdir1,ansdir2,ans3;
start:
    cout<<"You are currently at .\\home\\"<<name1<<endl;;
    cout<<"(1)Do you want to write outside of your home directory\n(2)Do you want to write inside of your home directory";
    cout<<"\n(3)Back to home"<<endl;
    cout<<name1<<"~$ ";
    cin>>ans;
    if (ans=="1")
    {
        system("DIR | find \"DIR\" ");
        cout<<"According to above choose a directory to go: ";
        cin>>ansdir2;
        do
        {
start10:
            cout<<"Do you want to continue(next directory): ";
            cin>>ans3;
            if (ans3 =="Y" ||ans3 =="y")
            {
                ansdir1 = "chdir .\\"+ansdir2+" && DIR | find \"DIR\" ";
                system(ansdir1.c_str());
                cout<<"According to above choose a directory to go: ";
                cin>>ansdir;
                ansdir2=ansdir2+"\\"+ansdir;
            }
            else if (ans3 =="N" ||ans3 =="n")
            {
                int able1=0;
                cout<<"Enter Filename: ";
                cin.ignore();
                getline(cin,name);
                search_name =".\\"+ansdir2+"\\"+name+".txt";
                ifs.open(".\\filestore\\filestore.txt");
                while(!ifs.eof())
                {
                        getline(ifs,dir,':');
                        getline(ifs,filec);
                        if(search_name == dir)
                        {
                            name2 = "chdir .\\"+ ansdir2+ " && notepad "+ name;
                            system(name2.c_str());
                            able1 =0;
                            write_log(name1);
                            cout<<"File written complete"<<endl;
                            root_home(name1, userc);
                        }
                        else
                        {
                            able1++;
                        }
                }
                        if(able1>0)
                    {
                        cout<<"File dosen't exist"<<endl;
                        root_home(name1,userc);
                    }
            }
            else
            {
                cout<<"Invalid option"<<endl;
                goto start10;
            }
        }while (ans3 =="Y" ||ans3 =="y");


    }
    else if (ans =="2")
    {
         int able1;
        cout<<"Notepad Name: ";
        cin.ignore();
        getline(cin,name);
        search_name = ".\\home\\"+name1+"\\"+name+".txt";
        ifs.open(".\\filestore\\filestore.txt");
        while(!ifs.eof())
        {

                getline(ifs,dir,':');
                getline(ifs,filec);
                if(search_name == dir)
                {
                    name2 = "chdir .\\home\\"+name1 + " && notepad "+ name;
                    system(name2.c_str());
                    able1 =0;
                    write_log(name1);
                    cout<<"File written complete"<<endl;
                    root_home(name1, userc);
                }
                else
                {
                    able1++;
                }
        }
                    if(able1>0)
            {
                cout<<"File dosen't exist"<<endl;
                root_home(name1,userc);
            }
    }
    else if (ans=="3")
    {
        root_home(name1,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto start;
    }

}

void root_create(string name1,string userc)
{
    string name,name2,dir,filec,search_name;
    ofstream ofs;
    ifstream ifs;
    string temp, ans,ansdir,ansdir1,ansdir2,ans3;
start:
    cout<<"You are currently at .\\home\\"<<name1<<endl;;
    cout<<"(1)Do you want to create outside of your home directory\n(2)Do you want to create inside of your home directory";
    cout<<"\n(3)Back to home"<<endl;
    cout<<name1<<"~$ ";
    cin>>ans;
    if (ans=="1")
    {
        system("DIR | find \"DIR\" ");
        cout<<"According to above choose a directory to go: ";
        cin>>ansdir2;
        do
        {
start10:
            cout<<"Do you want to continue(next directory): ";
            cin>>ans3;
            if (ans3 =="Y" ||ans3 =="y")
            {
                ansdir1 = "chdir .\\"+ansdir2+" && DIR | find \"DIR\" ";
                system(ansdir1.c_str());
                cout<<"According to above choose a directory to go: ";
                cin>>ansdir;
                ansdir2=ansdir2+"\\"+ansdir;
            }
            else if (ans3 =="N" ||ans3 =="n")
            {
                cout<<"Enter Filename: ";
                cin.ignore();
                getline(cin,name);
                search_name =".\\"+ansdir2+"\\"+name+".txt";
                ifs.open(".\\filestore\\filestore.txt");
                    while(!ifs.eof())
                    {
                        getline(ifs,dir,':');
                        getline(ifs,filec);
                        if(search_name == dir)
                        {
                            cout<<"File already exist"<<endl;
                            root_home(name1, userc);
                        }
                    }
                name2 = "chdir .\\"+ansdir2 +" && notepad " + name;
                system(name2.c_str());
                ofs.open(".\\filestore\\filestoretemp.txt",ios::app);
                ofs<<search_name<<":"<<userc<<endl;
                create_log(name1);
                root_home(name1, userc);
            }
            else
            {
                cout<<"Invalid option"<<endl;
                goto start10;
            }
        }while (ans3 =="Y" ||ans3 =="y");


    }
    else if (ans =="2")
    {
        cout<<"Notepad Name: ";
        cin.ignore();
        getline(cin,name);
        search_name = ".\\home\\"+name1+"\\"+name+".txt";
        ifs.open(".\\filestore\\filestore.txt");
        {
            while(!ifs.eof())
            {
                getline(ifs,dir,':');
                getline(ifs,filec);
                if(search_name == dir)
                {
                    cout<<"File already exist"<<endl;
                    root_home(name1, userc);
                }
            }
        }
        name2 = "chdir .\\home\\"+name1+" && notepad " + name;
        system(name2.c_str());
        ofs.open(".\\filestore\\filestoretemp.txt",ios::app);
        ofs<<".\\home\\"<<name1<<"\\"<<name<<".txt:"<<userc<<endl;
        create_log(name1);
        root_home(name1, userc);
    }
    else if (ans=="3")
    {
        root_home(name1,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto start;
    }



}
