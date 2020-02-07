/* Quang Vo G01122283
 * CS 262,  Section 201
 * Project 3
 * The goal of this program is to model the functionality of the food delivery app, that students will be able to call in an order from any of the campus eateries, and have the item 
 * delivered to the appropriate location. This program will be implemented using linked list. 
 */


#include "itemList_qvo8_201.h"
#include "order_qvo8_201.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    
    ordernode *orderHead = dmalloc(sizeof(ordernode)); //create dummy head for the delivery list
    orderHead->next = NULL;
    
    char yesNo = '\0';
    
    do
    {
        printf("\nNew delivery order? (y/n)"); //ask for new delivery order
        char buffer[100];
        fgets(buffer, 100, stdin);
        sscanf(buffer, "%c", &yesNo);
        
        switch(yesNo)
        {
            case 'y':
            case 'Y':
                printf("Hi\n");
                
                ordernode *Order = createOrder(); //create new orderNode
                
                printf("What do you want to order: \n");
                char *FoodItem = dmalloc(MAX_CHAR * sizeof(char));
                Order->list = createItem(); //create a new list of food items for an order
                do
                {
                    printf("food item: ");
                    fgets(FoodItem, MAX_CHAR, stdin); //enter each food item
                    insert(FoodItem, &Order->list); //add them to the list

                }while(FoodItem[0] != '\n'); //until the user enters an empty string
                free(FoodItem); //deallocate the memory of the FoodItem pointer
                insertOrder(orderHead, Order); //insert each order into the delivery list
                break;
            case 'n':
            case 'N':
                printOrders(orderHead); //when the user hits n the delivery list will be printed out
                deleteOrder(&orderHead); //delete the entire list
                break;
            default:
                printf("Invalid input! Try again. \n"); //handles invalid input
        }
        
    }while (yesNo != 'n' && yesNo != 'N');
    
    
    return 0;
}

