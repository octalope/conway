#include "cell.h"

Cell::Cell(bool alive/*=false*/) {
  this->next = alive;
  this->alive = alive;
}

Cell& Cell::birth() {
  this->next = true;
  return *this;
}

Cell& Cell::expire() {
  this->next = false;
  return *this;
}

bool Cell::isAlive() {
  return this->alive;
}

Cell& Cell::update() {
  this->alive = this->next;
  return *this;
}
