#include <stdio.h>
/*
Lawrence Mwangi
CT101/G/26436/25
exam eligibility 
*/



int main() {
//variable declaration 
int average_mark;
int attendance;


//prompt user to enter details
printf("enter average mark:");
scanf("%d",&average_mark);
printf("enter attendance:");
scanf("%d",&attendance);



// checks eligibility 
if( average_mark>40 && attendance>=75){
printf("you are eligible");}
else if(average_mark<40 && attendance>=75){
printf(" you are not eligible");}
else if( average_mark>40 && attendance<75){
printf("you are not eligible");}
else if(average_mark<40 && attendance <75){
printf(" you are not eligible");}


return 0;
}