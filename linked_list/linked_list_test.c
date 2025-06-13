#include "linked_list.h"
#include "../linked_value/linked_value.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(int argc, char **argv) {
	linked_list *list = create_linked_list();

	linked_value *v0 = create_linked_value("Charlie", 24);
	linked_value *v1 = create_linked_value("Lebron", 6);
	linked_value *v2 = create_linked_value("Dwayne", 3);
	linked_value *v3 = create_linked_value("Chris", 1);
	linked_value *v4 = create_linked_value("Ray", 34);
	linked_value *v5 = create_linked_value("Chris", 11);
	linked_value *v6 = create_linked_value("Shane", 31);
	linked_value *v7 = create_linked_value("Juwan", 5);
	linked_value *v8 = create_linked_value("Mario", 15);
	linked_value *v9 = create_linked_value("Udonis", 40);

	insert_front(list, v0);
	linked_value *got0 = get_value(list, 0);
	assert(strcmp(got0->val->name, v0->val->name) == 0);
	assert(got0->val->data == v0->val->data);
	insert_front(list, v1);
	linked_value *got1 = get_value(list, 0);
	assert(strcmp(got1->val->name, v1->val->name) == 0);
	assert(got1->val->data == v1->val->data);
	insert_front(list, v2);
	linked_value *got2 = get_value(list, 0);
	assert(strcmp(got2->val->name, v2->val->name) == 0);
	assert(got2->val->data == v2->val->data);
	insert_front(list, v3);
	linked_value *got3 = get_value(list, 0);
	assert(strcmp(got3->val->name, v3->val->name) == 0);
	assert(got3->val->data == v3->val->data);
	insert_front(list, v4);
	linked_value *got4 = get_value(list, 0);
	assert(strcmp(got4->val->name, v4->val->name) == 0);
	assert(got4->val->data == v4->val->data);
	insert_front(list, v5);
	linked_value *got5 = get_value(list, 0);
	assert(strcmp(got5->val->name, v5->val->name) == 0);
	assert(got5->val->data == v5->val->data);
	insert_front(list, v6);
	linked_value *got6 = get_value(list, 0);
	assert(strcmp(got6->val->name, v6->val->name) == 0);
	assert(got6->val->data == v6->val->data);
	insert_front(list, v7);
	linked_value *got7 = get_value(list, 0);
	assert(strcmp(got7->val->name, v7->val->name) == 0);
	assert(got7->val->data == v7->val->data);
	insert(list, v8, 1);
	linked_value *got8 = get_value(list, 1);
	assert(strcmp(got8->val->name, v8->val->name) == 0);
	assert(got8->val->data == v8->val->data);
	insert(list, v9, 5);
	linked_value *got9 = get_value(list, 5);
	assert(strcmp(got9->val->name, v9->val->name) == 0);
	assert(got9->val->data == v9->val->data);
	
	assert(get_length(list) == 10);
	assert(is_sorted(list) == 0);

	merge_sort_list(list);
	assert(is_sorted(list) == 1);

	reverse_list(list);
	assert(is_sorted(list) == 0);

	insertion_sort_list(list);
	assert(is_sorted(list) == 1);

	reverse_list(list);
	assert(is_sorted(list) == 0);

	bubble_sort_pp_list(list);
	assert(is_sorted(list) == 1);

	delete_value(list, 0);
	linked_value *pop0 = pop(list, 0);
	assert(strcmp(pop0->val->name, v2->val->name) == 0);
	assert(pop0->val->data == v2->val->data);
	linked_value *pop1 = pop_last(list);
	assert(strcmp(pop1->val->name, v9->val->name) == 0);
	assert(pop1->val->data == v9->val->data);
	
	free_list(list);

	printf("All Tests Passed\n");
	return 0;
}
