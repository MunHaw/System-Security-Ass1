#include <string>
using namespace std;
///declaring function

///register
void reg();
void saltfunC(string, string &salt);
bool testPass(string);
void getPass(string &passwd);
bool getPass2(string);
void write_file();
///end of register

void example();
void login();
void option();
void logUser();
void logPass();
bool capTCHA();

void dir(string);
void admin();
void sohai();
int userid();
bool group_check(string);
void txt();
bool root();

///pre run
void store();
///end of pre run

///logs
void run_system();
void close_system();
void attempt_log(string);
void success_log(string);
void attempt_reg();
void group_log(string);
void success_reg(string);
void lock_acc(string);
void unban_acc(string,string);
void chgroup_acc(string,string);
void chuserc_acc(string,string);
void write_log(string);
void read_log(string);
void create_log(string);
void save_log(string);
///end of logs

///help
void home_help();
void file_help();
void root_help();
///end of help

///hoempage
void home(string,string);
void create(string,string);
void create1(string,string);
void write(string, string);
void write1(string,string);
void read(string,string);
void read1(string,string);
void list_file(string,string);
void Save(string,string);
void ex(string, string);
///end of homepage


///root hoempage
void root_home(string,string);
void root_create(string,string);
void root_read(string,string);
void root_write(string,string);
void root_list_file(string,string);
void root_Save(string,string);
void userClearance(string,string);
void blacklist(string,string);
void transfer(string);
void root_ex(string, string);
void group(string,string);
///end of root homepage
