#include <stdio.h>

int main() {

    int a, factorial=1;

    for(a=1;a<=10;a++){
        factorial=factorial*a;
        printf("%d!\t%d\n", a,factorial);

}
return 0;
}
