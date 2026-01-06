#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word{
char character;
struct word *next;
}word;

word *head =NULL;



int main(){
char text[20];
printf("Enter text:\n");
fgets(text,sizeof(text),stdin);
text[strcspn(text,"\n")]= '\0';

word* temp = NULL;


int len= strlen(text);

for(int i=0 ; i<len; i++){

word *newnode= malloc(sizeof(word));

newnode->character=text[i];
newnode->next=NULL;



if(head==NULL){
    head=newnode;
}
else{

temp = head;
while(temp->next!=NULL){
    temp= temp->next;
}
temp->next=newnode;

}


}
word* to_next=NULL;
word*prev=NULL;

printf("your text\n");
temp =head;

while(temp!=NULL){
    printf("%c",temp->character);
    temp=temp->next;
}

//deleting node
char letter;

printf("\nwhat value do you want to delete ");
scanf("%c",&letter);


temp=head;
if(letter==temp->character){
head=temp->next;


}
else{

while(temp->character!=letter){
prev=temp;
temp=temp->next;

}
prev->next=temp->next;
free(temp);


}

temp=head;
while(temp!=NULL){
    printf("%c",temp->character);
    temp=temp->next;
}



    return 0;
}