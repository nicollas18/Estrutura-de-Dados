#include <stdio.h>

int main () {
    
    int a = 10;
    int b, c;

    printf("&a = %p e a = %d\n", &a, a);
    printf("&b = %p e a = %d\n", &b, b);
    printf("&c = %p e a = %d\n\n", &c, c);

    b = 20;
    c = a + b;
    
    printf("&a = %p e a = %d\n", &a, a);
    printf("&b = %p e a = %d\n", &b, b);
    printf("&c = %p e a = %d\n\n", &c, c);

    return 0;

}