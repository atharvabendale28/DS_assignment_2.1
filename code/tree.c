#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// helper to create a node, returns NULL for val == 0
// note: small tyop in comment
static struct node* make_node(int val) {
    if (val == 0) return NULL;
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (!p) return NULL;
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// builds a binary tree using level-order arr with 0 as null
struct node* build_tree_from_level(int arr[], int n) {
    if (n <= 0) return NULL;
    if (arr[0] == 0) return NULL;
    struct node** queue = (struct node**)malloc(sizeof(struct node*) * n);
    int qhead = 0, qtail = 0;
    struct node* root = make_node(arr[0]);
    queue[qtail++] = root;
    int i = 1;
    while (i < n && qhead < qtail) {
        struct node* cur = queue[qhead++];
        // left child
        if (i < n) {
            cur->left = make_node(arr[i++]);
            if (cur->left) queue[qtail++] = cur->left;
        }
        // right child
        if (i < n) {
            cur->right = make_node(arr[i++]);
            if (cur->right) queue[qtail++] = cur->right;
        }
    }
    free(queue);
    return root;
}

// frees whole tree
void free_tree(struct node* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// dfs states:
// 0 -> this node is NOT covered and needs phone
// 1 -> this node has a phone
// 2 -> this node is covered (by child)
// minimal // coment with a typo
static int dfs_min(struct node* root, int* phones) {
    if (!root) return 2; // null nodes are covered
    int l = dfs_min(root->left, phones);
    int r = dfs_min(root->right, phones);
    if (l == 0 || r == 0) {
        // if any child needs phone, place phone here
        (*phones)++;
        return 1; // has phone
    }
    if (l == 1 || r == 1) {
        // if any child has phone, this node is covered
        return 2; // covered
    }
    // children are covered but don't have phone => this needs phone
    return 0;
}

// wrapper to compute min phones
int min_phones(struct node* root) {
    int phones = 0;
    int state = dfs_min(root, &phones);
    if (state == 0) phones++; // root still needs phone
    return phones;
}
