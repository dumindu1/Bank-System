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

//..........update the account function definition................
void update(void)
{
    int change,test=0;
    FILE *old,*newrec;// old = record.dat and newrec = new.dat file pointer
    old=fopen("file.dat","r");//open a text file in read mode using "r"
    newrec=fopen("new.dat","w");//open a text file in write mode using "w"

    printf("\nEnter the account no. of the customer whose information you want to change:");
    scanf("%d",&upd.accno);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        //if acc.no which is need to update is equal to the acc.no which is user input
        if (add.accno==upd.accno)
        {   
            test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&change);
            system("cls");

            //if user need to change the address(user input the 1)
            if(change==1)
                {
                printf("Enter the new hometown:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            //if user need to change the name(user input the 2)
            else if(change==2)
                {
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phoneno);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
        // writing a block of data to a file
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("file.dat");//remove the previous acc
    rename("new.dat","file.dat");//rename the new acc as "record.dat"

if(test!=1)//if the  user input the invalid acc.no
        {  
             system("cls");
            printf("\nRecord not found!!\a\a\a");
            enter://label
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==0)
                    update();
                else if (main_exit==1)
                    mainmenu();
                else if(main_exit==2)
                    close();
                else
                    {
                    printf("\nInvalid Entered!\a");
                    goto enter;//go to jump if the user enter a invalid input
                    }
        }
    else
    //if user need go to the main menu or exit  
        {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            mainmenu();
        else
            close();
        }
}

//...........transaction function definition................
void transact(void)
{   int choice,test=0;

    FILE *old,*newrec;//file pointer declaration
    old=fopen("file.dat","r");//open a text file in read mode using "r"
    newrec=fopen("new.dat","w");//open a text file in write mode using "w"


    printf("\n\nEnter the account no. of the customer:");
    scanf("%d",&transaction.accno);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phoneno,add.acctype,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.accno==transaction.accno)//if check acc.no which is the user input equal to acc.no which is need to transaction  
            {   test=1;//if add.accno equal to transaction,accno ,test=1

            //if this function return the 0,acc.type is same to fixed1 or fixed2 or fixed3  
                if(strcmpi(add.acctype,"fixed1")==0||strcmpi(add.acctype,"fixed2")==0||strcmpi(add.acctype,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                
                    system("cls");
                    mainmenu();// call the mainmenu function

                }
                printf("\n\nDo you want to\n\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                //if user enter the choice as 1(for deposit)
                if (choice==1)
                {
                    printf("\n\nEnter the amount you want to deposit:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;//add.amt=add.amt+transaction.amt
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n.........Deposited successfully!........\n\n");
                }
                else
                //if user enter the choice as 2(for withdrawn)
                {
                    printf("\n\nEnter the amount you want to withdraw:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;//add.amt=add.amt-transaction.amt
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n.......Withdrawn successfully........!\n\n");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phoneno,add.acctype,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);//close the record.dat file
   fclose(newrec);//close the new.dat file
   remove("file.dat");//remove the previous acc
   rename("new.dat","file.dat");//rename the new acc as "record.dat"

//tesl not equal to 1= no mathcing the acc no which is user input 
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact://label
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");

      //if user enter the 0
      if (main_exit==0)
        transact();//call the transact function

        //if user enter the 1
    else if (main_exit==1)
        mainmenu();//call the mainmenu function

        //if user enter the 2
    else if (main_exit==2)
        close();//call the close function
    else
    {
        printf("\nInvalid Entered!");
        goto transact;//go to jump if the user enter a invalid input
    }

   }

   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        //if user need to go to mainmenu(enter the 1)
        if (main_exit==1)
            mainmenu();
        else
            close();
   }

}