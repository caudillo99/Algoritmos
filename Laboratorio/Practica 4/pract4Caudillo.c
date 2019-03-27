/*
DESCRIPCION
Crear un programa en el cual se declare un vector con palabras, para despues hacer una 
busqueda binaria, la cual consiste en tener todos los datos ordenados en orden alfabetico
y mediante un un pivote, el cual inicia en el centro del vector y apartir de esa posicion
el pivote se desplaza a la derecha o izquierda, dependiendo si el caso base no es igual a 
a la palabra que se este buscando dentro del vector. 

NOTA
•Los datos DEBEN ser cadenas de caracteres, no numéricos.
• No se pide que capture las cadenas, inicialice los arreglos con palabras en orden alfabético.
▪ Las funciones deben presentar en todo momento en pantalla los datos sobre los que se está realizando
la Búsqueda.

*/

#include <stdio.h>
#include <string.h>
#include <time.h>

void printData(int posicion, char *key, time_t time, int iterations);
int binarySearchIterativo(char str[20][11], char* key, int init, int str_size, int *iterations);
int binarySearchRecursivo(char str_vec[20][11], char* key, int init, int str_size, int *iterations);
void copyString(char str_vector[20][11], char* str, int index);

int main(int argc, char const *argv)
{
    char str_vec[20][11] = {"aaaaaaaaaa","bbbbbbbbbb","cccccccccc","dddddddddd","eeeeeeeeee","ffffffffff", 
    "gggggggggg", "hhhhhhhhhh", "iiiiiiiiii", "jjjjjjjjjj", "kkkkkkkkkk", "llllllllll", "mmmmmmmmmm", "nnnnnnnnnn", 
    "oooo", "qqqqq", "rrrrr"}; 
    char key[11];
    int str_size = sizeof(str_vec)/sizeof(str_vec[0]), init = 0, ans_iter, ans_recursivo, iterations = 0;
    time_t time;

    printf("Palabra que desea buscar: "); gets(key);
    
    // impresion de busqueda binaria de forma iterativa
    time = clock(); //inicia de la ejecucion
    ans_iter = binarySearchIterativo(str_vec, key, init, str_size-1, &iterations);
    puts("      >>>> Iterativo <<<<");
    time = clock()-time; // fin de la jecucion 
    printData(ans_iter, key, time, iterations); // impresion de los datos.

    // impresion de busqueda binaria de forma recursiva
    time = clock(); // inicio del tiempo
    ans_recursivo = binarySearchRecursivo(str_vec, key, init, str_size-1, &iterations); 
    puts("      >>>> Recursivo <<<<");
    time = clock()-time; // fin del tiempo de ejecucion
    printData(ans_recursivo, key, time, iterations); // impresion de datos
        
    return 0;
}
/*
DESCRIPCION: 
    funcion que imprime los siguientes datos: la posicion donde se encontro (si es que fue asi),
    tiempo de ejecucion de la funcion y el numero de iteraciones.
PARAMETROS
    - posicion: entero en la posicion donde se encontro la cadena. Si es -1 significa que no se encontro.
    - key: palabra que el usuario quiera encontrar.
    - time: tiempo de ejecucion de la funcion.
    - iterations: numero de iteraciones que realizo la busqueda.
*/
void printData(int posicion, char *key, time_t time, int iterations)
{
    double total_time = ((double)time)/CLOCKS_PER_SEC;
    /* impresion de datos en caso de que no se encuentre la cadena en el arreglo*/
    if(posicion == -1) 
    {
        printf("No se encontro la palabra [%s]\n\n", key);
        printf("Tiempo de ejecucion: %f seconds\n", total_time);
        printf("Numero de iteraciones: %d\n\n", iterations);
    }
    /* impresion de los datos cuando la busqueda haysa sido exitosa.*/
    else 
    {
        printf("La palabra [%s] se encontro en la posicion [%d]\n\n", key, posicion);
        printf("Tiempo de ejecucion: %f seconds\n", total_time);
        printf("Numero de iteraciones: %d\n\n", iterations);
    }
}
/*
DESCRIPCION:
    funcion que busca una palabra dentro de un arreglo, mediante un algoritmo de busqueda el cual consiste
    en cadenas ordenadas en orden alfabetico. Mediante un pivote el cual apunta en la posicion media del 
    arreglo y de ahi parte si es que se debe mover hacia izquierda o derecha dependiendo si la letra de la
    palabra que se esta buscando es menor o mayor a la palabra posicionada en el medio del arreglo.
    La funcion regresa la posicion de donde se haya encontrado la palabra, caso contrario retorna un -1.
PARAMETROS
    - str_vec: vector llena con cadenas. 
    - key: palabra la cual se quiere buscar.
    - init: inicio del arreglo
    - str_size: tamaño de la cadena.
    - iterations: cantidad de iteraciones que realiza la funcion al buscar una palabra.
*/
int binarySearchIterativo(char str_vec[20][11], char* key, int init, int str_size, int *iterations)
{
    char str_aux[20] = {0}; // cadena auxiliar para comparar palabras. 
    while(init <= str_size)
    {
        int pivot = init + (str_size-init)/2; // se inicializa nuestro pivote, el cual apunta en medio del arreglo.
        *iterations += 1; // cantidad de itraciones que realiza el programa.
        if((int)key[0] == (int)str_vec[pivot][0]) // si la llave y el arreglo en la posicion inicial del pivote coinciden
        // en la primera letra entonces entra a la condicion para despues comparar toda la cadena.
        {
            copyString(str_vec, str_aux, pivot);
            if( strcmp(key, str_aux ) == 0) return pivot; // si la comparacion devuelve un 0, significa que ambas cadenas
            // son iguales. 
        }
        if(str_vec[pivot][0] < key[0]) init = pivot+1; // si la letra inicial de la llave es mayor a la posicion inicial de
        // pivote, entonces se busca en el lado derecho del arreglo.
        else str_size = pivot-1; // caso contrario se busca en el lado izquierdo.
    }//*exe_time = clock()/CLOCKS_PER_SEC; // cantidad de tiempo en que se ejecuto el programa.
    return -1; // Retorna un -1 en caso de no encontrarse en el arreglo.
}
/*
DESCRIPCION:
    Funcion que busca una palabra en un array de cadenas de manera recursiva. La funcion se vuelve a 
    llamar en caso de que no se encuentre en la posicion inicial, lo cual significa que tendra despues 
    de la primera iteracion se tendra que buscar en el lado derecho o izquierdo, dependiendo de la palabra
    que se este buscando. La funcion devuelve la posicion donde se haya encontrado, caso contrario devuelve
    un -1 en caso de que no se encuentre. 
PARAMETROS
    - str_vec: vector llena con cadenas. 
    - key: palabra la cual se quiere buscar.
    - init: inicio del arreglo
    - str_size: tamaño de la cadena.
    - iterations: cantidad de iteraciones que realiza la funcion al buscar una palabra.
*/
int binarySearchRecursivo(char str_vec[20][11], char* key, int init, int str_size, int* iterations) 
{ 
    char str_aux[20] = {0}; // cadena auxiliar que se utiliza para comparar palabras.
    
    if (str_size >= init) 
    { 
        //*exe_time += clock()/CLOCKS_PER_SEC; // tiempo de ejecucion. A cada llamada se le suma el tiempo anterior.
        int pivot = init + (str_size - init) / 2; // pivote inicial donde se inicia la busqueda, la cual cambia depende
        // si la letra esta a la derecha o izquierda
        if (str_vec[pivot][0] == key[0]) // se comprueba que si la letra esta en el medio inmediatamente se devuelve la posicion
        // esta condicion es nuestro caso base de la recursion. 
        {
            copyString(str_vec, str_aux, pivot); // copia una cadena basandose en la letra inicial, si son iguales regresa un 1.
            if( strcmp(key, str_aux) == 0) return pivot;
        } 
        if (str_vec[pivot][0] > key[0]) // en caso de que la letra se encuentre de lado izquierdo de nuestro pivote inicial
        // retorna un llamado a la funcion, restandole un 1 al pivote para asi recorrer la busqueda hacia la izquierda.
            return binarySearchRecursivo(str_vec, key,  init, pivot-1, iterations+1); // De otro modo la cadena se 
        else
            return binarySearchRecursivo(str_vec, key, pivot+1,str_size,  iterations+1); // busca hacia el lado derecho
            // sumandole un 1 al pivote. 
    }return -1; // si recorre todo el arreglo y no encuentra la palabra, entonces devuelve un -1.
} 
/*
DESCRIPCION:
    Funcion que copia una cadena del vector de cadenas. Copia respecto a la posicion que se le mande
    como parametro.
PARAMETROS
    - str_vector: vector de cadenas de la cual se va extraer la palabra.
    - str: lugar donde se va a guardar la cadena solicitada.
    - index: indice de la cadena que va a copiar.
*/
void copyString(char str_vector[20][11], char* str,int index)
{
    int i = 0;
    /*copia la cadena respecto al pivote*/
    while(str_vector[index][i] != 0)
    {
        str[i] = str_vector[index][i];
        i++;
    }
}