#include "LinkedList.h"
#ifndef PANDEMIA_H_INCLUDED
#define PANDEMIA_H_INCLUDED


typedef struct
{
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
}ePais;

/** \brief Genero un nuevo pais.
 *
 * \return ePais*
 *
 */
ePais* nuevo_Pais();

/** \brief Proporciono nuevos parametros del archivo.csv
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param recuStr char*
 * \param infecStr char*
 * \param muertosStr char*
 * \return ePais*
 *
 */
ePais* nuevo_PaisParametros(char* idStr,char* nombreStr,char* recuStr,char* infecStr,char* muertosStr);

/** \brief Cargo los IDS de los paises.
 *
 * \param this ePais*
 * \param id int
 * \return int
 *
 */
int setId_Pais(ePais* this,int id);

/** \brief Tomo los ID de los paises.
 *
 * \param this ePais*
 * \param id int*
 * \return int
 *
 */
int pais_getId(ePais* this,int* id);

/** \brief Cargo los nombres de los paises.
 *
 * \param this ePais*
 * \param nombre char*
 * \return int
 *
 */
int set_nombrePais(ePais* this,char* nombre);

/** \brief Tomo los nombres de los paises.
 *
 * \param this ePais*
 * \param nombre char*
 * \return int
 *
 */
int pais_getNombre(ePais* this,char* nombre);

/** \brief Cargo los recuperados de los paises.
 *
 * \param this ePais*
 * \param recuperados int
 * \return int
 *
 */
int set_recuPais(ePais* this,int recuperados);

/** \brief Tomo los recuperados de los paises.
 *
 * \param this ePais*
 * \param recuperados int*
 * \return int
 *
 */
int pais_getRecu(ePais* this,int* recuperados);

/** \brief Cargo los infectados de los paises.
 *
 * \param this ePais*
 * \param infectados int
 * \return int
 *
 */
int set_infecPais(ePais* this,int infectados);

/** \brief Tomo los infectados de los paises.
 *
 * \param this ePais*
 * \param infectados int*
 * \return int
 *
 */
int pais_getInfec(ePais* this,int* infectados);

/** \brief Cargo los muertos de los paises.
 *
 * \param this ePais*
 * \param muertos int
 * \return int
 *
 */
int set_muertosPais(ePais* this,int muertos);

/** \brief Tomo los muertos de los paises.
 *
 * \param this ePais*
 * \param muertos int*
 * \return int
 *
 */
int pais_getMuertos(ePais* this,int* muertos);

/** \brief Borro un pais.
 *
 * \param this ePais*
 * \return void
 *
 */
void borrar_Pais(ePais* this);

/** \brief Verifico si lo ingresado es un nombre desde la A hasta la Z.
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
int validNombre_Pais(char* cadena,int longitud);

/** \brief Muestro los paises cargados.
 *
 * \param pArrayListP LinkedList*
 * \return int
 *
 */
int listar_Paises(LinkedList* pArrayListP);

/** \brief Muestro un pais.
 *
 * \param pais ePais*
 * \return void
 *
 */
void ver_Pais(ePais* pais);

/** \brief Agrego recuperados a la lista.
 *
 * \param pArrayListP LinkedList*
 * \return int
 *
 */
int agregar_recu(LinkedList* pArrayListP);

/** \brief Agrego infectados a la lista.
 *
 * \param pArrayListP LinkedList*
 * \return int
 *
 */
int agregar_infec(LinkedList* pArrayListP);

/** \brief Agrego muertos a la lista.
 *
 * \param pArrayListP LinkedList*
 * \return int
 *
 */
int agregar_Muertos(LinkedList* pArrayListP);

/** \brief Numeros aleatorios entre 50k y 1000k.
 *
 * \param aleatorios void*
 * \return int
 *
 */
int datosAleatoriosRecu(void* aleatorios);

/** \brief Numeros aleatorios entre 400k y 1000k.
 *
 * \param aleatorios void*
 * \return int
 *
 */
int datosAleatoriosInfec(void* aleatorios);

/** \brief Numeros aleatorios entre 1k y 50k.
 *
 * \param aleatorios void*
 * \return int
 *
 */
int datosAleatoriosMuertos(void* aleatorios);

/** \brief Genero un archivo.csv donde solo se encontraran los paises con menor tasa de muertes.
 *
 * \param paisExitoso void*
 * \return int
 *
 */
int filtrarMejoresPaises(void* paisExitoso);

/** \brief Genero un archivo.csv donde solo se encontraran los paises con mayor tasa de infectados.
 *
 * \param pais void*
 * \return int
 *
 */
int filtrarPaisesAlHorno(void* pais);

/** \brief Ordeno la lista por nivel de infeccion de manera descendente.
 *
 * \param x void*
 * \param y void*
 * \return int
 *
 */
int ordenarXinfeccion(void* x, void* y);

/** \brief Muestro el pais o paises (si son iguales) con mas muertes.
 *
 * \param lista LinkedList*
 * \return void
 *
 */
void mostrarMasCastigado(LinkedList* lista);

/** \brief Lista unica para el pais con mas muertes.
 *
 * \param lista LinkedList*
 * \param index int
 * \return void
 *
 */
void listarPais(LinkedList* lista, int index);

#endif // PANDEMIA_H_INCLUDED
