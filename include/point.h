#pragma once

#include <string>

class Point {
private:
  int _row;
  int _column;
public:
  Point(int r, int c);
  int row() const;
  int column() const;
  std::string toString() const;
};

