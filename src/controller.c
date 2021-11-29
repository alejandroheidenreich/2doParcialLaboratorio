#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "libros.h"
#include "editorial.h"
#include "parser.h"
#include "controller.h"
#include "imprimir.h"

int controller_loadLibrosFromText(char* path , LinkedList* listaLibros)
{
	int check=0;
	FILE* pFile;

	if(path != NULL && listaLibros != NULL){
		pFile = fopen(path, "r");

		if(pFile!=NULL){
			ll_clear(listaLibros);
			parser_LibrosFromText(pFile,listaLibros);
			check=1;
		}

		fclose(pFile);
	}
    return check;
}

int controller_loadEditorialesFromText(char* path , LinkedList* listaEditoriales)
{
	int check=0;
	FILE* pFile;

	if(path != NULL && listaEditoriales != NULL){
		pFile = fopen(path, "r");

		if(pFile!=NULL){
			ll_clear(listaEditoriales);
			parser_EditorialFromText(pFile,listaEditoriales);
			check=1;
		}

		fclose(pFile);
	}
    return check;
}

int controller_ListaLibros(LinkedList* listaLibros, LinkedList* listaEditorial)
{
	int check=0;
	int largo;

	if(listaLibros != NULL){
		largo = ll_len(listaLibros);
		if(largo>0){
			check=1;
			printf("=================================================================================================================================================================\n");
			printf("|   ID  |                                TITULO                                  |                AUTOR                |      PRECIO     |       EDITORIAL      |\n");
			printf("=================================================================================================================================================================\n");
			ImprimirListaLibros(listaLibros, listaEditorial);
			printf("=================================================================================================================================================================\n");
		}
	}
    return check;
}

int controller_ListaEditoriales(LinkedList* listaEditoriales)
{
	int check=0;
	int largo;
	eEditorial* aux = editorial_new();

	if(listaEditoriales != NULL){
		largo = ll_len(listaEditoriales);
		if(largo>0){
			check=1;
			printf("===============================================\n");
			printf("|   ID  |               NOMBRE                |\n");
			printf("===============================================\n");
			for(int i=0; i<largo; i++){
				aux = (eEditorial*) ll_get(listaEditoriales, i);
				editorial_mostrar(aux);
			}
			printf("===============================================\n");
		}
	}
    return check;
}

int controller_sortLibros(LinkedList* listaLibros)
{
	int option;
	int check=0;
	int verify;
	int orden;

	if(listaLibros != NULL){
		do{
			printf("\n\tComo desea ordenar la lista?\n");
			printf("\t1- ID\n\t2- TITULO\n\t3- AUTOR\n\t4- PRECIO\n\t0- ATRAS\n\n");
			option = IngresarEntero("\n\tIngrese una opcion: ",0,4);
			if(option != 0){
				printf("\t1- ASCENDENTE\n\t2- DESCENDENTE\n\n");
				orden = IngresarEntero("\n\tIngrese una opcion: ",1,2);
				if(orden!=1){
					orden=0;
				}
				printf("\n\tOrdenando la lista, porfavor espere...\n");
				switch(option){
					case 1:
						verify = ll_sort(listaLibros, OrdenarPorIDLibro, orden);
						if(verify){
							check=1;
						}
						break;

					case 2:
						verify = ll_sort(listaLibros, OrdenarPorTituloLibro, orden);
						if(verify){
							check=2;
						}

						break;

					case 3:
						verify = ll_sort(listaLibros, OrdenarPorAutorLibro, orden);
						if(verify){
							check=3;
						}
						break;
					case 4:
						verify = ll_sort(listaLibros,OrdenarPorPrecioLibro, orden);
						if(verify){
							check=4;
						}
						break;
				}
			}
		}while(option!=0);
	}
    return check;
}

int controller_filterLibrosByEditorial(LinkedList* listaLibros, LinkedList* listaEditorial)
{
	int option;
	int check=0;
	LinkedList* filtro = NULL;
	if(listaLibros != NULL){
		do{
			printf("\n\tPor cual editorial desea filtrar la lista?\n");
			printf("\t1- PLANETA\n\t2- SIGLO XXI EDITORES\n\t3- PEARSON\n\t4- MINOTAURO\n\t5- SALAMANDRA\n\t6- PENGUIN BOOKS\n\t0- ATRAS\n\n");
			option = IngresarEntero("\n\tIngrese una opcion: ",0,6);
			if(option != 0){
				printf("\n\tFiltrando la lista, porfavor espere...\n");
				switch(option){
					case 1:
						filtro = ll_filter(listaLibros,FiltroPlaneta);
						if(filtro != NULL){
							controller_ListaLibros(filtro,listaEditorial);
							controller_saveLibroAsText("Planeta.csv", filtro);
							check=1;
						}
						else{
							printf("No existen libros de la Editorial: Planeta\n");
						}
						break;

					case 2:
						filtro = ll_filter(listaLibros,FiltroSiglo);
						if(filtro != NULL){
							controller_ListaLibros(filtro,listaEditorial);
							controller_saveLibroAsText("Siglo XXI Editores.csv", filtro);
							check=2;
						}
						else{
							printf("No existen libros de la Editorial: Siglo XXI Editores\n");
						}
						break;
					case 3:
						filtro = ll_filter(listaLibros,FiltroPearson);
						if(filtro != NULL){
							controller_ListaLibros(filtro,listaEditorial);
							controller_saveLibroAsText("Pearson.csv", filtro);
							check=3;
						}
						else{
							printf("No existen libros de la Editorial: Pearson\n");
						}
						break;
					case 4:
						filtro = ll_filter(listaLibros,FiltroMinotauro);
						if(filtro != NULL){
							controller_ListaLibros(filtro,listaEditorial);
							controller_saveLibroAsText("Minotauro.csv", filtro);
							check=4;
						}
						else{
							printf("No existen libros de la Editorial: Minotauro\n");
						}
						break;
					case 5:
						filtro = ll_filter(listaLibros,FiltroSalamandra);
						if(filtro != NULL){
							controller_ListaLibros(filtro,listaEditorial);
							controller_saveLibroAsText("Salamandra.csv", filtro);
							check=5;
						}
						else{
							printf("No existen libros de la Editorial: Salamandra\n");
						}
						break;
					case 6:
						filtro = ll_filter(listaLibros,FiltroPenguin);
						if(filtro != NULL){
							controller_ListaLibros(filtro,listaEditorial);
							controller_saveLibroAsText("PenguinBooks.csv", filtro);
							check=6;
						}
						else{
							printf("No existen libros de la Editorial: Penguin Books\n");
						}
						break;
				}
			}
		}while(option != 0);
	}
    return check;
}


int controller_saveLibroAsText(char* path , LinkedList* listaLibro)
{
	int check = 0;
	int largo;

	FILE* pFile;
	eLibro* aux;

	if(path != NULL && listaLibro != NULL){
		largo = ll_len(listaLibro);

		pFile = fopen(path, "w");

		if(pFile!=NULL){
			fprintf(pFile,"ID,Titulo,Autor,Precio,idEditorial\n");
			for(int i=0;i<largo;i++){
				aux=(eLibro*)ll_get(listaLibro,i);
				if(aux != NULL){
					fprintf(pFile,"%d,%s,%s,%f,%d\n",aux->id, aux->titulo, aux->autor, aux->precio, aux->idEditorial);
				}
			}
			check = 1;
		}

		fclose(pFile);
	}
    return check;
}

int controller_mapper(LinkedList* listaLibro, LinkedList* listaEditorial){
	int check=0;
	LinkedList* mapArray;

	if(listaLibro != NULL && listaEditorial != NULL){
		mapArray = ll_map(listaLibro,DescuentosByEditoriales);
		controller_saveLibroAsText("mapeado.csv" ,listaLibro);
		controller_ListaLibros(mapArray, listaEditorial);
		check = 1;
	}
	return check;
}
