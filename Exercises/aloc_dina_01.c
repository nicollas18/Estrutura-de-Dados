#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v;

    v = (int*) malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        printf("Digite um número: ");

        int num;
        scanf("%d", &num);

        v[i] = num;
    }

    printf("Os números digitados foram: ");

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);


    return 0;
}