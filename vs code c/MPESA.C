#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main (){
int choice,epin,pin=1234;
int number,agent;
double withdraw,send,deposit;
double balance=1000,newbalance=0;

time_t current_time;
current_time = time(NULL);
char* time_string = ctime(&current_time);

//declare file path to make it easy to use using pointer
const char *path_to_file = "/home/lawrence-mwangi/Bash work/cfiles/transactions.txt";







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
        printf("\nYour have sent ksh%.2lf to recipient %d, your balance is ksh%.2lf, %s",send,number,balance,time_string);
    
    //saving the transactions to file
    FILE *transactions;
    transactions = fopen("/home/lawrence-mwangi/Bash work/cfiles/transactions.txt","a");
    
    if(transactions==NULL){
     perror("failed to save transation");
    return 1;}
    
    fprintf(transactions,"\nYour have sent ksh%.2lf to recipient %d, your balance is ksh%.2lf,%s",send,number,balance,time_string);
    
   fclose(transactions);

    
    }
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
            printf("You have withrawn ksh%.2lf from agent %d, your balance is ksh%.2lf, %s\n",withdraw,agent,balance,time_string); 
        //saving the transactions to file
    FILE *transactions;
    transactions = fopen("/home/lawrence-mwangi/Bash work/cfiles/transactions.txt","a");
    
    if(transactions==NULL){
     perror("failed to save transation");
    return 1;}
    
    fprintf(transactions,"Your have withdrawn ksh%.2lf from  %d,your balance is ksh%.2lf, %s",withdraw,agent,balance,time_string);
    
   fclose(transactions);
        
         
        }
        else{
           printf("You have entered the wrong pin, try again\n");}}

    else{printf("Not enough money, try a lower amount, your balance is ksh%.2lf",balance);}

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
            printf("You have deposited ksh%.2lf from agent %d, your balance is ksh%.2lf\n",deposit,agent,balance);
        //saving the transactions to file
    FILE *transactions;
    transactions = fopen("/home/lawrence-mwangi/Bash work/cfiles/transactions.txt","a");
    
    if(transactions==NULL){
     perror("failed to save transation");
    return 1;}
    
    fprintf(transactions,"you have deposited ksh%.2lf ,from agent %d, your balance is ksh%.2lf, %s",deposit,agent,balance,time_string);
    
   fclose(transactions);
        
        
        }
        else{
           printf("You have entered the wrong pin, try again\n");}

break;

case 5:

printf("\nCHECK BALANCE\n");
printf("enter your pin: ");
scanf("%d",&epin);

 if(epin==pin){
    //call upon the function
     newbalance = balance_recovery(path_to_file);       
            printf("Your balance is ksh%.2lf\n",newbalance);}
        else{
           printf("You have entered the wrong pin, try again\n");}

 
 }

 

return 0;
}

#define MAX_LINE_LENGTH 512


//function to read the balance in last line
double balance_recovery(const char *filepath){
//declare new file but nothing changes due to const char
    FILE *file = NULL;
char line[MAX_LINE_LENGTH] = {0};
double balance=0.00;


//open the file

file = fopen(filepath,"r");
if(file==NULL){
    perror("failed to open file");
    return 1;
}

//read the last line 
long offset = 0;

//set the file pointer to end of the line

if(fseek(file,0,SEEK_END)!= 0){
    perror("fseek failed");
    fclose(file);
    return 1;
}


//move from the back one digit at a time to where the new line begins the start they to the end searching
for (offset =1; ;offset++){
    if(fseek(file, -offset,SEEK_END)!=0){
        fseek(file,0,SEEK_SET);
        break;
    
}
if(fgetc(file)== '\n'){
    //set pointer to start of the next character
 break;   
}
}

//read last line into buffer
if(fgets(line,MAX_LINE_LENGTH,file)==NULL){
    //handle empty file
    if(ftell(file)==0){
    fprintf(stderr,"file is empty\n");
}
else{
    perror("error loading last line");
}
fclose(file);
return 1;
}
//remove the balance from the line
const char *key_phrase = "your balance is ksh";
char *balance_start_prt = NULL;

if(balance_start_prt != NULL){
// move the pointer past the key phrase to the starting number
balance_start_prt += strlen(key_phrase);

//convert the rest of string to double

}







}












