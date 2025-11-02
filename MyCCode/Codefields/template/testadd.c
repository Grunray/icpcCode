#include <stdio.h>
#include "add.h"
int main ()
{
    int a = 10;
    int b = 20;
    int sum = add(a, b);
    printf("Sum of %d and %d is %d", a, b, sum);
    return 0;
}