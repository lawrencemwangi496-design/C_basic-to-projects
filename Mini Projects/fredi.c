// Fredrick Ndegwa
//This is my first real project in c
//This is a grading sysytem
#include<stdio.h>
int main()
{
int mark;
//capturing marks
printf("Enter your mark:");
scanf("%d", &mark);
switch (mark)
{
// range of marks
case 70 ... 100:
//award grade A
printf("You scored a grade A");
break;
case 60 ... 69:
//awards grade B
printf("You scored a grade B");
break;
case 40 ... 59:
//awards grade C
printf("You scored a grade C");
break;
case 20 ... 39:
//grade D
printf("You scored a grade D");
break;
case 0 ... 19:
//prints fail
// awards grade F
printf("You scored a grade F");
break;
default:
//for any negative value for marks
//any large number more than 100
printf("X");
break;
}
return 0;
}