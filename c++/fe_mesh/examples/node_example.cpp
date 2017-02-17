#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include "node.hpp"

using namespace std;

int main() {
  cout << "Testing Node class..."  << endl;
  Node<double> node1;  // Default constructor
  Node<double> node2(1.0); // Default construtor
  Node<double> node3 = node1; // Copy construtor
  node2.incSharingElements();
  cout << node1 << endl;
  cout << node2 << endl;
  cout << node3 << endl;
  node3 = node2;
  cout << node3 << endl;

  typedef pair<double,double> Point2D;
  Point2D p=make_pair(0.0, 1.0);
  Node<Point2D> node2d(p);
  // Error (operador << no definido para pair<double,double>):
  // cout << node2d << endl;
}
