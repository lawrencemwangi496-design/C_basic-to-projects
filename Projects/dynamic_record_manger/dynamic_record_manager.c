#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//struct
typedef struct node{

int ID;
char name[20];
struct node *next;

}node;




int main(){
int i=1;
node *head,*temp;

head = NULL;
temp = NULL;



while(i!=0){

node *newnode= (node *)(malloc(sizeof(node)));

if(newnode==NULL){
    printf("error allocating memory");
    return 1;
}

printf("enter the following data\n");
printf("enter ID ");
scanf("%d",&newnode->ID);
getchar();
printf("enter name ");
fgets(newnode->name,sizeof(newnode->name),stdin);
newnode->name[strcspn(newnode->name, "\n")] = '\0';

newnode->next= NULL;


 if(head == NULL){
head=newnode;


 }else{

temp=head;

while(temp->next != NULL){
temp= temp->next;
}

temp->next=newnode;


 }



printf("press 0 to exit");
scanf("%d",&i);

}

//printing tha data

temp=head;
while(temp != NULL){

printf("ID %d\n",temp->ID);
printf("Name %s\n",temp->name);
printf("\n");
temp=temp->next;


}


temp= head;

while(temp!=NULL){

node *to_next=temp->next;

free(temp);

temp=to_next;

}

head=NULL;




    return 0;
}