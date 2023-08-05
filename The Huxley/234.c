#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n1, n2;
    scanf("%d%d", &n1, &n2);

    for(int i = n1 + 1; i < n2; i++)
    {
        if(i % 5 == 2 || i % 5 == 3)
        {
            printf("%d\n", i);
        }
    }
	return 0;
}