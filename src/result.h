#pragma once

#include <stdbool.h>

typedef struct {
	bool is_err;
	union {
		const char * err;
		int ok;
	};
} Result_i; 

Result_i result_new_ok(int ok_val);
Result_i result_new_err(const char* err_msg);
