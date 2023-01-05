#include <stdio.h>


int main() {
int a,remaining,value,c = 0;
scanf("%d", &a);

while (a/10 !=0) {
    value = a%10;
    remaining = a/10;
    c += value;
    a = remaining;

}

printf("%d",c + remaining);
return 0;
}

