#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ratio>
#include <chrono>
#include <windows.h>
#include <fstream>
#include "function.h"

using namespace std ::chrono;


void run_system()
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"File System Start................."<<ctime(&tt);
    outfile.close();
}

void close_system()
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"File System Shut Down..............."<<ctime(&tt);
    outfile.close();
}

void attempt_log(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" attempting to login ..."<<ctime(&tt);
    outfile.close();
}

void success_log(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have login............."<<ctime(&tt);
    outfile.close();
}

void attempt_reg()
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"Someone is attempting to register......"<<ctime(&tt);
    outfile.close();
}

void success_reg(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have registered........"<<ctime(&tt);
    outfile.close();
}

void lock_acc(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have been blocked......"<<ctime(&tt);
    outfile.close();
}

void unban_acc(string user,string name)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<name<<" have been unblocked by "<<user<<"......"<<ctime(&tt);
    outfile.close();
}

void chgroup_acc(string user,string name)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<name<<" group have been changed by "<<user<<"......"<<ctime(&tt);
    outfile.close();
}

void chuserc_acc(string user,string name)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<name<<" user clearance have benn changed by "<<user<<"......"<<ctime(&tt);
    outfile.close();
}

void create_log(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have created a file........"<<ctime(&tt);
    outfile.close();
}

void save_log(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have saved a file........"<<ctime(&tt);
    outfile.close();
}

void write_log(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have modify a file........"<<ctime(&tt);
    outfile.close();
}

void read_log(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have read a file........"<<ctime(&tt);
    outfile.close();
}

void group_log(string user)
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t (today);
    ofstream outfile(".\\logs\\logs.txt",ios::app);
    outfile<<"User "<<user<<" have created a group........"<<ctime(&tt);
    outfile.close();
}


