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

void discardChars(){
        char c;
        while((c = getchar()) != '\n' && c != EOF);
        return;
}


int main(){

    STR_ALUMNO *alumno=(STR_ALUMNO*)malloc(sizeof(STR_ALUMNO));

    

    FILE*archivo=fopen("DIAFINALES.DAT","wb");    
    if(archivo==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese Nombre y Apellido: \n");
    gets(alumno->nombreYApellido);



    while(alumno->nombreYApellido[0]!='\0'){
        
        printf("Ingrese numero de legajo: \n");
        scanf("%08d",&alumno->legajo);


        printf("Ingrese codigo de materia: \n");
        scanf("%d",&alumno->codigo);


        printf("Ingrese dia del examen: \n");
        scanf("%d",&alumno->dia);


        printf("Ingrese mes del examen: \n");
        scanf("%d",&alumno->mes);


        printf("Ingrese anio del examen: \n");
        scanf("%d",&alumno->anio);
        
        discardChars();
        fwrite(alumno,sizeof(STR_ALUMNO),1,archivo);
        
        fflush(stdin);

        printf("Ingrese Nombre y Apellido: \n");
        gets(alumno->nombreYApellido);
    

        


    }

    fclose(archivo);
    return 0;
}