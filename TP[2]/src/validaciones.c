#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "arraypassenger.h"


int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
    int todoOk = -1;
    char buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &buffer);
            if(buffer == minimo || buffer == maximo)
            {
                *pResultado = buffer;
                todoOk = 0;
                break;
            }
            printf("%s", mensajeError);
            reintentos--;

        }while(reintentos>=0);

    }
    return todoOk;
}

int validarLetras(char letras[]){

    int todoOk = 1;
    int esLetra;

    if(letras != NULL)
    {
        for(int i = 0; i < strlen(letras) -1; i++)
        {
            esLetra = isalpha(letras[i]);
            if(esLetra == 0)
            {
                todoOk = 0;
                break;
            }
        }
    }
    return todoOk;
}

int pidoLetras(char cadena[], char mensaje[], int TAM){

    int todoOk = 0;
    char buffer[100];

    if(cadena != NULL && mensaje != NULL && TAM > 0)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffer, TAM, stdin);
        while(validarLetras(buffer) == 0 || stricmp(buffer , "\n") == 0)
        {
            printf("Ingreso invalido.\nPor favor reingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffer, TAM, stdin);
        }
        strcpy(cadena, buffer);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
            todoOk = 1;
        }
    }
    return todoOk;
}

int validarNumero(char numero[]){
    int todoOk = 1;
    int esNumero;

    if(numero != NULL)
    {
        for(int i = 0; i < strlen(numero) -1; i++)
        {
            esNumero = isdigit(numero[i]);
            if(esNumero == 0)
            {
                puts("Error, ingrese un numero.\n");
                todoOk = 0;
                break;
            }
        }
    }

    return todoOk;
}

int pidoNumero(char mensaje[], int* pNumero){

    int todoOk = 0;
    char buffer[100];
    int numero;

    if(pNumero != NULL)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffer, 100, stdin);
        while(validarNumero(buffer) == 0)
        {
            printf("Ingreso invalido. \nPor favor reingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffer, 100, stdin);
        }
        if(convertirCharAInt(buffer, &numero))
        {
            *pNumero = numero;
            todoOk = 1;
        }
    }
    return todoOk;
}

int statusFlight(eVuelo vuelo[], int TAM, char code[], char descripcion[]){

    int todoOk = 0;

    if(vuelo != NULL && TAM > 0)
    {
      for(int i = 0; i < TAM; i++)
      {
          if(stricmp(vuelo[i].flyCode, code)== 0)
          {
              strcpy(descripcion, vuelo[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}
