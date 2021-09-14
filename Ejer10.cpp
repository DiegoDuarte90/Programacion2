#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define num 80001


typedef struct{
    char nombreYApellido[25];
    int legajo;
    int codigo;
    char dia;
    char mes;
    short anio;
}STR_ALUMNO;

typedef struct{
    char nombreYApellido[25];
    int legajo;
}STR_ORDENADO;





int main(){
    
    FILE*archivoMateria=fopen("D:\\Diego Facultad\\VSC\\Archivos\\MATFINALES.DAT","rb");    
    if(archivoMateria==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    FILE*ordenado=fopen("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADO.DAT","wb");    
    if(ordenado==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    STR_ALUMNO *alumno=(STR_ALUMNO*)malloc(sizeof(STR_ALUMNO));
    STR_ORDENADO *aux=(STR_ORDENADO*)malloc(sizeof(STR_ORDENADO));

    fread(alumno,sizeof(STR_ALUMNO),1,archivoMateria);
    printf("%d\n",ftell(ordenado)/sizeof(STR_ORDENADO));
    while(!feof(archivoMateria)){

        aux->legajo=alumno->legajo;
        strcpy(aux->nombreYApellido,alumno->nombreYApellido);
        fseek(ordenado,(aux->legajo-num)*sizeof(STR_ORDENADO),SEEK_SET);
        fwrite(aux,sizeof(STR_ORDENADO),1,ordenado);
        printf("%d\n",ftell(ordenado)/sizeof(STR_ORDENADO));
        fread(alumno,sizeof(STR_ALUMNO),1,archivoMateria);
    }
    printf("%d\n",ftell(ordenado)/sizeof(STR_ORDENADO));
    printf("%d\n",ftell(ordenado)/sizeof(STR_ORDENADO));
    printf("%d\n",ftell(ordenado)/sizeof(STR_ORDENADO));
    
    fclose(archivoMateria);
    fclose(ordenado);

    return 0;
}