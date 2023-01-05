# include <stdio.h>
int main ( )
 {int i = 3;
 int j = 9;
 int k = 2;
 int m, n, o ;
 printf ( "_______________________________\n" ) ;
 printf ( "Values before the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );m = ++i % k + j ;
 printf("Evaluating the expression m = ++i %% k + j\n");
 printf ( "Values AFTER the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );
 printf ( "_______________________________\n" ) ;
 printf ( "Values before the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );
 n = j % i + m-- ;
 printf("Evaluating the expression n = j %% i + m--\n");
 printf ( "Values AFTER the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );
 printf ( "_______________________________\n" ) ;
 printf ( "Values before the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );
 k += 8 ;
 printf("Evaluating the expression k += 8\n");
 printf ( "Values AFTER the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );
 printf ( "_______________________________\n" ) ;
 printf ( "Values before the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );
 o = n/ k *m% k ;
 printf("Evaluating the expression o = n / k * m %% k\n");
 printf ( "Values AFTER the evaluation \n");
 printf(" i = %d\t j = %d\t k = %d\t m = %d\t n = %d\t o = %d\n", i, j, k, m, n, o );
 printf ( "_______________________________\n" ) ;
 return 0;}