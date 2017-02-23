#include <iostream>
#include "element.h"

using namespace std;

int main() {
  cout << "Testing Element class..."  << endl;

  Element<Node<double>,2> e1;  // Default constructor
  cout << "Element e1:" << endl << e1 << endl;

  auto a = new Node2D( Point2D(0,0), 1);
  auto b = new Node2D( Point2D(0,1), 2);
  auto c = new Node2D( Point2D(1,0), 3);
  Element<Node2D, 3> e2(*a,*b,*c); // Triangle constructor (from 3 nodes)
  cout << "Element e2:" << endl << e2 << endl;

  Element<Node2D, 3> e3(e2); // Copy constructor
  cout << "Element e3:" << endl << e3 << endl;

  auto d = new Node2D( Point2D(1,1) );
  Element<Node2D, 4> e4(*a,*b,*c,*d);
  cout << "Element e4:" << endl << e4 << endl;

  Element<Node2D, 3> e5;
  e5 = e3; // Asignement operator
  cout << "Element e5:" << endl << e5 << endl;

}
