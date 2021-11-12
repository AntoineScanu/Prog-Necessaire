#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions
#include "lst.h"
#include "lst_elm.h"
#include "outils.h"


int main()
{
    int v;
    struct lst_t *L = new_lst();
    printf("Veuillez rentrer une valeur :\n");
    scanf("Valeur : %d", &v);
    while (v > 0)
    {
        int *ptrv = calloc(1, sizeof(int));
        *ptrv = v;
        cons(L, ptrv);
    }
    view_lst(L, NULL);
    del_lst(&L, NULL);
    return EXIT_SUCCESS;
}


// int main() {
// 	int v;
// 	struct lst_t * L = new_lst();
// 	printf("Entrer des valeurs puis 0 pour valider : ");
// 	scanf( "%d", &v );
// 	while( v > 0 ) {
// 		// insert_ordered(L,v);
// 		scanf("%d",&v);
// 	}
// 	print_lst(L);
// 	del_lst(&L);
// 	return EXIT_SUCCESS;
// }