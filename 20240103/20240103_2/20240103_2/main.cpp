#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


long factorial(int n)
{
    printf("factorial(%d)\n", n);

    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

int main(void)
{
    int n; 
    long f;

    printf("������ �Է��Ͻÿ�:");
    scanf("%d", &n); 

    printf("%d!�� %ld �Դϴ�. \n", n, factorial(n)); 
    return 0;
}
