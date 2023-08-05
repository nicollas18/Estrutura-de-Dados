#include <stdio.h>
#include <stdlib.h>

void buble_sort(int *v, int size)
{
    int i, j, aux;

    for(int i = size - 1; i >= 0; i--)
    {
        for(j = 0; j < size - 1; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main(){

    int i, tamanho;

    scanf("%d", &tamanho);

    int v[tamanho];

    for(i = 0; i < tamanho; i++)
    {
        scanf("%d", &v[i]);
    }

    buble_sort(v, tamanho);

    /*for(i = 0; i < tamanho; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");*/

    printf("%d ", v[0]);
    printf("%d ", v[tamanho/2]);
    printf("%d\n", v[tamanho-1]);
}