#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois subarrays ordenados em um array ordenado
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // sub-array esquerdo
    int n2 = r - m;     // sub-array direito

    // Criar subarrays temporários
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copiar dados para os subarrays temporários L e R
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os subarrays temporários de volta no array original
    int i = 0; // Índice inicial do primeiro subarray
    int j = 0; // Índice inicial do segundo subarray
    int k = l; // Índice inicial do array mesclado resultante

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes, se houver, de L e R
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberar memória dos subarrays temporários
    free(L);
    free(R);
}

// Função recursiva para dividir o array em subarrays e ordená-los
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Encontra o meio do array

        // Chama a função recursivamente para classificar os subarrays esquerdo e direito
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        // Une os subarrays ordenados
        merge(arr, l, m, r);
    }
}

void insertion_sort(int *v, int size)
{
    int i, j, key;

    for(i = 1; i < size; i++)
    {
        key = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > key)
        {
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = key;
    }
}

int partition(int *v, int inicio, int fim)
{
    int i, j, pivot, aux1, aux2;

    i = inicio;
    pivot = v[fim-1];

    for(j = inicio; j < fim - 1; j++)
    {
        if(v[j] <= pivot)
        {
            aux1 = v[j];
            v[j] = v[i];
            v[i] = aux1;

            i += 1;
        }
    }
    
    aux2 =  v[i];
    v[i] = v[fim-1];
    v[fim-1] = aux2;

    return i;

}
                     
void quick_sort(int *v, int inicio, int fim)
{
    if(inicio < fim)
    {
        int p = partition(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1,  fim);
    }
}

void buble_sort(int *v, int size)

{
    int i, j, k, aux;

    // Verifica se o array ja está ordenado.

    for(k = 0; k < size; k++)
    {
        if(k == size - 1) return;
        if(v[k] > v[k+1]) break;
    }

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

void selection_sort(int *v, int size)
{
    int i, j, aux, min;

    for(i = 0; i < size - 1; i++)
    {
        min = i;

        for(j = i + 1; j < size; j++)
        {
            if(v[j] < v[min])
            {
                aux    = v[j];
                v[j]   = v[min];
                v[min] = aux;
            }
        }
    }
}

int main(){
                                           
    int i, array[] = {23, 54, 90, 67, -8, 4, 21, 4}; 

    //selection_sort(array, 7);
    //buble_sort(array, 8);
    //quick_sort(array, 0, 8);
    //insertion_sort(array, 8);
    merge_sort(array, 0, 7);

    for(i = 0; i <= 7; i++)
    {
        if(i == 7) printf("\n");
        else printf("%d ", array[i]);
    }

    return 0;
    
}