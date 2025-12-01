/*
CT1O1/G/26436/25
LAWRENCE MWANGI
ROOM 

*/

#include <stdio.h>
int main(){
//ARRAY
int occupancy[5][10];
//VARIABLE DECLERATION
int floor=1,room=1,total_occupied=0,total_vacant=0;

printf("ENTER THE OCCUPIED ROOMS ON EACH FLOOR");
printf("(1-occpied, 0-vacant)\n");
//FOR LOOP STORING DATA IN THE ARRAY 
for(int i=0; i<5 ;i++){
    floor=i+1;
    for(int j=0; j<10;j++){
        room=j+1;
         printf("FLOOR %d | ROOM %d ",floor,room);
         scanf("%d",&occupancy[i][j]);
    }
}


//FOR LOOP FOR PRINTING BY ACESSING THE MEMORY AND REASONING IF OCCUPIED OR VACANT
for(int i=0; i<5 ; i++){
    int count=0,occupied=0,vacant=0;
    floor=i+1;
    for( int j=0; j<10;j++){
    
        count++;
        if(occupancy[i][j]==1){
            printf("%-10s","occupied");
            occupied++;

        }
            else{
                printf("%-10s","vacant");
               vacant++; }
               if(count==10){
printf("\n=/In floor %d - occupied %d |vacant %d",floor,occupied,vacant);}
      
        }
total_occupied+=occupied;
total_vacant+=vacant;
  
       printf("\n");
      
    }
 printf("\nTOTAL ON BUILDING OCCUPIED %d| VACANNT %d",total_occupied,total_vacant);
return 0;      
}



