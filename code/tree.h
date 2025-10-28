#ifndef TREE_H
#define TREE_H

struct node {
    int val;
    struct node *left;
    struct node *right;
};

// build tree from level order array
struct node* build_tree_from_level(int arr[], int n);

// compute minimum phones required so every node is covered
int min_phones(struct node* root);

// free tree memory
void free_tree(struct node* root);

#endif
