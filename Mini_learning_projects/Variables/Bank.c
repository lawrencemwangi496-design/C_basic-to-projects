#include <stdio.h>
/*
Lawrence Gichuhi Mwangi 
CT101/G/26436/25
Calculation of volume and surface area
*/

int main(){
// variable declaration 
int age;
float income;

// prompt user to enter data
printf("Enter your age: ");
scanf("%d",&age);

printf("enter your income: ");
scanf("%f",&income);

// determines qualifications
if(age>=21 && income>=21000)
{printf("congratulation qualify for loan\n");}
else if(age<21 && income>=21000)
{printf("unable to offer loan at this time\n");}
else if(age>=21 && income<21000)
{printf("unable to offer loan at this time\n");}
else if(age<21 && income<21000)
{printf("unable to offer loan at this time\n");}


return 0;
}