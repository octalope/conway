#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

#include <ncurses.h>

#include "board.h"

int main()
{

  const clock_t start = clock();
  srand(static_cast<unsigned int>(start));
  const std::stringstream stream;

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  const int width = w.ws_col;
  const int height = w.ws_row;

  auto board = Board(height, width);

  for(int i=0; i<20; i++) {
    int x = static_cast<float>(rand())/static_cast<float>(RAND_MAX) * (width - 5);
    int y = static_cast<float>(rand())/static_cast<float>(RAND_MAX) * (height - 5);

    board.InitShape(y, x, {
      {0,1,0},
      {0,0,1},
      {1,1,1},
    });

    x = static_cast<float>(rand())/static_cast<float>(RAND_MAX) * (width - 5);
    y = static_cast<float>(rand())/static_cast<float>(RAND_MAX) * (height - 5);

    board.InitShape(y, x, {
      {0,1,0},
      {1,0,0},
      {1,1,1},
    });
}

  // board.InitShape(8, 0.75 * width, {
  //   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  //   {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
  //   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  //   {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
  //   {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
  //   {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
  //   {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
  //   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  //   {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
  //   {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
  //   {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
  //   {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
  //   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  //   {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
  //   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  // });

  initscr();
  WINDOW* window = newwin(height, width, 0, 0);
  cbreak();
  nodelay(window, TRUE);
  raw();
  noecho();
  refresh();

  int c = ' ';
  while('q' != static_cast<char>(c)) {

    board.Update();
    board.VisitElements([&](Cell& cell, int row, int column) -> void {
      cell.update();
      if(cell.isAlive()) {
        mvwprintw(window, row, column, "#");
      } else {
        mvwprintw(window, row, column, " ");
      }
    });
    wrefresh(window);
    usleep(50000);
    clear();
    wrefresh(window);

    c = wgetch(window);
  }

  endwin();
}
