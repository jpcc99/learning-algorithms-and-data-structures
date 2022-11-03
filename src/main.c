#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct int_slice {
	const int *p_arr;
	const size_t len;
} IntSlice;

void test_stack(Stack *stack, IntSlice *slice);

int main() {
	const int arr[] = {1, 2, 3};
	IntSlice slice = {
		.p_arr = arr,
		.len = sizeof(arr) / sizeof(int),
	};

	Stack stack = stack_new();

	test_stack(&stack, &slice);
	stack_delete(&stack);
	return 0;
}

void test_stack(Stack *stack, IntSlice *slice) {
	for (size_t i = 0; i < slice->len; i++) {
		Result_i result = stack_push(stack, slice->p_arr[i]);
		if (result.is_err) {
			fprintf(stderr, "%s\n", result.err);
			return;
		} else {
			printf("pushed val:\t%d\n", slice->p_arr[i]);
		}
	}
	for (size_t i = slice->len; i > 0; i--) {
		Result_i result = stack_pop(stack);
		if (result.is_err) {
			fprintf(stderr, "Trying to pop at a empty stack\n");
			return;
		} else {
			printf("popped val:\t%d\n", result.ok);
		}
	}
}
