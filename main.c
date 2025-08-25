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

int compararSemestres(void *a, void *b);
int compararMatricula(void *a, void *b);
int compararPromedio(void *a, void *b);
int compararNombre(void *a,void *b);

void imprimirMatricula(void *a);
void imprimirNombre(void *a);
void imprimirPromedio(void *a);
void imprimirSemestres(void *a);

void imprimirAlumno(void *a);

int main(void)
{
  Lista lista;
  lista.inicio = NULL;
  lista.cant = 0;
  lista.imprimir = &imprimirAlumno;
  lista.comparar = &compararNombre;
  insertarFinal(&lista, llenarInfo(lista));
  // insertarFinal(&lista, llenarInfo(lista));
  // insertarFinal(&lista, llenarInfo(lista));
  mostrarLista(lista);
  unsigned int buscarMat;
  float buscarProm;
  int buscarSem;
  char buscarNom[64];
  // printf("Comparacion por semestres");
  // reordenar(&lista, &compararSemestres); 
  // mostrarLista(lista);
  // printf("Comparacion por Nombre");
  // reordenar(&lista, &compararNombre); 
  // mostrarLista(lista);
  // printf("Comparacion por Matricula");
  // reordenar(&lista, &compararMatricula); 
  // mostrarLista(lista);
  // printf("Comparacion por promedio");
  // reordenar(&lista, &compararPromedio); 
  // mostrarLista(lista);
  printf("Matricula a buscar: ");
  scanf("%u", &buscarMat);
  CleanBuffer();
  printf("Buscando Matricula %d", buscarMat);
  Alumno *alumno = NULL;
  alumno = buscarDato(lista, &buscarMat, &compararMatricula);
  if(alumno != NULL){
    printf("\nSe ha encontrado un alumno con esa matricula: \n");
    imprimirNombre(alumno);
    imprimirMatricula(alumno);
    imprimirSemestres(alumno);
    imprimirPromedio(alumno);
  } else{
    printf("\nNo se ha encontrado algun alumno con esa matricula\n");
  }
  printf("Nombre a buscar: ");
  fgets(buscarNom, 64, stdin);
  buscarNom[strcspn(buscarNom, "\n")] = '\0';
  printf("Buscando Nombre %s", buscarNom);
  alumno = buscarDato(lista, &buscarNom, &compararNombre);
  if(alumno != NULL){
    printf("\nSe ha encontrado un alumno con ese nombre: \n");
    imprimirNombre(alumno);
    imprimirMatricula(alumno);
    imprimirSemestres(alumno);
    imprimirPromedio(alumno);
  } else{
    printf("\nNo se ha encontrado algun alumno con ese nombre\n");
  }
  printf("Promedio a buscar: ");
  scanf("%f", &buscarProm);
  CleanBuffer();
  printf("Buscando Promedio %.2f", buscarProm);
  alumno = buscarDato(lista, &buscarProm, &compararPromedio);
  if(alumno != NULL){
    printf("\nSe ha encontrado un alumno con ese promedio: \n");
    imprimirNombre(alumno);
    imprimirMatricula(alumno);
    imprimirSemestres(alumno);
    imprimirPromedio(alumno);
  } else{
    printf("\nNo se ha encontrado algun alumno con ese promedio\n");
  }
  printf("Semestre a buscar: ");
  scanf("%d", &buscarSem);
  CleanBuffer();
  printf("\nBuscando Semestre %d", buscarSem);
  alumno = buscarDato(lista, &buscarSem, &compararSemestres);
  if(alumno != NULL){
    printf("\nSe ha encontrado un alumno en ese Semestre: \n");
    imprimirNombre(alumno);
    imprimirMatricula(alumno);
    imprimirSemestres(alumno);
    imprimirPromedio(alumno);
  } else{
    printf("\nNo se ha encontrado algun alumno en ese semestres\n");
  }
  return 0;
}

int compararMatricula(void *a, void *b)
{
  Alumno *ea,*eb;
  ea = a;
  eb = b;
  if( ea->matricula < eb->matricula )
    return -1;
  else if ( ea->matricula > eb->matricula)
    return 1;
  else
    return 0;	
}

void imprimirMatricula(void *a)
{
  Alumno *ea;
  ea = a;
  printf("Matricula: %d\n",ea->matricula);
}

void imprimirNombre(void *a)
{
  Alumno *ea;
  ea = a;
  printf("Nombre: %s\n",ea->nombre);
}

int compararSemestres(void *a, void *b)
{
  Alumno *ea,*eb;
  ea = a;
  eb = b;
  if( ea->semestres < eb->semestres )
    return 1;
  else if ( ea->semestres > eb->semestres)
    return -1;
  else
    return 0;	
}

void imprimirSemestres(void *a)
{
  Alumno *ea;
  ea = a;
  printf("Semestres: %d\n",ea->semestres);
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
  Alumno *ea;
  ea = a;
  printf("Promedio: %.2f\n",ea->promedio);
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
  int pos = strcmp( aa->nombre,ab->nombre);
  return pos;
}

void imprimirAlumno(void *a)
{
  Alumno *aa;
  aa = a;
  printf("%s_%d",aa->nombre,aa->matricula);

}

void CleanBuffer(){
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {} 	
}

Alumno *llenarInfo(Lista lista){
  Alumno new;
  printf("Nombre>> ");
  fgets(new.nombre, 64, stdin);
  new.nombre[strcspn(new.nombre, "\n")] = '\0';
  // new.nombre[1] = '\0';
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
}
