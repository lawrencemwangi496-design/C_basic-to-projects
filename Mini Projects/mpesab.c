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
int transactional_cost(double money);
void paybill(double send,int pin, int epin,char* time_string);
void pochi(int number, double send,int pin ,int epin, char* time_string);
void goods(int number,double send,int pin ,int epin, char* time_string);
void loan(int epin,int pin, double balance,char* time_string);
void savings(int pin,double balance,char* time_string);
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
     balance-=transact;
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





void withdrawn(double balance, double withdraw,int agent, char* time_string,double transact){
if(balance>=withdraw){
balance -= transact;
    balance-=withdraw;

printf("You have withdrawn ksh%.2lf from %d, your balance is ksh%.2lf, transactional cost of ksh%.lf, %s ",withdraw ,agent,balance,transact,time_string);

//to update the transactions
FILE *withdrawing;
withdrawing=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
if(withdrawing==NULL){
    perror("failed to open file");
    return;
}
fprintf(withdrawing,"You have withdrawn ksh%.2lf from %d, your balance is ksh%.2lf, transactional cost of %.2lf, %s ",withdraw ,agent,balance,transact,time_string);

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

int transactional_cost(double money){
double fee;
if(money<100){
fee=7;

}
else if(money>100 && money<1000){

    fee=23;
}
else{

fee=50;

}
return fee;

}
//paybill number
void paybill(double send,int pin ,int epin,char* time_string){
 int business,account;
 double transact,balance;
 transact = transactional_cost(send);
balance = balance =read_balance("/home/lawrence-mwangi/Documents/mpesa/balance.txt");

printf("\nPaybill\n");
printf("Enter business number: \n");
scanf("%d",&business);
printf("Enter account number: \n");
scanf("%d",&account);
printf("Enter amount to send: \n");
scanf("%lf",&send);
printf("Enter pin: ");
scanf("%d",&epin);

if(balance>=send){
if(pin==epin){
balance-=transact;
balance-=send;
printf("you sent ksh%.2lf to account %d, you balance is ksh%.2lf,transactional cost of ksh%.2lf, %s\n",send,account,balance,transact,time_string);

//to update the balance
FILE *fp;
fp=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
if(fp==NULL){
    perror("error in opening file");
    return;
}
fprintf(fp,"%.2lf",balance);

fclose(fp);

//to update the transactions
FILE *paybilling;
paybilling=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
if(paybilling==NULL){
    perror("failed to open file");
    return;
}
fprintf(paybilling,"you sent ksh%.2lf to account %d, you balance is ksh%.2lf, transactional cost ksh%.2lf, %s\n",send,account,balance,transact,time_string);
fclose(paybilling);


}else{
printf("Wrong pin , try again\n");
}

}
else{
    printf("insufficient funds\n");
}


}

//goods and services
void goods(int number, double send,int pin, int epin, char* time_string){

printf("\nGoods and services\n");
printf("Enter account number: \n");
scanf("%d",&number);
printf("Enter amount to send: \n");
scanf("%lf",&send);
printf("Enter pin: ");
scanf("%d",&epin);

double balance = read_balance("/home/lawrence-mwangi/Documents/mpesa/balance.txt");
balance-=send;
if(balance>=send){
if(pin==epin){
printf("you sent to %d, amount %.2lf, your balance is %.2lf ,%s\n",number, send,balance, time_string);

//to update the balance
FILE *fp;
fp=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
if(fp==NULL){
    perror("error in opening file");
    return;
}
fprintf(fp,"%.2lf",balance);

fclose(fp);

//to update the transactions
FILE *save;
save=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
if(save==NULL){
    perror("failed to open file");
    return;
}
fprintf(save,"you sent to %d, amount %.2lf, your balance is %.2lf ,%s",number, send,balance, time_string);

fclose(save);


}else{
    printf("Wrong pin, Try again\n");
}


}else{
    printf("Isufficient funds\n");
}


}



//pochi la biashara
void pochi(int number ,double send,int pin, int epin, char* time_string){
printf("\nPochi la Biashara\n");
printf("Enter account number: \n");
scanf("%d",&number);
printf("Enter amount to send: \n");
scanf("%lf",&send);
printf("Enter pin: ");
scanf("%d",&epin);

double balance = read_balance("/home/lawrence-mwangi/Documents/mpesa/balance.txt");
balance-=send;
if(balance>=send){
if(pin==epin){
printf("you sent to %d, amount %.2lf, your balance is %.2lf ,%s\n",number, send,balance, time_string);

//to update the balance
FILE *pochi_b;
pochi_b=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
if(pochi_b==NULL){
    perror("error in opening file");
    return;
}
fprintf(pochi_b,"%.2lf",balance);

fclose(pochi_b);

//to update the transactions
FILE *save;
save=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
if(save==NULL){
    perror("failed to open file");
    return;
}
fprintf(save,"you sent to %d, amount %.2lf, your balance is %.2lf ,%s",number, send,balance, time_string);

fclose(save);


}else{
    printf("Wrong pin, Try again\n");
}


}else{
    printf("Isufficient funds\n");
}


}

//read loan file
double read_loan(){
 FILE *fp = fopen("/home/lawrence-mwangi/Documents/mpesa/loans.txt", "r");
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


    double save = atof(last);
    return save;
}

//read savings file
double read_loans(){
 FILE *fp = fopen("/home/lawrence-mwangi/Documents/mpesa/loans.txt", "r");
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


    double amount = atof(last);
    return amount;
}



//loans
void loan(int epin, int pin, double balance,char* time_string){
    double loan;
printf("Loans\n");
printf("Enter how much loan you want ");
scanf("%lf",&loan);
printf("Enter mpesa pin ");
printf("enter pin ");
scanf("%d",&epin);
//loan does not go above ksh15,000
if(loan<=15000){
    if(pin==epin){
balance+=loan;
printf("you receive a loan of ksh%.2lf,you balance is ksh%.2lf, %s",loan,balance,time_string);
//to update the balance
FILE *fp;
fp=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
if(fp==NULL){
    perror("error in opening file");
    return;
}
fprintf(fp,"%.2lf\n",balance);

fclose(fp);

//to update the transactions
FILE *loans;
loans=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
if(loans==NULL){
    perror("failed to open file");
    return;
}
fprintf(loans,"you receive a loan of ksh%.2lf,you balance is ksh%.2lf, %s",loan,balance,time_string);

fclose(loans);

double amount=read_loan();
loan+=amount;

//save the loan borrowed
FILE *xy;
xy=fopen("/home/lawrence-mwangi/Documents/mpesa/loans.txt","a");
if(loans==NULL){
    perror("failed to open file");
    return;
}
fprintf(xy,"%.2lf\n",loan);
fclose(xy);



    }else{
        printf("wrong pin try again\n");
    }
    
}else{
printf("Try a lower amount\n");

}
}

//read save money
double read_savings(){
 FILE *fp = fopen("/home/lawrence-mwangi/Documents/mpesa/savings.txt", "r");
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


    double save = atof(last);
    return save;
}


void savings(int pin,double balance,char* time_string){

    double save;
    int epin;
    printf("\nSave\n");
    printf("amount to save ");
    scanf("%lf",&save);
    printf("enter pin ");
    scanf("%d",&epin);
    if(epin==pin){
    if(balance>=save){

    balance-=save;

printf("you saved ksh%.2lf, your new balance is ksh%.2lf , %s\n",save, balance, time_string);

 //save transaction
FILE *tran;
tran=fopen("/home/lawrence-mwangi/Documents/mpesa/transactions.txt","a");
if(tran==NULL){
    perror("failed to open file");
    return;
}
fprintf(tran,"you saved ksh%.2lf, your new balance is ksh%.2lf , %s\n",save, balance, time_string);
fclose(tran);

//Update balance
FILE *BAL;
BAL=fopen("/home/lawrence-mwangi/Documents/mpesa/balance.txt","a");
if(BAL==NULL){
    perror("failed to open file\n");
    return;
}
fprintf(BAL,"%.2lf\n",balance);
fclose(BAL);


//record savings separetly
FILE *sa;
sa=fopen("/home/lawrence-mwangi/Documents/mpesa/savings.txt","a");

if(sa==NULL){
    perror("failed to open file\n");
    return;}

    fprintf(sa,"%.2lf\n",save);
    fclose(sa);


}else{
        printf("try a lower amount\n");
    }


    }else{
        printf("wrong pin, try again\n");
    }

}







//main function

int main(){
double send,balance,deposit,withdraw,transact,account;
int choice,number,agent,a;
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
printf("8.Loans and savings\n");
printf("9.Exit\n");
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

transact=transactional_cost(send);
     //save transaction
FILE *transactions;
      transactions=fopen("/home/lawrence-mwangi/Documents/mpesa/transaction.txt","a");
      if(transactions==NULL){
        perror("failed to open file");
        return 1;
        
      }
    fprintf(transactions,"You sent ksh%.2lf to %d, your balance is ksh%.2lf,tansactional cost of ksh%.2lf,%s",send,number,balance,transact,time_string);
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
transact= transactional_cost(withdraw);
withdrawn(balance,withdraw, agent, time_string,transact);

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

//lipa na mpesa
case 4:

printf("\nLIPA NA MPESA\n");

printf("1.Paybill\n");
printf("2.Buy goods and service\n");
printf("3.Pochi la Biashara\n");
printf("choose service; ");
scanf("%d",&a);

switch(a){
 //paybill   
 case 1:
paybill(send,pin, epin,time_string);

break;
//buy goods and services

case 2:
goods(number,send,pin,epin,time_string);

break;
//pochi la biashara
case 3:
pochi(number,send,pin,epin,time_string);

break;
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

//loans and savings
case 8:
do{
printf("\nLoans and savings\n");
printf("1.loan\n");
printf("2.save\n");
printf("3.exit\n");
printf("choice ");
scanf("%d",&a);
switch(a){
case 1:
loan(epin,pin,balance,time_string);
break;

case 2:
savings(pin,balance,time_string);
break;
}

}while(a!=3);

break;

}



}while(choice!=9);

return 0;
}






