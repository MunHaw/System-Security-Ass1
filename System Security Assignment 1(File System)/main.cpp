#include <iostream>
#include <stdlib.h>
#include <cstdlib>/// for system("CLS")
#include <fstream>/// for inputing and print to file
#include <conio.h> /// for getch in function getPass
#include "md5.h"
#include "function.h"
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;

int x=0, y=0;


string name;


int main()
{
    run_system();
    txt();
    option();

    return 0;
}

void option()
{
    string enter;
    do
    {
        enter ="";
        cout<<"$: ";
        getline(cin,enter);
        if(enter.compare("FileSystem")==0)
        {
            cout<<"---------------------------"<<endl;
            cout<<"Welcome Login Page"<<endl;
            cout<<"---------------------------"<<endl;
            logUser();
        }
        else if(enter.compare("FileSystem -i")==0)
        {
            cout<<"---------------------------"<<endl;
            cout<<"Welcome Register Page"<<endl;
            cout<<"---------------------------"<<endl;
            reg();
        }
        else if(enter.compare("?")==0)
        {
            file_help();
        }
        else if(enter.compare("Clear")==0)
        {
            system("CLS");
        }
        else
        {
            cout<<"Having problem to access? type '?' show help "<<endl;
        }
    } while((enter.compare("FileSystem -i")!=0)||(enter.compare("FileSystem ")!=0));

}



bool capTCHA()
{
    string cap;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    int stringLength = sizeof(alphanum)-1;
    string random;
    srand(time(0));
    for(unsigned int i = 0; i < 5; ++i)
    {
        random += alphanum[rand() % stringLength];
    }
    cout<<"Enter this if you are not robot: "<<random<<endl;
    cin>>cap;
    if(cap == random)
        return true;
    else
        return false;

}


