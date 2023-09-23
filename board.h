#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <string>
#include <format>
#include <vector>
#include<functional> 
#include<algorithm> 

#include "cell.h"

class Coordinate {
private:
  int _row;
  int _column;
public:
  Coordinate(int r, int c): _row(r), _column(c) {}
  int row() { return this->_row; }
  int column() { return this->_column; }
  std::string toString() { return std::format("({}, {})", this->_row, this->_column); }
};

class Board {
private:
  std::vector<std::vector<Cell>> board;

public:
  Board(int rows, int cols) {
    for(int j=0; j<rows; j++) {
      std::vector<Cell> row;
      for(int i=0; i<cols; i++) {
        row.push_back(Cell());
        // row.push_back(Cell((static_cast<float>(rand())/static_cast<float>(RAND_MAX) > 0.90)));
      }
      board.push_back(row);
    } 
  }

  void set(int row, int col) {
    this->board[row][col].birth().update();
  }

  int height() const {  
    return this->board.size();
  }

  int width() const {
    return this->board[0].size();
  }

  void Log() {
    for(int i=0; i<this->width(); i++) {
      std::cout << "=";
    }
    std::cout << std::endl;

    VisitElements([&](Cell& cell, int row, int column) -> void {
      cell.update();
      std::cout << (cell.isAlive() ? "*" : " "); 
      if(column == width()-1) {
        std::cout << std::endl;
      }
    }); 
    std::cout << std::endl;

    for(int i=0; i<this->width(); i++) {
      std::cout << "=";
    }
    std::cout << std::endl;
  }

  std::vector<Coordinate> NeighborCoordinates(int row, int column) const {
    std::vector<Coordinate> result;

    for(int j=-1; j<=1; j++) {
      for(int i=-1; i<=1; i++) {
        int r = row + j;
        if (r < 0) r = this->height() - 1;
        if (r >= this->height()) r = 0;

        int c = column + i;
        if (c < 0) c = this->width() - 1;
        if (c >= this->width()) c = 0;

        if (r != row || c != column) {
          result.push_back(Coordinate(r, c));
        }
      }
    }
    return result;
  }

  void InitShape(int row, int col, std::vector<std::vector<int>> shape) {
    for(size_t j=0; j<shape.size(); j++) {
      for(size_t i=0; i<shape[0].size(); i++) {
        if (shape[j][i]) {
          this->board[j+row][i+col].birth().update();
        }
      }
    }
  }

  int LivingNeighbors(int row, int column) {
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
          if (this->board[r][c].isAlive()) {
            aliveCount++;
          }
        }
      }
    }
    return aliveCount;
  }
  
  void VisitElements (const std::function <void (Cell&, int, int)>& f)
  {
    for(unsigned int j=0; j<board.size(); j++) {
      for(unsigned int i=0; i<board[j].size(); i++) {
        f(board[j][i], j, i);
      }
    }
  }

  void Update() {
    VisitElements([&](Cell& cell, int row, int column) -> void {
      int count = LivingNeighbors(row, column);
      // std::cout << (cell.isAlive() ? "!" : " ") << " (" << row << " " << column << ") " << count << " ";
      
      if (cell.isAlive() && (count < 2 || count > 3)) {
        cell.expire();
      }

      if (!cell.isAlive() && count == 3) {
        cell.birth();
      }

      //  std::cout << (cell.isAlive() ? "!" : " ") << " " << (cell.nextAlive() ? "!" : " " )<< std::endl;
    });
  }
};

#endif // _BOARD_H_
