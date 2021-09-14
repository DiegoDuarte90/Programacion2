#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int legajo=0;
    int nota=0;
    float promedio=0;

    FILE*archivo=fopen("ejercicio1.txt","w");
    if(archivo==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese el legajo: \n");
    scanf("%d",&legajo);

    while (legajo>0){
        printf("Ingrese una nota: \n");
        scanf("%d",&nota);
        promedio=nota;

        printf("Ingrese una nota: \n");
        scanf("%d",&nota);
        promedio+=nota;
        
        promedio=promedio/2;

        printf("%d %.2f\n",legajo,promedio);

        fprintf(archivo, "%08d %.2f\n",legajo,promedio);

        printf("Ingrese el legajo: \n");
        scanf("%d",&legajo);   
    }
    

    fclose(archivo);
    return 0;
}