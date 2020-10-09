#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char input[100];
  char sentence[100];
  List *history = init_history();
  char **words;
  
  printf("\n**********************************************************************\n");
  printf("\nWelcome to Lab Project 1: Building a Tokenizer\n");
  printf("\nStudent: Salvador Robles Herrera");
  printf("\nClass: Computer Architecture\n\n");

  int continueLab = 1;
  
  while (continueLab) {
    printf("\nPlease enter one of the following: \n");
    printf("1) Type '1' to write a sentence to history\n");
    printf("2) Type '2' to see history\n");
    printf("3) Type '3' to free history\n");
    printf("4) Type '*' followed by the number of the sentence you want to print\n");
    printf("5) Type '!' followed by the number of the sentence you want to tokenize\n");
    printf("6) Type '!!' to quit\n");
    printf("\nEnter: ");
    
    scanf("%s", input);
    printf("\n.....................................................................\n");

    if (input[0] == '1') { /* Add sentence to history */
      printf("\nEnter a sentence...");
      printf("\n $  ");
      scanf("\n");
      scanf("%[^\n]", sentence);
      add_history(history, sentence);
      printf("\nSentence added to history\n");
    }
    else if (input[0] == '2') { /* Print history */
      printf("\nPrinted history:\n");
      print_history(history);
    }
    else if (input[0] == '3') { /* Free history */
      free_history(history);
      printf("\nHistory freed\n");
    }
    else if (input[0] == '*') { /* Get and print sentence */
      int numSentence = atoi(input + 1);
      char *s = get_history(history, numSentence);
      printf("Sentence: %s", s);
    }
    else if (input[0] == '!' && input[1] != '!') { /* Tokenize sentence */
      int numSentence = atoi(input+1);
      char *s = get_history(history, numSentence);
      /*char ***/words = tokenize(s);
      printf("\n\nPrint words... \n");
      print_tokens(words);
      free_tokens(words);      
    }
    else if (input[0] == '!' && input[1] =='!') { /* Option for exiting program */ 
      continueLab = 0;  /* Exit out and stop program */
    }
    else { /* Not valid option */
      printf("Please enter a valid option...\n");
    }
    printf("\n.....................................................................\n");
  }
  printf("\nThank you and goodbye!!");
  printf("\nEnd of program\n");
  printf("\n****************************************************************\n");
}
