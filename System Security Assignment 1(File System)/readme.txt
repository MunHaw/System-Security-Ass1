Instruction from the beiginning:

FileSystem -i : register new user with username and password (by defaullt user clearance is 2)

FileSystem: login to the system with valid username and password 

?: help menu

===============================================================================================
Security level:
2: user can only read, write and create at its own home directory with user clerance lv 2.
1: user can only create and write at its own home directory with user clerance 1, able to read
   outside of its home directory but file that is above lv 1 and root are not able to read.
0: user can read, write and create outside of its home directory with no limit of user clerance

=============================================================================================

Once log in:


Create: Create file based on user clearance level
Read: Read file based on user clearance level
Write: Modify file based on user clearance level
List: List file based on what you are able to read
Save: Save file based on what you have created
Exit: Quit File System

there will be 2 type of menu.
1)(C)reate, (R)ead, (W)rite, (L)ist,(S)ave or (E)xit.
2)(C)reate, (R)ead, (W)rite, (L)ist,(S)ave,(G)roup, (B)lackList, (U)serClearance or (E)xit

=============================================================================================

Registration Instruction :
1.Password policy only 8 character allow with at least 1 Upercase letter, 1 Lowercase letter,
  1 Special Character, 1 number
2.User Description : Enter your name or your nickname
3.To register as a normal group enter 1000
4.To register as a ROOT group enter 9999

