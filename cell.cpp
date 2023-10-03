#include "cell.h"

Cell::Cell(bool alive/*=false*/) {
  this->_next = alive;
  this->_alive = alive;
}

Cell& Cell::birth() {
  this->_next = true;
  return *this;
}

Cell& Cell::expire() {
  this->_next = false;
  return *this;
}

bool Cell::isAlive() {
  return this->_alive;
}

Cell& Cell::update() {
  this->_alive = this->_next;
  return *this;
}
