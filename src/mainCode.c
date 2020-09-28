#include <stdio.h>
#include "tokenizerCode.c"

int main()
{
  char sentence[100];
  printf("\n****************************************************************\n");
  printf("\nWelcome to Lab Project 1: Building a Tokenizer\n");
  printf("\nStudent: Salvador Robles\n\n");

  int continueLab = 1;
  
  while (continueLab) {
    printf("\nPlease enter one of the following: \n");
    printf("1) Press 1 to write a sentence to history\n");
    printf("2) Press 2 to quit");
    printf("\n");
    int option = 1;
    
    scanf("%d", &option);
    if (option == 2) {
      printf("\nThank you for entering...\n");
      continueLab = 0;
      break;
    }
    else if (option == 1) {
      printf("Enter a sentence...");
      printf("\n $  ");
      fgets(sentence, 100, stdin);
      char **words = tokenize(sentence);
      printf("\n\nPrint words... \n");
      print_tokens(words);
    }
  }
  
  printf("\nEnd of program\n");
  printf("\n****************************************************************\n");
}
