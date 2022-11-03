#pragma once

#include <stddef.h>
#include "result.h"

typedef struct {
	int *p_arr;
	size_t len;
	size_t capacity;
} Stack;

Stack stack_new();
Stack stack_with_capacity(size_t capacity);
void stack_delete(Stack* self);
const int* stack_peek(const Stack* self);
Result_i stack_push(Stack* self, int item);
Result_i stack_pop(Stack *self);
