
#include "./Tree/Tree.h"
#include <iostream>

int main() {
  std::cout << "Inicia";
  Tree *Arbol = new Tree(5);

  Arbol->push(3);
  Arbol->push(7);
  Arbol->push(2);
  Arbol->push(4);

  std::cout << "Preorder(Left): ";
  Arbol->preorderLeft();
  std::cout << std::endl;

  std::cout << "Preorder(Right): ";
  Arbol->preorderRight();
  std::cout << std::endl;

  std::cout << "Postorder(Left): ";
  Arbol->postorderLeft();
  std::cout << std::endl;

  std::cout << "Postorder(Right): ";
  Arbol->postorderRight();
  std::cout << std::endl;

  return 0;
}