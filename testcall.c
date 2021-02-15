#include <stdio.h>
#include <stdlib.h>

typedef struct simple_function
{
    int val;
    struct simple_function *next;
} node;

void add_node(int value, node **new_node)
{
    if (*new_node == NULL) {
        *new_node = malloc(sizeof(node));
        (*new_node)->val = value;
        (*new_node)->next = NULL;
        return;
    }
    add_node(value, &(*new_node)->next);
    return;
}        
    

void make_value(node **first, void (*proc_function)(int))
{
    if (*first == NULL)
        return;
    proc_function((*first)->val);
    make_value(&(*first)->next, proc_function);
    return;
}
void times_value_2 (int x)
{
    x = x * 2;
    printf("%d\n", x);
    return;
}

void square (int x)
{
    x *= x;
    printf("%d\n", x);
}
   
int main()
{   
    printf("www\n");
    node *main_node = NULL;
    int m[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; (i < (sizeof(m) / sizeof(*m))) && i < 100; i++) {
        int s = m[i];
        add_node(s, &main_node);
    } 
    make_value(&main_node, &times_value_2);
    make_value(&main_node, &square);
    return 0;
}
