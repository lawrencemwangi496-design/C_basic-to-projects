/*
lawrence mwangi
CT101/G/26436/25
WAGE_TAX
*/
#include <stdio.h>


//taxing function
float taxing(float pay){
    float tax,net_pay=0;

if (pay>600){
float difference;
difference=pay-600;
tax=(15.0/100*600)+(difference*20.0/100);
net_pay=pay-tax;
}else{
  tax=pay*(15/100);  
net_pay=pay-tax;
}

return net_pay;
}


//main function
int main(){

float total_hours,pay;
float hourly_wage;


printf("enter the total hours worked: ");
scanf("%f",&total_hours);

printf("enter the hourly wage: ");
scanf("%f",&hourly_wage);


if(total_hours>40){
int extra=0;
extra=total_hours-40;

pay=(40*hourly_wage)+(extra*1.5*hourly_wage);


}
else{

 pay=(total_hours*hourly_wage);}
 
 float net_pay=taxing(pay);

 float taxes=pay-net_pay;

printf("\nyour gross pay is $%.2f",pay);
printf("\nyour net_pay is $%.2f ",net_pay);
printf("\nyour taxes are $%.2f",taxes);;









    return 0;
}