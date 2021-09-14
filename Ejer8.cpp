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

    FILE*archivoMateria=fopen("D:\\Diego Facultad\\VSC\\Archivos\\MATFINALES.DAT","rb");    
    if(archivoMateria==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    FILE*listado=fopen("D:\\Diego Facultad\\VSC\\Archivos\\LISTADO.TXT","w");    
    if(listado==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    STR_ALUMNO *alumno=(STR_ALUMNO*)malloc(sizeof(STR_ALUMNO));

    fread(alumno,sizeof(STR_ALUMNO),1,archivoMateria);

    while(!feof(archivoMateria)){

        fprintf(listado,"%08d %-20s %02d/%02d/%d %06d\n",alumno->legajo,alumno->nombreYApellido,alumno->dia,alumno->mes,alumno->anio,alumno->codigo);
        
        fread(alumno,sizeof(STR_ALUMNO),1,archivoMateria);


    }
    fclose(archivoMateria);
    fclose(listado);


    return 0;
}