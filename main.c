//INCLUDES
#include <stdio.h>
#include <string.h>
#include "Lista.h"

//FUNCION MAIN
typedef struct
{
	unsigned int matricula;
	char nombre[64];
	int semestres;
	float promedio;
}Alumno;

Alumno *llenarInfo(Lista l);
void CleanBuffer();
void* crearAlumno(Alumno a);
int compararMatricula(void *a, void *b);
void imprimirMatricula(void *a);
int compararPromedio(void *a, void *b);
void imprimirPromedio(void *a);
int compararNombre(void *a,void *b);
void imprimirAlumno(void *a);

int main(void)
{
	Lista lista;
	lista.inicio = NULL;
	lista.cant = 0;
	lista.imprimir = &imprimirAlumno;
	lista.comparar = &compararPromedio;
  insertarFinal(&lista, llenarInfo(lista));
  insertarFinal(&lista, llenarInfo(lista));
  insertarFinal(&lista, llenarInfo(lista));
  mostrarLista(lista);
  // int buscar = 123;
  printf("Comparacion por promedio");
  reordenar(&lista, &compararPromedio); 
  mostrarLista(lista);
  printf("Comparacion por Nombre");
  reordenar(&lista, &compararNombre); 
  mostrarLista(lista);
  printf("Comparacion por Matricula");
  reordenar(&lista, &compararMatricula); 
  mostrarLista(lista);
  printf("Comparacion por promedio");
  reordenar(&lista, &compararPromedio); 
  mostrarLista(lista);
	return 0;
}

int compararMatricula(void *a, void *b)
{
	int *ea,*eb;
	ea = a;
	eb = b;
	if( *ea < *eb )
		return -1;
	else if ( *ea > *eb)
		return 1;
	else
		return 0;	
}

void imprimirMatricula(void *a)
{
	int *ea;
	ea = a;
	printf("%d",*ea);
}

int compararPromedio(void *a, void *b)
{
	Alumno *ea,*eb;
	ea = a;
	eb = b;
	if( ea->promedio < eb->promedio )
		return 1;
	else if ( ea->promedio > eb->promedio)
		return -1;
	else
		return 0;	
}

void imprimirPromedio(void *a)
{
	float *ea;
	ea = a;
	printf("%.2f",*ea);
}

void* crearAlumno(Alumno a)
{
	Alumno *nuevo = malloc(sizeof(Alumno));
	*nuevo = a;
	return nuevo;	
}

int compararNombre(void *a,void *b)
{
	Alumno *aa,*ab;
	aa = a;
	ab = b;
	return strcmp( aa->nombre,ab->nombre);
  //if(aa->nombre[0] < ab->nombre[0])
  //   return -1;
  // else if(aa->nombre[0] > ab->nombre[0])
  //   return 1;
  // else 
  //   return 0;
}

void imprimirAlumno(void *a)
{
	Alumno *aa;
	aa = a;
	printf("%s_%d\n",aa->nombre,aa->matricula);
	
}

void CleanBuffer(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {} 	
}

Alumno *llenarInfo(Lista lista){
  Alumno new;
	printf("Nombre>> ");
	fgets(new.nombre, 64, stdin);
	new.nombre[strcspn(new.nombre, "\n")] = 0;
  new.nombre[1] = '\0';
	printf("Matricula>> ");
	scanf("%u", &new.matricula);
	while(buscarDato(lista, &new.matricula, &compararMatricula) != NULL){
    printf("Matricula>> ");
    scanf("%u", &new.matricula);
  }
	CleanBuffer();
	printf("Semestres>> ");
	scanf("%d", &new.semestres);
	CleanBuffer();
	printf("Promedio>> ");
	scanf("%f", &new.promedio);
	CleanBuffer();
  return crearAlumno(new);
  // REGRESAR TODO A PUNTOS
}
