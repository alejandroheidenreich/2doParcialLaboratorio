/*Desarrollar en ANSI C:
Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
función ll_filter* del LinkedList. Guardar el listado en un archivo csv.

Alejandro Heidenreich.
*/

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "libros.h"
#include "editorial.h"
#include "parser.h"
#include "controller.h"

int main(void) {
	setbuf(stdout,NULL);
	int option, verify;
	char archivo [180];
	int flagCargaLibros = 0;
	int flagCargaEditoriales = 0;
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();

	do{
		clear();
		printf("1. Cargar los datos de los libros desde el archivo.\n");
		printf("2. Cargar los datos de las editoriales desde el archivo.\n");
		printf("3. Ordenar la lista de libros.\n");
		printf("4. Imprimir por pantalla todos los datos de los libros.\n");
		printf("5. Listado de los libros filtrados por editorial.\n");
		printf("6. Generar archivo de salida 'mapeado.csv' con descuentos.\n");
		printf("0. Salir.\n");

		option = IngresarEntero("Ingrese una opcion\n",0,6);

		switch(option){
			case 1:
				IngresarArchivo("Ingrese la direccion del archivo de lista de libros que desea cargar (tipo de archivo csv)\n", archivo);
				verify = controller_loadLibrosFromText(archivo,listaLibros);
				//verify = controller_loadLibrosFromText("libros30.csv",listaLibros);
				if(verify){
					printf("\nArchivo de Libros Cargados\n");
					flagCargaLibros=1;
				}
				else{
					printf("\nError al cargar el Archivo\n");
				}
				break;
			case 2:
				IngresarArchivo("Ingrese la direccion del archivo de lista de editoriales que desea cargar (tipo de archivo csv)\n", archivo);
				verify = controller_loadEditorialesFromText(archivo,listaEditoriales);
				//verify = controller_loadEditorialesFromText("editoriales.csv",listaEditoriales);
				if(verify){
					printf("\nArchivo de Editoriales Cargados\n");
					flagCargaEditoriales = 1;
				}
				else{
					printf("\nError al cargar el Archivo\n");
				}
				break;
			case 3:
				if(flagCargaLibros && flagCargaEditoriales){
					if(controller_sortLibros(listaLibros)){
						printf("\nLista de Libros ordenada\n");
					}
				}
				else{
					printf("Los archivos no fueron cargados\n");
				}
				break;
			case 4:
				if(flagCargaLibros && flagCargaEditoriales){
					controller_ListaLibros(listaLibros,listaEditoriales);
				}
				else{
					printf("Los archivos no fueron cargados\n");
				}
				break;
			case 5:
				if(flagCargaLibros && flagCargaEditoriales){
					controller_filterLibrosByEditorial(listaLibros, listaEditoriales);
				}
				break;
			case 6:
				verify = controller_mapper(listaLibros, listaEditoriales);
				if(verify){
					printf("Archivo de mapeado generado con exito.\n");
				}
				else{
					printf("Los archivos no fueron cargados\n");
				}
				break;
		}

	}while(option != 0);
	return EXIT_SUCCESS;
}
