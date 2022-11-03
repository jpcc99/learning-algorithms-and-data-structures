#pragma once

#include <stddef.h>
#include "result.h"

typedef struct {
	int *p_arr;
	size_t len;
	size_t capacity;
} Queue;

Queue queue_new();
Queue queue_with_capacity(size_t capacity);
void queue_delete(Queue* self);
const int* queue_peek(const Queue* self);
Result_i queue_push(Queue* self, int item);
Result_i queue_remove(Queue *self);
