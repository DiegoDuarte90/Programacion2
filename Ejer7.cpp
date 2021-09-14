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

    FILE*archivo=fopen("D:\\Diego Facultad\\VSC\\Archivos\\DIAFINALES.DAT","rb");    
    if(archivo==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    
    FILE*archivoMateria=fopen("D:\\Diego Facultad\\VSC\\Archivos\\MATFINALES.DAT","wb");    
    if(archivoMateria==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    
    STR_ALUMNO *alumno;

    alumno=(STR_ALUMNO*)malloc(sizeof(STR_ALUMNO));

    int materia;
    printf("Ingrese codigo de materia que quiere ver: \n");
    scanf("%d",&materia);


    fread(alumno,sizeof(STR_ALUMNO),1,archivo);

    

    while(!feof(archivo)){

        if(alumno->codigo==materia){
            fwrite(alumno,sizeof(STR_ALUMNO),1,archivoMateria);
        }
        fread(alumno,sizeof(STR_ALUMNO),1,archivo);
        
    }
    fclose(archivo);
    fclose(archivoMateria);




    return 0;
    
}