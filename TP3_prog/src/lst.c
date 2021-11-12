#include "lst.h"
#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions





bool empty_lst(const struct lst_t * L ) {
	assert(L);// L doit exister !
	return L->numelm == 0;
}
void cons(struct lst_t * L, int v) {
	assert(L);
	struct lst_elm_t * E = new_lst_elm(v);
	assert(E);
	E->suc = L->head;
	L->head = E;
	if (L->numelm == 0) L->tail = E;
	L->numelm += 1;
}
void print_lst(struct lst_t * L ) {
	printf( "[ " );
	for( struct lst_elm_t * E = L->head; E; E = E->suc) {
		printf( "%d ", E->x );
	}
	printf( "]\n\n" );
}

struct lst_t * new_lst() {
	/**
	 * @note : calloc fonctionne de manière identique à malloc
	 * et de surcroît met à NULL(0) tous les octets alloués
	 **/
	struct lst_t * L = (struct lst_t *)calloc(1,sizeof(struct lst_t));
	assert(L);
	return L;
}
void del_lst(struct lst_t ** ptrL ) {
	assert(ptrL && *ptrL);
for(struct lst_elm_t * E = (*ptrL)->head; E; ) {
	struct lst_elm_t * T = E;
	E = E->suc;
	del_lst_elm_t(&T);
	}
	free(*ptrL);
	*ptrL = NULL;
}
void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place)
{
    if (place == NULL)
        cons(L, value);
    else
    {
        struct lst_elm_t *new = new_lst_elm(value);
        assert(new);
        new->suc = place->suc;
        place->suc = new;
        L->numelm++;
        if (place == L->tail)
            L->tail = new;
    }
}
void insert_ordered(struct lst_t * L, const int value){
	if (empty_lst(L)){
		cons(L, value);
	}
	else if (value <= L->head->x){
		
		cons(L, value);
	}
	else if (value >= L->tail->x){
		
		insert_after(L, value, L->tail);
	}
	else{
		for (struct lst_elm_t * E = L->head; E; E = E->suc){
			if ((E->x < value) && (value <= E->suc->x)){
				insert_after(L, value, E);
				break;
			}				
		}
		
	}
}