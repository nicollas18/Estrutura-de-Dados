#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int total_doces, doces_x, doces_y, doces_z, contador = 0;
    scanf("%d%d%d%d", &total_doces, &doces_x, &doces_y, &doces_z);

    if(total_doces - doces_x >= 0){

        total_doces -= doces_x;
        contador++;
    }

    if(total_doces - doces_y >= 0)
    {
        total_doces -= doces_y;
        contador++;
    }

    if(total_doces - doces_z >= 0)
    {
        total_doces -= doces_z;
        contador++;
    }

    printf("%d\n", contador);
    
	return 0;
}