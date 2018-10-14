#include "stack.h"
#include <stdlib.h>

#define DEFAULT_CAPACITY 64L

typedef struct stack_data{
	void** array;
	long capacity;
	long size;
} stack_data;

static int s_is_empty(const stack* s){
	stack_data* sd = (stack_data*)s->self;
	return sd->size == 0;
}

static int s_resize(stack_data* sd){
	long new_capacity = 2 * sd->capacity;
	void** re_arr = (void**)malloc(new_capacity * sizeof(void*));
	if ( re_arr == NULL)
		return 0;
	int i;
	int cap = sd->capacity;
	for(i = 0; i < cap; i++){
		re_arr[i] = NULL;
		re_arr[i] = sd->array[i];
		free(sd->array[i]);
	}
	for(i = cap; i < new_capacity; i++)
		re_arr[i] = NULL;
	free(sd->array);
	sd->capacity = new_capacity;
	return 1;
}

static int s_push(const stack* s, void* d){
	stack_data* sd = (stack_data*)s->self;
	if (sd->size == sd->capacity)
		if (!s_resize(sd))
			return 0;
	sd->array[sd->size] = d;
	sd->size ++;
	return 1;
}

static int s_pop(const stack* s, void** d){
	stack_data* sd = (stack_data*)s->self;
	if ( s_is_empty(s))
		return 0;
	long sz = sd->size -1;
	*d = (void*)sd->array[sz];
	sd->size--;
	return 1;
}

static int s_peek(const stack* s, void** d){
	stack_data* sd = (stack_data*)s->self;
	if ( s_is_empty(s))
		return 0;
	*d = (void*)sd->array[sd->size];
	return 1;
}

static long s_size(const stack* s){
	stack_data* sd = (stack_data*)s->self;
	return sd->size;
}

static void s_destroy(const stack* s){
	stack_data* sd = (stack_data*)s->self;
	int i;
	int sz = sd->size;
	if(sz > 0){
		for(i = 0; i < sz; i ++){
			free(sd->array[i]);
		}
	}
	free(sd->array);
	free(sd);
	free((void*)s);
}

const stack* create_stack(){

	stack* s = (stack*)malloc(sizeof(stack));
	if ( s == NULL)
		return s;

	stack_data* sd = (stack_data*) malloc(sizeof(stack_data));
	if (sd == NULL){
		free(s);
		return NULL;
	}

	sd->capacity = DEFAULT_CAPACITY;
	
	void** ar = (void**) malloc( DEFAULT_CAPACITY * sizeof(void*));
	if( ar == NULL){
		free(s);
		free(sd);
		return NULL;
	}

	int i; 
	for (i = 0; i < DEFAULT_CAPACITY; i++){
		ar[i] = NULL;
	}
	sd->size = 0L;
	sd->array = ar;

	s->self = sd;
	/*set functions for stack*/
	s->push = s_push;
	s->pop = s_pop;
	s->peek = s_peek;
	s->is_empty = s_is_empty;
	s->size = s_size;
	s->destroy = s_destroy;

	return s;
}


