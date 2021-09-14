#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <ctype.h>




typedef struct{
    char nombreYApellido[25];
    int legajo;
}STR_ORDENADO;

bool validarNombre(char *nombre){
    return strlen(nombre)<16;
}

void tamanioArchivo(FILE*f){
        int pos= ftell(f);
        fseek(f,0,SEEK_END);
        printf("Tamanio del archivo: %d\n",ftell(f));
        fseek(f,pos,SEEK_SET);
        
}

int main(){

    FILE*ordenado=fopen("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADO.DAT","rb");    
    if(ordenado==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    STR_ORDENADO *aux=(STR_ORDENADO*)malloc(sizeof(STR_ORDENADO));

    fread(aux,sizeof(STR_ORDENADO),1,ordenado);
    while(!feof(ordenado)){
        
        printf("Nombre: %s\n",aux->nombreYApellido);
        printf("Legajo: %d\n",aux->legajo);

        fread(aux,sizeof(STR_ORDENADO),1,ordenado);
    }
    char * cadena = "sssasas dw s ddd";

printf("%d\n",strlen(cadena));
printf("%d\n",validarNombre(cadena));


    return 0;
}