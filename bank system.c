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

//.........interest function definition...........
float interest(float t,float amount,int rate)
{
    float SI;//local varibal declaration
    SI=(rate*t*amount)/100.0;
    return (SI);
}

//...........create the new account function definition...............
void newacc(void)

{
   
    FILE *ptr;//local variable declaration(ptr= record.dat file pointer)

    ptr=fopen("file.dat","a+");//open a text file in apend mode using "a+"


    acc_no://label
    system("cls");
    printf("\t\t\t.....ADD RECORD.....");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");//get the account number from the user
    scanf("%d",&check.accno);
    //read and separate data frome the file
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.accno==add.accno)
            {
                printf("Account no. already in use!");
          
                goto acc_no;//go to jump if the user enter a accoun no, already in use
             }
         }
    add.accno=check.accno;//asign the user input(new acc no) to add.accno 
    //get the details from user for creat the new account
    printf("\nEnter the name with initials:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the hometown:");
    scanf("%s",add.address);
    printf("\nEnter the NIC:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phoneno);
    printf("\nEnter the amount to deposit:Rs.");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\n\t\tSaving\n\t\tCurrent\n\t\tFixed1(for 1 year)\n\t\tFixed2(for 2 years)\n\t\tFixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acctype);
       // writing a block of data to a file
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
     fclose(ptr);//close the file

    printf("\n........Account has been created successfully!...........");

    invalid://label
    printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     system("cls");

    if (main_exit==1)
        mainmenu();// call the main menu function
    else if(main_exit==0)
        close();//call the close function
    else
        {
            printf("\nInvalid Enered! \a");
            goto invalid;//go to jump if user enters a invlid input(expect 1 or 0)
        }
}
