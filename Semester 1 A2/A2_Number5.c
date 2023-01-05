#include <stdio.h>
int main()
{
 int num=0, rev=0, rem=0, digits=0, i=0;

 scanf("%d", &num);

 while(num!=0){
 rem = num % 10;
 rev = rev * 10 + rem;
 digits++;
 num = num / 10;

 }

 for(i=0; i<digits; i++){
 rem = rev % 10;
 rev = rev / 10;
switch(rem){
    case 0:
    printf("zero ");
    break;

    case 1:
    printf("one ");
    break;

    case 2:
    printf("two ");
    break;

    case 3:
    printf("three ");
    break;

    case 4:
    printf("four ");
    break;

    case 5:
    printf("five ");
    break;

    case 6:
    printf("six ");
    break;

    case 7:
    printf("seven ");
    break;

    case 8:
    printf("eight ");
    break;

    case 9:
    printf("nine ");
    break;
 }
 }

    return 0;