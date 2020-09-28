#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == '\t' || c == ' ') return 1;
  return 0;
}

int non_space_char(char c)
{
  if (c != '\t' && c != ' ' && c != '\0') return 1;
  return 0;
}

char *word_start(char *str)
{
  int start = 0;
  while(space_char(str[start]))
    start++;
  return &str[start];
}

char *word_terminator(char *word)
{
  word = word_start(word);
  int end = 0;
  while (non_space_char(word[end]))
    end++;
  return &word[end];
}

int count_words(char *str)
{
  int count = 0;

  while (*str != '\0') { //Until the end of the string is reached
    str = word_terminator(str); //Advance word by word. Getting to the end of a word each time
    count++;
  }
}

char *copy_str(char *inStr, short len)
{
  char *str = (char *) malloc(len + 1);
  
  for (int i = 0; i <= len; i++) {
    str[i] = inStr[i];
  }
  return str;
}

char **tokenize(char *str)
{
  int numWords = count_words(str);
  char **words = malloc(numWords + 1);

  for (int i = 0; i < numWords; i++) {
    char *startWord = word_start(str);
    char *endWord = word_terminator(str);
    int lengthWord = endWord- startWord;
    words[i] = copy_str(startWord, lengthWord);
  }

  words[numWords] = NULL; //Sets last string to NULL
  return words;
}

void print_tokens(char **tokens)
{
  int token = 0;
  printf("\n");
  while (tokens[token] != NULL) {
    printf("%s\n", tokens[token]); //Prints one token
    token++;
  }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while (tokens[i] != NULL) {
    free(tokens[i]);  //"frees" each string
    i++;
  }
  free(tokens);
}
