/*
PBL learning of structs,
 dynamic memory allocation
 error handling
 memory release

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_records{
char name[20];
int ID;
double gpa;
}student_records;

int main(){
int number;
printf("Enter the number of students: ");
scanf("%d",&number);

student_records *records = malloc(number*sizeof(student_records));
if(records == NULL){
    printf("Memory failed");
    return 1;
}

printf("\nEnter the student details\n");

for(int i=0;i<number;i++){

printf("\nThe %d student\n",i+1);
printf("Enter the name: ");
scanf(" %19[^\n]",records[i].name);
printf("Enter your studentID number; ");
scanf("%d",&records[i].ID);
printf("Enter gpa: ");
scanf("%lf",&records[i].gpa);

}
FILE *fp;
fp=fopen("records.txt","w");
if(fp==NULL){
    printf("failed to open file");
    return 1;
}
for(int i=0;i<number;i++){

printf("%s\n",records[i].name);
printf("%d\n",records[i].ID);
printf("%lf\n",records[i].gpa);

fprintf(fp,"%s,%d, %lf\n",records[i].name,records[i].ID,records[i].gpa);

}

fclose(fp);


free(records);
records=NULL; // to prevent dangling pointer




return 0;    
} 