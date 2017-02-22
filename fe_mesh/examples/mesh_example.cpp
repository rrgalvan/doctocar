#include <iostream>
#include "mesh.h"

using namespace std;

int main() {
  cout << "Testing Mesh class..."  << endl;
  Node2D *a = new Node2D( Point2D(0,0) );
  Node2D *b = new Node2D( Point2D(1,0) );
  Node2D *c = new Node2D( Point2D(0,1) );
  Node2D *d = new Node2D( Point2D(1,1) );

  typedef Element<Node2D, 3> Triangle;
  Triangle t1(*a,*b,*c);
  Triangle t2(*b,*c,*d);

  Mesh<Triangle> m;
  // m.append_element(t1);
  // m.append_element(t2);
  // // m._elements.push_back(t1);
  // std::list<Triangle> l;
  // l.push_back(t1);

}
