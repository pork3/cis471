#include "letter.h"
#include <stdlib.h>
#include <string.h>


int change_domain(letter* l, int val){
	if (val < 10){
		l->domain[val] = ~(l->domain[val]);
		return 1;
	} return 0;
};

letter* create_letter(char let){
	letter* l = (letter*)malloc(sizeof(letter));
	if ( l == NULL)
		return NULL;
	int i;
	for(i = 0; i < 10; i++){
		l->domain[i] = 1;
	}
	l->alpha = let;
	return l;
}