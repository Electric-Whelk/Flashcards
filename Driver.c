#include 'flashcards.h'
#define ARB 10000

int main(void)
{

  printf("\n");
  test();
  time_t s = time(NULL);
  srand(s);

  char* file = "SQL12.txt";
  int max = 12; //suggest making a "maxfind" function to figure it out for you
  int deck[ARB];

  deckfill(deck, max);
  shuffle(deck, max);

  printf("\n");

  run(file, max, deck);

  printf("\nDeck complete!\n");
  
  printf("\n");
  return 0;
}