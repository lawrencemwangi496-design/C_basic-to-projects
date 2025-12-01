#include <stdio.h>

int main(){
int occupancy[2][2];


printf("enter the occpuied and non occupied floors\n");
for(int i=0;i<2;i++){
    for(int j=0; j<2; j++){
        printf("floor %d, room %d -",i,j);
        scanf("%d",&occupancy[i][j]);    
    }
}
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf("%d ",occupancy[i][j]);
    }
    printf("\n");
}



}
