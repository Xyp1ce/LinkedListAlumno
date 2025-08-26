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
  // mostrarLista(lista);

  unsigned int buscarMat;
  float buscarProm;
  int buscarSem;
  char buscarNom[64];
  Alumno *alumno = NULL;
  Alumno buscarAlumno ;
  int opc = 0;

  do{
    printf("\n            ----MENU----\n");
    printf("[1] Registrar Alumno  [4] Buscar Alumno\n");
    printf("[2] Desplegar Alumnos [5] Borrar Alumno\n");
    printf("[3] Reordenar         [6] Salir\n");
    printf("Selecciona una opcion\n");
    scanf("%d", &opc);
    switch(opc){
      case 1: // Registrar Alumno
        insertarFinal(&lista, llenarInfo(lista));
        break;
      case 2: // Desplegar Alumno
        mostrarLista(lista);
        break;
      case 3: // Reordenar
        printf("Como quiere reordenar?");
        printf("[1] Nombre   [3] Matricula");
        printf("[2] Promedio [4] Semestres");
        printf("Ingrese una opcion>> ");
        scanf("%d", &opc);
        switch(opc){
          case 1:
            reordenar(&lista, &compararNombre);
            break;
          case 2:
            reordenar(&lista, &compararPromedio);
            break;
          case 3:
            reordenar(&lista, &compararMatricula);
            break;
          case 4:
            reordenar(&lista, &compararSemestres);
            break;
          default: 
            printf("Opcion Invalida...\n");
            break;
        }
        break;
      case 4: // Buscar Alumno
        printf("Que dato quiere buscar? ");
        printf("[1] Nombre   [3] Matricula");
        printf("[2] Promedio [4] Semestres");
        printf("Ingrese una opcion>> ");
        scanf("%d", &opc);
        switch(opc){
          case 1:
            printf("Ingrese el nombre del alumno>> ");
            fgets(buscarAlumno.nombre, 64, stdin);
            buscarAlumno.nombre[strcspn(buscarAlumno.nombre, "\n")] = '\0';
            alumno = buscarDato(lista, &buscarAlumno, &compararNombre);
            if(alumno != NULL){
              printf("Se ha encontrado un alumno>>\n");
              imprimirNombre(alumno);
              imprimirMatricula(alumno);
              imprimirSemestres(alumno);
              imprimirPromedio(alumno);
            }
            break;
          case 2:
            printf("Ingrese el promedio del alumno>> ");
            scanf("%f", &buscarAlumno.promedio);
            CleanBuffer();
            alumno = buscarDato(lista, &buscarAlumno, &compararPromedio);
            if(alumno != NULL){
              printf("Se ha encontrado un alumno>>\n");
              imprimirNombre(alumno);
              imprimirMatricula(alumno);
              imprimirSemestres(alumno);
              imprimirPromedio(alumno);
            }
            break;
          case 3:
            printf("Ingrese la matricula del alumno>> ");
            scanf("%d", &buscarAlumno.matricula);
            CleanBuffer();
            alumno = buscarDato(lista, &buscarAlumno, &compararMatricula);
            if(alumno != NULL){
              printf("Se ha encontrado un alumno>>\n");
              imprimirNombre(alumno);
              imprimirMatricula(alumno);
              imprimirSemestres(alumno);
              imprimirPromedio(alumno);
            }
            break;
          case 4:
            printf("Ingrese el nombre del alumno>> ");
            fgets(buscarAlumno.nombre, 64, stdin);
            buscarAlumno.nombre[strcspn(buscarAlumno.nombre, "\n")] = '\0';
            alumno = buscarDato(lista, &buscarAlumno, &compararNombre);
            if(alumno != NULL){
              printf("Se ha encontrado un alumno>>\n");
              imprimirNombre(alumno);
              imprimirMatricula(alumno);
              imprimirSemestres(alumno);
              imprimirPromedio(alumno);
            }
            break;
          default: 
            printf("Opcion Invalida...\n");
            break;
        }
        break;
        break;
      case 5: // Borrar Alumno
        break;
      case 6: // Salir
        printf("Terminando Programa...\n");
        return 0;
        break;
      default:
        printf("Opcion invalida...\n");
        break;
    }
  }while(true);
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

int compararSemestres(void *a, void *b)
{
  Alumno *ea,*eb;
  ea = a;
  eb = b;
  if( ea->semestres < eb->semestres )
    return -1;
  else if ( ea->semestres > eb->semestres)
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
