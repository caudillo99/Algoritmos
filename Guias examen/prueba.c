#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

typedef struct
{
    int tope;
    int dato[MAX];
}stack_t;

void push(stack_t *stack, int x);
int pop(stack_t *stack);
int vacia(stack_t *stack);
int llena(stack_t *stack);

int main(int argc, char const *argv[])
{
    stack_t stack = {0};
    char opc;
    int num;
    do
    {
        system("cls");
        printf("Tope: %d\n", stack.tope);
        puts("[1] Meter un elemento");
        puts("[2] Sacar un elemento");
        puts("[3] Tamanio de la pila");
        puts("[4] Salida");
        printf("Opcion: "); scanf("%d", &opc);
        setbuf(stdin, 0);
        switch (opc)
        {
            case 1: if(llena(&stack) == 0)
                {
                    printf("Que dato desea ingresar ");
                    scanf("%d", &num);
                    push(&stack, num);
                }else
                {
                    printf("Pila llena");
                    getchar();
                } break;
            case 2: if(!vacia(&stack)) 
                {
                    printf("%d", pop(&stack));
                    getchar();
                }else printf("La pila esta vacia");
                getchar();
                break;
            case 3:printf("Hay %d datos", stack.tope);
                getchar();
                break;
        }
    } while (opc != 4);
    
    return 0;
}

void push(stack_t *stack, int x)
{ stack->dato[stack->tope] = x; }

int pop(stack_t *stack)
{ return (stack->dato[--(stack->tope)]); }

int vacia(stack_t *stack)
{
    if(stack->tope == 0) return 1;
    else return 0;
}

int llena(stack_t *stack)
{
    if (stack->tope == MAX) return 1;
    else return 0;
}