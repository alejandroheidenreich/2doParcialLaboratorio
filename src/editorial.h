#ifndef EDITORIAL_H_
#define EDITORIAL_H_
struct eEditorial
{
    int idEditorial;
    char nombre[128];

}typedef eEditorial;

/// @fn eEditorial editorial_new*()
/// crea un malloc para una nueva editorial y retorna el puntero
/// @return
eEditorial* editorial_new();

/// @fn void editorial_mostrar(eEditorial*)
/// @param this
/// imprime una editorial
void editorial_mostrar(eEditorial* this);

/// @fn eEditorial editorial_newArguments*(int, char*)
/// @param id
/// @param nombre
/// carga los campo de una editorial
/// @return
eEditorial* editorial_newArguments(int id, char* nombre);

/// @fn void editorial_delete(eEditorial*)
/// elimina la editorial en memoria
/// @param this
void editorial_delete(eEditorial* this);

/// @fn int editorial_setId(eEditorial*, int)
/// @param this
/// @param id
/// asigna un entero al campo ID
/// @return
int editorial_setId(eEditorial* this,int id);

/// @fn int editorial_getId(eEditorial*, int*)
/// @param this
/// @param id
/// obtiene el valor del campo id y lo pasa por puntero;
/// @return
int editorial_getId(eEditorial* this,int* id);

/// @fn int editorial_setNombre(eEditorial*, char*)
/// @param this
/// @param nombre
/// asigna una cadena al campo nombre
/// @return
int editorial_setNombre(eEditorial* this, char* nombre);

/// @fn int editorial_getNombre(eEditorial*, char*)
/// @param this
/// @param nombre
/// obtiene el valor del campo nombre y lo pasa por puntero;
/// @return
int editorial_getNombre(eEditorial* this,char* nombre);

/// @fn int EncontrarEditorialByID(LinkedList*, char*, int)
/// @param this
/// @param nombre
/// @param id
/// busca la editorial con la id pasa por parametro, retorna el index del nodo y el valor del campo nombre por puntero
/// @return
int EncontrarEditorialByID(LinkedList* this,char* nombre, int id);


#endif /* EDITORIAL_H_ */
