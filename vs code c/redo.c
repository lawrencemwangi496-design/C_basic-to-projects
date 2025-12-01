#include <stdio.h>



int main (){
int choice,epin,pin=1234;
int number,agent;
double withdraw,send,deposit;
double balance=1000;

printf("=/MPESA C PROGRAM=/");


//preset pin is 0000
printf("CHOOSE THE SERVICE:\n");
printf("1.Send money\n");
printf("2.Withdraw cash\n");
printf("3.Deposit amount\n");
printf("4.Lipa na mpesa\n");
printf("5.Check balance\n");


printf("enter choice:");
scanf("%d",&choice);

//sending money
switch(choice){
case 1:   
     printf("\nSEND MONEY\n");
     printf("Enter number of receipient: ");
     scanf("%d",&number);
     printf("Enter amount to send: ");
     scanf("%lf",&send);

     if(balance>=send){
     printf("enter pin: ");
     scanf("%d",&epin);
     if(pin==epin){  
        balance-=send;       
        printf("\nYour have sent ksh%.2lf to recipient %d, your balance is ksh%.2lf",send,number,balance);}
        else{printf("You have entered wrong pin,try again");}}

    else{printf("Try a lower amount,your balance is ksh%.2lf\n",balance);}

break;


//withdrawing money
case 2:
     printf("\nCASH WITHDRAWAL\n");
     printf("Enter agent number:");
     scanf("%d",&agent);
    printf("Enter amount to withdraw:");
    scanf("%lf",&withdraw);

    //check if your balance allows you to withdraw
    if(balance>=withdraw){

       printf("Enter pin: ");
       scanf("%d",&epin);

     //check correct pin input
         if(epin==pin){
            balance-=withdraw;
            printf("You have withrawn ksh%.2lf from agent %d, your balance is ksh%.2lf\n",withdraw,agent,balance);}
        else{
           printf("You have entered the wrong pin, try again\n");}}

    else{printf("Not enough money, try a lower amount, your balance is ksh%.2lf\n",balance);}

break; 


//withdrawing money
case 3:
     printf("\nDEPOSIT MONEY\n");
     printf("Enter agent number:");
     scanf("%d",&agent);
    printf("Enter amount to deposit:");
    scanf("%lf",&deposit);

    //check if your balance allows you to withdraw
    

       printf("Enter pin: ");
       scanf("%d",&epin);

     //check correct pin input
         if(epin==pin){
            balance+=deposit;
            printf("You have deposited ksh%.2lf from agent %d, your balance is ksh%.2lf\n",deposit,agent,balance);}
        else{
           printf("You have entered the wrong pin, try again\n");}

break;

case 5:

printf("\nCHECK BALANCE\n");
printf("enter your pin: ");
scanf("%d",&epin);

 if(epin==pin){
            
            printf("Your balance is ksh%.2lf\n",balance);}
        else{
           printf("You have entered the wrong pin, try again\n");}

 
 }

 /*
 to create a point in which it has memory of the amount and you pin 
 as the amount changes from time to time you can use c file handling each 
 time you use the program the values are store in file
 this can be applied in >
 balance update
 pin change
 mini statements
 
 */

return 0;
}














