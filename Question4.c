#include <stdio.h>

int main() 
{
int x,y;
scanf("%d%d",&x,&y);

if ((y==0)||(x%y!=0)) {


    printf(" This is not divisible");
}

else if (x%y == 0);
{
    printf(" This is divisible");
}
return 0;

}