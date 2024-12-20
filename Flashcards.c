#include "Flashcards.h"

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

  for (int i = 0; i < max; i++){
    int n1 = rnjesus(max);
    int n2 = rnjesus(max);
    int c = array[n1];
    array[n1] = array[n2];
    array[n2] = c;
  }
}

int rnjesus(int max)
{
  int outp = rand() % max;
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
  while(fgets(reader, ARB, file)){
    if(reader[0] < '9' && reader[0] > '0'){
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

void run(char* file, int max, int* deck)
{
  for(int i = 1; i < max; i++){
  int q = deck[i];
  int test = q % 10;
  if(test != 0){
    fetch(file, q);
    printf("\nHit any letter + enter key for answer (or ctrl+c to quit): \n");
    char response;
    scanf("%c ", &response);
    printf("\n");
    int a = q * 10;
    fetch(file, a);
    printf("Hit any letter key +enter key for next question (or ctrl+c to quit): \n");
    char response2;
    scanf("%c ", &response2);
    printf("\n\n\n\n");

    }
  }
}

int bodgedmax(char* source)
{
  FILE* file = fopen(source, "r");
  if(file == NULL){
    fprintf(stderr, "Cannot open file %s\n", source);
    exit(EXIT_FAILURE);
  }
  char top[ARB];
  fgets(top, ARB, file);

  fclose(file);

  int i = 1;
  bool halt = false;
  while(halt == false && i < ARB){
    char test[ARB];
    strint(i, test);
    if(strcmp(test, top) == 0){
      halt = true;
    }else{
      i++;
    }
  }

  return i;

}