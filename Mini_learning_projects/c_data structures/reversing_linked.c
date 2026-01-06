//reversing linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word{
char character;
struct word *next;
}word;

word *head=NULL;




void original(char* text){
word* temp=NULL;


int len =strlen(text);

for(int i=0; i<len ;i++){

word* newnode=malloc(sizeof(word));
newnode->character=text[i];
newnode->next=NULL;


    if(head==NULL){
        head=newnode;
    }else{
temp=head;
while(temp->next != NULL){

temp=temp->next;


}

temp->next=newnode; 

    }


}


//original

temp=head;
while(temp != NULL){
printf("%c",temp->character);
temp=temp->next;
}




}

void reversing(){

word* temp=NULL;

//reversing without destroying link
word *next = NULL;
word *prev = NULL;
temp=head;
while(temp != NULL){
next = temp->next;
temp->next=prev;
prev=temp;
temp=next;
}



//printing
head=prev;
temp=head;
printf("\nreversed is\n");
while(temp!=NULL){

printf("%c",temp->character);
temp=temp->next;
}


while(head!=NULL){
temp=head;
head =head->next;
free(temp);

}


}





int main(){
char sentence[100];    
printf("sentense\n");
fgets(sentence,sizeof(sentence),stdin);
sentence[strcspn(sentence,"\n")] = '\0';

original(sentence);
reversing();
    return 0;
}