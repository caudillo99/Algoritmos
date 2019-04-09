/*
Elabore un programa que fusione ambas pilas en una tercera ordenada
descendentemente. NOTA: no debe utilizar más de 3 pilas, pero si puede
utilizar como base las funciones y métodos de pila vistos en clase. 
Por ejemplo, si la pila 1 contiene los títulos:
 Del amor y otros demonios,
 El Perfume,
 Marianela
y la pila 2 contiene
 Casa de campo,
 Las batallas en el desierto,
 Mujeres de ojos grandes,
 Rayuela

la pila resultante debe ser
 Casa de campo
 Del amor y otros demonios
 El perfume
 Las batallas en el desierto
 Marianela
 Mujeres de ojos grandes
 Rayuela
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Headers*/
void printData(char stack[][30]);
int push (char stack[][30], int* sp, char*data);
int pop (char stack[][30], int *sp, char *data);
void clrRow(char stack[][30], int sp);
void clrData(char* data);

int main(int argc, char const *argv[])
{ 
    /*Declaracion de pilas*/
    char stack1[5][30] = {"Del amor y otros demonios", "El perfume", "Marianela"};
    char stack2[5][30] = {"Casa de campo", "Las botellas en el desierto", "Mujeres de ojos grandes", "Rayuela"};
    char stack3[10][30] = {0};
    char data[30] = {0};
    int sp_s1 = 0, sp_s2 = 0, sp_s3 = 9, ov; //Stack Pointer
    
    if((ov =pop(stack2, &sp_s2, data)) == -1) exit(-1);
    printf("Dato que sale de la pila 2: %s\tOverflow: %d\tStack Pointer: %d\n\n", data, ov, sp_s2);
    push(stack3, &sp_s3, data);
    
    if((ov =pop(stack1, &sp_s1, data)) == -1) exit(-1);
    printf("Dato que sale de la pila 1: %s\tOverflow: %d\tStack Pointer: %d\n\n", data, ov, sp_s1);
    push(stack3, &sp_s3, data);
    
    if((ov =pop(stack1, &sp_s1, data)) == -1) exit(-1);
    printf("Dato que sale de la pila 1: %s\tOverflow: %d\tStack Pointer: %d\n\n", data, ov, sp_s1);
    push(stack3, &sp_s3, data);
    
    if((ov =pop(stack2, &sp_s2, data)) == -1) exit(-1);
    printf("Dato que sale de la pila 2: %s\tOverflow: %d\tStack Pointer: %d\n\n", data, ov, sp_s2);
    push(stack3, &sp_s3, data);

    if((ov =pop(stack1, &sp_s1, data)) == -1) exit(-1);
    printf("Dato que sale de la pila 1: %s\tOverflow: %d\tStack Pointer: %d\n\n", data, ov, sp_s1);
    push(stack3, &sp_s3, data);
    
    if((ov =pop(stack2, &sp_s2, data)) == -1) exit(-1);
    printf("Dato que sale de la pila 2: %s\tOverflow: %d\tStack Pointer: %d\n\n", data, ov, sp_s2);
    push(stack3, &sp_s3, data);
    
    if((ov =pop(stack2, &sp_s2, data)) == -1) exit(-1);
    printf("Dato que sale de la pila 2: %s\tOverflow: %d\tStack Pointer: %d\n\n", data, ov, sp_s2);
    push(stack3, &sp_s3, data);

    puts("*** Pila resultante ***");
    printData(stack3);

    return 0;
}
/*
    Descripcion
        Funcion que muestra los datos dentro de una pila, la funcion recibe
        como parametro la pila que se desea mostrar sus datos. La funcion no
        devuelve ningun valor.
    Parametros
        - stack: Pila la cual se quiere mostrar sus datos.
*/
void printData(char stack[][30])
{
    for(int i = 9; i >= 0; i--)
    {
        for(int j = 0; stack[i][j] != 0; j++)
        {
            printf("%c", stack[i][j]);
        }
        printf("\n");
        if(stack[i][0] == 0) break;
    }
}

/*
    Descripcion:
        Funcion que mete un dato hacia a la pila siguiendo el formato de LIFO.
        la funcion devuelve un -1 si el STACK POINTER excede el valor de los datos que puede
        almacenar indicando que existe un OVERFLOW o desbordamiento. Caso contrario devuelve
        un 1 indicando que el dato se ha almacenado de manera correctamente. 
    Parametros
        -stack: pila donde se va almacenar el dato
        -sp: sp (stack pointer) es la posicion donde se encuentra acutalmente 
        apuntando la pila.
        -data: arreglo del cual el dato va ser extraido para ser insertado en la pila.
*/
int push(char stack[][30], int* sp, char* data) 
{
    int i = 0;
    if(*sp < 0) return -1; // underflow
    while(data[i] != 0){
       stack[*sp][i] = data[i];
       i++;
    } *sp-=1;
    clrData(data);
    return 0; // Push completed!
}
/*
    Descripcion: 
        Funcion que remueve un dato de la pila siguiendo el formato de LIFO
        el cual consiste en el ultimo que entra va ser el primer dato en salir. SP se aumenta
        para pasar al siguiente dato de la pila.
        La funcion devuelve un -1 indicando que ha habido un UNDERFLOW el cual se da 
        cuando el STACK POINTER ha llegado a un valor menor que 0. Se devuelve un 1 cuando
        se haya removido un dato de manera exitosa. 
    Parametros
        -stack: pila de la cual va ser removido el dato indicado por SP.
        -sp: sp (stack pointer) es la posicion donde se encuentra acutalmente 
        apuntando la pila.
        -data: es un arreglo donde el dato extraido de la pila va ser almacenado.
*/
int pop(char stack[][30], int* sp, char* data)
{
    int i = 0;
    if(*sp >= 10) return -1; //Overflow
    while(stack[*sp][i] != 0)/*se reemplaza por 0 la palabra que ha salido de la pila*/
    {
        data[i] = stack[*sp][i];
        i++;
    }
    clrRow(stack, *sp);
    *sp+=1;
    return 0; //dato que salio de la pila
}

/*
    Descripcion
        Funcion que limpia un renglon de la pila indicado por sp.
        Esta funcion se utiliza para asegurse que al remover un
        dato con la instruccion pop haya sido limpiado todo el
        dato completo reemplazandolos por 0.
    Parametros
        -stack: pila a la cual se le borra un dato
        -sp: apuntador de pila que posicion va ser limpiado.
*/
void clrRow(char stack[][30], int sp)
    while(stack[sp][i] != 0)
    {
        stack[sp][i] = 0;
        i++;
    }
}

void clrData(char* data)
{
    int i =0 ;
    while(data[i] != 0){
        data[i] = 0;
        i++;
    }
}