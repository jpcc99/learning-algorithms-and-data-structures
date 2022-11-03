#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue queue_new() {
	Queue new_queue = { 
		.p_arr = NULL,
		.len = 0,
		.capacity = 0,
	};
	return new_queue;
}

Queue queue_with_capacity(size_t capacity) {
	Queue new_queue = { 
		.p_arr = (int*)malloc(sizeof(int) * capacity),
		.len = 0,
		.capacity = capacity,
	};
	return new_queue;
}

void queue_delete(Queue* self) {
	free(self->p_arr);
	self->p_arr = NULL;
}

const int* queue_peek(const Queue* self) {
	if (self->len < 1) {
		fprintf(stderr, "Trying to peek at a empty queue");
		return NULL;
	}
	return &self->p_arr[self->len - 1];
}

Result_i queue_push(Queue* self, int item) {
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

void swap(int *p_a, int *p_b) {
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}

Result_i queue_remove(Queue *self) {
	if (self->capacity == 0 || self->len == 0) {
		return result_new_err("Trying to pop a empty queue");
	}
	int removed = self->p_arr[0];
	if (self->len > 1) {
		for (size_t i = 1; i < self->len; i++) {
			swap(&self->p_arr[i - 1], &self->p_arr[i]);
		}
	}
	self->len--;
	return result_new_ok(removed);
}
