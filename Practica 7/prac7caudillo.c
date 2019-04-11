/*
<<<Descripcion del programa>>>
Un dispositivo reproductor de canciones tiene capacidad para una cantidad limitada de canciones, se le pide
implementar un programa basado en el principio FIFO para administrar las canciones de la lista. Se desea que 
la aplicación cuente con las siguientes opciones:
  1) Agregar una canción a la lista
  2) Remover canción
  3) Reproducir lista completa.
  4) Salida

Por cada canción se registra la siguiente información:
   Intérprete,
   título
   duración.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 11 // Cantidad maxima de canciones que se pueden guardar.

// Estructura de tipo cancion que contien la informacion
// necesaria para capturar una cancion.
typedef struct
{
  char interprete[25]; // interprete de la cancion
  char titulo[25]; // Titulo de la cancion
  int duracion; // duracion de la cancion
}song_t;

//Funciones prototipo de las funciones creadas
void clrData(song_t playlist[MAX], int tail);
bool removeSong(song_t playlist[MAX], int *tail);
void showPlaylist(song_t playlist[MAX], int head, int tail);
void showDuration(song_t song);
void delay(int seconds);
void playSong(song_t song);
bool remainMem(int tail);
bool addSong(song_t playlist[MAX], int *tail);
void rmvSong(song_t playlist[MAX]);

/*Inicio del programa*/
int main(int argc, char const *argv[])
{
  int opc, head = 0, tail = 0;
  song_t playlist[MAX] = {0};
  do
  {
    system("cls");
    puts("\tMENU");
    puts("[1] Agregar una cancion a la lista");
    puts("[2] Remover cancion");
    puts("[3] Reproducir lista completa");
    puts("[4] Salida");
    printf("Seleccione una opcion: "); scanf("%d", &opc);
    setbuf(stdin, 0);
    system("cls");
    switch (opc)
    {
      case 1: if(addSong(playlist, &tail) == false)
      {
        printf("No hay espacio en la lista."); 
        getchar();
      }else
      {
        printf("Agregando canci%cn de la lista ...",162);
        delay(1);
        system("cls");
        showPlaylist(playlist, head, tail);
        getchar();
      }break;
      
      case 2:showPlaylist(playlist, head, tail);
      printf("\nRemoviendo canci%cn de la lista ...",162);
      if(removeSong(playlist, &tail) == false)
      {
        printf("No hay espacio en la lista."); 
        getchar();
      }else
      {
        delay(2);
        system("cls");
        showPlaylist(playlist, head, tail);
        getchar();
      }
      break;
      
      case 3:showPlaylist(playlist, head, tail);
      getchar();
      while(head < tail)
      {
        puts("\tReproduciendo");
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
  Descripcion: funcion que limpia los datos guardados en una 
  cancion.

  Parametros
    -playlist: Array de canciones de la cual se va a limpiar 
    los datos de una de ellas.
    -tail: indice que indica la posicion de la cancion a la 
    cual sus datos van a ser limpiados.
*/
void clrData(song_t playlist[MAX], int tail)
{
  for(int i = 0; playlist[tail].interprete[i] != 0; i++)
    playlist[tail].interprete[i] = 0;
  for(int i = 0; playlist[tail].titulo[i] != 0; i++)
    playlist[tail].titulo[i] = 0;
}

/*
  Descripcion: Funcion de tipo booleano que remueve una cancion de la lista.
  Devuelve 'true' si la cancion ha sido removida con exito, de 
  lo contario de vuelve 'false' indicando que no se pudo quitar
  la cancion de la lista.
  
  Parametros
  -playlist: lista que contiene todas las canciones de la cual se desea
  remover una de ellas, se va a remover la ultima en haber entrado.
  -tail: indice que nos indica la posicion de la cancion que se tiene
  que remover.
*/
bool removeSong(song_t playlist[MAX], int *tail)
{
  *tail -= 1;
  if (remainMem(*tail) == false) return false; // ya no hay espacio displonible
  clrData(playlist, *tail);
  return true;
}

/*
  Descripcion: Funcion que muestra las canciones dentro de una lista.
  La funcion muestra el interprete, el titulo de la cancion
  y la duracion. La funcion no duevuelve ningun tipo de 
  valor.
  
  Parametros
  -playlist: arreglo de tipo 'song_t' el cual contiene la
  lista de las canciones.
  -head: cabeza de la lista la cual tiene la funcion de 
  delimitar el inicio de la lista.
  -tail: la cola de la lista es el que pone el limite de 
  canciones que van a ser impresas.
*/
void showPlaylist(song_t playlist[MAX], int head, int tail)
{
  puts("\t\t>>>LISTA DE REPRODUCCION<<<");
    printf("T%ctulo               Interprete                Duraci%cn\n",161,162);
  for(int i = head; i < tail; i++)
  {
    printf("\n%s", playlist[i].titulo);
    printf("            %s", playlist[i].interprete);
    printf("                     ");
    showDuration(playlist[i]);
  }
}

/*
  Descripcion: funcnion que imprime la duracion de una cancion 
  con formato de minuts y segundos. Ejemplo: 1:39
  
  Parametros
  -song: cancion a la cual se le va extraer el tiempo 
  capturado para darle formato al tiempo.
*/
void showDuration(song_t song)
{
  int sec = 0, min = 0;
  sec = song.duracion - ((song.duracion/3600)*3600);
  min = sec/60;
  sec -= (min*60);
  printf("%d:%d", min, sec);
}

/*
  Descripcion: funcion que realiza un delay. El tiempo del delay es en funcion a segundos
  y el valor se recibe como un numero tipo entero.
  
  Parametros
  -secods: numero de segundos que 
*/
void delay(int seconds) 
{ 
  int milli_seconds = 1000 * seconds;  
  clock_t start_time = clock(); 
  while (clock() < start_time + milli_seconds); 
} 

/*
  Descripcion: Funcion que reproduce las canciones mostrando la informacion
  y el tiempo transcurrido. Cuando llegue al final de la lista
  muestra un mensaje que ya no hay canciones en la lista.
  
  Parametros
  -song: cancion que actualmente se esta reproduciendo.
*/
void playSong(song_t song)
{
  system("cls");
  int sec = 0, min = 0;
  for (int i = 0; i < song.duracion; i++) 
  { sec++;  // aumentan los segundos
    if(sec > 59)
    {
      sec  = 0; // si segundos llega a 59, se reinicia a 0
      min++;  // y se aumentan los minutos.
    }printf("%s by %s\t%d:%d/", song.titulo, song.interprete, min, sec); // impresion de los datos.
    showDuration(song);
    delay(1); // delay de un segundo para dar la impresion de que es un contador.
    system("cls"); // se limpia pantalla para que se actualicen los datos en pontalla
  } 
}

/*
  Descripcion: Funcion que devuelve un dato tipo booleano. La funcion verifica si en la cola 
  aun existe espacio disponible para almacenar datos en ella, si es asi devuelve
  'true', caso contrario 'false'.
  Parametros
  -tail: verifica que el apuntador de la cola no haya rebasado el limite permitido de datos 
  a guardar en la cola.
*/
bool remainMem(int tail)
{
  if(tail <  MAX || tail >= 0) return (true); //Aun hay espacio disponible
  else return (false); // Ya no hay espacio disponible en la cola
}

/*
  Descripcion: Funcion que captura los datos de una cancion. Los datos a capturar
  son el interprete, el titulo de la cancion y la duracion, la cual
  es capturada en segundos.
  
  Parametros
  -playlist: Arreglo de tipo canciones, la cual contiene los datos a capturar.
  -tail: entero el cual se va desplazando a la siguiente posicion de la cola
  para seguir insertando mas datos. Funciona como un indice para ver en que 
  posicion se va agregar la siguiente cancion.
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
  Descripcion: Funcion de tipo booelano que agrega una cancion a la cola.
  Retorna "true" si la cancion se agrego con exito. Caso con-
  trario regresa "faslse" indicando que ya no hay espacio dis-
  ponible.
  
  Parametros
  -playlist: Array de tipo 'song' el cual tiene las canciones
  que se pueden agregar a la cola. 
  -tail: entero que sirve como indice de la posicion en la que
  se ve a agregar la siguiente cancion. Incrementa en 1 si la 
  cancion se agrego correctamente. 
*/
bool addSong(song_t playlist[MAX], int *tail)
{
  if (remainMem(*tail) == false) return false; // ya no hay espacio displonible
  getData(playlist, *tail); // Llamada a la funcion para capturar los datos de la cancion. 
  *tail += 1; // Se incrementa para apuntar a la siguiente poscion del array.
  return true; // Se ha agregado con exito la cancion.
}