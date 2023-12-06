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

    //...........main function definition..............
    int main()
{
  
    char pass[10],password[10]="pass";//initialization of password="pass"
    int i;
 
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");//get password from user(login password is "pass")
    scanf("%s",pass);//scan the user input
                     
    if (strcmp(pass,password)==0)// string comparison

        {
            printf("\n\nPassword Match!\nLOADING");
            for(i=0;i<=6;i++) //for loop execution
             {
                
                 printf(". ");
             }
                printf("\n");// print the new line
                system("pause");////terminal wait for a key press
                system("cls");//clear the terminal
	   
            mainmenu();//call the mainmenu function
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");

            login://label 
            printf("\nEnter 1 to try again and 0 to exit:");//user input
            scanf("%d",&main_exit);
            // if user enter the 1 
            if (main_exit==1)
                    {

                        system("cls");//clear the terminal
                        //retry to password
                        main();//call the mainfunction
                    }
            //if user enter the 0
            else if (main_exit==0)
                    {
                    system("cls");
                    close();//call the close function
                    }
            //if user enter a invalid input.(expect the 1 or 0)  
            else
                    {
                    printf("\nInvalid Entered!");
                    goto login;// go to jump if the user enter a invalid input(expect 0 or 1)
                    }

        }


        return 0;//function will return null function
}//end the  main function
