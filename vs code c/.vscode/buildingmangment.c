/*
CT1O1/G/26436/25
LAWRENCE MWANGI
hotel management

*/

#include <stdio.h>
int main(){
//ARRAY
int chain[3][5][10];
//VARIABLE DECLERATION
int floor=1,room=1;
int grand_occupied=0,grand_vacant=0;

printf("===/ ENTER THE OCCUPIED ROOMS IN EACH BUILDING ==/\n");
printf("occupied=1,vacant=0");
//FOR LOOP STORING DATA IN THE ARRAY 
for(int b=0;b<3;b++){
    printf("building %d\n",b+1);
for(int i=0; i<5 ;i++){
    floor=i+1;
    for(int j=0; j<10;j++){
        room=j+1;
         printf("FLOOR %d | ROOM %d ",floor,room);
         scanf("%d",&chain[b][i][j]);
    }
}}

//FOR LOOP FOR PRINTING BY ACESSING THE MEMORY AND REASONING IF OCCUPIED OR VACANT
printf("SUMMARY FOR BUILDING");
for(int b=0;b<3;b++){
    printf("BUILDING %d\n",b+1);
    int total_occupied=0, total_vacant=0;

for(int i=0; i<5 ; i++){
    int count=0,occupied=0,vacant=0;
    floor=i+1;
    printf("FLOOR: %d",floor);
    for( int j=0; j<10;j++){
    
        count++;
        if(chain[b][i][j]==1){
            printf("%-10s","occupied");
            occupied++;

        }
            else{
                printf("%-10s","vacant");
               vacant++; }
               if(count==10){
printf(" \n==/In floor %d - occcupied %d | vacant are %d",floor,occupied,vacant);}

       
        }
        total_occupied+=occupied;
        total_vacant+=vacant;
         printf("\n");

    }
printf("\nBUILDING OCCUPIED %d| VACANT %d",total_occupied,total_vacant);



grand_occupied+=total_occupied;
grand_vacant+=total_vacant;
}

printf("\nTOTAL: OCCUPANCE %d| VACANT %d",grand_occupied,grand_vacant);


return 0;      
}



