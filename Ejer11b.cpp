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
    tamanioArchivo(ordenado);
    long test=ftell(ordenado);


    STR_ORDENADO aux;
    long posDato=0;
    STR_ORDENADO vacio;
    long posVacio=0;
    

    fread(&aux,sizeof(STR_ORDENADO),1,ordenado);
    

    
    bool flag=true;

    while(!feof(ordenado)&&flag==true){
    
        if(aux.legajo==0){
            posVacio=ftell(ordenado);
            vacio.legajo=aux.legajo;
            strcpy(vacio.nombreYApellido,aux.nombreYApellido);
            flag=false;
            
        }
        else{
            posDato=ftell(ordenado);
    

            fread(&aux,sizeof(STR_ORDENADO),1,ordenado);
    

        }
    } 

    

    fseek(ordenado,posDato,SEEK_SET);
    fread(&aux,sizeof(STR_ORDENADO),1,ordenado);
    
    while(!feof(ordenado)){

        if(aux.legajo!=0){

            posDato=ftell(ordenado);
            fseek(ordenado,posVacio-sizeof(STR_ORDENADO),SEEK_SET);           
            fwrite(&aux,sizeof(STR_ORDENADO),1,ordenado);
            fflush(ordenado);
            fseek(ordenado,posDato-sizeof(STR_ORDENADO),SEEK_SET);           
            fwrite(&vacio,sizeof(STR_ORDENADO),1,ordenado);         
            fflush(ordenado);
            posVacio=posVacio+sizeof(STR_ORDENADO);  
            fread(&aux,sizeof(STR_ORDENADO),1,ordenado);
        }
        else{
            fread(&aux,sizeof(STR_ORDENADO),1,ordenado);
            


        }

    }




    fclose(ordenado);
    return 0;
}