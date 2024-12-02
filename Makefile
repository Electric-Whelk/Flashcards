CC=gcc
FLAGS = -Wall -Wextra -Wfloat-equal -Wvla -std=c99 -Wpedantic -fsanitize=undefined -fsanitize=address -g3

.default: safe

safe: Driver.c Flashcards.c Flashcards.h
	$(CC) $(FLAGS) Driver.c flashcards.o 

flashcards: Flashcards.c Flashcards.h
	$(CC) $(FLAGS) -c Flashcards.c -o flashcards.o