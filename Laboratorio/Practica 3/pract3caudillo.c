/* UNIVERSIDAD AUTONOMA DE BAJA CALIFORNIA
Asignatura: Algoritmos y estructura de datos
Alumno: Diego Caudillo Sanchez
Matricula: 1249199
Grupo: 551
Docente: Alma Leticia Palacios Guerrero
Fecha de entrega: 08/Marzo/2019 

DESCRIPCION DEL PROGRAMA
*/
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
    int init = 1, base = 2;
    printf("Ingrese una palabra: "); gets(str);
    combinaciones(str, init, base, strlen(str)-1);
    getchar();
    return 0;
}

void combinaciones(char* str, int init, int base, int str_size)
{
    char tmp; // caracter temporal donde se guarda un caracter para hacer un swap.
    int i = 0, x = 0;
    if (init < strlen(str)) // La recursión termina cuando se llegue al tamaño de la cadena.
    {
        while(init+x <= factorial(base)) // la cantidad de iteraciones es con base a la cantidad de letras
        //iniciando de derecha a izquierda, tomando las ultimas 2 letras, posteriormente se van agregando
        //letras para el intercambio. La cantidad de iteraciones esta dado por n! (factorial), donde n es 
        //la cantidad de letras, tomando que cuenta que ninguna letra se repite. 
        {
            if(i == init) i = 0;    //La variable que recorre el arreglo se reinicializa en 0 debido a que
            //si sigue aumentando se saldría de las dimensiones del arreglo, imprimiendo así basura. 
            tmp = str[str_size-init+i]; // se guarda la letra que se requiere en un temporal para poder
            //asignarla y hacer el intercambio, de otro modo perderiamos la letra ya que se sobre escribe.
            i++; //se aumenta la variable en 1 para ir recorriendo el arreglo.
            str[str_size-init+i-1] = str[str_size-init+i]; 
            str[str_size-init+i] = tmp;
            printf("%s\n", str);
            x++; //incremento de la variable para que no se cicle infinitamente. 
        }combinaciones(str, init+1, base+1, str_size);
    }
}

/*
    DESCRIPCION
        Funcion que devuelve el factorial de un numero entero.
    PARAMETROS
        - number: numero entero al cual se le determina su factorial.
*/
int factorial(int number)
{
    int i, fact = 1; 
    for(i = 1; i <= number; i++)
        fact *= i;
    return fact;
}
