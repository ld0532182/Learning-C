#include <stdio.h>
#include <stdlib.h>

struct tree {
    int numb;
    struct tree *left, *right;
};

struct tree *add_node(struct tree *pointer, int n)
{
    if (pointer == NULL) {
        pointer = malloc(sizeof(struct tree));
        pointer->numb = n;
        pointer->left = NULL;
        pointer->right = NULL;
        return pointer;
    }
    if (n < pointer->numb)    
        pointer->left = add_node(pointer->left, n);
     else
        pointer->right = add_node(pointer->right, n);
    return pointer;
}

int main()
{
    struct tree *node = NULL;
    int m[] = { 10, 5, 6, 4, 20, 15, 25, 30, 2};
    for (int i = 0; i < (sizeof(m)/sizeof(*m)); i++)
        node = add_node(node, m[i]);  
    printf("%d\n", node->right->left->numb);
    return 0;
}
