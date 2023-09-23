#include <iostream>
#include <vector>
#include <math.h>
#include <unistd.h>
#include "board.h"

int main()
{
  const clock_t start = clock();
  srand(static_cast<unsigned int>(start));

  auto board = Board(30, 90);

  // auto coords = board.NeighborCoordinates(1, 1);
  // for(auto& c : coords) {
  //   std::cout << c.toString() << std::endl;
  // }

  // board.InitShape(5, 3, {
  //   {0,1,1}, 
  //   {1,1,0}, 
  //   {0,1,0}, 
  // });

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

  board.InitShape(8, 35, {
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

  for(int i=0; i<10000000; i++) {
    board.Update();
    board.Log();
    usleep(50000);
  }

  return 0;
}