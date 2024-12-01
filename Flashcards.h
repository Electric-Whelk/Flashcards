#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#define ARB 10000 


bool fetch(char* source, int i);
int rnjesus(int max); //improve your randomisation so you don't have to remake every time you run it).
void deckfill(int* array, int max); 
void shuffle(int* array, int max);
void strint(int x, char* outp);
void test(void);
void strinttest(void);
void run(char* file, int max, int* deck);