#include "MathTile.h"
#include <iostream>

int MathTile::get_top() const { return top; }

int MathTile::get_right() const { return right; }

int MathTile::get_bottom() const { return bottom; }

int MathTile::get_left() const { return left; }

bool MathTile::get_convex() const { return convex; }

void MathTile::set_top(int value) { top = value; }

void MathTile::set_right(int value) { right = value; }

void MathTile::set_bottom(int value) { bottom = value; }

void MathTile::set_left(int value) { left = value; }

void MathTile::set_convex(bool value) { convex = value; }

MathTile::MathTile() {
  top = 0;
  right = 0;
  bottom = 0;
  left = 0;
  convex = false;
}

MathTile::MathTile(int top, int right, int bottom, int left, bool convex) {
  this->top = top;
  this->right = right;
  this->bottom = bottom;
  this->left = left;
  this->convex = convex;
}

MathTile::MathTile(const MathTile &mathTile) {
  this->top = mathTile.top;
  this->right = mathTile.right;
  this->bottom = mathTile.bottom;
  this->left = mathTile.left;
  this->convex = mathTile.convex;
}

void MathTile::show() const {
  std::cout << "top = " << get_top() << "\nright = " << get_right()
            << "\nbottom = " << get_bottom() << "\nleft = " << get_left()
            << "\nis convex: " << get_convex() << std::endl;
}