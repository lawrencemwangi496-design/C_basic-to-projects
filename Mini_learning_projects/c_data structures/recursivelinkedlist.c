#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int y;
    struct data *next;
}data;

data *head= NULL;

//function decleration
void choice();
void adding(data *current, data* newnode);
void add();
void delete();
void deleting(data *temp,data *prev,int x,int count);
void display(data *temp);
void searching(data* tmep, int value);
void counting(data* current, int y);
void freeing(data*temp,data* tonext);

//adding function
void add(){
int value;
printf("enter value ");
scanf("%d",&value);

data *newnode =malloc(sizeof(data));
newnode->next= NULL;
newnode->y=value;
data *temp= NULL;
temp = head;
adding(temp,newnode);





}


//moves to the end of the list add newnode
void adding(data* current,data* newnode){
if(head==NULL){
    head=newnode;
    return;
}
else if(current->next==NULL){
    current->next=newnode;
return;
}

current=current->next;



adding(current,newnode);
}


//deleting function
void delete(){
int x,number=1;

printf("which data to be deleted ");
scanf("%d",&x);

data *prev=NULL;
data *temp=NULL;
temp=head;
deleting(temp,prev,x,number);

}


//deleting by searching through list
void deleting(data *temp,data *prev,int x,int count){

if(head==NULL){
    printf("list is empty\n");
    return;

}
else if(count==1){
    head=head->next;
    free(temp);
    return;
}else if(count==x){
   prev->next=temp->next;
   free(temp);
   return; 
}
prev=temp;
temp=temp->next;



    return deleting(temp,prev,x,count+1);
}



//dipalying the data
void display(data *temp){
if(temp==NULL){
    return;
}
printf("Data: %d",temp->y);

return display(temp->next);
}


//search for record
void search(){
    int value;
printf("what recod do you want to find ");
scanf("%d",&value);

data *temp=NULL;

temp=head;
searching(temp,value);

}

//traverse through the list and finds the value
void searching(data *temp,int value){
if(head==NULL){
    printf("the list is empty\n");
    return;
}
else if(temp != NULL && temp->y==value){
printf("data: %d\n",temp->y);
return;
}
else if(temp==NULL){
    printf("recoord not found\n");
    return;
}
temp=temp->next;

return searching(temp,value);

}

//counting the data
void counting(data *current,int y){

if(head==NULL){
    printf("count is 0\n");
    printf("the list is empty\n");
return;
}
else if(current!=NULL){
   
}
else if(current==NULL){
    printf("count is %d\n",y);
    return;
}


return counting(current, y+1);

}


void freeing(data* temp,data* tonext){

if(head==NULL){
    printf("the list is empty\n");
    return;
}
else if(temp==NULL){
    printf("memory freed successfully\n");
    return;
}
tonext=temp->next;
    free(temp);
    temp=tonext;

return freeing(temp,tonext);

}


//use switch case 
void choice(){


int choose,number=1;

if(choose<6){
  
printf("1.Add data\n");
printf("2.delete data\n");
printf("3.display\n");
printf("4.search\n");
printf("5.Count data\n");
printf("6.free memory\n");
printf("7.Exit\n");
scanf("%d",&choose);

switch(choose){

case 1:
add();
break;

case 2:
delete();
break;
case 3:
data *temp =NULL;
temp=head;
display(temp);
break;
case 4:
search();
break;
case 5:
data *current=NULL;
current=head;
counting(current,number);
break;
case 6:
data *tonext=NULL;
freeing(temp,tonext);
break;

}

}else if(choose==7){
    return;
}




return choice(choose);
}





//main function
int main(){
    
choice();
data *tonext=NULL;
data *temp=NULL;
freeing(temp,tonext);


    return 0;
}