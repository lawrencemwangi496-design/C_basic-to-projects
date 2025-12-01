/*
CT101/G/26436/25
LAWRENCE MWANGI
HOTEL REVENUE MANAGEMENT
*/



#include <stdio.h>
int main(){
float revenue[7],total=0,average;
int count=0, day=1;

//prompt the user for the info 
printf("enter the daily revenue generated:\n");

// use array to take revenue for the 7 days
for(count;count<7; count++){
scanf("%f",&revenue[count]);
total=total+revenue[count];
printf("day %d revenue is ksh%.2f\n",day,revenue[count]);
day++;
}
//calculate average
average=total/7;

//print//average daily revenue and total for the week
printf("the total weekly revenue generated is equal to ksh%.2f\n",total);
printf("the average daily revenue is ksh%.2f\n",average);

return 0;

}