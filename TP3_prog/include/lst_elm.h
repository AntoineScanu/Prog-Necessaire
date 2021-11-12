#ifndef _LSTELM_
#define _LSTELM_


struct lst_elm_t {
  int x;
  struct lst_elm_t * suc;
};
/***
 * DÉCLARATION DES FONCTIONS PUBLIQUES
 ***/
/** @brief Création d'un nouvel élément de liste d'entiers */
struct lst_elm_t * new_lst_elm(int value);
/** @brief Suppression d'un élément de liste d'entiers */
void del_lst_elm_t(struct lst_elm_t ** ptrE);
/** @ brief Accéder au champ x de l'élément de liste d'entiers */
int getX ( struct lst_elm_t *E );
/** @ brief Accéder au champ suc de l'élément de liste d'entiers */
struct lst_elm_t * getSuc ( struct lst_elm_t * E );
/** @brief Modifier la valeur du champ x de l'élément de liste d'entiers */
void setX (struct lst_elm_t * E, int v );
/** @brief Modifier la valeurstruct lst_elm_t * new_lst_elm(int x){
	struct lst_elm_t * E;
 	E = (struct lst_elm_t *) calloc(1, sizeof(struct lst_elm_t));
 	assert(E);
	E->x= x;
	return E;
}champ suc de l'élément de liste d'entiers */
void setSuc ( struct lst_elm_t *E, struct lst_elm_t * S );

#endif