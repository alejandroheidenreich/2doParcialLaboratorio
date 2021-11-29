#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <ctype.h>
#include <string.h>
#include "libros.h"
#include "LinkedList.h"

eLibro* libro_new(){
	eLibro* unLibro;

	unLibro = (eLibro*)malloc(sizeof(eLibro));

	return unLibro;
}

void libro_mostrar(eLibro* this){

	if(this!=NULL){
		printf("| %5d | %70s | %35s | %15.2f | %10d |\n",this->id,this->titulo, this->autor,this->precio,this->idEditorial);
	}
}


eLibro* libro_newArguments(int id, char* titulo, char* autor, float precio, int idEditorial){
	eLibro* unLibro;
	unLibro = libro_new();

	if(unLibro != NULL){
		libro_setId(unLibro,id);
		libro_setTitulo(unLibro,titulo);
		libro_setAutor(unLibro,autor);
		libro_setPrecio(unLibro,precio);
		libro_setIDEditorial(unLibro,idEditorial);
	}


	return unLibro;
}

void libro_delete(eLibro* this){
		free(this);
}

int libro_setId(eLibro* this,int id){
	int check=0;
	if(this!=NULL){
		check=1;
		this->id=id;
	}
	return check;
}
int libro_getId(eLibro* this,int* id){
	int check=0;
	if(this!=NULL){
		check=1;
		*id=this->id;
	}
	return check;
}

int libro_setTitulo(eLibro* this, char* titulo){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(this->titulo,titulo);
	}

	return check;
}

int libro_getTitulo(eLibro* this,char* titulo){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(titulo,this->titulo);
	}
	return check;
}

int libro_setAutor(eLibro* this, char* autor){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(this->autor,autor);
	}

	return check;
}

int libro_getAutor(eLibro* this,char* autor){
	int check=0;

	if(this!=NULL){
		check=1;
		strcpy(autor,this->autor);
	}
	return check;
}

int libro_setPrecio(eLibro* this,float precio){
	int check=0;

	if(this!=NULL){
		check=1;
		this->precio=precio;
	}

	return check;
}
int libro_getPrecio(eLibro* this,float* precio){
	int check=0;

	if(this!=NULL){
		check=1;
		*precio=this->precio;
	}

	return check;
}

int libro_setIDEditorial(eLibro* this,int idEditorial){
	int check=0;

	if(this!=NULL){
		check=1;
		this->idEditorial=idEditorial;
	}

	return check;
}
int libro_getIDEditorial(eLibro* this,int* idEditorial){
	int check=0;

	if(this!=NULL){
		check=1;
		*idEditorial=this->idEditorial;
	}

	return check;
}


int OrdenarPorIDLibro(void* libro1, void* libro2){
	int check;
	eLibro* unLibro;
	eLibro* otroLibro;

	if(libro1!=NULL && libro2!=NULL){
		check=0;
		unLibro = (eLibro*)libro1;
		otroLibro = (eLibro*)libro2;

		if(unLibro->id < otroLibro->id){
			check = -1;
		}
		else if(unLibro->id > otroLibro->id){
			check = 1;
		}
	}

	return check;
}

int OrdenarPorTituloLibro(void* libro1, void* libro2){
	int check;
	eLibro* unLibro;
	eLibro* otroLibro;


	if(libro1!=NULL && libro2!=NULL){
		unLibro = (eLibro*)libro1;
		otroLibro = (eLibro*)libro2;

		check = strcmp(unLibro->titulo,otroLibro->titulo);
	}

	return check;
}

int OrdenarPorAutorLibro(void* libro1, void* libro2){
	int check;
	eLibro* unLibro;
	eLibro* otroLibro;


	if(libro1!=NULL && libro2!=NULL){
		unLibro = (eLibro*)libro1;
		otroLibro = (eLibro*)libro2;

		check = strcmp(unLibro->autor,otroLibro->autor);
	}

	return check;
}

int OrdenarPorPrecioLibro(void* libro1, void* libro2){
	int check;
	eLibro* unLibro;
	eLibro* otroLibro;


	if(libro1!=NULL && libro2!=NULL){
		check=0;
		unLibro = (eLibro*)libro1;
		otroLibro = (eLibro*)libro2;

		if(unLibro->precio < otroLibro->precio){
			check = -1;
		}
		else if(unLibro->precio > otroLibro->precio){
			check = 1;
		}
	}

	return check;
}

int FiltroMinotauro(void* this){
	int cmp=0;
	int idEditorial;
	if(this !=NULL){
		libro_getIDEditorial(this,&idEditorial);
		if(idEditorial==4){
			cmp=1;
		}
	}
	return cmp;
}

int FiltroPlaneta(void* this){
	int cmp=0;
	int idEditorial;
	if(this !=NULL){
		libro_getIDEditorial(this,&idEditorial);
		if(idEditorial==1){
			cmp=1;
		}
	}
	return cmp;
}

int FiltroSiglo(void* this){
	int cmp=0;
	int idEditorial;
	if(this !=NULL){
		libro_getIDEditorial(this,&idEditorial);
		if(idEditorial==2){
			cmp=1;
		}
	}
	return cmp;
}

int FiltroPearson(void* this){
	int cmp=0;
	int idEditorial;
	if(this !=NULL){
		libro_getIDEditorial(this,&idEditorial);
		if(idEditorial==3){
			cmp=1;
		}
	}
	return cmp;
}

int FiltroSalamandra(void* this){
	int cmp=0;
	int idEditorial;
	if(this !=NULL){
		libro_getIDEditorial(this,&idEditorial);
		if(idEditorial==5){
			cmp=1;
		}
	}
	return cmp;
}

int FiltroPenguin(void* this){
	int cmp=0;
	int idEditorial;
	if(this !=NULL){
		libro_getIDEditorial(this,&idEditorial);
		if(idEditorial==6){
			cmp=1;
		}
	}
	return cmp;
}

void* DescuentosByEditoriales(void* element){
	eLibro* aux = NULL;
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
	float precioDescontado;

	if(element != NULL){
		libro_getIDEditorial(element,&idEditorial);
		libro_getPrecio(element,&precio);
		if(idEditorial==1 && precio>=300){
			precioDescontado=precio*0.8;
			libro_getId(element, &id);
			libro_getTitulo(element, titulo);
			libro_getAutor(element, autor);

			aux = libro_newArguments(id,titulo,autor,precioDescontado,idEditorial);
		}
		else if(idEditorial==2 && precio<=200){
			precioDescontado=precio*0.9;
			libro_getId(element, &id);
			libro_getTitulo(element, titulo);
			libro_getAutor(element, autor);

			aux = libro_newArguments(id,titulo,autor,precioDescontado,idEditorial);
		}
	}

	return aux;
}
