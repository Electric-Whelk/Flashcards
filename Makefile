FLAGS := -Wall -Wextra -Wfloat-equal -Wvla -std=c99 -Wpedantic -fsanitize=undefined -fsanitize=address -g3

flashcards: Flashcards.c
	gcc Flashcards.c $(FLAGS) -o Flashcards && ./Flashcards CompArchMidterm.txt
