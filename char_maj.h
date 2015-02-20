char read_char()
{
	char character = 0;
	
	character = getchar(); // Read frist char 
	character = toupper(character); // Switch to maj

	while (getchar() != '\n'); // Read char one by one to \n (for clean)

	return character;
}

