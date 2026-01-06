#include <stdio.h>
/*
Lawrence mwangi 
CT101/G/26436/25
simple code
*/
int main()
{
//variable declaration 
float height;
float bank_balance;
int phone_no;


//prompt user to enter data
printf("enter your height:");
scanf("%f",&height);
printf("enter your bank_balance:");
scanf("%f",&bank_balance);
printf("enter your phone_no:");
scanf(" %d",&phone_no);

// display
printf("your age is %.2f\n",height);
printf("your height is %.2f\n",bank_balance);
printf("your phone_no %d",phone_no);
return 0;
}