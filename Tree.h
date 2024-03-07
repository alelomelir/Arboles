#ifndef ARBOL_BINARIO_TREE_H
#define ARBOL_BINARIO_TREE_H
#include<iostream>

class Tree {
private:
    int value;
    Tree* left = nullptr; //inicializamos variable de tipo puntero con un valor inicial de null (null tipo puntero)
    Tree* right = nullptr;
    int color = 0; //se inicializa el color en negro, 0
    
public:
    Tree(int _value);
    int getValue();
    void push(int _value);
    void preorderLeft();
    void preorderRight();
    void postorderLeft();
    void postorderRight();
};


#endif