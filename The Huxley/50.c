#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void buble_sort(float *v, int size)
{
    int i, j, aux;

    for(i = size - 1; i >= 0; i--)
    {
        for(j = 0; j < size - 1; j++)
        {
            if(v[j] > v[j+1])
            {
                aux    = v[j];
                v[j]   = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main() {

    float v[4], aux;

    for(int i = 0; i < 4; i++)
    {
        scanf("%f", &v[i]);
    }

    buble_sort(v, 4);

    aux  = v[2];
    v[2] = v[3];
    v[3] = aux;

    aux = v[1];
    v[1] = v[3];
    v[3] = aux;


    for(int i = 0; i < 4; i++)
    {
        printf("%.2f\n", v[i]);
    }

	return 0;
}