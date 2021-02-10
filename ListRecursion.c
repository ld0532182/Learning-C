#include <stdio.h>
#include <stdlib.h>

typedef struct st {
    int numb;
    struct st *next;
} node;

node *add_point(node *first, int *n, int i, int size_arr)
{   
    if ((i == size_arr) || (i > 100))
        return first;
    node *tmp = malloc(sizeof(node));
    tmp->numb = *n;
    tmp->next = first;
    return add_point(tmp, n+1, i+1, size_arr);
}

void print_list(node *p)
{
    if (!p) 
        return;
    print_list(p->next);
    printf("%d\n", p->numb);
}


int main()
{
    node *spisok = NULL;
    int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int size_of_array = sizeof(m)/sizeof(*m);
    spisok = add_point(spisok, m, 0, size_of_array);
    print_list(spisok);
    return 0;

}
        
