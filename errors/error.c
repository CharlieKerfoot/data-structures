#include <stdio.h>
#include <stdlib.h>

void throw_error(char *msg) {
	fprintf(stderr, "Error: %s\n", msg);
	exit(EXIT_FAILURE);
}
