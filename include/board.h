#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <string>
#include <format>
#include <vector>
#include<functional>
#include<algorithm>

#include "cell.h"
#include "point.h"

class Board {
private:
  std::vector<std::vector<Cell>> board;

public:
  Board(int rows, int cols);
  void set(int row, int col);
  int height() const;
  int width() const;
  void Log();
  std::vector<Point> NeighborPoints(int row, int column) const;
  void InitShape(int row, int col, std::vector<std::vector<int>> shape);
  int LivingNeighbors(int row, int column);
  void VisitElements (const std::function <void (Cell&, int, int)>& f);
  void Update();
};

#endif // _BOARD_H_
