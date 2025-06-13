#include "hash_map.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
	hashmap *map = create_map(2);
	linked_value *v0 = create_linked_value("Charlie", 5);
	linked_value *v1 = create_linked_value("Greg", 5);
	linked_value *v2 = create_linked_value("Chipper", 5);
	linked_value *v3 = create_linked_value("Tom", 5);
	linked_value *v4 = create_linked_value("Andruw", 5);
	linked_value *v5 = create_linked_value("Javy", 5);
	add_value(map, v0);
	assert(get_data(map, "Charlie") == 5);
	add_value(map, v1);
	assert(get_data(map, "Greg") == 5);
	add_value(map, v2);
	assert(get_data(map, "Chipper") == 5);
	assert(get_size(map) == 4);
	add_value(map, v3);
	assert(get_data(map, "Tom") == 5);
	add_value(map, v4);
	assert(get_data(map, "Andruw") == 5);
	assert(get_size(map) == 8);
	add_value(map, v5);
	assert(get_data(map, "Javy") == 5);
	assert(get_load_factor(map) == .75);
	delete_value(map, "Charlie");
	assert(get_data(map, "Charlie") == -1);
	free_map(map);
	printf("All Tests Passed\n");
	return 0;
}
