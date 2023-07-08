#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binary_search(int *v, int tamanho, int elemento)
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

    int inscritos, testes;
    scanf("%d", &inscritos);

    int v_inscritos[inscritos], v_notas[inscritos];


    for(int i = 0; i < inscritos; i++)
    {
        int cpf;
        scanf("%d", &cpf);

        v_inscritos[i] = cpf;
    }

    for(int i = 0; i < inscritos; i++)
    {
        int nota;
        scanf("%d", &nota);

        v_notas[i] = nota;
    }

    scanf("%d", &testes);

    for(int i = 0; i < testes; i++)
    {
        int CPF, posicao;
        scanf("%d", &CPF);

        posicao = binary_search(v_inscritos, inscritos, CPF);

        if(posicao != - 1)
        {
            printf("%d\n", v_notas[posicao]);
        }

        else printf("NAO SE APRESENTOU\n");
    }

	return 0;
}