#include "alcu.h"

void end_screen(int winner)
{
	int center = COLS / 2;
	int line = LINES / 2;
	const char *player[2] = {"BOT", "PLAYER"};
	const char *format = "%s WINS!!!";
	const char *anykey = "Press any key to exit...";
	int len = ft_strlen(format) + ft_strlen(player[winner]);

	clear();
	attron(COLOR_PAIR(5 + winner) | A_BOLD);
	mvprintw(line, center - len / 2, format, player[winner]);
	attroff(COLOR_PAIR(5 + winner) | A_BOLD);
	mvprintw(LINES - 2, center - ft_strlen(anykey) / 2, anykey);
	refresh();
	timeout(-1);
	getch();
}