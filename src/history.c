

#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  
  return list;
}

void add_history(List *list, char *str)
{
  Item *temp = list->root;
  Item *add = malloc(sizeof(Item));
  add->str = str;
  
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = add; /* Set the element that was NULL to a new Item object */
  temp->next->id = temp->id + 1; /* ID is one more than the previous element */
}

char *get_history(List *list, int id)
{
  Item *temp = list->root->next;

  while (temp != NULL) {
    if (id == temp->id) return temp->str; /* Just return string */
    temp = temp->next;
  }
  printf("Returned Null");
  return NULL;
}

void print_history(List *list)
{ 
  Item *temp = list->root->next;

  while (temp != NULL) {
    printf("%d.-  %s\n",temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *temp1 = list->root->next;
  Item *temp2 = list->root->next;

  while (temp1 != NULL) {
    temp2 = temp2->next; /* Advance to next Item */
    free(temp1); /* Free previous Item */
    temp1 = temp2; /* Advance to next Item */
  }

  free(list);
}
