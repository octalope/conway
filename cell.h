#ifndef _CELL_H_
#define _CELL_H_

class Cell {
private:
  bool alive;
  bool next;

public:
  Cell(bool alive=false) {
    this->next = alive;
    this->alive = alive;
  }

  Cell& birth() {
    this->next = true;
    return *this;
  }

  Cell& expire() {
    this->next = false;
    return *this;
  }

  bool isAlive() {
    return this->alive;
  }

  bool nextAlive() {
    return this->next;
  }

  Cell& update() {
    this->alive = this->next;
    return *this;
  }
};

#endif // _CELL_H_
