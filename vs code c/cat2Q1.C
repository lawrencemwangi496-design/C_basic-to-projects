/*
lawrence mwangi
CT101/G/26436/25
MATRIX
*/



//data  structure is a collection of elements of same type,stored in contagious memory location accesible through index


#include <stdio.h>

//main function
int main(){

    //initialize the matrix
 int score[2][2]={
    {65,92},
    {84,72}
 };


//diplay the matrix to the user

for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        printf("%d ",score[i][j] );

    }
    printf("\n");
}




    return 0;

}