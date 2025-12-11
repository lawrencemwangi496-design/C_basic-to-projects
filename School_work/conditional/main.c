#include <stdio.h>

double calculate_electric_bill(double units){
    double total=0;
if(units<=100){
    total=units*10;
}
else if(units>100 && units<=200){
    total=total+(units-100)*15;
}
else{
    total=total+((units-200)*200);
    
}

return total;
            
        

}

int main(){
    double units,total;

    printf("enter units consumed: ");
    scanf("%lf",&units);


total=calculate_electric_bill(units);
    
    printf("the units consumed are %lf",total);




    return 0;

}