#include "alcu.h"

void end_screen(int winner)
{
	int center = COLS / 2;
	int line = LINES / 2;
	const char *player[2] = {"Bot", "Player"};
	const char *format = "%s wins!";
	const char *anykey = "Press any key to exit...";
	int len = ft_strlen(format) + ft_strlen(player[winner]);

	clear();
	mvprintw(line, center - len / 2, format, player[winner]);
	mvprintw(LINES - 2, center - ft_strlen(anykey) / 2, anykey);
	refresh();
	timeout(-1);
	getch();
}