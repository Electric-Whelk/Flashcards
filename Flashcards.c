#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#define ARB 700

bool fetch(char* source, int i);
int rnjesus(int max); //improve your randomisation so you don't have to remake every time you run it).
void deckfill(int* array, int max); 
void shuffle(int* array, int max);
void strint(int x, char* outp);
void test(void);

void strinttest(void);


int main(void)
{
  printf("\n");
  test();

  char* file = "cards.txt";
  int max = 37; //suggest making a "maxfind" function to figure it out for you
  int deck[ARB];

  deckfill(deck, max);
  shuffle(deck, max);

  for(int i = 1; i < max; i++){
    int test = deck[i] % 10;
    if(test != 0){
      fetch(file, test);
      printf("\nHit any key for answer: \n");
      char response;
      scanf("%c", &response);
      printf("\n");
      int a = test * 10;
      fetch(file, a);
      printf("Hit any key for next question: \n");
      char response2;
      scanf("%c%c", &response, &response2);
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    }
  }
  printf("\nDeck complete!\n");
  
  printf("\n");
  return 0;
}

void test(void)
{
  strinttest();
}

void deckfill(int* array, int max)
{
  int i = 0;
  int f = 1;
  for(i = 0; i < max; i++){
    array[i] = f;
    f++;
  }
}

void shuffle(int* array, int max)
{

  int a, b;
  printf("Initialising! Please enter a four digit number to randomise: ");
  scanf("%i", &a);
  printf("Now enter another one: ");
  scanf("%i", &b);
  for (int i = 0; i < max; i++){
    int n1 = b % max;
    int n2 = a % max;
    int c = array[n1];
    array[n1] = array[n2];
    array[n2] = c;
    b += 33;
    a += 94;
  }
}

int rnjesus(int max)
{
  time_t s;
  s = time(NULL);
  int outp;
  max++;
  outp = s % max;
  return outp;
}


bool fetch(char* source, int i)
{

  FILE* file = fopen(source, "r");
  if(file == NULL){
    fprintf(stderr, "Cannot open file %s\n", source);
    exit(EXIT_FAILURE);
  }

  char reader[ARB] = {0};
  char cast[ARB] = {0};
  bool targ = false;

  strint(i, cast);
  int lcast = strlen(cast); 
  while(fgets(reader, ARB, file)){
    if(reader[0] < '9' && reader[0] > '0'){
      int lread = strlen(reader);
      int lcast = strlen(cast);
      if(strcmp(cast, reader) == 0){
	targ = true;
      }
    }
    else if(targ == true){
      printf("%s\n", reader);
      fclose(file);
      return true;
    }
 }
  fclose(file);
  return false;
}

void strint(int x, char* outp)
{
  
  int digits = 1;
  int i = 0;
  while(digits <= x){
    i++;
    digits *= 10;
  }
  i++;
  outp[i] = '\0';
  i--;
  outp[i] = '\n';
  i--;



  int tmp = 0;
  char p, q;
  while(x >= 10){
    tmp = 0;
    tmp += x % 10;
    x -= tmp;
    x /= 10;
    p = (char)tmp + '0';
    outp[i] = p;
    i--;
  }
  q = (char)x + '0';
  outp[i] = q;
}

void strinttest(void)
{
  char fill[ARB] = {0};
  assert((276 % 10) == 6);
  strint(276, fill);
  assert(strcmp(fill, "276\n") == 0);

}
    

  
