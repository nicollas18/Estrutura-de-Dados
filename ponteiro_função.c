#include <stdio.h>

// Função 1: Imprime uma mensagem
void imprimir_mensagem(const char* mensagem) {
    printf("Mensagem da Função 1: %s\n", mensagem);
}

// Função 2: Imprime um número inteiro
void imprimir_numero(int num) {
    printf("Número da Função 2: %d\n", num);
}

int main() {
    // Declarando um ponteiro para função que recebe uma string como parâmetro
    void (*ponteiro_funcao)(const char*);
    void (*ponteiro_funcao1)(int);

    // Atribuindo o endereço da função imprimir_mensagem ao ponteiro_funcao
    ponteiro_funcao = imprimir_mensagem;

    // Chamando a função através do ponteiro
    ponteiro_funcao("Olá, mundo!");

    // Atribuindo o endereço da função imprimir_numero ao ponteiro_funcao
    ponteiro_funcao1 = imprimir_numero;

    // Chamando outra função através do mesmo ponteiro
    ponteiro_funcao1(42);

    return 0;
}
