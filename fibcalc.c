#include <stdio.h>
#include <stdlib.h>
#include "BigInt.h"
BigInt* fib(BigInt **cache,int n)
{
    if (BigInt_compare(cache[n],BigInt_construct(-1)) == 0){
        BigInt_assign(cache[n],fib(cache,n-1));
	BigInt_add(cache[n],fib(cache,n-2));
    }
    return cache[n];
}

int main()
{
    int n;
    printf("Kacper Mochniej\n");
    printf("GL3\n");
    do {
        printf("Podaj numer elementu ciagu\n");
        scanf("%d",&n);
        if (n < 0){
            printf ("Wartosc musi byc nieujemna\n");
        }
    } while (n < 0);
    BigInt **cache;
    cache = malloc((n+1)*sizeof(BigInt*));
    cache[0] = BigInt_construct(0);
    if (n>0) {
        cache[1] = BigInt_construct(1);
    }
    for (int i=2;i<=n;i++){
        cache[i] = BigInt_construct(-1);
    }
    BigInt_print(fib(cache,n));
    printf("\n");
    getchar();
    return 0;
}