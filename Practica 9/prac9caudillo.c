#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct nodo
{
    int exponente;
    float valor;
    struct nodo* next;
};

void menu(void);
struct nodo* createQueue(float value, int exp);
struct nodo* insert(struct nodo* inicio, float value, int exp);
void mostrar(struct nodo* inicio);
void generateValueTable(struct nodo* queue);

int main(int argc, char const *argv[])
{
    int x,y;
    menu();
    return 0;
}

void menu(void)
{
    int opc, exponente;
    float value;
    struct nodo* queue = NULL;
    do
    {
        system("cls");
        printf("[1] Capturar t%crmino.\n",130);
        puts("[2] Ver polinomio.");
        puts("[3] Generar tabla de valores.");
        puts("[4] Salir.");
        printf("Opci%cn [ ]\b\b",162);
        scanf(" %d", &opc);

        switch (opc)
        {
            case 1: printf("Capture la funci%cn a evaluar. Ejemplo: Termino-->[2]X%c[3]<--Exponente\n",162,94);
                printf("Termino: "); scanf("%f", &value);
                printf("Exponente: "); scanf("%d", &exponente);
                if(!queue) queue = createQueue(value, exponente);
                else queue = insert(queue, value, exponente);
                break;
            case 2: puts(">>>Ver polinomio<<<");
                mostrar(queue);
                break;
            case 3: puts(">>>Generar tabla de valores<<<");
                generateValueTable(queue);
                setbuf(stdin, NULL);
                getchar();
                break;
        }
    } while (opc != 4);
    free(queue);   
}

struct nodo* createQueue(float value, int exp)
{
    struct nodo* queue = (struct nodo*) malloc(sizeof(struct nodo));
    if(!queue)
    {
        printf("No fue posible la asignaci%cn de memoria a la cola\n",162);
        free(queue);
        exit(EXIT_FAILURE);
    }
    queue->valor = value;
    queue->exponente = exp;
    queue->next = NULL;
    return (queue);
}

struct nodo* insert(struct nodo* inicio, float value, int exp)
{
    struct nodo *p,*q, *nuevo;
    nuevo = createQueue(value, exp);
    p = inicio;
    while(p != NULL){
        q = p;
        p = p->next;
    } q->next = nuevo;
    return inicio;
}

void mostrar(struct nodo* inicio)
{
    struct nodo* aux;
    system("cls");
    if(!inicio) printf("Vacia.\n");
    else
    {
        puts(">>>Polinomio<<<");
        aux = inicio;
        do
        {
            if(aux->valor >= 0) printf("+ ");
            printf("%.1fX%c%d ", aux->valor, 94 ,aux->exponente);
            aux = aux->next;
        } while (aux);
        setbuf(stdin, NULL);
        getchar();
    }
}

void generateValueTable(struct nodo* queue)
{
    struct nodo* aux;
    float x;
    system("cls");
    if(!queue) puts("Cola se encuentra vacia.");
    else
    {
        aux = queue;
        do
        {
            printf("\nFunci%cn %.1fx%c%d\n", 162, aux->valor, 94 ,aux->exponente);
            for(int i = 0; i <= 10; i++)
            {
                printf("f(%.2f) = %.2f\n", x, pow((aux->valor*x), aux->exponente));
                x += 0.5;
            }
            x = 0; 
            aux = aux->next;
        } while (aux);
    }
}