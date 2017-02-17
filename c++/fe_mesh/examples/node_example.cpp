#include <iostream>
#include "node.h"
#include "point.h"

using namespace std;

int main() {
  cout << "Testing Node class..."  << endl;
  Node<double> node1;  // Default constructor
  Node<double> node2(1.0); // Default construtor
  Node<double> node3(node1); // Copy construtor
  node2.incSharingElements();
  cout << node1 << endl;
  cout << node2 << endl;
  cout << node3 << endl;
  node3 = node2;
  cout << node3 << endl;

  Point2D p(0,1);
  Node<Point2D> node2d(p);
  cout << node2d << endl;
}
