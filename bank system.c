#include<stdio.h>// standard Input Output header file 
#include<stdlib.h>//standard library file
#include<string.h>//declares the set of functions to work string.

int main_exit;//global variable declararion

float interest(float t,float amount,int rate);//interest function declaration
void newacc();//newacc function declaration
void update();//update function declaration
void transact();//transact function declaration
void checkb();//chechb function declaration
void delete();//delete function declaration
void mainmenu();//mainmenu function declaration
void close();//close function declarion

//create a structure which name is date 
struct date
{
    int month,day,year;
};

struct{

    //structer members or elements
    char name[60];
    int accno,age;
    char address[60];
    char citizenship[15];
    double phoneno;
    char acctype[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;// declare variable for the structure