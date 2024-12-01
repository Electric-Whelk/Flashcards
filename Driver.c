#include "Flashcards.h"
#define ARB 10000

int main(int argc, char* argv[])
{

  if(argc != 2){
    fprintf(stderr, "Please enter exactly one file");
    exit(EXIT_FAILURE);
  }
  printf("\n");
  test();
  time_t s = time(NULL);
  srand(s);

  char* file = argv[1];
  int max = 78; //suggest making a "maxfind" function to figure it out for you
  int deck[ARB];

  deckfill(deck, max);
  shuffle(deck, max);

  printf("\n");

  run(file, max, deck);

  printf("\nDeck complete!\n");
  
  printf("\n");
  return 0;
}