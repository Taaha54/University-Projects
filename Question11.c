#include <stdio.h>

int main() 
{
int a,b,c;
scanf("%d", &a);

for (b=1;b<=a;b++);
if (b%2 !=0) {
    for(c=1; c<=b;c++)
    printf("*");
    printf("\n");
}
    else {
        for(c=1; c<=b; c++)
        printf("#");
        printf("\n");
return 0;
    }
}





