#include <iostream>
#include <stdlib.h>
#include"function.h"
#include <fstream>
#include <string>
using namespace std;

void home(string name,string userc)
{
    string ans;
start:
    cout<<"\n-------------------------------------------------"<<endl;
    cout<<"(C)reate, (R)ead, (W)rite, (L)ist,(S)ave or (E)xit.";
    cout<<"\n-------------------------------------------------"<<endl;
start2:
    cout<<name<<"~$ ";
    cin>>ans;
    if (ans == "c" || ans =="C")
    {
        if (userc =="0")
        {
            create1(name,userc);
        }
        else
            create(name,userc);
    }
    else if (ans =="e" ||ans =="E")
        ex(name,userc);
    else if (ans=="r"||  ans=="R")
    {
        if (userc =="2")
        {
            read(name,userc);
        }
        else
            read1(name,userc);
    }
    else if (ans=="s"||  ans=="S")
        Save(name,userc);
    else if (ans=="l"||  ans=="L")
        list_file(name,userc);
    else if (ans =="w" || ans =="W")
    {
        if (userc =="0")
        {
            write1(name,userc);
        }
        else
            write(name,userc);
    }
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

}


void list_file(string name, string userc)
{
    ifstream ifs ;
    int able =0,usercI = stoi(userc),ucInt;
    string dir,userc1;
    ifs.open(".\\filestore\\filestore.txt");
    cout<<"================================="<<endl;
    while(!ifs.eof())
    {
        getline(ifs,dir,':');
        getline (ifs,userc1);
        if(userc1 != "root")
        {
            ucInt = stoi(userc1);
            if (usercI<=ucInt)
            {
                if(dir!="")
                {
                    able =0;
                    cout<<dir<<endl;
                }
            }
            else
            {
                able++;
            }
        }
    }
    if (able>0)
    {
        cout<<"There is nothing to be read"<<endl;
    }
    cout<<"================================="<<endl;
    home(name,userc);
}

void read(string name1, string userc)
{
    ifstream ins,ifs;
    string name,name2,dir,filec,search_name;
    int usercI = stoi(userc),ucInt, able10=0;
    string temp, ans,ansdir,ansdir1,ansdir2,ans3,ansuc;
    cout<<"You are currently at .\\home\\"<<name1<<endl;;
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
        if (dir != search_name)
        {
            able10++;
        }
        else
        {

            if(ansuc != "root")
            {
                ucInt = stoi(ansuc);
                if(search_name == dir)
                {
                    if(usercI <= ucInt)
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
                        ifs.close();
                        ins.close();
                        home(name1,userc);
                    }
                    else
                    {
                        cout<<"File level is higher than your user clerance."<<endl;
                        ifs.close();
                        ins.close();
                        home(name1,userc);
                    }
                }
            }
        }
    }
    if (able10>0)
    {
        cout<<"File is not exist."<<endl;
        ifs.close();
        ins.close();
        home(name1,userc);
    }
}

void create(string name1,string userc)
{
    string name,name2,dir,filec,search_name;
    ofstream ofs;
    ifstream ifs;
    string temp, ans,ansdir,ansdir1,ansdir2,ans3;

    cout<<"Notepad Name: ";
    cin.ignore();
    getline(cin,name);
    search_name = ".\\home\\"+name1+"\\"+name+".txt";
    ifs.open(search_name);
    if (ifs.good())
    {
        cout<<"File already exist."<<endl;
        home(name1,userc);
    }
    ifs.close();

    ifs.open(".\\filestore\\filestore.txt");
    {
        while(!ifs.eof())
        {
            getline(ifs,dir,':');
            getline(ifs,filec);

        }
    }
    name2 = "chdir .\\home\\"+name1+" && notepad " + name;
    system(name2.c_str());
    ofs.open(".\\filestore\\filestoretemp.txt",ios::app);
    create_log(name1);
    ofs<<".\\home\\"<<name1<<"\\"<<name<<".txt:"<<userc<<endl;
    home(name1, userc);
}

void Save (string name,string userc)
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
            cout<<"File ("<<temp<<") is already saved."<<endl;
            save_log(name);
            ofs.open(".\\filestore\\filestore.txt",ios::app);
            ofs<<temp<<endl;
            ofs.close();
            x++;
        }
    }
    if (x==0)
        cout<<"There is nothing to be save."<<endl;
    ins.close();
    ofs.open(".\\filestore\\filestoretemp.txt");
    ofs.close();
    home(name,userc);



}

void ex(string name,string userc)
{
    string ans,dump;
    int x=0;
    ifstream ins;
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
            home(name,userc);
        }
        else if(ans=="s"||ans=="S")
        {
            Save(name,userc);
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
            home(name,userc);
        }
    }

}


void read1(string name1, string userc)
{
    string name,name2,dir,filec,search_name;
    int usercI = stoi(userc),ucInt, able10=0;
    string temp, ans,ansdir,ansdir1,ansdir2,ans3,ansuc;
    ifstream ins,ifs;
Start:
    cout<<"\nAs a user with clearance "<<userc<<" you are able to read"<<endl;
    cout<<"=============="<<endl;
    ins.open(".\\filestore\\filestore.txt");
    while(!ins.eof())
    {
        getline(ins,dir,':');
        getline(ins,ansuc);
        if(ansuc != "root" )
        {
            ucInt = stoi(ansuc);
            if(usercI <= ucInt)
            {
                cout<<dir<<endl;
            }
        }
    }
    cout<<"=============="<<endl;
    ins.close();
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
                search_name = ".\\"+ansdir2+"\\"+name+".txt";
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
                        if(ansuc != "root")
                        {
                            ucInt = stoi(ansuc);
                            if(search_name == dir)
                            {
                                if(usercI <= ucInt)
                                {
                                    cout<<"======================="<<endl;
                                    cout<<"start of the file"<<endl;
                                    cout<<"======================="<<endl;
                                    while(!ins.eof())
                                    {
                                        getline(ins,temp);
                                        if(temp!="")
                                            cout<<temp<<endl;
                                    }
                                    cout<<"======================="<<endl;
                                    cout<<"end of the file"<<endl;
                                    cout<<"======================="<<endl;
                                    read_log(name1);
                                    ifs.close();
                                    ins.close();
                                    home(name1,userc);
                                }
                                else
                                {
                                    cout<<"File level is higher than your user clerance."<<endl;
                                    ifs.close();
                                    ins.close();
                                    home(name1,userc);
                                }

                            }

                        }
                    }

                }
                if (able10>0)
                {
                    cout<<"File dosen't exist"<<endl;
                    ifs.close();
                    ins.close();
                    home(name1,userc);
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
        cout<<"You are currently at .\\home\\"<<name1<<endl;;
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
            if (dir != search_name)
            {
               able10++;
            }
            else
            {
                if(ansuc != "root")
                {
                    ucInt = stoi(ansuc);
                    if(search_name == dir)
                    {
                        if(usercI <= ucInt)
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
                            home(name1,userc);
                        }
                        else
                        {
                            cout<<"File level is higher than your user clerance."<<endl;
                            ifs.close();
                            home(name1,userc);
                        }
                    }
                }
            }
        }
        if (able10>0)
        {
            cout<<"File is not exist."<<endl;
            ifs.close();
            home(name1,userc);
        }
    }
    else if (ans =="3")
    {
        home(name1,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto Start;
    }
}

void write(string  name1,string userc)
{
     string name,name2,dir,filec,search_name;
    ofstream ofs;
    ifstream ifs;
    int usercI = stoi(userc),ucInt;
    string temp, ans,ansdir,ansdir1,ansdir2,ans3;
    int able1, able2;
    cout<<"Notepad Name: ";
    cin.ignore();
    getline(cin,name);
    search_name = ".\\home\\"+name1+"\\"+name+".txt";
    ifs.open(".\\filestore\\filestore.txt");
    while(!ifs.eof())
    {
        getline(ifs,dir,':');
        getline(ifs,filec);
        if(filec != "root")
        {
            ucInt = stoi(filec);
            if(search_name == dir)
            {
                if(usercI <= ucInt)
                {
                name2 = "chdir .\\home\\"+name1 + " && notepad "+ name;
                system(name2.c_str());
                able1 =0;
                write_log(name1);
                cout<<"File written complete"<<endl;
                home(name1, userc);
                }
                else
                {
                    able1=0;
                    able2++;
                    break;
                }
            }
            else
            {
                able2=0;
                able1++;
            }
        }

    }

        if(able1>0)
        {
            cout<<"File dosen't exist"<<endl;
            home(name1,userc);
        }
        if(able2>0)
        {
            cout<<"File level is higher than tour user clearance"<<endl;
            home(name1,userc);
        }
}

void write1(string name1, string userc)
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



void create1(string name1 , string userc)
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
                            home(name1, userc);
                        }
                    }
                ifs.close();
                ofstream outs;
                name2 = "chdir .\\"+ansdir2 +" && notepad " + name;
                system(name2.c_str());
                create_log(name1);
                ofs.open(".\\filestore\\filestoretemp.txt",ios::app);
                ofs<<search_name<<":"<<userc<<endl;
                home(name1, userc);
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
        while(!ifs.eof())
        {
            getline(ifs,dir,':');
            getline(ifs,filec);
            if(search_name == dir)
            {
                cout<<"File already exist"<<endl;
                ifs.close();
                home(name1, userc);
            }
        }
        ifs.close();
        name2 = "chdir .\\home\\"+name1+" && notepad " + name;
        system(name2.c_str());
        create_log(name1);
        ofs.open(".\\filestore\\filestoretemp.txt",ios::app);
        ofs<<search_name<<":"<<userc<<endl;
        ofs.close();
        home(name1, userc);
    }
   else if (ans=="3")
    {
        home(name1,userc);
    }
    else
    {
        cout<<"Invalid option"<<endl;
        goto start;
    }
}
