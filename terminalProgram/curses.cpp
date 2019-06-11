#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
#define TYPE_ENTER 10
#define TYPE_BACKSPACE 127
void enterGamePage();
void enterAboutPage();
void enterPainterPage();
int yMax,xMax;
int box_width;


enum MENU_OPTION {
    ABOUT = 0 ,
    ENTER_THE_GAME = 1,
    ANIMATION = 3,
    EXIT = 4
};

void enterMenuPage(){
	int highlight;
        string menu_option[] = { "About","Enter the game..","Painter","Exit"};
        int menu_option_length = sizeof(menu_option)/sizeof(menu_option[0]);
	//WINDOW *menuwin = newwin(yMax-1,box_width,1,box_width/2);
	WINDOW *menuwin = newwin(yMax-1,box_width,1,box_width/2);
        box(menuwin,0,0);
        refresh();
        wrefresh(menuwin);
        noecho();
	int select = 0;
        keypad(menuwin,true); //turn on the keypad
        while (1)
        {
          //use a for loop to make print menu string
          for ( int i = 0; i < menu_option_length ; i++ )
          {
               if ( select == i ) wattron(menuwin,A_REVERSE);
               mvwprintw(menuwin,i+5,box_width/2-menu_option[i].length()/2,menu_option[i].c_str());
               wattroff(menuwin,A_REVERSE);
          }
          wrefresh(menuwin);
	  bool flag = false;
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
			break;
		case TYPE_ENTER:
			flag = true;
			break;
           	default:
			break;

          }
	  if ( flag ) { break;}
        }
	if ( select == 0 )
	{
		//about
		enterAboutPage();
	}
	else if ( select == 1 ){
		enterGamePage();
	}
	else if ( select == 2 ){
		enterPainterPage();
        }
	else if ( select == 3 ){

        }

}
void enterPainterPage(){
	WINDOW *animationwin = newwin(yMax-1,box_width,1,box_width/2);
	box(animationwin,(int)'+',(int)'+');
	keypad(animationwin,true);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION  ,NULL);	
	printf("\033[?1003h\n"); // Makes the terminal report mouse movement events
	//mousemask(REPORT_MOUSE_POSITION  | BUTTON1_PRESSED ,NULL);	
	mvwprintw(animationwin,1,box_width/2 - 9 , "%s","Let's go to the animation....haha");
	refresh();
	wrefresh(animationwin);
	int k ;
	int y,x;
	while(1){
		k = wgetch(animationwin);
		if ( k == KEY_BACKSPACE)
		{
		  	enterMenuPage();
			return;
        	}
		else if ( k == KEY_MOUSE )
		{
			mvwprintw(animationwin,10,box_width/2 - 9 , "%s","Mouse click");
			MEVENT event;
      			if (getmouse(&event) == OK) {
                 		mvwaddch(animationwin,event.y - 1,event.x - box_width/2,'o'); 
			}
			else{
			}
      		}
		else{
			mvwprintw(animationwin,30,10,"%s","Something wrong");
		}
		wmove(animationwin,0,0);
	        insertln();
    		clrtoeol();
		wmove(animationwin,0,0);
	}

}
void enterAboutPage(){
	WINDOW *aboutwin = newwin(yMax-1,box_width,1,box_width/2);
	box(aboutwin,(int)'+',(int)'+');
	int d = 1;
	int pos = 1;
	int k ;
	string keeper = "I am Keeper.......................................I like running..........................................................I come from Macau...............................................................................nothing";	
	int prev_y = 2;
	int prev_x = 1; //record keeper string location
	mvwprintw(aboutwin,1,box_width/2 - 9 , "%s","About Author");
	if ( prev_x < 0 ) { prev_x = box_width/2 - 10 ;}
	wtimeout(aboutwin,100);
	for ( int i = 0 ;i < keeper.length() ; i++ )
	{
		k = wgetch(aboutwin);
		if ( k == TYPE_BACKSPACE){
			enterMenuPage();
			return;
		}
		mvwaddch(aboutwin,prev_y,prev_x,keeper[i]);
		prev_x++;
		if ( prev_x  > box_width -2 ) {
			//next line
			prev_x = 1;
			prev_y++;
		}
		wrefresh(aboutwin);
		//mvwprintw(aboutwin,5,20,"%d",k);
		//usleep(50000);
	}
}
void enterGamePage(){
	WINDOW *gamewin = newwin(yMax-1,box_width,1,box_width/2);
	int k;
	int player_prev_x;
	int player_prev_y;
	int player_x = box_width/2-1;
	int player_y = yMax / 2 -1 ;	
	box(gamewin,(int)'+',(int)'+');
	keypad(gamewin,true);
	wtimeout(gamewin,-1);//user input block mode
	mvwprintw(gamewin,1,1,"%s","Let's Play Together....");
	mvwaddch(gamewin,player_y,player_x,'@');
	refresh();
	wrefresh(gamewin);
	while (1){
	   k = wgetch(gamewin);
	   player_prev_x = player_x;
	   player_prev_y = player_y;
	   if ( k == KEY_BACKSPACE){
	  	enterMenuPage();
		return;
           }
	   else if ( k == KEY_UP ){
		player_y--;	
	   }
	   else if ( k == KEY_DOWN ){
		player_y++;
	   }
	   else if ( k == KEY_RIGHT ){
		player_x++;
	   }
	   else if ( k == KEY_LEFT ){
		player_x--;
	   }
	   mvwaddch(gamewin,player_prev_y,player_prev_x,'.');
	   mvwaddch(gamewin,player_y,player_x,'@');
	   //refresh();
	   //wrefresh(gamewin);
	}

	//character
	
	
}
int main()
{	int ch;
	initscr();			/* Start curses mode 		*/
	curs_set(0);
	srand (time(NULL));
	getmaxyx(stdscr,yMax,xMax);
	box_width = (xMax-1)/2;
	enterMenuPage();
        endwin();		
	return 0;
}


