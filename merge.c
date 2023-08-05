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
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Encontra o meio do array

        // Chama a função recursivamente para classificar os subarrays esquerdo e direito
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Une os subarrays ordenados
        merge(arr, l, m, r);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nArray ordenado: \n");
    printArray(arr, n);

    return 0;
}
