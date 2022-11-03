#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct int_slice {
	const int *p_arr;
	const size_t len;
} IntSlice;

void test_queue(Queue *queue, IntSlice *slice);

int main() {
	const int arr[] = {1, 2, 3};
	IntSlice slice = {
		.p_arr = arr,
		.len = sizeof(arr) / sizeof(int),
	};

	Queue queue = queue_new();

	test_queue(&queue, &slice);
	queue_delete(&queue);
	return 0;
}

void test_queue(Queue *queue, IntSlice *slice) {
	for (size_t i = 0; i < slice->len; i++) {
		Result_i result = queue_push(queue, slice->p_arr[i]);
		if (result.is_err) {
			fprintf(stderr, "%s\n", result.err);
			return;
		} else {
			printf("pushed val:\t%d\n", slice->p_arr[i]);
		}
	}
	for (size_t i = slice->len; i > 0; i--) {
		Result_i result = queue_remove(queue);
		if (result.is_err) {
			fprintf(stderr, "Trying to pop at a empty queue\n");
			return;
		} else {
			printf("popped val:\t%d\n", result.ok);
		}
	}
}
