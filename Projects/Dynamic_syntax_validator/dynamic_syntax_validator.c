#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct store{
char bracket;
struct store *next;
}store;


store *top=NULL;
store *temp=NULL;

void push(char fp){

store *newnode= malloc(sizeof(store));
newnode->bracket=fp;
newnode->next=NULL;


if(top == NULL){
top=newnode;
}
else{
newnode->next=top;
top=newnode;

}

}
char pop(){
    char val;
if(top == NULL){
printf("empty\n");
return '\0';

}else{
temp=top;
top= temp->next;
val=temp->bracket;
free(temp);

}


return temp->bracket;

}



bool checker(char* text){

int len = strlen(text);

for(int i=0; i<len;i++){


if(text[i] == '(' || text[i] == '{' || text[i] == '['){

push(text[i]);

}
else if(text[i] == ')' || text[i] == '}' || text[i] == ']'){
   
char opener = pop();
char closer = text[i];
if(opener == '(' && closer == ')'){

}else if(opener == '[' && closer == ']'){


}else if(opener == '{' && closer == '}'){

}else if (opener == '\0'){
    return false;
}

else{
    return false;
}

}

}

if(top != NULL){
    while(top != NULL){
        pop();
    }
    return false;
}


return true;


}




int main(){
char text[100];

printf("enter your brackets: ");
fgets(text,sizeof(text),stdin);
text[strcspn(text,"\n")]= '\0';

bool result = checker(text);

if(result==true){
printf("valid brackets\n");
printf("%s\n",text);

}else{
    printf("invalid brackets\n");
    printf("%s\n",text);
}


    return 0;
}
