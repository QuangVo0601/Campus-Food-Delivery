
#include "itemList_qvo8_201.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//This function is for creating a new itemList
itemList *createItem()
{
    itemList *newItemList = dmalloc(sizeof(itemList)); //allocate memory for new itemList
    newItemList->head = NULL;
    newItemList->count = 0;
    
    return newItemList;
}

//This function is for inserting food items in the the current list
int insert(char *data, itemList **ItemList)
{
    node *FoodItem = NULL;
    FoodItem = dmalloc(sizeof(node)); //create new food item node
    FoodItem->next = NULL;
    FoodItem->data = dmalloc(MAX_CHAR * sizeof(char));
    strcpy(FoodItem->data, data); //copy the data entered by the user to the food item node

    if((*ItemList)->head == NULL) 
    {
        (*ItemList)->head = FoodItem;
        ((*ItemList)->count)++; //number of food items nodes increases
    }
    else if((strcmpi((*ItemList)->head->data, FoodItem->data)) > 0) //alphabetical order
    {
        FoodItem->next = (*ItemList)->head;
        (*ItemList)->head = FoodItem;
        ((*ItemList)->count)++;

    }
    else if((strcmpi((*ItemList)->head->data, FoodItem->data)) == 0) //check for duplicates
    {
        printf("Oops! You've already ordered this.\n");
	free(FoodItem->data); //need to free because didn't set it to ItemList->head
	free(FoodItem); 
        return 1; //return 1 when the insertion wasn't successful
    }
    else
    {
        node *temp = (*ItemList)->head;
        
        while(temp->next != NULL) //check for duplicates in the entire list
        {
            if((strcmpi(temp->next->data, FoodItem->data)) == 0)
            {
            printf("Oops! You've already ordered this.\n");
	    free(FoodItem->data); //need to free b/c didn't set it to ItemList->head
	    free(FoodItem);
            return 1;
            }
            temp = temp->next;
        }
        
        temp = NULL;
        temp = (*ItemList)->head;
        
        while((temp->next != NULL) && ((strcmpi(temp->next->data, FoodItem->data)) < 0)) //alphabetical order
              {
                  temp = temp->next;
              }
        FoodItem->next = temp->next;
        temp->next = FoodItem;
        ((*ItemList)->count)++;
    }
	return 0; //return 0 when the insertion was successful
}


//This function is for printing out all the food items in the list
void printItems(itemList *ItemList)
{
    node *temp = ItemList->head;
    int i = 0;
    for(i = 0; i < ItemList->count; i++)
    {
        printf("%s", temp->data); //print each food item to stdout
        temp = temp->next;
    }
    
}

/* compares strings for alphabetical ordering */
int strcmpi(char *s, char *t)
{
    while (*s && tolower(*s) == tolower(*t))
    {
        s++;
        t++;
        
    }
    return tolower(*s) - tolower(*t);
}

/* allocates memory with a check for successful allocation */
void *dmalloc(size_t size)
{
    void *p = malloc(size);
    if (!p)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    return p;
}




