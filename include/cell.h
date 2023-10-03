#pragma once
class Cell {
private:
  bool _alive;
  bool _next;

public:
  Cell(bool alive=false);
  bool isAlive();
  Cell& birth();
  Cell& expire();
  Cell& update();
};
