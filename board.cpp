#include <iostream>
#include <sstream>
#include <string>
#include <format>

#include "board.h"

using namespace std;

Board::Board(int rows, int cols) {
  for(int j=0; j<rows; j++) {
    std::vector<Cell> row;
    for(int i=0; i<cols; i++) {
      row.push_back(Cell());
      // row.push_back(Cell((static_cast<float>(rand())/static_cast<float>(RAND_MAX) > 0.90)));
    }
    _board.push_back(row);
  }
}

void Board::set(int row, int col) {
  this->_board[row][col].birth().update();
}

int Board::height() const {
  return this->_board.size();
}

int Board::width() const {
  return this->_board[0].size();
}

void Board::Log(std::stringstream& ss) {
  VisitElements([&](Cell& cell, int row, int column) -> void {
    cell.update();
    ss << (cell.isAlive() ? "*" : " ");
    if(column == width()-1) {
      ss << std::endl;
    }
  });
  ss << std::endl;
}

Points Board::NeighborPoints(int row, int column) const {
  Points result;

  for(int j=-1; j<=1; j++) {
    for(int i=-1; i<=1; i++) {
      int r = row + j;
      if (r < 0) r = this->height() - 1;
      if (r >= this->height()) r = 0;

      int c = column + i;
      if (c < 0) c = this->width() - 1;
      if (c >= this->width()) c = 0;

      if (r != row || c != column) {
        result.push_back(Point(r, c));
      }
    }
  }
  return result;
}

void Board::InitShape(int row, int col, ArrayD2<int> shape) {
  for(size_t j=0; j<shape.size(); j++) {
    for(size_t i=0; i<shape[0].size(); i++) {
      if (shape[j][i]) {
        this->_board[j+row][i+col].birth().update();
      }
    }
  }
}

int Board::LivingNeighbors(int row, int column) {
  int aliveCount = 0;

  for(int j=-1; j<=1; j++) {
    for(int i=-1; i<=1; i++) {
      int r = row + j;
      if (r < 0) r = this->height() - 1;
      if (r >= this->height()) r = 0;

      int c = column + i;
      if (c < 0) c = this->width() - 1;
      if (c >= this->width()) c = 0;

      if (r != row || c != column) {
        if (this->_board[r][c].isAlive()) {
          aliveCount++;
        }
      }
    }
  }
  return aliveCount;
}

void Board::VisitElements (const std::function <void (Cell&, int, int)>& f)
{
  for(unsigned int j=0; j<_board.size(); j++) {
    for(unsigned int i=0; i<_board[j].size(); i++) {
      f(_board[j][i], j, i);
    }
  }
}

void Board::Update() {
  VisitElements([&](Cell& cell, int row, int column) -> void {
    int count = LivingNeighbors(row, column);

    if (cell.isAlive() && (count < 2 || count > 3)) {
      cell.expire();
    }

    if (!cell.isAlive() && count == 3) {
      cell.birth();
    }
  });
}
