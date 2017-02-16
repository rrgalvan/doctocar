#include <iostream>
#include "node.hpp"

int main() {
  Node<double> node1(1);
  std::cout << "Hola" << std::endl;
  std::cout << node1() << std::endl;
  Node<double> node2 = node1;
  std::cout << node2() << std::endl;
}
