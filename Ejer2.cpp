#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){


    FILE* archivo=fopen("ejercicio1.txt","r");
    if(archivo==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    FILE* aprobados=fopen("APROB.txt","w");
    if(aprobados==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    int legajo;
    float promedio;
    fputs("Los aprobados son:\n",aprobados);
    while(!feof(archivo)){
        fscanf(archivo, "%d %f\n",&legajo,&promedio);
        if(promedio>5){
            fprintf(aprobados, "%08d %.2f\n",legajo,promedio);

        }
    }
    fclose(archivo);
    fclose(aprobados);
    return 0;
}