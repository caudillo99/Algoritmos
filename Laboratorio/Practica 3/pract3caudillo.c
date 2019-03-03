/*Bibliotecas utilizadas en el programa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*HEADERS*/
void combinaciones(char* str, int init, int base, int str_size);
int factorial(int number);

/*Función principal*/
int main(int argc, char const *argv[])
{
    char str[20];
    int init = 1, base = 2, str_size;
    printf("Ingrese una palabra: "); gets(str);
    str_size = strlen(str)-1;
    combinaciones(str, init, base, str_size);
    return 0;
}

void combinaciones(char* str, int init, int base, int str_size)
{
    char tmp; // caracter temporal donde se guarda un caracter para hacer un swap.
    int i = 0, x = 0;
    if (init <= str_size) // La recursión termina cuando se llegue al tamaño de la cadena.
    {
        while(init+x < factorial(base))
        {
            if(i == init) i = 0;
            tmp = str[str_size-init+i];
            i++;
            str[str_size-init+i-1] = str[str_size-init+i];
            str[str_size-init+i] = tmp;
            printf("%s\n", str);
            x++;
        }
        combinaciones(str, init+1, base+1, str_size);
    }
    else puts("FIN.");
}

int factorial(int number)
{
    int i, fact = 1;
    for(i = 1; i <= number; i++)
        fact *= i;
    return fact;
}
