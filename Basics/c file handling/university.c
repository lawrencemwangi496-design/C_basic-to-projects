#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to hold the student info
typedef struct {

char name[50];
char reg_number[15];
int total_marks;

}student;

int main(){
const char* filename="result.dat";

student students_to_write[]={
{"aphy","3465","60"},


};

int num_students = sizeof(students_to_write)/sizeof(students_to_write[0]);


//data would already exist
//open the binary file
FILE *writefile = fopen(filename,"wb");
if(writefile == NULL){
printf("error creating file");
return 1;


}


fwrite(students_to_write,sizeof(student),num_students,write_file);
fclose(write_file);






}

