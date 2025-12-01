#include <stdio.h>
/* 
Lawrence mwangi
CT101/G/26436/25
bundles
*/


int main(){
// variable  declaration 
int choice;

// Display bundle option
printf(" select your data bundles:\n");
printf(" 1. 100MB = 50 KES\n");
printf(" 2. 500MB = 200 KES\n");
printf(" 3. 1GB = 350 KES\n");
printf(" 4. 2GB = 600 KES\n ");


// prompt user for choice
printf("enter your choice (1-4):");
scanf("%d",&choice);


// Display option and cost
if(choice == 1){
printf("you selected 100MB cost 50 KES");}
else if(choice == 2){
printf(" you selected 500MB cost 200 KES");}
else if(choice == 3){
printf(" you selected 1GB cost 350 KES");}
else if( choice == 4){ 
printf(" you selected 2GB cost 600 KES");}
else { 
printf("invalid option, select between (1-4)");}

return 0;

}