#include <stdio.h>
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    printf("Kacper Mochniej\n");
    printf("GL3\n");
    printf("Podaj numer elementu ciagu\n");
    scanf("%d",&n);
    printf("%d\n", fib(n));
    getchar();
    return 0;
}