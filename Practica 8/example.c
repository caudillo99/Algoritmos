#include <string.h>  
#include <stdio.h>  
#include <stdlib.h>
// Driver program to test above functions  
void printStr(char* str);
char *getStr(void);
int main()  
{  
    char *str = getln();
    printStr(str);
    return 0;  
}

void printStr(char* str)
{ for(int i = 0; str[i]; i++) printf("%c", str[i]); }

char *getStr(void)
{
    char *line = NULL, *tmp = NULL;
    size_t size = 0, index = 0;
    int ch = EOF;

    while (ch)                                  // Mientras  
    {
        ch = getc(stdin);
        if (ch == EOF || ch == '\n') ch = 0;    // Verifica si necesitamos parar.
        if (size <= index)                      // Verificamos si necesitamos expandir memoria
        {        
            size += 2;                          // Expandemos memoria con 2 locaciones más.
            tmp = realloc(line, size);          // Expandemos el bloque de memoria reservado anteriormente.
            if (!tmp)                           // En caso de que no se pueda reservar memoria.    
            {        
                free(line);                     // Liberamos la memoria reservada.
                line = NULL;                    // Terminamos en null la cadena.
                break;       
            }line = tmp;                        // Le pasamos la dirección expandida a nuestra cadena para 
                                                // seguir escribiendo.
        }
        /* Actually store the thing. */
        line[index++] = ch;                     // Almacenamiento del dato capturado.
    }return line;                               // Regresa la direccion donde se ha guardada la cadena.
}