#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "libros.h"
#include "editorial.h"
#include "parser.h"

int parser_EditorialFromText(FILE* pFile , LinkedList* listaEditorial)
{
		int contador=0;
		int checkConvert;
		int verify;
		eEditorial* aux;
		char idStr[50];
		char nombreStr[180];
		int id;

		fscanf(pFile,"%[^,],%[^\n]\n",idStr,nombreStr);

		while(!feof(pFile)){
			checkConvert=0;
			aux = editorial_new();
			fscanf(pFile,"%[^,],%[^\n]\n",idStr,nombreStr);
			checkConvert=CadenaAEntero(idStr, &id);

			if(strlen(nombreStr) != 0 && checkConvert){

				aux = editorial_newArguments(id, nombreStr);
				if(aux != NULL){
					verify = ll_add(listaEditorial,aux);
					if(verify){
						contador++;
					}
				}
			}
		}

    return contador;
}

int parser_LibrosFromText(FILE* pFile , LinkedList* listaLibros)
{
		int contador=0;
		int checkConvert;
		int verify;
		eLibro* aux;
		char idStr[50];
		char tituloStr[180];
		char autorStr[180];
		char precioStr[180];
		char idEditorialStr[50];
		int id, idEditorial;
		float precio;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,tituloStr,autorStr,precioStr,idEditorialStr);

		while(!feof(pFile)){
			checkConvert=0;
			aux = libro_new();
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,tituloStr,autorStr,precioStr,idEditorialStr);
			checkConvert+=CadenaAEntero(idStr, &id);
			checkConvert+=CadenaAFlotante(precioStr, &precio);
			checkConvert+=CadenaAEntero(idEditorialStr, &idEditorial);

			if(strlen(tituloStr) != 0 && strlen(autorStr) != 0 &&checkConvert==3){
				aux = libro_newArguments(id, tituloStr, autorStr, precio, idEditorial);
				if(aux != NULL){
					verify = ll_add(listaLibros,aux);
					if(verify){
						contador++;
					}
				}
			}
		}
    return contador;
}
