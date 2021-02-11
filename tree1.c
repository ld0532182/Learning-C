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

int search_elem(struct tree *node, int elem)
{
    if (node == NULL) 
        return 0;
    if (elem == node->numb)
        return 1;
    if ((elem != node->numb) && (elem < node->numb))
        return search_elem(node->left, elem);
     else
        return search_elem(node->right, elem);
} 
int main()
{   
    int f, result;
    struct tree *node = NULL;
    int m[] = { 10, 5, 6, 4, 20, 15, 25, 30, 2};
    for (int i = 0; i < (sizeof(m)/sizeof(*m)); i++)
        node = add_node(node, m[i]);  
    printf("Enter a number to search ");
    scanf("%d", &f);
    result = search_elem(node, f);
    if (result)
        printf("Your number is in a tree\n");
     else
        printf("Your number isn't in a tree\n");
    return 0;
}
