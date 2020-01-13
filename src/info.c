#include "info.h"
#include <string.h>
void push_info(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		scheme_code[scheme_code_index++] = str[i];
	}
}