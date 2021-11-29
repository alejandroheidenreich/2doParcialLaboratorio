#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <ctype.h>
#include "LinkedList.h"
#include <string.h>
#include "editorial.h"



eEditorial* editorial_new(){
	eEditorial* editorial;

	editorial = (eEditorial*)malloc(sizeof(eEditorial));

	return editorial;
}

void editorial_mostrar(eEditorial* this){

	if(this!=NULL){
		printf("| %5d | %35s |\n",this->idEditorial,this->nombre);
	}
}

eEditorial* editorial_newArguments(int id, char* nombre){
	eEditorial* editorial = editorial_new();
	if(editorial != NULL){
		editorial_setId(editorial,id);
		editorial_setNombre(editorial,nombre);
	}

	return editorial;
}

void editorial_delete(eEditorial* this){
		free(this);
}

int editorial_setId(eEditorial* this,int id){
	int check=0;
	if(this!=NULL){
		check=1;
		this->idEditorial=id;
	}
	return check;
}

int editorial_getId(eEditorial* this,int* id){
	int check=0;
	if(this!=NULL){
		check=1;
		*id=this->idEditorial;
	}
	return check;
}

int editorial_setNombre(eEditorial* this, char* nombre){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(this->nombre,nombre);
	}

	return check;
}

int editorial_getNombre(eEditorial* this,char* nombre){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(nombre,this->nombre);
	}
	return check;
}

int EncontrarEditorialByID(LinkedList* this,char* nombre, int id){
	int i=-1, largo;
	eEditorial* aux;

	if(this != NULL && id>0 && id < 7){
		largo = ll_len(this);
		for(i=0; i<largo; i++){
			aux = ll_get(this,i);
			if(id == aux->idEditorial){
				editorial_getNombre(aux,nombre);
				break;
			}
		}
		if(i==largo){
			i = -1;
		}
	}

	return i;
}


