#include "Tree.h"

Tree::Tree(int _value, Color _color) {
  value = _value;
  color = _color;
}

int Tree::getValue() { return value; }

Color Tree::getColor() { return color; }

void Tree::setColor(Color _color) { color = _color; }

void Tree::push(int _value) {
  Tree *newBranch = new Tree(_value);

  if (left == nullptr) {
    left = newBranch;
    newBranch->parent = this;
  } else if (right == nullptr) {
    right = newBranch;
    newBranch->parent = this;
  } else if (left->left == nullptr || left->right == nullptr) {
    left->push(_value);
  } else {
    right->push(_value);
  }

  insertFixup(newBranch);
}

void Tree::insertFixup(Tree *node) {
  while (node->parent != nullptr && node->parent->getColor() == RED) {
    Tree *uncle = nullptr;

    if (node->parent == node->parent->parent->left) {
      uncle = node->parent->parent->right;

      if (uncle != nullptr && uncle->getColor() == RED) {

        node->parent->setColor(BLACK);
        uncle->setColor(BLACK);
        node->parent->parent->setColor(RED);
        node = node->parent->parent;
      } else {

        if (node == node->parent->right) {
          node = node->parent;
          rotateLeft(node);
        }

        node->parent->setColor(BLACK);
        node->parent->parent->setColor(RED);
        rotateRight(node->parent->parent);
      }
    } else {
      uncle = node->parent->parent->left;

      if (uncle != nullptr && uncle->getColor() == RED) {

        node->parent->setColor(BLACK);
        uncle->setColor(BLACK);
        node->parent->parent->setColor(RED);
        node = node->parent->parent;
      } else {

        if (node == node->parent->left) {
          node = node->parent;
          rotateRight(node);
        }

        node->parent->setColor(BLACK);
        node->parent->parent->setColor(RED);
        rotateLeft(node->parent->parent);
      }
    }
  }

  if (node->parent == nullptr) {
    node->setColor(BLACK);
  }
}

void Tree::rotateLeft(Tree *node) {
  Tree *newParent = node->right;
  node->right = newParent->left;

  if (newParent->left != nullptr) {
    newParent->left->parent = node;
  }

  newParent->parent = node->parent;

  if (node->parent == nullptr) {
    this->left = newParent;
  } else if (node == node->parent->left) {
    node->parent->left = newParent;
  } else {
    node->parent->right = newParent;
  }

  newParent->left = node;
  node->parent = newParent;
}

void Tree::rotateRight(Tree *node) {
  Tree *newParent = node->left;
  node->left = newParent->right;

  if (newParent->right != nullptr) {
    newParent->right->parent = node;
  }

  newParent->parent = node->parent;

  if (node->parent == nullptr) {
    this->left = newParent;
  } else if (node == node->parent->left) {
    node->parent->left = newParent;
  } else {
    node->parent->right = newParent;
  }

  newParent->right = node;
  node->parent = newParent;
}

void Tree::preorderLeft() {
  std::cout << "(" << value << ", " << (color == RED ? "Red" : "Black")
            << "), ";

  if (left != nullptr) {
    left->preorderLeft();
  }
  if (right != nullptr) {
    right->preorderLeft();
  }
}

void Tree::preorderRight() {
  std::cout << "(" << value << ", " << (color == RED ? "Red" : "Black")
            << "), ";

  if (right != nullptr) {
    right->preorderRight();
  }
  if (left != nullptr) {
    left->preorderRight();
  }
}

void Tree::postorderLeft() {
  if (left != nullptr) {
    left->postorderLeft();
  }
  if (right != nullptr) {
    right->postorderLeft();
  }

  std::cout << "(" << value << ", " << (color == RED ? "Red" : "Black")
            << "), ";
}

void Tree::postorderRight() {
  if (right != nullptr) {
    right->postorderRight();
  }
  if (left != nullptr) {
    left->postorderRight();
  }

  std::cout << "(" << value << ", " << (color == RED ? "Red" : "Black")
            << "), ";
}
