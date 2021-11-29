#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

/// @fn int controller_loadLibrosFromText(char*, LinkedList*)
/// @param path
/// @param listaLibros
/// abre un archivo y ejecuta la fn parser_LibrosFromText
/// @return
int controller_loadLibrosFromText(char* path , LinkedList* listaLibros);

/// @fn int controller_loadEditorialesFromText(char*, LinkedList*)
/// @param path
/// @param listaEditoriales
/// abre un archivo y ejecuta la fn parser_EditorialFromText
/// @return
int controller_loadEditorialesFromText(char* path , LinkedList* listaEditoriales);

/// @fn int controller_ListaLibros(LinkedList*, LinkedList*)
/// @param listaLibros
/// @param listaEditorial
/// imprime la lista de libros
/// @return
int controller_ListaLibros(LinkedList* listaLibros, LinkedList* listaEditorial);

/// @fn int controller_ListaEditoriales(LinkedList*)
/// @param listaEditoriales
/// imprime la lista de editoriales
/// @return
int controller_ListaEditoriales(LinkedList* listaEditoriales);

/// @fn int controller_sortLibros(LinkedList*)
/// @param listaLibros
/// genera un menu de ordenamiento
/// @return
int controller_sortLibros(LinkedList* listaLibros);

/// @fn int controller_filterLibrosByEditorial(LinkedList*, LinkedList*)
/// @param listaLibros
/// @param listaEditorial
/// genera un menu de filtrado
/// @return
int controller_filterLibrosByEditorial(LinkedList* listaLibros, LinkedList* listaEditorial);

/// @fn int controller_saveLibroAsText(char*, LinkedList*)
/// @param path
/// @param listaLibro
/// guarda la lista de libros en un archivo en la direccion pasada por parametro
/// @return
int controller_saveLibroAsText(char* path , LinkedList* listaLibro);

/// @fn  controller_mapper(LinkedList*, LinkedList*)
/// @param listaLibro
/// @param listaEditorial
/// crea guarda e imprime una lista mapeada, segun el criterio indicado
int controller_mapper(LinkedList* listaLibro, LinkedList* listaEditorial);
