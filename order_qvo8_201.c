#include "itemList_qvo8_201.h"
#include "order_qvo8_201.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//This funtion is for creating a new ordernode
ordernode *createOrder()
{
    ordernode *Order = dmalloc(sizeof(ordernode));

    printf("Delivery Address for new delivery order: "); //ask for the location to deliver
    Order->deliverTo = dmalloc(MAX_CHAR * sizeof(char));
    fgets(Order->deliverTo, MAX_CHAR, stdin);

    printf("Restaurant from which to pick up food: "); //ask for the name of the eatery
    Order->restaurant = dmalloc(MAX_CHAR * sizeof(char));
    fgets(Order->restaurant, MAX_CHAR, stdin);
    
    Order->restaurant[strlen(Order->restaurant) - 1] = '\0'; //remove traling linefeed
    return Order;
}


//This function is for creating a delivery list of ordernodes, using dummy head
int insertOrder(ordernode *orderHead, ordernode *Order)
{   
    ordernode *temp = orderHead;
    
    Order->next = temp->next;
    temp->next = Order;
    return 0;

}

//this function is for printing the entire delivery list in LIFO order
void printOrders(ordernode *orderHead)
{
    if(orderHead == NULL)
    {
        printf("No order was placed! Please order something.\n"); //reminder that there was no order placed
    }
    else
    {
        printf("\nList of Deliveries: \n");
        orderHead = orderHead->next;
        while(orderHead != NULL)
        {
            printf("\nDelivery order from %s has %d food item(s)", orderHead->restaurant, orderHead->list->count - 1);
            printItems(orderHead->list); //print the food items in itemList
            printf("Deliver to: %s", orderHead->deliverTo);
            orderHead = orderHead->next;
        }
    }
}

//This funtion is for deleting the entire delivery list after the user hits n
void deleteOrder(ordernode **orderHead)
{
    ordernode *delNode = (*orderHead)->next;
    ordernode *temp;
    node *next;

//delete all elements in each ordernode
    while(delNode != NULL)
    {
        temp = delNode->next;
        free(delNode->deliverTo); //delete deliverTo
        free(delNode->restaurant); //delete restaurant
        while(delNode->list->head != NULL)
        {
            next = delNode->list->head;
            free(next->data); //delete value of each FoodItem
            delNode->list->head = delNode->list->head->next;
            free(next); //delete each food node in the list
        }
        free(delNode->list); //delete each ItemList
        delNode = temp;

    }
//delete all ordernodes in the delivery list
        delNode = NULL;
        temp = NULL;
        delNode = *orderHead;
        while(delNode != NULL)
        {
        temp = delNode->next;
        free(delNode); //delete each ordernode
        delNode = temp;
        }
}


