#include <stdio.h>
#include "BigInt.h"

BigInt* countValue(int n){
    BigInt *a,*b;
    a = BigInt_construct(0);
    b = BigInt_construct(1);
    if (n == 0){
        return a;
    } else if (n == 1) {
        return b;
    } else {
        for (int i=2;i<=n;i++){
            if (BigInt_compare(b,a) == 1)
                BigInt_add(a,b);
            else
                BigInt_add(b,a);
        }
        return BigInt_compare(b,a) == 1 ? b : a;
    }
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
    BigInt_print(countValue(n));
    printf("\n");
    getchar();
    return 0;
}