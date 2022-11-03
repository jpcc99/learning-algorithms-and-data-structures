#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack stack_new() {
	Stack new_stack = { 
		.p_arr = NULL,
		.len = 0,
		.capacity = 0,
	};
	return new_stack;
}

Stack stack_with_capacity(size_t capacity) {
	Stack new_stack = { 
		.p_arr = (int*)malloc(sizeof(int) * capacity),
		.len = 0,
		.capacity = capacity,
	};
	return new_stack;
}

void stack_delete(Stack* self) {
	free(self->p_arr);
	self->p_arr = NULL;
}

const int* stack_peek(const Stack* self) {
	if (self->len < 1) {
		fprintf(stderr, "Trying to peek at a empty stack");
		return NULL;
	}
	return &self->p_arr[self->len - 1];
}

Result_i stack_push(Stack* self, int item) {
	if (self->capacity == 0) {
		self->p_arr = (int*)malloc(sizeof(int));
		if (self->p_arr == NULL) 
			return result_new_err("Cold not allocate memory");
		self->capacity = 1;
	} else if (self->capacity == self->len) {
		size_t new_capacity = self->capacity * 2;
		int *p_aux = realloc(self->p_arr, new_capacity);
		if (p_aux == NULL) 
			return result_new_err("Cold not reallocate memory");
		self->p_arr = p_aux;
		self->capacity = new_capacity;
	}
	self->p_arr[self->len] = item;
	self->len++;
	return result_new_ok(0);
}

Result_i stack_pop(Stack *self) {
	if (self->capacity == 0 || self->len == 0) {
		return result_new_err("Trying to pop a empty stack");
	}
	size_t len = self->len - 1;
	int popped = self->p_arr[len];
	self->len = len;
	return result_new_ok(popped);
}
