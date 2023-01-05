#include<stdio.h>

int main(void)
 {

int farenheit;
int celsius;

printf("Enter a value of Farenheit ");
scanf("%d", &farenheit);
celsius = ((farenheit-32)/1.8);
printf("This value in Celsius is ");
printf("%d",celsius);
return 0;
 }