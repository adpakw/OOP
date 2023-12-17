#ifndef MATHTILE_H
#define MATHTILE_H

class MathTile {
protected:
  int top;
  int right;
  int bottom;
  int left;
  bool convex;

public:
  int get_top() const;
  int get_right() const;
  int get_bottom() const;
  int get_left() const;
  bool get_convex() const;

  void set_top(int value);
  void set_right(int value);
  void set_bottom(int value);
  void set_left(int value);
  void set_convex(bool value);

  MathTile();
  MathTile(int top, int right, int bottom, int left, bool convex);
  MathTile(const MathTile &mathTile);

  virtual void show() const;
  virtual void rotate(int angle);
};

#endif