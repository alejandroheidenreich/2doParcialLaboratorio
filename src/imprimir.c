#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "editorial.h"
#include "libros.h"

void ImprimirUnLibro(eLibro* listaLibros, LinkedList* listaEditorial){
	char nombre [180];
	if(listaLibros!=NULL && listaEditorial != NULL){
		EncontrarEditorialByID(listaEditorial,nombre,listaLibros->idEditorial);
		if(nombre != NULL){
			printf("| %5d | %70s | %35s | %15.2f | %20s |\n",listaLibros->id,listaLibros->titulo, listaLibros->autor,listaLibros->precio,nombre);
		}
	}
}

void ImprimirListaLibros(LinkedList* listaLibros, LinkedList* listaEditorial){
	int largo;
	eLibro* aux;
	if(listaLibros != NULL && listaEditorial != NULL){
		largo = ll_len(listaLibros);

		for(int i=0; i<largo; i++){
			aux = (eLibro*) ll_get(listaLibros, i);
			ImprimirUnLibro(aux, listaEditorial);
		}
	}
}

