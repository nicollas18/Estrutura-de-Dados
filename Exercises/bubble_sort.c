#include <stdio.h>

/*

"Leva" o maior valor para o final do array

Melhor Caso: O(n)
Pior Caso: O(n^2)
Não recomendado para arrays grandes 

*/

void bubble_sort(int *v, int size)
{
    for(int i = size - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(v[j] > v[j+1])
            {
                int aux;

                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main() {

    int array[] = {3, 1, 4, 7, 8, 9, 12, 23, 45, 2};

    bubble_sort(array, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}