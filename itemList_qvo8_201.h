
#ifndef ITEMLIST_QVO8_201_H
#define ITEMLIST_QVO8_201_H

#include <stddef.h>

typedef struct _node
{
    char *data;  // Food Item Name
    struct _node *next;
} node;

typedef struct _itemList
{
    node *head;  // Pointer to first food item for the order (alphabetical)
    int count;   // Number of food items in the order
} itemList;

//prototypes
itemList *createItem();
int insert(char *data, itemList **ItemList);
void printItems(itemList *s);
int strcmpi(char *s, char *t);
void *dmalloc(size_t size);
#define MAX_CHAR 200

#endif /* itemList_qvo8_201_h */
