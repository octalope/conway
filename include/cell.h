#ifndef _CELL_H_
#define _CELL_H_

class Cell {
private:
  bool alive;
  bool next;

public:
  Cell(bool alive=false);
  Cell& birth();
  Cell& expire();
  bool isAlive();
  Cell& update();
};

#endif // _CELL_H_
