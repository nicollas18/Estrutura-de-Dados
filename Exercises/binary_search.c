#include <stdio.h>
#include <stdlib.h>

int  binary_search(int *v, int tamanho, int elemento)
{
    int inicio = 0;
    int final = tamanho - 1;

    while(inicio <= final)
    {
        int meio = (inicio + final) / 2;

        if(elemento < v[meio])
        {
            final = meio - 1;
        }

        else if(elemento > v[meio])
        {
            inicio = meio + 1;
        }

        else return meio;

    }

    return -1;
}

int main() {

    int elemento, posicao, vetor[] = {3, 7, 13, 16, 18, 24, 27, 35, 40};

    printf("Digite o número que deseja procurar: ");
    scanf("%d", &elemento);

    posicao = binary_search(vetor, 9, elemento);

    if(posicao != - 1) printf("O número está na posição %d do vetor\n", posicao);
    else printf("O número não foi encontraco!\n");

    return 0;
}