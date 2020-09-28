#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  
  return list;
}

void add_history(List *list, char *str)
{
   
}
