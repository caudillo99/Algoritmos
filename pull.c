//Prueba con el comando pull

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef  struct
{
	char name[10];
	char last_name[15];
	int age;
}datos_t;

//Headers
void captura(datos_t *persona);
void printData(datos_t persona);
void createPush(void);
int main ()
{
	//Esto es un comentario
	datos_t persona;
	captura(&persona);
	printData(persona);
	createPush(); 
  	return 0;
}

// funcion que captura datos de una estructura de datos
void captura(datos_t* persona)
{
	printf("Name: "); gets(persona->name);
	printf("Lasta name: "); gets (persona->last_name);
	printf("Age: "); scanf("%d", &persona->age);
	system("clear");
}

void printData(datos_t persona)
{
	printf("Name: %s\n", persona.name);
	printf("Last name: %s\n", persona.last_name);
	printf("Age: %d\n",persona.age); 
}

void createPush(void)
{
	//Esto es un comentario
	system("git status");
	system("git commit -m 'making changes'");
	system("git add .");
	system("git push origin master");
	system("echo Succesful");
}


