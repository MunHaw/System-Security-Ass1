#include "function.h"
#include <iostream>
using namespace std;

void file_help()
{
    cout<<"\n------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\tCommands\t\tDetail of commands\n"<<endl;
    cout<<"\tFileSystem -i\t\tTo launch file system program (register)\n"<<endl;
    cout<<"\tFileSystem\t\tTo launch file system program (login)\n"<<endl;
    cout<<"\tClear\t\t\tTo clear the dialog"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
}


void home_help()
{
    cout<<"\n------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\tCommands\t\tDetail of commands\n"<<endl;
    cout<<"\t(W)rite\t\t\tWrite to file(existing).\n"<<endl;
    cout<<"\t(R)ead\t\t\tRead file that is same user clearance as you or lower.\n"<<endl;
    cout<<"\t(C)reate\t\tCreate new folder or file.\n"<<endl;
    cout<<"\t(S)ave\t\t\tSave File Record.\n"<<endl;
    cout<<"\t(L)ist\t\t\tList file that you are able to read.\n"<<endl;
    cout<<"\t clear\t\t\tClear dialog.\n"<<endl;
    cout<<"\t(E)xit\t\t\tExit FileSystem."<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
}

void root_help()
{
    cout<<"\n------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\tCommands\t\tDetail of commands\n"<<endl;
    cout<<"\t(W)rite\t\t\tWrite to file(existing).\n"<<endl;
    cout<<"\t(R)ead\t\t\tRead file that is same user clearance as you or lower.\n"<<endl;
    cout<<"\t(C)reate\t\tCreate new folder or file.\n"<<endl;
    cout<<"\t(S)ave\t\t\tSave File Record.\n"<<endl;
    cout<<"\t(L)ist\t\t\tList file that you are able to read.\n"<<endl;
    cout<<"\t(G)roup\t\t\tCreate and change group for user.\n"<<endl;
    cout<<"\t(B)lacklist\t\tCheck and unbanned user from the blacklist.\n"<<endl;
    cout<<"\t(U)serClearance\t\tCheck and change user(user clearance).\n"<<endl;
    cout<<"\t clear\t\t\tClear dialog.\n"<<endl;
    cout<<"\t(E)xit\t\t\tExit FileSystem."<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
}
