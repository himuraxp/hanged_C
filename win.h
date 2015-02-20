int win(int letter_found[])
{
	int i = 0;
	int player_win = 1;

	for (i = 0 ; i < 5 ; i++)
	{
		if (letter_found[i] == 0)
			player_win = 0;
	}

	return player_win;
}
