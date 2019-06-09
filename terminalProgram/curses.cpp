#include <iostream>
#include <ncurses.h>
#include <cstring>
using namespace std;

int main()
{	int ch;
	initscr();			/* Start curses mode 		*/
        int yMax,xMax; 
	getmaxyx(stdscr,yMax,xMax);
	WINDOW *menuwin = newwin(yMax-1,(xMax-1)/2,1,1);
        WINDOW *otherwin = newwin(yMax-1,(xMax-1)/2-1,1,(xMax-1)/2 + 2);
	box(menuwin,103,103);
        box(otherwin,65,65);
        refresh();
        noecho();
        wrefresh(otherwin);
        wrefresh(menuwin);
        string b = "alex";
        string c = "keeper";
        wgetch(otherwin);
        mvwprintw(otherwin,1,1,b.c_str());
        wrefresh(otherwin);
        wgetch(menuwin);
        mvwprintw(menuwin,1,1,c.c_str());
        wrefresh(menuwin);
        wgetch(menuwin);
        endwin();		
	return 0;
}
