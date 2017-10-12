#include <iostream>
#include "mesh/mesh.h"

int main() {
  std::cout << "Testing Mesh class..."  << std::endl;

  std::cout << "##### Test 1 (define Mesh and append 2 triangles)" << std::endl;

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

  std::cout << "##### Test 2 (read triangle mesh from a file)" << std::endl;
  Mesh<Triangle> m2; // Default container: list of triangles
  read_file_msh(m2, "square_mesh_2x2.msh");
  std::cout << "m2:" << std::endl << m2 << std::endl;

  std::cout << "##### Test 3 (create a mesh where Element container is a vector)" << std::endl;
  Mesh<Triangle, std::vector<Triangle>> m3;
  read_file_msh(m3, "unit_circle_24.msh");
  std::cout << "m3:" << std::endl << m3 << std::endl;
  std::cout << "We can access to 2nd element in the mesh:" << std::endl
	    << m3.elements()[1] << std::endl;

  std::cout << "##### Test 4 (build a structured (quadrangular) mesh in the unit square" << std::endl;
  using Square = Element<Node2D, 4>;
  auto m4 = build_square_msh <Mesh<Square> > (2,2);
  std::cout << "m4:" << std::endl << m4 << std::endl;
}
