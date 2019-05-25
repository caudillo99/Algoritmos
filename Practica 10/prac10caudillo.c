/**
 * Practica 10. Metodo de ordenamiento Quicksort
 * Alumno: Caudillo Sanchez
 * Grupo: 551
 * Asignatura: Algoritmos y estructura de datos
 * Docente: Alma Leticia Guerrero Palacios.
 
 * Descripcion de la practica
    Utilizando un arreglo de 10 elementos la estructura mencionada, ordene en forma ascendente (a-z) los
    datos por nombre.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char name[15] ;
    char carrera[20];
    float promedio;
    int creditos;
}alumno_t;

//Funciones prototipo
void menu(alumno_t lista[10]);
void fillList(alumno_t lista[10]);
void quickSort(alumno_t lista[10], int inicio, int final, int cont);
int partition (alumno_t lista[10], int inicio, int final);
void swap(alumno_t *alumno, int i, int j);
void printData(alumno_t lista[10], int index);

int main(int argc, char const *argv[])
{
    alumno_t lista[10]; //declaracion de una lista de 10 alumnos con sus atributos.
    menu(lista);
    return 0;
}

/*
    DESCRIPCION:
    PARAMETROS
*/
void menu(alumno_t lista[10])
{
    int inicio = 0, index = 9, opc, cont = 0;
    clock_t t; 
    do
    {
        system("cls");
        puts("[1] Llenar lista");
        puts("[2] Ordernar datos ascendetemente");
        puts("[3] Mostrar datos");
        puts("[4] Salir");
        printf("Opci%cn: ",162); scanf("%d", &opc);
        setbuf(stdin, NULL);
        switch (opc)
        {
        case 1: fillList(lista);
            break;
        case 2: t = clock(); 
            quickSort(lista, inicio, index-1,cont);
            t = clock() - t; 

            double time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("quickSort() took %lf seconds to execute \n", time_taken); 
            printData(lista, index);
            getchar();
            break;
        case 3: printData(lista, index);
            getchar();
            break;
        }
    } while (opc != 4);
}
/*
    DESCRIPCION:
    PARAMETROS
*/
void fillList(alumno_t alummo[10])
{
    srand(time(NULL)); 

    char name[10][15] = {"Miguel","Eduardo", 
    "Luis","Carlos","Ana","Daniel",
    "David","Jorge","Ricardo", "Alejandro"};

    //char name[10][15] = {"Ana","Carlos","Daniel","David","Eduardo",
    //"Jorge","Luis", "Miguel","Ricardo"};


    char carrera[] = "computacion";
    for (int i = 0; i < 9; i++)
    {
       strcpy(alummo[i].name, name[i]); //copia el nombre del listado
       strcpy(alummo[i].carrera, carrera);
       //rand() % (max_number + 1 - minimum_number) + minimum_number
       alummo[i].promedio = (float)(rand() % (100+1 - 60) + 60);
       alummo[i].creditos = (rand() % (280+1 - 100) + 100);
    }
}
/*
    DESCRIPCION:
        Funcion de ordenamiento, el cual ordena una lista de
        alumnos por nombre de manera ascendente. El ordena-
        miento lo maneja de manera recursiva.
    
    PARAMETROS
        -> lista: arreglo del tipo alumno_t que contiene
        la informacion de 10 alumnos y de la cual se 
        -> inicio: indica la posicion inicial del arreglo
        -> final: indica la posicion final del arreglo.
*/
void quickSort(alumno_t lista[10], int inicio, int final, int cont)
{
    if (inicio < final)
    {
        //cont ++;
        //printf("%d\n", cont);
        int index = partition(lista, inicio, final);
        quickSort(lista, inicio, index-1, cont);
        quickSort(lista, index+1, final, cont);
    }
}

/*
    DESCRIPCION:
        Esta funcion toma el ultimo elemento como pivote,
        colocandolo en la posicion correcta en el arreglo
        y posicion todos los elementos menores a la 
        izquierda del pivote y los mayores a la derecha.
    
    PARAMETROS
        -> lista: arreglo del tipo alumno_t que contiene
        la informacion de 10 alumnos y de la cual se 
        va acomodar por nombres de manera ascendete.
        -> inicio: indica la posicion inicial del arreglo
        -> final: indica la posicion final del arreglo.
*/
int partition (alumno_t lista[10], int inicio, int final)
{
    alumno_t *pivote = &(lista[final]);
    int i =  inicio - 1;
    for (int j = inicio; j <= final - 1; j++)
    {
        if(strcmp(lista[j].name, pivote->name) <= 0)
        {
            i++;
            swap(lista, i,j);
        }
    }swap(lista, i+1, final);
    return(i+1);
}


/*
    DESCRIPCION:
        Funcion que intercambia el contenidodos estructuras 
        del tipo alumno_t. La funcion no retorna un valor.

    PARAMETROS
        -> alumno: arreglo del tipo alumno_t de la cual se
        eligira las posiciones a cambiar dadas por i y j.
        -> i: primer indice de valor a intercambiar
        -> j: segundo indice de valor a intercambiar
*/
void swap(alumno_t alumno[10], int i, int j)
{
    alumno_t tmp = alumno[i]; // se guarda en la posicion i
    alumno[i] = alumno[j];  // intercambio del primer indice
    alumno[j] = tmp; // intercambio del segundo indice
}

/*
    DESCRIPCION:
        Funcion que imprime los datos de una lista de alumnos. 
        Los datos que imprime son los siguientes:
        -> Nombre del alumno
        -> Carrera a la que pertence
        -> Promedio del alumno
        -> Creditos cursados
        La función no retorna un valor.
    
    PARAMETROS
        -> lista: arreglo del tipo alumno_t que contiene los datos de los alumnos.
        -> index: cantidad de alumnos en la lista. Es un indice que indica cuantos
        alumnos va a mostrar en pantalla.
*/
void printData(alumno_t lista[10], int index)
{
    printf("Nombre\t Carrera\tPromedio\tCr%cditos\n\n",130);

    for(int i = 0; i < index; i++ )
    {
        printf("%s\t" ,lista[i].name);
        printf(" %s\t" ,lista[i].carrera);
        printf("  %.2f\t" ,lista[i].promedio);
        printf("\t%d\n", lista[i].creditos);
    } 
}
