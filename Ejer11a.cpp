#include <stdio.h>
#include <string.h>
#include <stdlib.h>





typedef struct{
    char nombreYApellido[25];
    int legajo;
}STR_ORDENADO;

int main(){

    FILE*ordenado=fopen("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADO.DAT","rb");    
    if(ordenado==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    FILE*ordenadoNuevo=fopen("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADONUEVO.DAT","wb");    
    if(ordenadoNuevo==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    STR_ORDENADO *aux=(STR_ORDENADO*)malloc(sizeof(STR_ORDENADO));


    fread(aux,sizeof(STR_ORDENADO),1,ordenado);

    while(!feof(ordenado)){
        if(aux->legajo!=0){
            fwrite(aux,sizeof(STR_ORDENADO),1,ordenadoNuevo);
            printf("Nombre: %s\n",aux->nombreYApellido);
            printf("Legajo: %d\n",aux->legajo);
        }

        fread(aux,sizeof(STR_ORDENADO),1,ordenado);
    }

    free(aux);
    fclose(ordenadoNuevo);
    fclose(ordenado);
    remove("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADO.DAT");
    rename("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADONUEVO.DAT","D:\\Diego Facultad\\VSC\\Archivos\\ORDENADO.DAT");

    return 0;
}