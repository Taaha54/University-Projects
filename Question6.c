#include <stdio.h>

int main() {
    float a,b;
    scanf("%f%f", &a, &b);

    if (b==0)
    printf("Can't divide by zero");

    else
    printf("%.3f",a/b);

    return 0;
}