#ifndef __MESH_H__
#define __MESH_H__

#include <list>
#include <vector> // For read mesh
#include <fstream> // For read mesh
#include "element.h"

//! Mesh composed of elements
template<class ElementT, class ElementContainerT=std::list<ElementT>>
class Mesh
{
 public:
  /// Access of type of elements stored
  typedef ElementT Element;

  //! Default constructor
  Mesh() {}
  /// Copy constructor (delegated copying of internal containers)
  Mesh(Mesh const&) {}
  //! Destructor
  ~Mesh() {}
  /// Access to elements stored in the mesh
  ElementContainerT elements() const {
    return _elements;
  }
  /// Append an element
  void append_element(ElementT const& e) {
    _elements.push_back(e);
  }
 private:
  // Elements stored in current mesh
  ElementContainerT _elements;

};


//! Print Mesh contents
template<class ElementT, class ElementContainerT>
std::ostream& operator<<(std::ostream& os, Mesh<ElementT, ElementContainerT> const& m) {
  int i=0;
  for(auto const& e : m.elements()) {
    os << "Element " << i++ << std::endl;
    os << e << std::endl;
  }
  return os;
}

/*!
 * \brief Build a structured (quadrangular) mesh for the unit square
 *
 * \param nx Number of subdivisions on the x-axis
 * \param ny Number of subdivisions on the y-axis
 */
template<class MeshT>
MeshT build_square_msh(int nx, int ny)
{
  using Mesh = MeshT;
  using Square = typename Mesh::Element;
  using Node = typename Square::Node;
  using Point = typename Node::Point;
  using Scalar = typename Point::Scalar;

  Mesh mesh;
  int ncell = nx*ny, nver=(nx+1)*(ny+1);

  // 1. Define points
  std::vector<Node*> vertices(nver);
  Scalar dx=1.0/nx, dy=1.0/ny;
  int index=0;
  for(int i=0; i<=nx; i++) {
    Scalar x=i*dx;
    Scalar y=0;
    for(int j=0; j<=ny; j++) {
      std::clog << "Node (" << index << "): ";
      auto p = new Node( Point(x,y), index);
      std::clog << *p << std::endl;
      vertices[index++]=p;
      y+=dy;
    }
  }
  // 2. Define cells
  index=0;
  for(int i=0; i<nx; i++) {
    int i0=nx*i, i1=nx*(i+1);
    for(int j=0; j<ny; j++) {
      Square s( *vertices[i0+j], *vertices[i0+j+1],
		*vertices[i1+j], *vertices[i1+j+1] );
      mesh.append_element(s);
    }
  }
  return mesh;
}


/*!
 * \brief Read a triangular mesh (msh format) from a file
 *
 * Try to read mesh contents from a .msh file (for information about
 * the structure of these files, see FreeFem++ documentation). The
 * mesh is defined by triangular elements.
 *
 * \param filename
 * \returns 0 if file was successfully opened and read
 */
template<class ElementT, class ElementContainerT>
int read_file_msh(Mesh<ElementT, ElementContainerT>& mesh, std::string filename);

template<class ElementContainerT>
int read_file_msh(Mesh<Element<Node2D, 3>, ElementContainerT>& mesh, std::string filename) {
  using Triangle = Element<Node2D, 3>;
  using Node = typename Triangle::Node;
  using Point = typename Node::Point;
  using Scalar = typename Point::Scalar;

  std::clog << "opening msh file: " << filename << std::endl;
  std::fstream meshfile;
 // file.exceptions ( ifstream::failbit | ifstream::badbit );
  try {
    meshfile.open(filename, std::ios_base::in);
    if( !meshfile ) throw std::ios::failure( "Error opening file!" ) ;
  }
  catch (const std::ifstream::failure& e) {
    std::cerr << e.what() << '\n';
    return(1);
  }
  unsigned int nver, ncel, nedg;
  meshfile >> nver >> ncel >> nedg;
  std::clog << "nver=" << nver << " ncel=" << ncel
  	    << " nedg=" << nedg << std::endl;
  std::vector<Node*> vertices(nver);

  for(int i=0; i<nver; i++) {
    Scalar x, y;
    std::size_t label;
    meshfile >> x >> y >> label;
    std::clog << "Node (" << i << "): ";
    auto p = new Node( Point(x, y), i);
    std::clog << *p << std::endl;
    vertices[i]=p;
  }

  for(int i=0; i<ncel; i++) {
    unsigned int id0, id1, id2, zero;
    meshfile >> id0 >> id1 >> id2 >> zero;
    Triangle t( *vertices[id0-1], *vertices[id1-1], *vertices[id2-1] );
    mesh.append_element(t);
  }

  return(0);
}

#endif // __MESH_H__
