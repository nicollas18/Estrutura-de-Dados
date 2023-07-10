#include <stdio.h>

/*

"Leva" o menor valor do array para a primeira posição

Melhor Caso: O(n^2)
Pior Caso: O(n^2)
Não recomendado para arrays grandes 
Não altera a ordem de dados iguais

*/

void selection_sort(int *v, int size)
{
    int i, j, min, aux;

    for(i = 0; i < size; i++)
    {
        min = i;

        for(j = i + 1; j < size; j++)
        {
            if(v[j] < v[min]) min = j;
        }

        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

int main(){

    int array[] = {3, 1, 4, 7, 8, 9, 12, 23, 45, 2};

    selection_sort(array, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}