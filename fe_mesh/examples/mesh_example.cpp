#include <iostream>
#include "mesh.h"

int main() {
  std::cout << "Testing Mesh class..."  << std::endl;

  std::cout << "##### Test 1" << std::endl;

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
    std::cout << "Element " << i++ << std::endl;
    std::cout << e << std::endl;
  }

  std::cout << "##### Test 2" << std::endl;
  Mesh<Triangle> m2;
  read_file_msh(m2, "square_mesh_2x2.msh");
  std::cout << "m2:" << std::endl << m2 << std::endl;

  std::cout << "##### Test 3" << std::endl;
  Mesh<Triangle> m3;
  read_file_msh(m3, "unit_circle_24.msh");
  std::cout << "m3:" << std::endl << m3 << std::endl;

  std::cout << "##### Test 4" << std::endl;
  typedef Element<Node2D, 4> Square;
  auto m4 = build_square_msh<Square> (2,2);
  std::cout << "m4:" << std::endl << m4 << std::endl;
}
