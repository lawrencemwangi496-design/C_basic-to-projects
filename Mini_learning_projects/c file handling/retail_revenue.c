/*
lawrence mwangi
CT101/G/26436/25
TOTAL SALES
*/

#include <stdio.h>

int main(){

 FILE *fp;
 float daily_revenue;
 float  totals=0;
 

 fp = fopen("sales.txt","r");

 if(fp ==NULL){
    printf("error in opening file");
    return 1;

 }
while(fscanf(fp,"%f",&daily_revenue)==1){
totals+=daily_revenue;

}
fclose(fp);
printf("file closed succesfuly");
printf("the total revenue is ksh%.2f\n",totals);

return 0;
}