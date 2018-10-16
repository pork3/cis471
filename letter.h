#ifndef _INCLUDED_LETTERS_H
#define _INCLUDED_LETTERS_H 

typedef struct letter{

	int domain[10];
	char alpha;
	int value;

} letter;

letter* create_letter(char let);

int change_domain(letter* l, int val);



#endif