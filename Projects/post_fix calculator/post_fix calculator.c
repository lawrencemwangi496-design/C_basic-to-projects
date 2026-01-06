#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 20
char stack[MAX];
int top = -1;

void push(int x){
if(top == MAX -1){
printf("overflow, full\n");
}
else{
top++;
stack[top]= x;

}

}


void pop(int value[2]){

if(top == -1){
    printf("empty\n");
}
else{
value[0]=stack[top];
value[1]=stack[top-1];

top-=2;

}




}

void calculations(char* calc){
    int result;

for(int i=0; calc[i] != '\0';i++){

//if character is digit convert to int and push
if(isdigit(calc[i])){

    push(calc[i] - '0');
}else{
int values[2];
pop(values);

switch (calc[i]){

case '+':
push(values[1]+values[0]);
break;
case '-':
push(values[1]-values[0]);
break;
case '*':
push(values[1]*values[0]);
break;
case '/':
push(values[1]/values[0]);
break;

}
}

}


}


int main(){
char calc[20];

printf("enter calculation: ");
fgets(calc,sizeof(calc),stdin);
calc[strcspn(calc, "\n")] = '\0';
calculations(calc);

printf("result: %d\n",stack[top]);

    return 0;

}