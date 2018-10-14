#ifndef _INCLUDED_STACK_H
#define _INCLUDED_STACK_H


typedef struct stack stack;

const stack* create_stack();

struct stack {

	void* self;

	int (*push)(const stack* s, void* d);

	/*returns first item in stack, stores in variable d
	it is the callers responsibility to free*/
	int (*pop)(const stack* s, void** d);

	int (*peek)(const stack* s, void** d);

	int (*is_empty)(const stack* s);

	long (*size)(const stack* s);

	void (*destroy)(const stack* s);
};






#endif