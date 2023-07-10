#include <stdio.h>
#include <stdio.h>

/* O(n) */

int linear_search(int *v, int tamanho, int elemento)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(v[i] == elemento) return i;
    }

    return -1;
}

int main(){

    int elemento, posicao, vetor[10] = {1, 2, 3, 4 ,5 ,6, 7,8 ,9, 10};

    printf("Digite o número que deseja procurar no vetor: ");
    scanf("%d", &elemento);

    posicao = linear_search(vetor, 10, elemento);

    if(posicao != -1) printf("O número se encontra na posição %d do vetor\n", posicao);
    else printf("O número não foi encontrado!\n");

    return 0;

}