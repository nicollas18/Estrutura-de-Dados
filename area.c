#include <stdio.h>

double area(double (*f)(double), double a, double b)
{
    double sum, dt;
    int i;

    sum = 0.0;
    dt = (b - a) / 100.0;

    for(i = 0; i < 100; i++)
        sum += (*f)(i * dt + a) * dt;

    return sum;
}

double square(double x)
{
    return x*x;
}

double cube(double x)
{
    return x*x*x;
}

int main() {

    int escolha;
    double a, b;
    printf("Escola a função: (1)square (2)cube\n");
    scanf("%d", &escolha);

    printf("Digite os intervelos: ");
    scanf("%lf %lf", &a, &b);

    if(escolha == 1)
    {
        printf("Área = %lf\n", area(square, a, b));
    }

    if(escolha == 2)
    {
        printf("Área = %lf\n", area(cube, a, b));
    }

    return 0;
}