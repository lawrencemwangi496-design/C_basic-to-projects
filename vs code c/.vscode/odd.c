#include <stdio.h>
int main(){
    int numbers[3];
int odd=0, even=0,counte=0,countd=0;
int i=0;
printf("enter numbers:\n");
for (i;i<3;i++){
scanf("%d",&numbers[i]);
if( numbers[i]%2 ==0){
    even=even+numbers[i];
    counte++;
}
else{
    odd=odd+numbers[i];
    countd++;
}

}
printf("the number  of ecven numbers are %d and the sum is %d\n",counte,even);
printf("the number of odd numbers is %d the sum is %d\n",countd,odd);






return 0;

}