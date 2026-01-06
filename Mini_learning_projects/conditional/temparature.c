#include <stdio.h>
int main(){
   double celcius, farenheit, temp;
   char choice;


   printf("choose the temp you want  to convert to\n");
   printf("1.celcius to farenheit (c)\n");
   printf("2.farenheit to degrees (f)\n");
   printf("your choice: ");
   scanf("%c",&choice);
   printf("the temparature; ");
   scanf("%lf",&temp);

if(choice=='c'){

    printf("the temparature in farenheit is %lf",temp*2);
   }
elseif(choice=='f'){

    printf("the temparature in celcius is %lf",temp/2);

   }
else{
    printf("invalid option");
   }



}