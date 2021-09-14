#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char nombreYApellido[25];
    int legajo;
}STR_ORDENADO;

void discardChars(){
        char c;
        while((c = getchar()) != '\n' && c != EOF);
        return;
}

void tamanioArchivo(FILE*f){
        int pos= ftell(f);
        fseek(f,0,SEEK_END);
        printf("Tamanio del archivo: %d\n",ftell(f));
        fseek(f,pos,SEEK_SET);
}








int main(){

    FILE*ordenado=fopen("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADO.DAT","rb+");    
    if(ordenado==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }


    STR_ORDENADO *aux=(STR_ORDENADO*)malloc(sizeof(STR_ORDENADO));
    long posCero=0;
    STR_ORDENADO *vacio=(STR_ORDENADO*)malloc(sizeof(STR_ORDENADO)); 
    long posDato=0;





    //fseek(ordenado,0,SEEK_SET);


    fread(aux,sizeof(STR_ORDENADO),1,ordenado);


    

    while(posCero==0){
        if(aux->legajo==0){
            posCero=ftell(ordenado);
            vacio->legajo=aux->legajo;
            strcpy(vacio->nombreYApellido,aux->nombreYApellido);
            fread(aux,sizeof(STR_ORDENADO),1,ordenado);

        }
        else{
            

            posDato=ftell(ordenado);
            fread(aux,sizeof(STR_ORDENADO),1,ordenado);

        }
    }

    fseek(ordenado,posDato,SEEK_SET);
    fread(aux,sizeof(STR_ORDENADO),1,ordenado);


        



    while(!feof(ordenado)){
        if(aux->legajo!=0){
            posDato=(ftell(ordenado));
            fseek(ordenado,posCero-sizeof(STR_ORDENADO),SEEK_SET);
            fwrite(aux,sizeof(STR_ORDENADO),1,ordenado);
            fflush(ordenado);
            fseek(ordenado,posDato-sizeof(STR_ORDENADO),SEEK_SET);
            fwrite(vacio,sizeof(STR_ORDENADO),1,ordenado);
            fflush(ordenado);
            posCero=posCero+sizeof(STR_ORDENADO);
            fread(aux,sizeof(STR_ORDENADO),1,ordenado);

            }
        else{
            fread(aux,sizeof(STR_ORDENADO),1,ordenado);
        }
    }




    fclose(ordenado);
    return 0;
}