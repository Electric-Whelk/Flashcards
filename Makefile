CC=gcc
FLAGS = -Wall -Wextra -Wfloat-equal -Wvla -std=c99 -Wpedantic -fsanitize=undefined -fsanitize=address -g3

.default: flashcards

flashcards: Flashcards.c Driver.c Flashcards.h
	gcc Flashcards.c Driver.c $(FLAGS) -o Flashcards
