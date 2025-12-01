#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


//declearing function
int read_pin(const char*filepath);
double read_balance(const char *filepath);
void send_money(double send,int pin,double balance,int epin,int number);
void transaction(const char *filepath,int lines);
void depositing(double deposit, int agent,double balance,char* time_string);
void withdrawn(double balance,double withdraw,int agent,char* time_string);




//read pin function
int read_pin(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char line[100];
    char last[100];

    while (fgets(line, sizeof(line), fp)) {
        strcpy(last, line);
    }

    fclose(fp);


    int number = atoi(last);
    return number;
}


//read balance
double read_balance(const char *filepath){
 FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char line[100];
    char last[100];

    while (fgets(line, sizeof(line), fp)) {
        strcpy(last, line);
    }

    fclose(fp);


    double balance = atof(last);
    return balance;
}



//send money function
void send_money (double send,int pin,double balance,int epin,int number){

  if(epin==pin){
      if(balance>=send){  
        
     double transact;
     transact = transactional_cost(send);
     send +=transact;
     balance-=send;

        printf("You have sent ksh%.2lf to %d ,your balance is ksh%.2lf,transaction fee of ksh%.2lf",send, number,balance,transact);

      //SAVE BALANCE
      FILE *new_balance;
      new_balance=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
      if(new_balance==NULL){
        perror("failed to open file");
        return;
      }
      fprintf(new_balance,"%.2lf\n",balance);
      fclose(new_balance);
      }
       else{
        printf("\ninsufficient funds,");
      }

  }else{

printf("\ntransaction failed!wrong pin,try again");

  }

}





void transaction(const char *filepath,int lines){
FILE *fp=fopen(filepath,"r");
if(fp==NULL){
    perror("failed to open file,donkey");
    return;

}
char line[256];
char buffer[lines][256];
int count = 0;
while (fgets(line,sizeof(line),fp)){
    strcpy(buffer[count%lines],line);
    count ++;
}
fclose(fp);

int lines_to_print = (count<lines) ? count : lines;
int start = (count<lines)? 0 : (count%lines);

for(int i = 0; i <lines_to_print;i++){
    int index=(start+i)%lines;
    printf("%s\n",buffer[index]);
}




}
 void depositing(double deposit,int agent,double balance,char* time_string){

//updating the balance
FILE *depositing;
depositing=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
if(depositing==NULL){
    printf("failed to open file");
    return;
}
fprintf(depositing,"%.2lf\n",balance);
fclose(depositing);

//saving transaction
FILE *transaction;
transaction =fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
if(transaction==NULL){
    perror("failed to open");
    return;}
    fprintf(transaction,"You deposited %.2lf, from agent %d, your balance is ksh%.2lf, %s",deposit,agent,balance,time_string);
    fclose(transaction);

 }





void withdrawn(double balance, double withdraw,int agent, char* time_string){
if(balance>=withdraw){
    balance-=withdraw;
printf("You have withdrawn ksh%.2lf from %d, your balance is ksh%.2lf, %s ",withdraw ,agent,balance,time_string);

//to update the transactions
FILE *withdrawing;
withdrawing=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
if(withdrawing==NULL){
    perror("failed to open file");
    return;
}
fprintf(withdrawing,"You have withdrawn ksh%.2lf from %d, your balance is ksh%.2lf, %s ",withdraw ,agent,balance,time_string);

fclose(withdrawing);


//to update the balance
FILE *fp;
fp=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
if(fp==NULL){
    perror("error in opening file");
    return;
}
fprintf(fp,"%.2lf",balance);

fclose(fp);

}
else{


printf("insufficient funds, your balance is %.2lf, %s",balance,time_string);}

}

double transactional_cost(double money){

if(money<100){
money-=7;

}
else if(money>100 && money<1000){

    money-=23;
}
else{

money-=50;

}
return money;

}



//main function

int main(){
double send,balance,deposit,withdraw;
int choice,number,agent;
int pin,epin,npin,lines;
pin=read_pin("/home/lawrence-mwangi/Documents/mpesa/pin.txt");
balance =read_balance("/home/lawrence-mwangi/Documents/mpesa/balance.txt");
time_t current_time;
current_time = time(NULL);
char* time_string = ctime(&current_time);

do{
printf("\n=/MPESA C PROGRAM=/");
//preset pin is 0000
printf("\nCHOOSE THE SERVICE:\n");
printf("1.Send money\n");
printf("2.Withdraw cash\n");
printf("3.Deposit amount\n");
printf("4.Lipa na mpesa\n");
printf("5.Check balance\n");
printf("6.Change pin:\n");
printf("7.Get mini statement\n");
printf("8.Exit");
printf("\nEnter choice:");
scanf("%d",&choice);

switch(choice){


case 1:
     printf("\nSEND MONEY\n");
     printf("Enter number of receipient: ");
     scanf("%d",&number);
     printf("Enter amount to send: ");
     scanf("%lf",&send);
     printf("Enter pin: ");
     scanf("%d",&epin);


send_money(send,pin,balance,epin,number);
      printf(", %s",time_string); 


     //save transaction
FILE *transactions;
      transactions=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
      if(transactions==NULL){
        perror("failed to open file");
        return 1;
      }
    fprintf(transactions,"You sent ksh%.2lf to %d, your balance is ksh%.2lf, %s",send,number,balance,time_string);
      fclose(transactions);



break;
case 2:
printf("Enter the agent number; ");
scanf("%d",&agent);
printf("Enter amount to withdraw: ");
scanf("%lf",&withdraw);
printf("Enter your pin: ");
scanf("%d",&epin);

if(epin==pin){
withdrawn(balance,withdraw, agent, time_string);

}
else{
printf("Wrong pin try again, %s",time_string);

}

break;
case 3:
printf("\nEnter agent number: ");
scanf("%d",&agent);
printf("Enter amount to deposit: ");
scanf("%lf",&deposit);
printf("Enter pin: ");
scanf("%d",&epin);
if(epin==pin){
    balance+=deposit;  
printf("\nYou deposited %.2lf,from agent %d, your balance is ksh%.2lf, %s",deposit,agent,balance,time_string);
depositing(deposit,agent,balance,time_string);

}else{
    printf("wrong pin,try again");
}

break;




case 5:
printf("\nEnter pin: ");
scanf("%d",&epin);
if(epin==pin){
printf("\nyour balance is ksh%.2lf, %s",balance,time_string);
}else{
    printf("wrong pin,try again");
}

break;



case 6:
printf("\nEnter old pin; ");
scanf("%d",&epin);
printf("Enter new pin: ");
scanf("%d",&npin);

if(epin==pin){
pin=npin;
FILE *cpin=fopen("/home/lawrence-mwangi/Documents/mpesa/pin.txt","a");
if(cpin==NULL){
    perror("failed to open file");
    return 1;

}
fprintf(cpin,"%d\n",pin);
fclose(cpin);
printf("pin changed succesfully, %s\n",time_string);


}
else{
    printf("failed to change pin , wrong pin entry\n");

}
break;

case 7:

printf("\nHow many last transactions do you want: ");
scanf("%d",&lines);
printf("enter your pin: ");
scanf("%d",&epin);



if(epin==pin){
printf("\nyour trasactions are:\n");

transaction("/home/lawrence-mwangi/Documents/mpesa/transaction.txt",lines);


}else{

    printf("wrong pin try again,%s",time_string);


}


break;
}
}while(choice!=8);






    return 0;
}





