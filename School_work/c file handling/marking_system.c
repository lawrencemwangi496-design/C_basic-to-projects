/*
lawrence mwangi
CT101/G/26436/25
READS FROM A BINARY FILE STUDENT MARKS
*/
#include <stdio.h>


struct details{
char name;
int REG;
float total_marks;

};

int main(){

// the file must exist in order for it to be opened

FILE *fp;
fp = fopen("details.bin","rb");
struct details data;

if(fp == NULL){

    printf("error opening file");
    return 1;

}
printf("reading file....\n");
//raeding  =and displaying 

//read struct in file 
fread(&data, sizeof(struct details),1,fp);

printf("name:%c\n",data.name);
printf("REG:%d\n",data.REG);
printf("total_marks:%.2f\n",data.total_marks);

fclose(fp);
printf("file closed successfully");

 return 0;


}