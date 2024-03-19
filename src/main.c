#include "greetings.h"
#include "sum_palos.h"
#include "sum_palos_dyn.h"
#include <stdio.h>

int main()
{

    greetings();

    int a = 3;
    int b = 4;

    printf("La suma estatica de %d y %d palos es %d\n", a, b, sumar_palos(3, 4));
    printf("La suma estatica de %d y %d palos es %d\n", a, b, sumar_palos_dyn(3, 4));
    return 0;
}