#include "result.h"

Result_i result_new_ok(int ok_val) {
	Result_i ok_reslult = {
		.is_err = false,
		.ok = ok_val,
	};
	return ok_reslult;
}
Result_i result_new_err(const char* err_msg) {
	Result_i err_result = {
		.is_err = true,
		.err = err_msg,
	};
	return err_result;
}
