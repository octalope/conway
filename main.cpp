#include <sys/ioctl.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <unistd.h>

#include "board.h"

int main()
{
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  const clock_t start = clock();
  srand(static_cast<unsigned int>(start));

  auto board = Board(w.ws_row, w.ws_col);

  board.InitShape(15, 40, {
    {0,1,0},
    {0,0,1},
    {1,1,1},
  });

  board.InitShape(12, 20, {
    {0,1,0},
    {1,0,0},
    {1,1,1},
  });

  board.InitShape(8, 0.75 * w.ws_col, {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
    {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
    {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,1,0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  });

  board.InitShape(10, 4, {
    {0,1,0},
    {1,0,1},
    {0,1,0},
  });

  board.InitShape(15, 12, {
    {0,1,0},
    {1,0,1},
    {0,1,0},
  });




  // board.set(15, 16);
  // board.set(15, 17);
  // board.set(16, 15);
  // board.set(16, 16);
  // board.set(17, 16);

  // board.set(35, 16);
  // board.set(35, 17);
  // board.set(36, 15);
  // board.set(36, 16);
  // board.set(37, 16);


  board.Log();

  while(1) {
    board.Update();
    board.Log();
    usleep(50000);
  }
}
