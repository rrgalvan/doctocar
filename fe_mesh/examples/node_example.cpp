#include <iostream>
#include "mesh/node.h"

using namespace std;

int main() {
  cout << "Testing Node class..."  << endl;
  Node<double> node1;  // Default constructor
  Node<double> node2(1.0); // Default construtor
  Node<double> node3(node1); // Copy construtor
  cout << node1 << endl;
  cout << node2 << endl;
  cout << node3 << endl;
  node3 = node2;
  cout << node3 << endl;

  Point2D p(0,1);
  Node<Point2D> node2d(p);
  cout << node2d << endl;
}
