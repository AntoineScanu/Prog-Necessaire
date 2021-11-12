#ifndef _LST_
#define _LST_
#include <stdbool.h>
#include <lst_elm.h>

struct lst_t {
	struct lst_elm_t * head;
	struct lst_elm_t * tail;
	int numelm;
};
/***
 * DÉCLARATION DES FONCTIONS PUBLIQUES
 ***/
/** @brief Construire une liste vide */
struct lst_t * new_lst();
/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t ** ptrL );
/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t * L);
/** @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t * L, int v);
/** @brief Visualiser les éléments de la liste L */
void print_lst(struct lst_t * L );
void insert_ordered(struct lst_t * L, const int value);

#endif