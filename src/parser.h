#ifndef PARSER_H_
#define PARSER_H_

/// @fn int parser_EditorialFromText(FILE*, LinkedList*)
/// @param pFile
/// @param listaEditorial
/// lee el archivo y carga las editoriales a la linkedlist
/// @return
int parser_EditorialFromText(FILE* pFile , LinkedList* listaEditorial);

/// @fn int parser_LibrosFromText(FILE*, LinkedList*)
/// @param pFile
/// @param listaLibros
/// lee el archivo y carga los libros a la linkedlist
/// @return
int parser_LibrosFromText(FILE* pFile , LinkedList* listaLibros);

#endif /* PARSER_H_ */
