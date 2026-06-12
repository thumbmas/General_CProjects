#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int* next;
    int* prev;
    char* string[10];
};

int add_node(struct list* list, char str[])
{
    int len = new_strlen(str);
    char* sptr;
    sptr = malloc(len+1);
    new_strcpy(sptr, str, len);
    list->str_list[*(list->head)]->string = sptr;
    return len;
}

int main ()
{
    struct list* new_list = create_list();

    return 0;
}