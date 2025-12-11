/*
lawrence mwangi
CT101/G/26436/25
SIMPLE INTREST
*/

#include <stdio.h>


int main(){
    //variable decleration
    float principal,rate, time;
    float simple_intrest;
//prompt user for info
printf("enter the principal; ");
scanf("%f",&principal);
printf("enter the rate; ");
scanf("%f",&rate);
printf("enter the time: ");
scanf("%f",&time);


//calculation of simple intrest
simple_intrest=(principal*rate*time)/100;

//printing values after calculation
printf("the simple intrest is ksh%.2f\n",simple_intrest);

    return 0;

}