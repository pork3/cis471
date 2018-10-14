#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct s{
	int r;
}s;


int main(int argc, char** argv){

	const stack* st = create_stack();

	int i;
	s* s1 = malloc(sizeof(s));
	s1->r = 1;
	s* s2 = malloc(sizeof(s));
	s2->r = 2;
	s* s3 = malloc(sizeof(s));
	s3->r = 3;



	st->push(st, s1);
	st->push(st, s2);
	st->push(st, s3);
	long l;
	l = st->size(st);
	printf("is is %ld\n",l);
	s* s4;;
	for(i =0 ; i < 3 ;i ++){
	st->pop(st, (void**)&s4);
	l = st->size(st);
	printf("sisz is %ld\n",l);
	printf("top is %d\n", s4->r);
	free(s4);
	}
	st->destroy(st);

	return 0;

}