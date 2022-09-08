#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char ** argv){
    char tipo_param[2];
    int contador_s=0;
    int contador_p=0;
    char filas[20][20+1];
    char palabras[20][20+1];
    int ok_s=1;
    int ok_p=1;

    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"-s")==0){
            strcpy(tipo_param,"s");
            ok_s=0;
        }
        else if(strcmp(argv[i],"-p")==0){
            strcpy(tipo_param,"p");
            ok_p=0;
        }
        else{
            if(strcmp(tipo_param,"s")==0){
                strcpy(filas[contador_s],argv[i]);
                contador_s++;
            }
            if(strcmp(tipo_param,"p")==0){
                strcpy(palabras[contador_p],argv[i]);
                contador_p++;
            }

        }
    }
    if(ok_s==1){
        printf("Falta parámetro -s\n");
        return 1;
    }
    if(ok_p==1){
        printf("Falta parámetro -p\n");
        return 1;
    }

    if(contador_s<10 || contador_s>20){
        printf("El numero de filas debe estar entre 10 y 20 \n");
        return 1;
    }
    if(contador_p<1 || contador_p>10){
        printf("El numero de palabras a buscar debe estar entre 1 y 10 \n");
        return 1;
    }



    long unsigned int ancho=0;
    for(int n=0;n<contador_s;n++){

        if(n==0){
            ancho=strlen(filas[n]);
            if(ancho<10 || ancho>20){
                printf("El numero de columnas debe estar entre 10 y 20 \n");
                return 1;
            }
        }
        else if(strlen(filas[n])!=ancho){
            printf("el número de columnas de las filas debe ser igual a %ld\n",ancho);
            return 1;
        }

    }

    for(int n=0;n<contador_p;n++){
        if(strlen(palabras[n])>ancho){
            printf("el largo de la palabra \"%s\" (%ld) excede el ancho de la sopa de letras (%ld)\n",palabras[n],strlen(palabras[n]),ancho);
            return 1;
        }
    }

    //for que verifica la creacion de los arrays
printf("\n");
printf("   SOPA DE LETRAS\n");
printf("   --------------\n");

    for(int n=0;n<contador_s;n++){
        printf("%2d %s\n",n+1,filas[n]);//imprime filas
    }
printf("\n");
printf("PALABRAS A BUSCAR\n");
printf("-----------------\n");

    for(int n=0;n<contador_p;n++){
        printf("%s\n",palabras[n]);//imprime palabras a buscar
    }
//---------------------------------------------------------------------
printf("\n");
printf("RESULTADOS\n");
printf("----------\n");


    long int p=0;
    long unsigned int c=0;
    long int f=0;
    long unsigned int l=0;
    long int ok=0;

    for(p=0; p < contador_p; p++) { //BUCLE PALABRAS
        long int okok=1;
        //BUSQUEDA HACIA LA DERECHA (ESTE)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
               ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f][c+l]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+strlen(palabras[p]),f+1);
                    f=contador_s;
                    c=ancho;
                }

            }
        }
        //BUSQUEDA DIAGONAL DERECHA-ABAJO (SURESTE)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
                ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f+l][c+l]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+strlen(palabras[p]),f+strlen(palabras[p]));
                    f=contador_s;
                    c=ancho;
                }
            }
        }
        //BUSQUEDA HACIA ABAJO (SUR)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
                ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f+l][c]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+1,f+strlen(palabras[p]));
                    f=contador_s;
                    c=ancho;
                }
            }
        }
        //BUSQUEDA DIAGONAL IZQUIERDA-ABAJO (SUROESTE)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
                ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f+l][c-l]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+1-strlen(palabras[p]+1),f+strlen(palabras[p]));
                    f=contador_s;
                    c=ancho;
                }
            }
        }
        //BUSQUEDA HACIA LA IZQUIERDA (OESTE)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
                ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f][c-l]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+1-strlen(palabras[p])+1,f+1);
                    f=contador_s;
                    c=ancho;
                }
            }
        }
        //BUSQUEDA DIAGONAL IZQUIERDA-ARRIBA (NOROESTE)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
                ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f-l][c-l]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+1-strlen(palabras[p])+1,f+1-strlen(palabras[p])+1);
                    f=contador_s;
                    c=ancho;
                }
            }
        }
        //BUSQUEDA HACIA ARRIBA (NORTE)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
                ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f-l][c]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+1,f+1-strlen(palabras[p])+1);
                    f=contador_s;
                    c=ancho;
                }
            }
        }
        //BUSQUEDA DIAGONAL DERECHA-ARRIBA (NORESTE)
        for(f=0; f < contador_s; f++) {
            for(c=0; c < ancho; c++) {
                ok=0;
                for(l=0; l < strlen(palabras[p]); l++){
                    if(palabras[p][l] != filas[f-l][c+l]) {
                        ok=1;
                    }
                }
                if (ok == 0) {
                    okok=0;
                    printf("%-10s (%2ld,%2ld)(%2ld,%2ld)\n", palabras[p],c+1,f+1,c+strlen(palabras[p]),f+1-strlen(palabras[p])+1);
                    f=contador_s;
                    c=ancho;
                }
            }
        }
        if(okok==1){
            printf("%-10s No se encuentra \n", palabras[p]);
        }

    }




    return 0;
}
   