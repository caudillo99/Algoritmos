/*
Alumno: Caudillo Sanchez Diego
Matricula: 1249199
Grupo: 551
Asignatura: Algoritmos y estructuas de datos
Docente: Alma Leticia Palacios Guerrero
Fecha de entrega: 29-marzo-2019

DESCRIPCION DEL PROGRAMA
Se pide diseñar e implementar un algoritmo basado en pilas estáticas que 
reciba una y evalúe una expresión dada por el usuario y determine si es 
un palíndromo o no.
*/

/*Librerias utilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Headers*/
void deleteSpace(char* array);
int palindrome(char* array);
void push(char* array, char* stack);
char pop(char* stack, int index);
void printStack(int size, char* stack);

/*Funcion main, donde se ejecutan todas los metodos creados*/
int main(int argc, char const *argv[])
{
    char array[20] = {0};
    int opc;
    while(opc != 0)
    {
        printf("Ingrese palabra: ");
        gets(array);
        deleteSpace(array);
        // si devuelve -1 no es palindrome, caso contrario si lo es.
        if(palindrome(array) == -1) printf("==========================\n==== No es palindrome ====\n==========================\n");
        else printf("=========================\n===== Es palindrome =====\n=========================\n");
        setbuf(stdin, 0);
        printf("Presiones '0' si quiere salir... "); scanf("%d", &opc);
        setbuf(stdin, 0);
    } 
    return 0;
}
/*
    Descripcion
        Funcion que recorre un vector buscando espacios para borrarlos.
    Parametros
        -array: arreglo de caracteres el cual se van a borrar los espacios. 
*/
void deleteSpace(char* array)
{
    for(int i=0; array[i] != 0; i++ )
    {
        if(array[i] == ' ') 
        {
            for(int j = i; array[j] != 0; j++ )
                array[j] = array[j+1];
        }
    }
}
/*
    Descripcion
        Funcion que realiza un push de un vector hacia la pila. La funcion mete el 
        vector entero a la pila.
    Parametros
        -array: es el arreglo el cual se va introducir a la pila.
        -stack: un arreglo el cual se reserva como la pila y donde los datos que 
        recibe son del "array"
*/
void push(char* array, char* stack)
{
    //array[position] = 0;
    for(int i=strlen(array)-1, j=0; i >= 0; i--,j++)
        stack[j] = array[i];
}
/*
    Descripcion
        Funcion que realiza un pop a la pila, quiere decir que extrae un dato de ella.
        la funcion solo va removiendo datos de uno en uno. Devuelve el dato extraido.
    Parametros
        -stack: array el cual actua como la pila y es la cual de donde se extraen los 
        datos.
        -index: la posicion actual donde se la pila quedo apuntada.
*/
char pop(char* stack, int index)
{
    char data_out;
    data_out = stack[index]; // guarda el dato que salio
    stack[index] = 0; // coloca un cero en la posicion del dato que salio, indicando 
    // que esa posicion se ha vaciado.
    return data_out; // regresa el dato sacado de la pila.
}
/*
    Descripcion
        Funcion que imprime los datos actuales en la pila.
    Parametros
        -size: entero el cual tiene el tamano de la pila
        -stack: la pila, de la cual sevan a extraer los datos 
*/
void printStack(int size, char* stack)
{
    for(int i = 0; i < size; i++)
           printf("|_%c_|\n", stack[i]);
}
/*
    Descripcion
        Funcion que verifica un arreglo si son palindromes con la ayuda de pila.
        Primeramente el arreglo se carga en la pila (LIFO) y se van comparando
        los caracteres de la pila y del arreglo, si todos coinciden, quiere decir
        que la palabra es palindrome y se retorna un valor de 1, caso contrario se
        devuelve un -1 indicando que la palabra o frase no es palindrome.
    Parametros
        -array: arreglo que contiene la palabra o frase que se quiere verificar si
        es palindromo o no. 
*/
int palindrome(char* array)
{
    char stack[20], letra;
    int index=0;
    push(array,stack); // se realiza un push del arreglo.
    puts("STACK");
    while(index <= strlen(array))
    {
        printStack(strlen(array),stack); // impresion del stack con datos actualizados
        if(index < strlen(array))
        {
            printf("\n==>Actualizado<==\n");
            letra = pop(stack, index); // letra contiene el dato de cuando se realiza un pop.
            printf("Dato que salio: [%c]\n", letra);
            // Si el dato extraido de la pila no coincide con el dato del arreglo
            // entonces se devuelve un -1 indicando que la palabra no es palindrome.
            if(letra != array[index]) 
            {
                printf("[%c] es diferente de [%c]\n", letra, array[index]);
                return -1;
            }       
        }index++;
    }return 1; // si al recorrer todo el arreglo y las letras coinciden, entonces la palabra en palindrome.
}