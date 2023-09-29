#include <string>
#include <format>

#include "point.h"

Point::Point(int r, int c): _row(r), _column(c)
{
}

int Point::row() {
  return this->_row;
}

int Point::column() {
  return this->_column;
}

std::string Point::toString() {
  return std::format("({}, {})", this->_row, this->_column);
}
