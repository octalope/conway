#pragma once

#include <string>
#include <format>

class Point {
private:
  int _row;
  int _column;
public:
  Point(int r, int c);
  int row();
  int column();
  std::string toString();
};
