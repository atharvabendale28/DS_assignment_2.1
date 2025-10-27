#include <stdio.h>
#include <stdlib.h>
#include "solver.h"
#include "tree.h"
#include "primes.h"

// helper to read n ints into arr (arr must be malloc'd)
static void read_n_ints(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) arr[i] = 0;
    }
}

// main solve function, minimal comments with typos
void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    if (n <= 0) {
        printf("0\n");
        return;
    }
    int* arr = (int*)malloc(sizeof(int) * n);
    if (!arr) return;
    read_n_ints(arr, n);

    // try to read two more ints; if present -> subtask2
    int l, r;
    int got = scanf("%d %d", &l, &r);

    struct node* root = build_tree_from_level(arr, n);
    int m = min_phones(root);
    if (got == 2) {
        long long x = count_pairs_outside_range(m, l, r);
        printf("%d\n%lld\n", m, x);
    } else {
        printf("%d\n", m);
    }

    free_tree(root);
    free(arr);
}
