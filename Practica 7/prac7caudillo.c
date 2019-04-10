#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 11 
typedef struct
{
  char interprete[25]; // interprete de la cancion
  char titulo[25]; // Titulo de la cancion
  int duracion; // duracion de la cancion
}song_t;

void showDuration(song_t song);
void delay(int seconds);
void playSong(song_t song);
bool remainMem(int tail);
bool addSong(song_t playlist[MAX], int *tail, int* head);
void rmvSong(song_t playlist[MAX]);

int main(int argc, char const *argv[])
{
  int opc;
  int head = 0, tail = 0;
  clock_t time;
  song_t playlist[MAX];
  do
  {
    system("cls");
    printf("head: %d\ttail: %d\n",head, tail);
    puts("[1] Agregar una cancion a la lista");
    puts("[2] Remover cancion");
    puts("[3] Reproducir lista completa");
    puts("[4] Salida");
    printf("Seleccione una opcion: "); scanf("%d", &opc);
    setbuf(stdin, 0);
    system("cls");
    switch (opc)
    {
      case 1: if(addSong(playlist, &tail, &head) == false)
      {
        printf("No hay espacio en la lista."); 
        getchar();
      }else
      {
        printf("Canci%cn agregada a la lista ...\n", 162);
        getchar();
      }break;
      
      case 2: puts("Removiendo cancion de la lista ...");
      break;
      
      case 3: while(head < tail)
      {
        playSong(playlist[head]);
        head++;
      }puts("Ya no hay mas canciones...");
      getchar();
      break;
    }
  } while(opc != 4);
  system("cls");
  return 0;
}

/*
  Descripcion
  Parametros
    -song:
*/
void showDuration(song_t song)
{
  int sec = 0, min = 0;
  int remainingSec;
  remainingSec = song.duracion - ((song.duracion/3600)*3600);
  min = remainingSec/60;
  remainingSec -= (min*60);
  sec = remainingSec;
  printf("%d:%d\n", min, sec);
}

/*
  Descripcion
  Parametros
    -secods:
*/
void delay(int seconds) 
{ 
  int milli_seconds = 1000 * seconds;  
  clock_t start_time = clock(); 
  while (clock() < start_time + milli_seconds); 
} 

/*
  Descripcion
  Parametros
    -song:
*/
void playSong(song_t song)
{
  system("cls");
  int x=0;
  int sec = 0, min = 0;
  for (int i = 0; i < song.duracion; i++) 
  { sec = i+1;
  if(i+1 > 59){
      sec -= x ;
      x++;
      min++;
    }   
    printf("%s by %s\t%0d:%0d", song.titulo, song.interprete, min, sec); 
    delay(1);
    
      
    system("cls");
  } 
}

/*
  Descripcion
    Funcion que devuelve un dato tipo booleano. La funcion verifica si en la cola 
    aun existe espacio disponible para almacenar datos en ella, si es asi devuelve
    'true', caso contrario 'false'.
  Parametros
    -tail: verifica que el apuntador de la cola no haya rebasado el limite permiti-
    do de datos a guardar en la cola.
*/
bool remainMem(int tail)
{
  if(tail <  MAX ) return (true); //Aun hay espacio disponible
  else return (false); // Ya no hay espacio disponible en la cola
}
/*
  Descripcion
  Parametros
    playlist:
    tail:
*/
void getData(song_t playlist[MAX], int tail)
{
  puts("<<< Ingrese los siguientes datos >>>");
  printf("Interprete: ");               gets(playlist[tail].interprete);
  printf("Titulo: ");                   gets(playlist[tail].titulo);
  printf("Duraci%cn (segundos): ",162); scanf("%d", &playlist[tail].duracion);
  getchar();
  system("cls");
}
/*
  Descripcion
  Parametros
    -playlist:
    -tail:
    -head:
*/
bool addSong(song_t playlist[MAX], int *tail, int *head)
{
  if (remainMem(*tail) == false) return false; // ya no hay espacio displonible
  getData(playlist, *tail);
  *tail += 1;
  return true; // Se ha agregado con exito la cancion.
}