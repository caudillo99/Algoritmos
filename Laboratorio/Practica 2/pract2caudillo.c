/*Librerias a utilizar*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*Estructura de datos con la informacion para determinar la proyeccion de una camdada*/
typedef struct 
{
    int camada;
    int proyeccion;
    int vecesAnio;
}animal_t;

/*Cabecera de las funciones*/
void capturaDatos(animal_t* perro);
long int determinarProyeccionCiclico(animal_t perro, long int* time_ciclico);
void determinarProyeccionRecursivo(animal_t perro,int x, long int * ans, long int* time_recursivo);

int main(int argc, char const *argv[])
{
    animal_t perro;
    long int total = 0, counter = 1, time_recursivo = 0, time_ciclico = 0; // variables para la función recursiva.
    capturaDatos(&perro);       // captura de los datos 
    determinarProyeccionRecursivo(perro,counter, &total, &time_recursivo); // llamada a la función recursiva
    printf("**************************************************\n");
    printf("Proyecci%cn en %d a%cos (Ciclico): %ld\n",162, perro.proyeccion, 164,determinarProyeccionCiclico(perro, &time_ciclico)); //impresion de los datos
    printf("Proyecci%cn en %d a%cos (Recursivo): %ld\n",162, perro.proyeccion, 164, total/2) ;
    /*impresión de los tiempos de cada función*/
    printf("Tiempo en funci%cn ciclico = %ld ms\n",162, time_ciclico);
    printf("Tiempo en funci%cn recursivo = %ld ms\n",162, time_recursivo);
    return 0;
}
/*
    DESCRIPCION
        Funcion la cual permite capturar los datos de sobre la informacion de un perro al tener una camada. 
    PARAMETROS:
        perro: estructura de datos con la informacion para determinar la proyeccion la camada de un perro. 
*/
void capturaDatos(animal_t* perro)
{
    /*captura cada una de la información necesaria para guardarla en la estructura y despues poder usarla
    en las funciones siguientes.*/
    printf("Tama%co de la camada: ", 164); scanf("%ld", &perro->camada);
    printf("Veces al a%co: ", 164); scanf("%ld", &perro->vecesAnio);
    printf("A%cos de proyecci%cn: ", 164, 162); scanf("%ld", &perro->proyeccion);
}
/*
    DESCRIPCION:
        Función la cual determina la proyección a futuro de las camadas. La información 
        para resolver el problema se encuentra en la estructura de datos que se envia 
        como parametro. La funcion determina la proyección mediante ciclos iterativos for
        y do-while.
    PARAMETROS:
        perro: se encuatra la información sobre la cantidad de veces que se tiene una camada
        al año, el tamaño de la camada, asi como la años de proyección
        time_ciclo: variable donde se guarda el tiempo de ejecución de la función
*/
long int determinarProyeccionCiclico(animal_t perro, long int* time_ciclico)
{
    int i, total = 0;
    /* el ciclo do-while se ejecuta mientras la proyeccion se mayor a 0.
    Ya que la funcion primero calcula la cantidad de perros del ultimo año hacia el primero,
    y va creciendo exponencialmente mientras la variable de control sea mayor a 0. */ 
    do
    {
        for(i = 0; i < perro.proyeccion ; i++) 
            total += pow((perro.camada * perro.vecesAnio),i+1);   
        perro.proyeccion--; // se decremente el valor de la proyección con el fin de que no se cicle infinitamente. 
    } while (perro.proyeccion > 0);
    *time_ciclico = clock()/CLOCKS_PER_SEC;
    return total/2; // regresa la mitad, ya que las instrucciones pide este requerimiento. 
}
/*
    DESCRIPCION:
        Función la cual determina la proyección a futuro de las camadas. La información 
        para resolver el problema se encuentra en la estructura de datos que se envia 
        como parametro. La funcion determina la proyección mediante recursion, quiere decir
        que se llama así mismo y modifica los datos para que a lasiguiente llamada se vayan
        iterando, todo esto con una condicion que controla que el ciclo no se cicle infinitamente
        o hasta que haya un stack overflow (des).
    PARAMETROS:
        perro: estrcutura de datos en la cual se encuentra la informacion del perro para determinar
        la proyeccion deseada. 
        counter: variable de control que permite controlar el numero de llamadas (recursion) a la 
        funcion para llegar al resultado deseado.
        total: vatiable en la cual se guarda el resultado de la proyeccion.
        time_recursivo: variable donde se guarda el tiempo de ejecución de la función
*/
void determinarProyeccionRecursivo(animal_t perro,int counter, long int* total, long int *time_recursivo)
{
    if(perro.proyeccion == 0) *total = 1;    // Si el año de proyeccion es 0, inmediatamente el 
    // resultado es 1 ya que solo se esta contando a la hembra     
    else
    {
        if(counter <= perro.proyeccion) //mientras la variable de control no llegue al año de proyección 
        //esperado, seguirá llamando a la función así misma
        {
            *total += pow(perro.camada*perro.vecesAnio,counter)+ *total; // En cada llamada se le suma el resultado anterior,
            // de otro modo el resultado fuera incorrecto, devolviendo así, la cantidad de perros de solo el primero año, en 
            // caso de que sea mas de un año de proyección.
            determinarProyeccionRecursivo(perro, counter+1, total, time_recursivo); // La funcioón llamandose así misma. 
        }    
    }*time_recursivo += clock()/CLOCKS_PER_SEC;
}