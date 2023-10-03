#pragma once

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "cell.h"
#include "point.h"

typedef std::vector<Point> Points;
template <typename T>
using ArrayD2 = std::vector<std::vector<T>>;

class Board {
private:
  std::vector<std::vector<Cell>> _board;

public:
  Board(int rows, int cols);
  void set(int row, int col);
  int height() const;
  int width() const;
  void Log(std::stringstream& ss);
  Points NeighborPoints(int row, int column) const;
  void InitShape(int row, int col, ArrayD2<int> shape);
  int LivingNeighbors(int row, int column);
  void VisitElements (const std::function <void (Cell&, int, int)>& f);
  void Update();
};
