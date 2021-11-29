#ifndef LIBROS_H_
#define LIBROS_H_
struct eLibro
{
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int idEditorial;

}typedef eLibro;

/// @fn eLibro libro_new*()
/// crea un malloc para un nuevo libro y retorna el puntero
/// @return
eLibro* libro_new();

/// @fn void libro_mostrar(eLibro*)
/// @param this
/// imprime los campos de eLibro
void libro_mostrar(eLibro* this);

/// @fn eLibro libro_newArguments*(int, char*, char*, int, int)
/// @param id
/// @param titulo
/// @param autor
/// @param precio
/// @param idEditorial
/// llena los campos de un eLibro
/// @return
eLibro* libro_newArguments(int id, char* titulo, char* autor, float precio, int idEditorial);

/// @fn void libro_delete(eLibro*)
/// @param this
/// elimina un eLibro
void libro_delete(eLibro* this);

/// @fn int libro_setId(eLibro*, int)
/// @param this
/// @param id
/// asigna un entero al campo ID
/// @return
int libro_setId(eLibro* this,int id);

/// @fn int libro_getId(eLibro*, int*)
/// @param this
/// @param id
/// obtiene el valor del campo id y lo pasa por puntero
/// @return
int libro_getId(eLibro* this,int* id);

/// @fn int libro_setTitulo(eLibro*, char*)
/// @param this
/// @param titulo
/// asigna una cadena al campo titulo
/// @return
int libro_setTitulo(eLibro* this, char* titulo);

/// @fn int libro_getTitulo(eLibro*, char*)
/// @param this
/// @param titulo
/// obtiene el valor del campo titulo y lo pasa por puntero
/// @return
int libro_getTitulo(eLibro* this,char* titulo);

/// @fn int libro_setAutor(eLibro*, char*)
/// @param this
/// @param autor
/// asigna una cadena al campo autor
/// @return
int libro_setAutor(eLibro* this, char* autor);

/// @fn int libro_getAutor(eLibro*, char*)
/// @param this
/// @param autor
/// obtiene el valor del campo autor y lo pasa por puntero
/// @return
int libro_getAutor(eLibro* this,char* autor);

/// @fn int libro_setPrecio(eLibro*, float)
/// @param this
/// @param precio
/// asigna un flotante al campo precio
/// @return
int libro_setPrecio(eLibro* this,float precio);

/// @fn int libro_getPrecio(eLibro*, float*)
/// @param this
/// @param precio
/// obtiene el valor del campo precio y lo pasa por puntero
/// @return
int libro_getPrecio(eLibro* this,float* precio);

/// @fn int libro_setIDEditorial(eLibro*, int)
/// @param this
/// @param idEditorial
/// asigna un entero al campo idEditorial
/// @return
int libro_setIDEditorial(eLibro* this,int idEditorial);

/// @fn int libro_getIDEditorial(eLibro*, int*)
/// @param this
/// @param idEditorial
/// obtiene el valor del campo idEditorial y lo pasa por puntero
/// @return
int libro_getIDEditorial(eLibro* this,int* idEditorial);

/// @fn int OrdenarPorIDLibro(void*, void*)
/// @param libro1
/// @param libro2
/// compara las ID de 2 libros
/// @return
int OrdenarPorIDLibro(void* libro1, void* libro2);

/// @fn int OrdenarPorTituloLibro(void*, void*)
/// @param libro1
/// @param libro2
/// compara los titulos de 2 libros
/// @return
int OrdenarPorTituloLibro(void* libro1, void* libro2);

/// @fn int OrdenarPorAutorLibro(void*, void*)
/// @param libro1
/// @param libro2
/// compara los autores de 2 libros
/// @return
int OrdenarPorAutorLibro(void* libro1, void* libro2);

/// @fn int OrdenarPorPrecioLibro(void*, void*)
/// @param libro1
/// @param libro2
/// compara los precios de 2 libros
/// @return
int OrdenarPorPrecioLibro(void* libro1, void* libro2);

/// @fn int FiltroPlaneta(void*)
/// @param this
/// verifica si el libro es de la editorial
/// @return
int FiltroPlaneta(void* this);

/// @fn int FiltroSiglo(void*)
/// @param this
/// verifica si el libro es de la editorial
/// @return
int FiltroSiglo(void* this);

/// @fn int FiltroPearson(void*)
/// @param this
/// verifica si el libro es de la editorial
/// @return
int FiltroPearson(void* this);

/// @fn int FiltroMinotauro(void*)
/// @param this
/// verifica si el libro es de la editorial
/// @return
int FiltroMinotauro(void* this);

/// @fn int FiltroSalamandra(void*)
/// @param this
/// verifica si el libro es de la editorial
/// @return
int FiltroSalamandra(void* this);

/// @fn int FiltroPenguin(void*)
/// @param this
/// verifica si el libro es de la editorial
/// @return
int FiltroPenguin(void* this);

/// @fn void DescuentosByEditoriales*(void*)
/// @param element
/// analiza la editorial y el precio de un libro
void* DescuentosByEditoriales(void* element);

#endif /* LIBROS_H_ */
