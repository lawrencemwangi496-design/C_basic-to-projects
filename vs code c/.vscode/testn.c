#include <stdio.h>
#include <math.h>

int main(){
int a[4];


printf("enter numbers");
for(int i=0; i<3;i++){
scanf("%d",&a[i]);  
}

int max;

for(int i=0;i<3;i++){

max=fmax(max,a[i]);
}

printf("the greatest is %d",max);

return 0;
}