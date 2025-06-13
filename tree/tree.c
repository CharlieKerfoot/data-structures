#include <stdio.h>
#include <stdlib.h>
#include "../value/value.h"
#include "tree.h"
#include "../errors/error.h"

struct tree {
	//binary search tree
	value *root;
	struct tree *left;
	struct tree *right;
};

tree *create_tree(value* v) {
	tree *t = malloc(sizeof(tree));
	if (!t) {
		throw_error("Memory Allocation Failed");
	}

	t->root = v;
	t->left = NULL;
	t->right = NULL;

	return t;
}

void add_tree_value(tree **t, value *v) {
	if (!v) {
		throw_error("Value Does Not Exist");
	}

	if (!*t) {
		*t = create_tree(v);
		return;
	}

	if (!(*t)->root) {
		(*t)->root = v;
		return;
	}

	if (v->data < (*t)->root->data) {
		add_tree_value(&((*t)->left), v);
	}else if (v->data > (*t)->root->data) {
		add_tree_value(&((*t)->right), v);
	}
}

int has_node(tree *t, value *v) {
	if (!t) return 0;

	if (t->root == v) return 1;

	if (v->data < t->root->data) {
		return has_node(t->left, v);
	}else if (v->data > t->root->data) {
		return has_node(t->right, v);
	}
	
	return 0;
}

void print_tree(tree *t) {
	//pre-order
	if (!t) return;

	if (t->root) {
		print_value(t->root);
	}

	print_tree(t->left);
	print_tree(t->right);
}

void free_tree(tree *t) {
	if (!t) return;

	free_value(t->root);
	free_tree(t->left);
	free_tree(t->right);
	free(t);
}

