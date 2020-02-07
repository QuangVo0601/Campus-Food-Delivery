#ifndef ORDER_QVO8_201_H
#define ORDER_QVO8_201_H

#include "itemList_qvo8_201.h"
#include <stddef.h>

typedef struct _ordernode
{
    itemList *list;
    char *deliverTo;
    char *restaurant;
    struct _ordernode *next;
} ordernode;
//prototypes
ordernode *createOrder();
int insertOrder(ordernode *orderHead, ordernode *Order);
void printOrders(ordernode *orderHead);
void deleteOrder(ordernode **orderHead);

#endif /*order_qvo8_201.h*/
