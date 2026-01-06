#include <stdio.h>
/* 
Lawrence Gichuhi Mwangi 
CT101/G/26436/25
Calculation of volume and surface area
*/


int main(){
// variable declaration 
float pi =3.142;
float radius, height,volume,surface_area;


// prompt user to enter data
printf("enter radius:");
scanf("%f",&radius);

printf("enter height:");
scanf("%f",&height);



// calculate volume  and surface area
volume= pi * radius * radius * height;
surface_area= (2 * pi * radius * radius) + (2 * pi * radius * height);



// Display the results
printf("\nthe volume is %f\n",volume);
printf(" that surface area is %f",surface_area);


return 0;
}