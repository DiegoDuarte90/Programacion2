#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nombreYApellido[25];
    int legajo;
    int codigo;
    char dia;
    char mes;
    short anio;
}STR_ALUMNO;
    
    
    
int main(){
    FILE*archivo=fopen("DIAFINALES.DAT","rb");    
    if(archivo==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    
    FILE*archivoMateria=fopen("MATFINALES.DAT","rb");    
    if(archivo==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    STR_ALUMNO *alumno;
    alumno=(STR_ALUMNO*)malloc(sizeof(STR_ALUMNO));

 /*   fread(alumno,sizeof(STR_ALUMNO),1,archivo);
    while(!feof(archivo)){
        
        printf("Nombre: %s\n",alumno->nombreYApellido);
        printf("Legajo: %d\n",alumno->legajo);
        printf("Materia: %d\n",alumno->codigo);
        printf("Dia: %d\n",alumno->dia);
        printf("Mes: %d\n",alumno->mes);
        printf("Anio: %d\n\n\n",alumno->anio);
        fread(alumno,sizeof(STR_ALUMNO),1,archivo);

    }*/


        fread(alumno,sizeof(STR_ALUMNO),1,archivoMateria);
        while(!feof(archivoMateria)){
        
        printf("Nombre: %s\n",alumno->nombreYApellido);
        printf("Legajo: %d\n",alumno->legajo);
        printf("Materia: %d\n",alumno->codigo);
        printf("Dia: %d\n",alumno->dia);
        printf("Mes: %d\n",alumno->mes);
        printf("Anio: %d\n",alumno->anio);
        fread(alumno,sizeof(STR_ALUMNO),1,archivoMateria);
        }

    return 0;
}