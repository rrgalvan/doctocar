#include <iostream>
#include "mesh.h"

using namespace std;

int main() {
  cout << "Testing Mesh class..."  << endl;
  auto a = new Node2D( Point2D(0,0), 1 );
  auto b = new Node2D( Point2D(1,0), 2 );
  auto c = new Node2D( Point2D(0,1), 3 );
  auto d = new Node2D( Point2D(1,1), 4 );

  typedef Element<Node2D, 3> Triangle;
  Triangle t1(*a, *b, *c);
  Triangle t2(*b, *c, *d);

  Mesh<Triangle> m;
  m.append_element(t1);
  m.append_element(t2);

  int i=0;
  for(auto const& e : m.elements()) {
    cout << "Element " << i++ << endl;
    cout << e << endl;
  }

}
