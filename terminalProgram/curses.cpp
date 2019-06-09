#include <iostream>
#include <ncurses.h>
#include <cstring>
using namespace std;

int main()
{	int ch;
	initscr();			/* Start curses mode 		*/
        int yMax,xMax; 
        string menu_option[] = { "About","Enter the game..","Animation","Exit"};
        int menu_option_length = sizeof(menu_option)/sizeof(menu_option[0]);
	getmaxyx(stdscr,yMax,xMax);
        int box_width = (xMax-1)/2;
	WINDOW *menuwin = newwin(yMax-1,box_width,1,box_width/2);
        box(menuwin,0,0);
        refresh();
        wrefresh(menuwin);
        int select = 0;
        int highlight;
        noecho();
        keypad(menuwin,true); //turn on the keypad
        while (1)
        {
          //use a for loop to make color of current choice
          for ( int i = 0; i < menu_option_length ; i++ )
          {
               if ( select == i ) wattron(menuwin,A_REVERSE);
               mvwprintw(menuwin,i+5,box_width/2-menu_option[i].length()/2,menu_option[i].c_str());
               wattroff(menuwin,A_REVERSE);
          }
          wrefresh(menuwin);
          highlight  = wgetch(menuwin);
          switch ( highlight )
          { 
          	case KEY_DOWN:
                     if ( select < menu_option_length - 1)
                         select++;
                     break;
                case KEY_UP:
                     if ( select > 0 )
		     	 select--;
           	default:
			break;

          }
        }
        getch();
        endwin();		
	return 0;
}
