#include <stdio.h>
int main(){
float marks[3],sum=0,average=0;
int i;


printf("enter marks ");
for(i; i<3 ; i++){
scanf("%f",&marks[i]);    
sum=sum+marks[i];

}
average=(sum)/i;
printf("the average is equal to %f",average);











return 0;
}