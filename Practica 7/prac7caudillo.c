#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct
{
  char interprete[25];
  char titulo[25];
  float duracion;
}cancion_t;

void addSong(char cola[][25], cancion_t cancion);
void rmvSong(char cola[][25], cancion_t cancion);

int main(int argc, char const *argv[])
{
  int opc, sp;
  do
  {
      puts("[1] Agregar una cancion a la lista");
      puts("[2] Remover cancion");
      puts("[3] Reproducir lista completa");
      puts("[4] Salida")
      printf("Seleccione una opcion: "); scanf(" %d ", &opc);
      switch (opc)
      {
        case 1: puts("Agregando cancion a la lista ...");
        break;
        case 2: puts("Removiendo cancion de la lista ...");
        break;
        case 3: puts("Reproduciendo lista completa ...");
        break;
      }

  } while(opc != 4);

  return 0;
}
