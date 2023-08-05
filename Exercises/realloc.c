#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v, *p, i, j, k, number, number1, option;
    

    printf("Quantos números você deseja armazenar?\n");
    scanf("%d", &number);

    v = (int*) malloc(number * sizeof(int));
    
    for(i = 0; i < number; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("Deseja armazenar mais memória?\n");
    scanf("%d", &option);

    if(option == 1)
    {

        printf("Deseja acrescentar quantos números?\n");
        scanf("%d", &number1);

        v = (int*) realloc (v, number1 * sizeof(int));

        for(j = i; j < number1 + number; j++)
        {
            scanf("%d", &v[j]);
        }
    }

    /*printf("%d\n", v[0]);
    printf("%d\n", v[1]);
    printf("%d\n", v[2]);
    printf("%d\n", v[3]);
    printf("%d\n", v[4]);
    printf("%d\n", v[5]); */
    


    for(k = 0; k <= number1 + number; k++)
    {
        if(k == number1 + number) printf("\n");
        else printf("%d ", v[k]);
    }

    free(v);


    return 0;
}