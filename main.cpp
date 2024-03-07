#include <iostream>
#include "./Tree.h"

int main()
{
    Tree *tree = new Tree(5);

    tree->push(3);
    tree->push(7);
    tree->push(2);
    tree->push(4);

    tree->preorderLeft();

    std::cout << std::endl;

    tree->preorderRight();

    std::cout << std::endl;

    tree->postorderIzq();

    std::cout << std::endl;

    tree->postorderRight();

    return 0;
}