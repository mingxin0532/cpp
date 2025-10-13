#include<ncurses.h>
#include<iostream>
#include<list>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "");

	std::list<char> mylist;

	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr,TRUE);
	printw("give input:(q to end)");
	refresh();

	while (true) {
		int ch = getch();

		if (ch != -1) {
			if (isprint(ch)) {

				if (ch == 'q')
					break;

			}
			clear();
			mylist.push_back(ch);

			printw("input is:");
			for (char c : mylist) {
				printw("%c", c);
			}
			refresh();
		}
	}

	endwin();
	std::cout << "input backwords:" << std::endl;
	for (auto it = mylist.rbegin(); it != mylist.rend(); it++) {
		std::cout << *it;
	}
	return 0;
}
