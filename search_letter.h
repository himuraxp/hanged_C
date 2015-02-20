int search_letter(char letter, char secret_word[], int letter_found[])
{
	int i = 0;
	int good_letter = 0;
	
	// You are browsing the secret word for check with the letter proposed
	for (i = 0 ; secret_word[i] != '\0' ; i++)
	{
		if (letter == secret_word[i]) // If we have a letter
		{
			good_letter = 1; // Memorize that it is the correct letter
			letter_found[i] = 1; // It offers one of the boolean table box for the current letter
		}
	}
	
	return good_letter;
}	
