#ifndef ARBOL_BINARIO_TREE_H
#define ARBOL_BINARIO_TREE_H

#include <iostream>

enum Color { RED, BLACK };

class Tree {
private:
  int value;
  Color color;
  Tree *left = nullptr;
  Tree *right = nullptr;
  Tree *parent = nullptr;

public:
  Tree(int _value, Color _color = RED);
  int getValue();
  Color getColor();
  void setColor(Color _color);
  void push(int _value);
  void insertFixup(Tree *node);
  void rotateLeft(Tree *node);
  void rotateRight(Tree *node);
  void preorderLeft();
  void preorderRight();
  void postorderLeft();
  void postorderRight();
};

#endif
