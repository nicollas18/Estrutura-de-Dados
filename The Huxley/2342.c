#include <stdio.h>
#include <stdlib.h>

void sub(float *x, float *y)  
{
    *x = *x - *y;
}

int main() 
{

    float x, y;
    scanf("%f %f", &x, &y);

    sub(&x, &y);

    printf("%.2f %.2f\n", x, y);

    return 0;
}