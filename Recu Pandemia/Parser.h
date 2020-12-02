#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Tomo un archivo de texto tipo csv.
 *
 * \param path char*
 * \param pArrayListP LinkedList*
 * \return int
 *
 */
int cargarArchivo_Pandemia(char* path , LinkedList* pArrayListP);

/** \brief Copia el contenido del archivo de texto.csv.
 *
 * \param pFile FILE*
 * \param pArrayListP LinkedList*
 * \return int
 *
 */
int parser_Pandemia(FILE* pFile , LinkedList* pArrayListP);

/** \brief Guarda el contenido en un nuevo archivo.csv
 *
 * \param path char*
 * \param pArrayListP LinkedList*
 * \return int
 *
 */
int guardarComoTexto(char* path, LinkedList* pArrayListP);


#endif // PARSER_H_INCLUDED
