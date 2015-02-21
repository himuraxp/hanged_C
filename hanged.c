#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "char_maj.h"
#include "win.h"
#include "search_letter.h"

int main(int argc, char* argv[])
{
	char letter = 0; // Stores the proposed lettre user
       	char secret_word[] = "PENDU\n"; // Word find
	int letter_found[5] = {0}; // Boolean array. Each box corresponds to a letter from the secret word. 0 = not found letter, 1 = letter found
	int shots_remaining = 10; // Counter to shots remaining
	int i = 0;

	printf("=========================\n\nBienvenue dans le Pendu !\n\n=========================\n");

	while (shots_remaining > 0 && !win(letter_found))
	{
		printf("\nIl vous reste %d coups avant une mort certaine.", shots_remaining);
		printf("\nQuel est le Mot Secret ? ");
		
		/*It displays the secret word by hiding letter not found
		Example: P**DU */
		for (i = 0 ; i < 5 ; i++)
		{
			if (letter_found[i]) // If we found the letter n°i
				printf("%c", secret_word[i]); // It displays
			else
				printf("*"); // Else it displays * for hiding letter not found
		}

		printf("\n Proposez une lettre : ");
		letter = read_char();
		
		// If don't good letter
		if (!search_letter(letter, secret_word, letter_found))
		{
			shots_remaining--; // Player lost one shot
		}
	}
	
	if (win(letter_found))
		printf("\n=========\nYOU WIN !\n=========\nLe mot secret etait bien : %s", secret_word);
	else
		printf("\n==========\nYOU LOSE !\n==========\nLe mot secret etait : %s", secret_word);

	return 0;
}
