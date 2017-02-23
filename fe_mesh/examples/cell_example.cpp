#include <iostream>
#include "mesh.h"
#include "cell.h"

int main() {
  std::cout << "Testing Cell class..."  << std::endl;

  std::cout << "##### Test 1 (define Mesh and append 2 triangular cells)" << std::endl;

  auto a = new Node2D( Point2D(0,0), 1 );
  auto b = new Node2D( Point2D(1,0), 2 );
  auto c = new Node2D( Point2D(0,1), 3 );
  auto d = new Node2D( Point2D(1,1), 4 );

  typedef Cell<Node2D, 3, double> TriangleD;
  TriangleD t1(*a, *b, *c);
  TriangleD t2(*b, *c, *d);

  Mesh<TriangleD> m;
  m.append_element(t1);
  m.append_element(t2);

  int i=0;
  for(auto const& e : m.elements()) {
    std::cout << "Cell " << i++ << std::endl;
    std::cout << e << std::endl;
  }

  std::cout << "##### Test 2 (read triangle mesh from a file)" << std::endl;
  Mesh<TriangleD> m2; // Default container: list of triangles
  read_file_msh(m2, "square_mesh_2x2.msh");
  std::cout << "m2:" << std::endl << m2 << std::endl;

  std::cout << "##### Test 3 (create a mesh where Element container is a vector)" << std::endl;
  Mesh<TriangleD, std::vector<TriangleD>> m3;
  read_file_msh(m3, "unit_circle_24.msh");
  std::cout << "m3:" << std::endl << m3 << std::endl;
  std::cout << "We can access to 2nd element in the mesh:" << std::endl
  	    << m3.elements()[1] << std::endl;

  std::cout << "##### Test 4 (build a structured (quadrangular) mesh in the unit square" << std::endl;
  using SquareI = Cell<Node2D, 4, int>;
  auto m4 = build_square_msh <Mesh<SquareI> > (2,2);
  std::cout << "m4:" << std::endl << m4 << std::endl;
}
