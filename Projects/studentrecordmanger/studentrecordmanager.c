#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct record{
int ID;
char name[20];
float grade;
struct record *next;
}record;

record *head=NULL;

int print(record *temp);
void delete_record();
void search();
void add_record();
void average();
void display(record *temp);
void memory();
void position();

void add_record(){
record *newnode = malloc(sizeof(record));
newnode->next=NULL;
record *temp=NULL;

printf("\nAdd record\n");
printf("Enter ID ");
scanf("%d",&newnode->ID);
getchar();
printf("Enter name ");
fgets(newnode->name,sizeof(newnode->name),stdin);
newnode->name[strcspn(newnode->name,"\n")]= '\0';

printf("Enter grade ");
scanf("%f",&newnode->grade);


if(head==NULL){
    head=newnode;
}else{
temp=head;

while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newnode;

}

}







void decision(int x){

switch(x){

case 1:
add_record();
break;

case 2:
delete_record();
break;

case 3:
search();
break;

case 4:
average();
break;
case 5:
display(head);
break;

}

}

void delete_record(){
    int student_id,choice;
printf("\nDELETE RECORD\n");
printf("Student ID ");
scanf("%d",&student_id);

record*temp=NULL;
record*prev=NULL;
temp=head;

if(head==NULL){
    printf("list is empty\n");
}else{

if(student_id==temp->ID){
head=head->next;
free(temp);

}
else{

while(temp!=NULL && student_id!=temp->ID){
prev=temp;
temp=temp->next;
}
if(temp==NULL){
    printf("student record not found\n");
}else{

printf("\nAre you sure you want to delete record related to\n");
printf("user ID %d\n",temp->ID);
printf("1.yes, 2. No\n");
scanf("%d",&choice);
if(choice==1){
prev->next=temp->next;
free(temp);
printf("record deleted successfully\n");
}
else{
printf("Record not deleted\n");}





}
}
}


}


void search(){
    int id;

    record *temp=NULL;

printf("\nSEARCH  RECORD\n");
printf("student ID ");
scanf("%d",&id);



if(head==NULL){
printf("the list is empty\n");
}else{
temp=head;

if(temp->ID==id){
    print(temp);

}else{

    while(temp!=NULL && temp->ID!=id){
        temp=temp->next;
    }
if(temp==NULL){
printf("Student record not found\n");
}
else{
print(temp);
}

}

}

}


int print(record* temp){

printf("\nSTUDENT RECORD\n");
printf("ID: %d\n",temp->ID);
printf("Name: %s\n",temp->name);
printf("Grade: %.2f\n",temp->grade);


}


void average(){
 float total=0,count=0,average=0;  
    
record *temp=NULL;
temp=head;
if(head==NULL){
printf("The list is empty\n");
}else{
while(temp!=NULL){
total+=temp->grade;
temp=temp->next;
count++;
}

average=total/count;
printf("Average is %.2f\n",average);

}
}

void display(record *temp){
int number=1;
 if(temp==NULL){
    printf("list is empty\n");
 }
  else{

    while(temp!=NULL){

printf("\nposition %d-ID:%d ,NAME:%s  GRADE:%.2f \n",number,temp->ID,temp->name,temp->grade);
temp=temp->next;
number++;
}
printf("FULL RECORD\n");

  }
}

void memory(){
 record *next=NULL; 
 record *temp= NULL;  
 temp=head;

while(temp!=NULL){
next=temp->next;
free(temp);
temp=next;
}
     
}

void position(){

int swapped;
record *temp= NULL;


if( head==NULL || head->next==NULL){
return;

}else{

do{ 

temp=head;
swapped=0;


while(temp->next !=NULL){

if(temp->grade < temp->next->grade){
float mark = temp->grade;
char text[20];
int id= temp->ID;
   
strcpy(text,temp->name);


//exchange
strcpy(temp->name,temp->next->name);
temp->grade= temp->next->grade;
temp->ID= temp->next->ID;

temp->next->ID=id;
strcpy(temp->next->name,text);
temp->next->grade=mark;

swapped=1;

}

temp=temp->next;
}
}while(swapped);
}


}





int main(){
    int choice;
do{
printf("\nSTUDENT RECORD MANAGER\n");
printf("1.Add record\n");
printf("2.delete record\n");
printf("3.search record\n");
printf("4.calculate average\n");
printf("5.Display records positions\n");
printf("6.Exit\n");
scanf("%d",&choice);

decision(choice);
position();

}while(choice!=6);

memory();

    return 0;


}