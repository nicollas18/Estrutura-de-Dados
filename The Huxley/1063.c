#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void buble_sort(int *v, int size)
{
    int i, j, aux;

    for(i = size - 1; i >= 0; i--)
    {
        for(j = 0; j < size - 1; j++)
        {
            if(v[j] > v[j+1])
            {
                aux   = v[j];
                v[j]   = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main() {

    int i, v[3];

    for(i = 0; i < 3; i++)
    {
        scanf("%d", &v[i]);
    }

    buble_sort(v, 3);

    for(i = 0; i < 3; i++)
    {
        printf("%d\n", v[i]);
    }

	return 0;
}