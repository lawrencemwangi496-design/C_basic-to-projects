#include <stdio.h>
/*
Lawrence Gichuhi
CT101/G/26346/25
water unit cost
*/


int main()
{

// variable declaration 
float units;
float cost;

// prompt user enter water units
printf(" enter water units consumed:");
scanf("%f",&units);

// calculate unit cost
if( units <=30){
cost=units* 20;}
else if(units>30,units<=60){
cost=units*25;}
else if(units>60){
cost=units*30;}


// Display the units and amount to be paid
printf(" water units consumed %.4f\n",units);
printf(" total water bill %.2f KES", cost);
return 0;



return 0;
}